//------------------------------------------------------------------------------------------------------------
#include "libtmic.h"
//------------------------------------------------------------------------------------------------------------
import Tonic.Chat.Clients;
//------------------------------------------------------------------------------------------------------------
void DLibtmic_API_Func_Client_Test(const SLibtmic_Settings *settings, wchar_t *msg_fserver, size_t msg_fserver_size)
{
   int index = 0;
    AClient client;

    if (index < msg_fserver_size)
       msg_fserver[0] = L'A';

    if (settings == 0)
       return; // Проверяем, что настройки предоставлены
    else
       client.Server_Connect(settings->Host, settings->Port);
}
//------------------------------------------------------------------------------------------------------------
