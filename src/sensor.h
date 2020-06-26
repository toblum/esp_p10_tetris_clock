float readTemperature(int index_sensor = 0)
{
    Serial.println("Requesting temperatures...");

    // Disable Serial while reading OneWire sensor on RX pin
    Serial.flush();
    Serial.end();

    float tempC = sensors.getTempCByIndex(0);
    sensors.requestTemperatures();

    Serial.begin(115200);
    Serial.flush();
    

    // Check if reading was successful
    if (tempC != DEVICE_DISCONNECTED_C)
    {
        Serial.print("Temperature for the device is: ");
        Serial.println(tempC);
        return tempC;
    }
    else
    {
        Serial.println("Error: Could not read temperature data");
        return NULL;
    }
}

void updateTemperature()
{
    float tempC = readTemperature(0);
    if (tempC) {
        temperatureSamples.add(tempC);
    }
}