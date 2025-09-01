#pragma once

#ifdef _WIN32
  #ifdef DLIBTMIC_EXPORTS
    #define DLIBTMIC_EXPORTS __declspec(dllexport)   // при сборке DLL
  #else
    #define DLIBTMIC_EXPORTS __declspec(dllimport)   // при использовании DLL
  #endif
#else
  #define DLIBTMIC_EXPORTS
#endif

extern "C"
{
   DLIBTMIC_EXPORTS int DLibtmic_Exports_Func_From_AdTemp(int a, int b);
}
