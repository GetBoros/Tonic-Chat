#include "Main.h"

#include "libtmic.h"

//------------------------------------------------------------------------------------------------------------
extern "C" int __stdcall SetConsoleOutputCP(unsigned int code_page);
extern "C" int __stdcall SetConsoleCP(unsigned int code_page);
//------------------------------------------------------------------------------------------------------------
constexpr unsigned int UTF8_CODE_PAGE = 65001;
//------------------------------------------------------------------------------------------------------------
void Init_Console()
{
   SetConsoleOutputCP(UTF8_CODE_PAGE);
   SetConsoleCP(UTF8_CODE_PAGE);
}
//------------------------------------------------------------------------------------------------------------
void handle_connected()
{
   std::cout << "EVENT: Connected!" << std::endl;
}
//------------------------------------------------------------------------------------------------------------
void handle_disconnected(const char* reason)
{
   std::cout << "EVENT: Disconnected. Reason: " << reason << std::endl;
}
//------------------------------------------------------------------------------------------------------------
void handle_message(const char *message_fserver)
{
   std::cout << message_fserver << std::endl;
}
//------------------------------------------------------------------------------------------------------------
int main()
{
   SLibtmic_Settings libtmic_settings { .Host = "127.0.0.1", .Port = 8080 };
   SLibtmic_Callbacks libtmic_callbacks = { 
      .On_Connected = &handle_connected,
      .On_Disconnected = &handle_disconnected,
      .On_Message_Received = &handle_message
   };

   Init_Console();
   DLibtmic_Run_Twitch_Chat_Client(&libtmic_settings, &libtmic_callbacks);

   return 0;
}
//------------------------------------------------------------------------------------------------------------
