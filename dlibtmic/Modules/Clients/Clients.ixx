//------------------------------------------------------------------------------------------------------------
module;
#include <iostream>
#include <vector>

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")
//------------------------------------------------------------------------------------------------------------
export module Tonic.Chat.Clients;
//------------------------------------------------------------------------------------------------------------
export class AClient
{
public:
   ~AClient();
   AClient();

   void Server_Connect(const char *host, const unsigned short port);

private:
   void Init_Server_Connection();
   void Message_Receive();
   void Message_Send(const char *msg);

   bool Is_Connected;
   unsigned short PORT;
   const char *HOST;

   SOCKET Socket_Client = 0;
};
//------------------------------------------------------------------------------------------------------------
AClient::~AClient()
{
}
//------------------------------------------------------------------------------------------------------------
AClient::AClient()
 : Is_Connected(false), PORT(0), HOST(0)
{

}
//------------------------------------------------------------------------------------------------------------
void AClient::Server_Connect(const char *host, const unsigned short port)
{
   int i = 0;
   const char *str_00 = "Hello World";
   const char *str_01 = "0";
   const char *str_arr[2] { str_00, str_01 };
   
   PORT = port;
   HOST = host;

   Init_Server_Connection();

   do
   {
      // if connected | send some msg | msg not 0 still conected | say server for disconect | if connected
      Message_Receive();  // waiting server response | if connected

      if (i < 2)  // change to enum state
         Message_Send(str_arr[i++]);  // if connected send some msg

   } while (Is_Connected == true);


   std::cout << "\nPress Enter to exit..." << std::endl;
   std::cin.get();
}
//------------------------------------------------------------------------------------------------------------
void AClient::Init_Server_Connection()
{
   sockaddr_in server_address;
   WSADATA wsa_data;

   if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
   {
      std::cerr << "WSAStartup failed." << std::endl;
      return;
   }

   Socket_Client = socket(AF_INET, SOCK_STREAM, 0);
   if (Socket_Client == INVALID_SOCKET)
   {
      std::cerr << "Failed to create socket." << std::endl;
      WSACleanup();

      return;
   }

   server_address.sin_family = AF_INET;
   server_address.sin_port = htons(PORT);
   inet_pton(AF_INET, HOST, &server_address.sin_addr);

   if (connect(Socket_Client, (struct sockaddr*)&server_address, sizeof(server_address) ) == SOCKET_ERROR)
   {
      std::cerr << "Failed to connect to server." << std::endl;

      closesocket(Socket_Client);
      WSACleanup();

      return;
   }
   std::cout << "Successfully connected to server." << std::endl;

}
//------------------------------------------------------------------------------------------------------------
void AClient::Message_Receive()
{
   int bytes_received;
   constexpr int buffer_size = 4096; //4 KB
   std::vector<char> buffer(buffer_size);

   bytes_received = recv(Socket_Client, buffer.data(), (int)buffer.size() - 1, 0);

   if (bytes_received > 0)
   {
      Is_Connected = true;
      buffer[bytes_received] = '\0'; // Важно для безопасности, чтобы сделать строку
      std::cout << "\n--- Server Response ---\n" << buffer.data() << "\n-----------------------\n" << std::endl;
   }
   else
   {
      std::cout << "\n--- Server Response End ---\n";

      Is_Connected = false;
      closesocket(Socket_Client);
      WSACleanup();
   }
}
//------------------------------------------------------------------------------------------------------------
void AClient::Message_Send(const char *msg)
{
   int send_bytes;
   //constexpr const char *message_to_server = "0";

   send_bytes = send(Socket_Client, msg, (int)strlen(msg), 0);

   if (send_bytes == SOCKET_ERROR)
      std::cerr << "Failed to send data to server." << std::endl;
   else
      std::cout << "Message sent to server successfully." << std::endl;
}
//------------------------------------------------------------------------------------------------------------
