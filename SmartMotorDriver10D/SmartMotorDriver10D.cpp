#include "SmartMotorDriver10D.h"

#include <math.h>

// MotorDriver::MotorDriver(HardwareSerial serial)
// : mode(SERIAL_MODE) {
//     info.serial = serial;
// }

// MotorDriver::MotorDriver(uint8_t s1, uint8_t s2)
// : mode(ANALOG_MODE), s1(s1), s2(s2) {}

// MotorDriver::MotorDriver(uint8_t s1, uint8_t s2, uint8_t d1, uint8_t d2)
// : mode(PWM_MODE), s1(s1), s2(s2), d1(d1), d2(d2) {}

#define IS_VALID_SPEED(v) (v >= -9 && v <= 9)

void setSpeedSerial(int v1, int v2) {
    if (!IS_VALID_SPEED(v1) || !IS_VALID_SPEED(v2)) {
        return;
    }
    String command('*');
    command += (v1 < 0 ? '0' : '1') + ('0' + abs(v1));
    command += '#';
    Serial.println(String("Motor 1: ") + command);
    command = '*';
    command += (v2 < 0 ? '0' : '1') + ('0' + abs(v2));
    command += '#';
    Serial.println(String("Motor 2: ") + command);
}

void MotorDriver::setSpeed(int v1, int v2) {
    if (mode == SERIAL_MODE) setSpeedSerial(v1, v2);
}
