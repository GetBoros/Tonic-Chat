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
int main()
{
   wchar_t *msg_from_server = new wchar_t[10] {};
   SLibtmic_Settings libtmic_settings { .Host = "127.0.0.1", .Port = 8080 };

   Init_Console();
   DLibtmic_API_Func_Client_Test(&libtmic_settings, msg_from_server, 10);

   delete[] msg_from_server;

   return 0;
}
//------------------------------------------------------------------------------------------------------------
