#ifndef _CONFIGINIT_H_
#define _CONFIGINIT_H_
#include <Arduino.h>

#include <wifi.h>

#define TIME_DELAY_ELEC_VAL 800

wifi_mode_t initWifiType = WIFI_MODE_APSTA;

String initSsidSTA = "Router_Casa_Juncares";
String initSsidAP = "MyESP32AP_2022";

String initPassSTA = "Red_Juncares";
String initPassAP = "adminadmin";

String initHost = "ESP32_2022";

String initIPap = "192.168.10.1";

String initIPsta = "";
String initGateway = "";
String initSubnet = "";

#endif //_CONFIGINIT_H_