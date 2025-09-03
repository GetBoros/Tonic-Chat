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
typedef struct _Tonic_Chat_Call_backs
{// or can like this || typedef void (*on_message_received_t)(const char* channel, const char* user, const char* message);

   void (*On_Connected)();
   void (*On_Disconnected)(const char *reason);
   void (*On_Message_Received)(const char *message_fserver);

} SLibtmic_Callbacks;
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
   * @brief Runs the main loop for the Twitch chat client.
   *
   * @details This is a blocking function. It initializes a connection to the server
   * using the provided settings and then enters a continuous loop to receive messages.
   * All events, such as a successful connection, receiving a new message, or
   * a disconnection, are reported asynchronously through the functions provided
   * in the `callbacks` structure.
   *
   * This function will only return control to the caller once the connection
   * to the server is terminated.
   *
   * @warning Since this function blocks the calling thread, it is highly recommended
   * to run it in a separate thread (e.g., using `std::thread` in C++ or `CreateThread`
   * in the Windows API). Otherwise, the main thread of your application (e.g., the
   * user interface) will be frozen until the client disconnects.
   *
   * @param settings A pointer to a structure containing the settings for the connection
   *                 (host address, port, etc.). This pointer must not be null.
   * @param callbacks A pointer to a structure containing the callback functions that will
   *                  be invoked on various events (on connected, on message received, etc.).
   *                  This pointer must not be null.
   */
   DLIBTMIC_API void DLibtmic_Run_Twitch_Chat_Client(const SLibtmic_Settings *settings, const SLibtmic_Callbacks *callbacks);
}
//------------------------------------------------------------------------------------------------------------

