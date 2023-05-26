#ifndef _DEVICE_H_
#define _DEVICE_H_

#include "Arduino.h"

#include "log.h"
#include "lora_send.h"

#include "debug_utils.h"
#define DEBUG

// Pines de los reles de las electrovalvulas
#define EV_SEC_1_ON 12
#define EV_SEC_1_OFF 13

#define EV_SEC_2_ON 15
#define EV_SEC_2_OFF 2

#define ON "ON"

#define OFF "OFF"

// Estado de cada electrovalvula
struct elecVal
{
    bool evDepGaloBajoSec1 = false;
    bool evDepGaloBajoSec2 = false;

} elecVal;

// Topic recibidos
// const char evDepHuertoSec1[] = "regar/huerto/sec1";
// const char evDepHuertoSec2[] = "regar/huerto/sec2";

const char evDepGaloBajoSec1[] = "regar/galo/bajo/sec1";
const char evDepGaloBajoSec2[] = "regar/galo/bajo/sec2";

// Topic enviar estados
// const char evDepHuertoSec1State[] = "regar/huerto/sec1/state";
// const char evDepHuertoSec2State[] = "regar/huerto/sec2/state";

const char evDepGaloBajoSec1State[] = "regar/galo/bajo/sec1/state";
const char evDepGaloBajoSec2State[] = "regar/galo/bajo/sec2/state";

void initPinDevice()
{
    // Inicializar electrovalvula sector 1
    pinMode(EV_SEC_1_ON, OUTPUT);
    digitalWrite(EV_SEC_1_ON, HIGH);

    pinMode(EV_SEC_1_OFF, OUTPUT);
    digitalWrite(EV_SEC_1_OFF, HIGH);

    // Inicializar electrovalvula sector 2
    pinMode(EV_SEC_2_ON, OUTPUT);
    digitalWrite(EV_SEC_2_ON, HIGH);

    pinMode(EV_SEC_2_OFF, OUTPUT);
    digitalWrite(EV_SEC_2_OFF, HIGH);

    DEBUG_PRINT("Pines de las electrovalvulas y motor iniciados...");

    // Escribe en el log inicializacion de los pines
    write_log("Pines de las electrovalvulas y motor iniciados...");
}

#endif // _DEVICE_H_