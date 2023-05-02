#ifndef _DEVICE_LORA_HANDLER_H_
#define _DEVICE_LORA_HANDLER_H_

#include <Arduino.h>

#include "device.h"

#include "debug_utils.h"
#define DEBUG

void data_lora_receive_control(String data)
{
    String send_state = "";

    // Comprueba si es la electrovalvula del sector 1 y pasa los datos a la funcion
    // que se encarga de activar o desactivar la electrovalvula
    if (data.indexOf((String)evDepGaloBajoSec1) != -1)
    {
        String payload = data.substring(data.indexOf("=") + 1);

        DEBUG_PRINT((String)evDepGaloBajoSec1 + "=" + payload);

        // Control sector 1
        if (payload == ON && elecVal.evDepGaloBajoSec1 == false)
        {
            DEBUG_PRINT("Sector_1=ON");

            digitalWrite(EV_SEC_1_ON, LOW);
            vTaskDelay(500);
            digitalWrite(EV_SEC_1_ON, HIGH);

            elecVal.evDepGaloBajoSec1 = true;
        }
        else if (payload == OFF)
        {
            DEBUG_PRINT("Sector_1=OFF");

            digitalWrite(EV_SEC_1_OFF, LOW);
            vTaskDelay(500);
            digitalWrite(EV_SEC_1_OFF, HIGH);

            elecVal.evDepGaloBajoSec1 = false;
        }

        // Envia los datos mediante lora
        send_state = (String)evDepGaloBajoSec1State + "=" + payload;

        send_data_lora(send_state);
    }

    // Comprueba si es la electrovalvula del sector 2 y pasa los datos a la funcion
    // que se encarga de activar o desactivar la electrovalvula
    if (data.indexOf((String)evDepGaloBajoSec2) != -1)
    {
        String payload = data.substring(data.indexOf("=") + 1);

        DEBUG_PRINT((String)evDepGaloBajoSec2 + "=" + payload);

        if (payload == ON && elecVal.evDepGaloBajoSec2 == false)
        {
            DEBUG_PRINT("Sector_2=ON");

            digitalWrite(EV_SEC_2_ON, LOW);
            vTaskDelay(500);
            digitalWrite(EV_SEC_2_ON, HIGH);

            elecVal.evDepGaloBajoSec2 = true;
        }
        else if (payload == OFF)
        {
            DEBUG_PRINT("Sector_2=OFF");

            digitalWrite(EV_SEC_2_OFF, LOW);
            vTaskDelay(500);
            digitalWrite(EV_SEC_2_OFF, HIGH);

            elecVal.evDepGaloBajoSec2 = false;
        }

        // Envia los datos mediante lora
        send_state = (String)evDepGaloBajoSec2State + "=" + payload;

        send_data_lora(send_state);
    }
}

#endif //_DEVICE_LORA_HANDLER_H_
