//------------------------------------------------------------------------------------------------------------
#include "libtmic.h"
//------------------------------------------------------------------------------------------------------------
import Tonic.Chat.Clients;
//------------------------------------------------------------------------------------------------------------
void DLibtmic_Run_Twitch_Chat_Client(const SLibtmic_Settings *settings, const SLibtmic_Callbacks *callbacks)
{
   int index = 0;  // if index == 2 has logic to disconect from server, temp for now
   ATwitch_Chat_Client twitch_chat_client;

   if (settings == 0)
      return;

   if (twitch_chat_client.Connect_To_Server(settings->Host, settings->Port) )
      callbacks->On_Connected();
   else
      return callbacks->On_Disconnected("Can`t connect server, some reason");

   do
   {
      twitch_chat_client.Tick(index);  // here is logic to save msg from server to Queue_From_Server
      
      // !!! Temp prototype
      //callbacks->On_Message_Received(twitch_chat_client.Queue_From_Server.front().c_str() );  // read msg from server
      twitch_chat_client.Queue_From_Server.pop();  // delete msg from queue || 

   } while (twitch_chat_client.Is_Connected == true);
}
//------------------------------------------------------------------------------------------------------------
