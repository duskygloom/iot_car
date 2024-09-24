#include "FSCT6B.h"

Receiver::Receiver(uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4, uint8_t ch5, uint8_t ch6)
{
    pinMode(ch1, INPUT_PULLUP);
    channels[CH1] = ch1;
    pinMode(ch2, INPUT_PULLUP);
    channels[CH2] = ch2;
    pinMode(ch3, INPUT_PULLUP);
    channels[CH3] = ch3;
    pinMode(ch4, INPUT_PULLUP);
    channels[CH4] = ch4;
    pinMode(ch5, INPUT_PULLUP);
    channels[CH5] = ch5;
    pinMode(ch6, INPUT_PULLUP);
    channels[CH6] = ch6;
}

void Receiver::printPWMs() {
    for (int i = CH1; i <= CH6; ++i)
        Serial.print(String(getPWM(i)) + " ");
    Serial.println();
}

void Receiver::printAnalogs() {
    for (int i = CH1; i <= CH6; ++i)
        Serial.print(String(getAnalog(i)) + " ");
    Serial.println();
}

void Receiver::printFractions() {
    for (int i = CH1; i <= CH6; ++i)
        Serial.print(String(getFraction(i)) + " ");
    Serial.println();
}

/**
 * @note
 * PWM belongs to [MIN_PWM, MAX_PWM], even if it is
 * actually not.
 * 
 * @returns
 * Returns PWM at the channel. If channel does not
 * exist, returns -1.
 */
int Receiver::getPWM(int channel) {
    if (channel < CH1 || channel > CH6)
        return -1;
    int pulse = pulseIn(channels[channel], HIGH);
    if (pulse > MAX_PWM) return MAX_PWM;
    else if (pulse < MIN_PWM) return MIN_PWM;
    return pulse;
}

/**
 * @returns
 * Returns PWM mapped to [-MAX_ANALOG, MAX_ANALOG] at the
 * channel. If channel does not exist, returns -1.
 * 
 * @note
 * Analog value returned may be negative. Ensure that the
 * direction value is inverted and speed value is positive
 * when using it in motor drivers.
 */
int Receiver::getAnalog(int channel) {
    int pulse = getPWM(channel);
    if (pulse == -1) return -1;
    return map(pulse, MIN_PWM, MAX_PWM, -MAX_ANALOG, MAX_ANALOG);
}

/**
 * @returns
 * Returns PWM mapped to [0, 1] at the channel.
 * If channel does not exist, returns -1.
 */
double Receiver::getFraction(int channel) {
    int pulse = getPWM(channel);
    if (pulse == -1) return -1;
    return double(pulse - MIN_PWM) / (MAX_PWM - MIN_PWM);
}

/**
 * @return
 * Returns true if switch B is turned on.
 * Else returns false.
 * 
 * @note
 * When switch B is off, channel B returns
 * very low PWM.
 */
bool Receiver::switchB()
{
    return getFraction(CH3) > 0.05;
}
