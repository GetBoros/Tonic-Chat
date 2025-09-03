//------------------------------------------------------------------------------------------------------------
#include "libtmic.h"
//------------------------------------------------------------------------------------------------------------
import Tonic.Chat.Clients;
//------------------------------------------------------------------------------------------------------------
void DLibtmic_Run_Twitch_Chat_Client(const SLibtmic_Settings *settings, const SLibtmic_Callbacks *callbacks)
{
   int index = 0;
   ATwitch_Chat_Client twitch_chat_client;

   if (settings == 0)
      return;

   if (twitch_chat_client.Connect_To_Server(settings->Host, settings->Port) )
      callbacks->On_Connected();
   else
      return callbacks->On_Disconnected("Server error");

   do
   {
      twitch_chat_client.Tick(index);
      
      // !!!
      callbacks->On_Message_Received(twitch_chat_client.Queue_From_Server.front().c_str() );  // read msg from server
      twitch_chat_client.Queue_From_Server.pop();  // delete msg from queue || 

   } while (twitch_chat_client.Is_Connected == true);
}
//------------------------------------------------------------------------------------------------------------
