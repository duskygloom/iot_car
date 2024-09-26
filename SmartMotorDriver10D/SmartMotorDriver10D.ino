void setup()
{
    pinMode(27, OUTPUT);
    Serial.begin(115200);
    while (!Serial) delay(10);
    Serial.println("\n\n---------- New session ----------\n\n");
}

void loop()
{
    for (int i = 0; i < 256; ++i) {
        // analogWrite(27, i);
        // Serial.println(String("Analog: ") + i);

        delay(100);
    }
}