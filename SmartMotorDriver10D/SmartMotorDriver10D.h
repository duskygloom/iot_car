#ifndef SMART_MOTOR_DRIVER_10D_H
#define SMART_MOTOR_DRIVER_10D_H

#define PWM_MODE 1
#define ANALOG_MODE 2
#define SERIAL_MODE 3

#define INVALID_SPEED 10


class MotorDriver
{
private:
    int mode;
    HardwareSerial serial;
    uint8_t s1, s2, d1, d2;

    union {
        HardwareSerial serial;
        struct {
            uint8_t s1, s2;
        } speed;
        struct {
            uint8_t d1, d2;
        } distance;
    } info;

public:
    MotorDriver(HardwareSerial serial);
    MotorDriver(uint8_t s1, uint8_t s2);
    MotorDriver(uint8_t s1, uint8_t s2, uint8_t d1, uint8_t d2);

    void setSpeed(int v1, int v2);
};

#endif // SMART_MOTOR_DRIVER_10D_H
