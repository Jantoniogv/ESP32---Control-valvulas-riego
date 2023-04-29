#ifndef _LORA_SEND_H_
#define _LORA_SEND_H_
#include <Arduino.h>

#include "lora_init.h"
#include "log.h"

#include "debug_utils.h"
#define DEBUG

QueueHandle_t queue_lora_send = 0;

void sendDataLora(void *pvParameter)
{

    char data_buffer[32] = {0};
    String data = "";
    for (;;)
    {
        if (xQueueReceive(queue_lora_send, &data_buffer, pdMS_TO_TICKS(100)) == pdTRUE)
        {
            data = String(data_buffer);

            // send packet
            LoRa.beginPacket();
            LoRa.print(data);
            LoRa.endPacket();

            DEBUG_PRINT(data);
            write_log("send LoRa: " + data);
        }

        vTaskDelay(pdMS_TO_TICKS(200));
    }
}

void sendDataLora(String data)
{
    DEBUG_PRINT(data);

    // send packet
    LoRa.beginPacket();
    LoRa.print(data);
    LoRa.endPacket();

    write_log("send LoRa: " + data);
}

#endif //_LORA_SEND_H_