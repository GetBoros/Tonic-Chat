//------------------------------------------------------------------------------------------------------------
module;
#include <iostream>
#include <vector>
#include <queue> // Нужно подключить этот заголовок для работы с очередью

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")
//------------------------------------------------------------------------------------------------------------
export module Tonic.Chat.Clients;
//------------------------------------------------------------------------------------------------------------
export class ATwitch_Chat_Client  // !!! refactoring all class, a lot of shit`s logic
{
public:
   ~ATwitch_Chat_Client();
   ATwitch_Chat_Client();

   bool Connect_To_Server(const char *host, const unsigned short port);
   void Tick(int &index);

   bool Is_Connected;  // temp || use enums
   std::queue<std::string> Queue_From_Server;

private:
   void Message_Receive();
   void Message_Send(const int index);

   SOCKET Socket_Client = 0;
   std::vector<char> Receive_Buffer;  // 4 Kb
};
//------------------------------------------------------------------------------------------------------------
ATwitch_Chat_Client::~ATwitch_Chat_Client()
{
}
//------------------------------------------------------------------------------------------------------------
ATwitch_Chat_Client::ATwitch_Chat_Client()
 : Is_Connected(false), Receive_Buffer(4096)
{

}
//------------------------------------------------------------------------------------------------------------
bool ATwitch_Chat_Client::Connect_To_Server(const char *host, const unsigned short port)
{
   sockaddr_in server_address;
   WSADATA wsa_data;

   if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
   {
      std::cerr << "WSAStartup failed." << std::endl;
      return false;
   }

   Socket_Client = socket(AF_INET, SOCK_STREAM, 0);
   if (Socket_Client == INVALID_SOCKET)
   {
      std::cerr << "Failed to create socket." << std::endl;
      WSACleanup();

      return false;
   }

   server_address.sin_family = AF_INET;
   server_address.sin_port = htons(port);
   inet_pton(AF_INET, host, &server_address.sin_addr);

   if (connect(Socket_Client, (struct sockaddr*)&server_address, sizeof(server_address) ) == SOCKET_ERROR)
   {
      std::cerr << "Failed to connect to server." << std::endl;

      closesocket(Socket_Client);
      WSACleanup();

      return false;
   }
   std::cout << "Successfully connected to server." << std::endl;
   
   return true;
}
//------------------------------------------------------------------------------------------------------------
void ATwitch_Chat_Client::Tick(int &index)
{
   constexpr const int max_message = 10;
   int max_message_receive = 0;

   Message_Receive();  // waiting server response | if connected

   if (index == max_message)
   {
      max_message_receive++;
      Is_Connected = false;
   }
   
   Message_Send(max_message_receive);

   index++;
}
//------------------------------------------------------------------------------------------------------------
void ATwitch_Chat_Client::Message_Receive()
{
   int bytes_received;

   bytes_received = recv(Socket_Client, Receive_Buffer.data(), (int)Receive_Buffer.size() - 1, 0);  // wait until server send something
   if (bytes_received > 0)
   {
      Is_Connected = true;
      Receive_Buffer[bytes_received] = '\0';  // import to have idea where is string end

      Queue_From_Server.emplace(Receive_Buffer.data(), bytes_received);

      std::cout << "\n--- Server Response ---\n" << Receive_Buffer.data() << "\n-----------------------\n" << std::endl;
   }
   else  // if server send 0, end connection
   {
      Is_Connected = false;
      
      closesocket(Socket_Client);
      WSACleanup();

      std::cout << "\n--- Server Response End ---\n";
   }
}
//------------------------------------------------------------------------------------------------------------
void ATwitch_Chat_Client::Message_Send(const int index)
{
   constexpr const char *str_00 = "Still Can work";
   constexpr const char *str_01 = "0";  // if send to server he try to disconnect client
   constexpr const char *str_arr[2] { str_00, str_01 };

   int send_bytes = send(Socket_Client, str_arr[index], (int)strlen(str_arr[index]), 0);

   if (send_bytes == SOCKET_ERROR)
      std::cerr << "Failed to send data to server." << std::endl;
   else
      std::cout << "Message sent to server successfully." << std::endl;
}
//------------------------------------------------------------------------------------------------------------
