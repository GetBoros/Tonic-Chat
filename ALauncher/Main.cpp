#include "Main.h"

//#include <iostream>

//#include "cppmet.h"  // .dll cmet
//#include "AdTemp.h"  // .dll dexample
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
   Init_Console();

   DLibtmic_API_Func_Client_Test();

   //int result = Add_Numbers(5, 7);

   //Func_From_AdTemp(6, 8);
   //std::cout << "Result = " << result << std::endl;
   //std::system("pause");

   return 0;
}
//------------------------------------------------------------------------------------------------------------
