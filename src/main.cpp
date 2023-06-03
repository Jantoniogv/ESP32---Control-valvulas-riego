#include <Arduino.h>

// #include <Wire.h>

#include "config.h"
#include "wifi_functions.h"
#include "server_functions.h"
#include "lora_init.h"
#include "lora_receiver.h"
#include "device.h"
#include "device_lora_handler.h"
#include "log.h"

#include "debug_utils.h"
#define DEBUG

void setup()
{
  // Borra todas las claves del espacio de nombres en memoria
  // eraseFlash("config");

  // Inicializa el objeto con la variables de configuracion
  Config configData;

  // Inicia la conexion serial
  Serial.begin(115200);

  // Inicia el modulo LoRa
  init_lora();

  // Se captura los eventos de la conexion wifi
  WiFi.onEvent(WiFiEvent);

  // Configuramos el modo del wifi
  WiFi.mode(configData.getWifiType());

  // Iniciamos la conexion wifi como punto de acceso
  wifiConnectAP();

  // Inicia y configura el servidor web
  init_server();

  // Inicia la tarea que recibe los datos por LoRa
  xTaskCreatePinnedToCore(receiveDataLora, "loraData", 2048, nullptr, 5, nullptr, 1);

  // Inicia los pines usados para activas los dispositivos
  initPinDevice();

  // Iniciamos la conexion wifi como cliente
  wifiConnectSTA();
}

void loop()
{
  /* sendDataLora((String)n);
  n++;
  vTaskDelay(5000); */

  /*   if (Serial.available())
    {
      data_lora_receive_control(Serial.readString());
      } */

  vTaskDelay(pdMS_TO_TICKS(1));
}
