#ifndef FSCT4B_H
#define FSCT4B_H

#define MIN_PWM 1000
#define MAX_PWM 2000

#define MIN_ANALOG 0
#define MAX_ANALOG 256

#define NUM_CHANNELS 4

#define CH1 0
#define CH2 1
#define CH3 2
#define CH4 3

#include <Arduino.h>

/**
 * @note
 * Use channel micros instead of integers.
 */
class Receiver
{
private:
    uint8_t channels[NUM_CHANNELS];

public:
    Receiver(uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4);

    void printPWMs();
    void printAnalogs();
    void printFractions();

    int getPWM(int channel);
    int getAnalog(int channel);
    double getFraction(int channel);

    bool switchB();
};

#endif // FSCT4B_H
