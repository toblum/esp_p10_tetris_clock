float readTemperature(int index_sensor = 0)
{
    Serial.println("Requesting temperatures...");

    // Disable Serial while reading OneWire sensor on RX pin
    Serial.flush();
    Serial.end();

    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);

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

String getTemperatureString() {
    float tempC = temperatureSamples.getAverage() * 10;
    int tempCent = (int) tempC;
    String tempString = String(abs(tempCent));

    int len = tempString.length();
    if (len > 3) {
        tempString = tempString.substring(len-3, len);
    }
    if (len == 2) {
        tempString = " " + tempString;
    }
    if (len == 1) {
        tempString = " 0" + tempString;
    }
    // Serial.println(tempString + "C");
    return tempString + "C";
}