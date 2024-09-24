#include "FSCT4B.h"

#define PIN_CH1 35
#define PIN_CH2 32
#define PIN_CH3 33
#define PIN_CH4 25

#define PIN_SPEED 26
#define PIN_DIRECTION 27

Receiver receiver(PIN_CH1, PIN_CH2, PIN_CH3, PIN_CH4);

void setup()
{
    Serial.begin(115200);
    while (!Serial) delay(10);
    Serial.println("\n\n---------- New session ----------\n\n");
}

void loop()
{
    receiver.printPWMs();
    receiver.printAnalogs();
    receiver.printFractions();
    Serial.println();
    delay(500);
}
