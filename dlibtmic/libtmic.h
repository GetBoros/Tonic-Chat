//------------------------------------------------------------------------------------------------------------
#pragma once
//------------------------------------------------------------------------------------------------------------
#ifdef _WIN32
  #ifdef DLIBTMIC_EXPORTS
    #define DLIBTMIC_API __declspec(dllexport)
  #else
    #define DLIBTMIC_API __declspec(dllimport)
  #endif
#endif
//------------------------------------------------------------------------------------------------------------
typedef struct _SLibtmic_Settings
{
   const char *Host;
   unsigned short Port;

} SLibtmic_Settings;
//------------------------------------------------------------------------------------------------------------
extern "C"
{
   /**
     * @brief Выполняет тестовую клиентскую функцию с заданными настройками и возвращает сообщение.
     *
     * @param host Указатель на строку (UTF-8 или ANSI) с адресом хоста.
     * @param port Номер порта.
     * @param outMessageBuffer Указатель на буфер, куда будет записано сообщение.
     * @param outMessageBufferSize Размер буфера в WCHARs (для wide-символов).
     * @return Размер записанного сообщения в WCHARs (без учета завершающего нуля),
     *         или 0, если произошла ошибка, или требуемый размер буфера, если он слишком мал.
     */
   DLIBTMIC_API void DLibtmic_API_Func_Client_Test(const SLibtmic_Settings *settings, wchar_t *msg_fserver, size_t msg_fserver_size);
}
//------------------------------------------------------------------------------------------------------------
