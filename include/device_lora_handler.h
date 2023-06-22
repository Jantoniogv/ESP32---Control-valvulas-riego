#ifndef _DEVICE_LORA_HANDLER_H_
#define _DEVICE_LORA_HANDLER_H_

#include <Arduino.h>

#include "device.h"
#include "config_init.h"
#include "lora_init.h"

#include "debug_utils.h"
#define DEBUG

void data_lora_receive_control(String data)
{
    String send_state = "";

    // Comprueba si es la electrovalvula del sector 1 y pasa los datos a la funcion
    // que se encarga de activar o desactivar la electrovalvula
    if (data.indexOf((String)evDepGaloBajoSec1) != -1)
    {
        // Finaliza la conexion LoRa a fin de evitar las interferencias con las bobinas de las electrovalvulas que se producen en pruebas
        end_lora();

        // Variable que almacena el payload del mensaje
        String payload = data.substring(data.indexOf("=") + 1);

        DEBUG_PRINT(data);

        // Control sector 1
        if (payload == ON && elecVal.evDepGaloBajoSec1 == false)
        {
            DEBUG_PRINT("Sector_1=ON");

            digitalWrite(EV_SEC_1_ON, LOW);
            vTaskDelay(pdMS_TO_TICKS(TIME_DELAY_ELEC_VAL));
            digitalWrite(EV_SEC_1_ON, HIGH);

            elecVal.evDepGaloBajoSec1 = true;
        }
        else if (payload == OFF)
        {
            DEBUG_PRINT("Sector_1=OFF");

            digitalWrite(EV_SEC_1_OFF, LOW);
            vTaskDelay(pdMS_TO_TICKS(TIME_DELAY_ELEC_VAL));
            digitalWrite(EV_SEC_1_OFF, HIGH);

            elecVal.evDepGaloBajoSec1 = false;
        }

        // Envia los datos mediante lora
        send_state = (String)evDepGaloBajoSec1State + "=" + payload;

        vTaskDelay(pdMS_TO_TICKS(10));

        // Inicia el modulo LoRa de nuevo
        init_lora();

        send_data_lora(send_state);
    }

    // Comprueba si es la electrovalvula del sector 2 y pasa los datos a la funcion
    // que se encarga de activar o desactivar la electrovalvula
    if (data.indexOf((String)evDepGaloBajoSec2) != -1)
    {
        // Finaliza la conexion LoRa a fin de evitar las interferencias con las bobinas de las electrovalvulas que se producen en pruebas
        end_lora();

        // Variable que almacena el payload del mensaje
        String payload = data.substring(data.indexOf("=") + 1);

        DEBUG_PRINT(data);

        if (payload == ON && elecVal.evDepGaloBajoSec2 == false)
        {
            DEBUG_PRINT("Sector_2=ON");

            digitalWrite(EV_SEC_2_ON, LOW);
            vTaskDelay(pdMS_TO_TICKS(TIME_DELAY_ELEC_VAL));
            digitalWrite(EV_SEC_2_ON, HIGH);

            elecVal.evDepGaloBajoSec2 = true;
        }
        else if (payload == OFF)
        {
            DEBUG_PRINT("Sector_2=OFF");

            digitalWrite(EV_SEC_2_OFF, LOW);
            vTaskDelay(pdMS_TO_TICKS(TIME_DELAY_ELEC_VAL));
            digitalWrite(EV_SEC_2_OFF, HIGH);

            elecVal.evDepGaloBajoSec2 = false;
        }

        // Envia los datos mediante lora
        send_state = (String)evDepGaloBajoSec2State + "=" + payload;

        vTaskDelay(pdMS_TO_TICKS(10));

        // Inicia el modulo LoRa de nuevo
        init_lora();

        send_data_lora(send_state);
    }
}

#endif //_DEVICE_LORA_HANDLER_H_
