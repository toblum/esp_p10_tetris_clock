// #define PATTERN4
#include <Wire.h>
#include <Ticker.h>
#include <PxMatrix.h> // Download from: https://github.com/2dom/PxMatrix/, needs https://github.com/adafruit/Adafruit-GFX-Library via library manager
#include <TimeLib.h>
#include <NtpClientLib.h> // https://github.com/gmag11/NtpClient via library manager
#include <ESP8266WiFi.h>

// WiFi-Manager
#include <DNSServer.h>		  // Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h> // Local WebServer used to serve the configuration portal
#include <WiFiManager.h>	  // https://github.com/tzapu/WiFiManager WiFi Configuration Magic

// Local includes
#include "definitions.h"
#include "colors.h"
#include "numbers.h"
#include "drawing.h"
#include "ntp_time.h"

// ****************************************************************
// * Setup
// ****************************************************************
void setup()
{
	Serial.begin(115200);

	display.begin(16);
	display.setFastUpdate(true);
	display.clearDisplay();

	// Draw intro while WiFi is connecting
	drawIntro();

	// Connect to WiFi using WiFiManager
	// wifiManager.resetSettings();       // Reset WiFiManager settings, uncomment if needed
	wifiManager.setTimeout(AP_TIMEOUT); // Timeout until config portal is turned off
	if (!wifiManager.autoConnect(AP_NAME, AP_PASS))
	{
		Serial.println("Failed to connect and hit timeout");
		delay(3000);
		//reset and try again
		ESP.reset();
		delay(5000);
	}

	init_state = 1;

	display_ticker.attach(0.001, display_updater);
	yield();
	delay(2000);
	display_ticker.detach();
}

void loop()
{
	unsigned long now = millis();

	// Initialization state 1
	// WiFi is connected, now start NTP
	if (init_state == 1)
	{
		NTP.begin("pool.ntp.org", timeZone, true, minutesTimeZone);
		NTP.setInterval(63);
		init_state = 2;
	}

	// Initialization state 2
	// Clock is now set, init number updater
	if (init_state == 2)
	{
		// Log the current time
		Serial.print(NTP.getTimeDateString());
		Serial.print(" ");
		Serial.print(NTP.isSummerTime() ? "Summer Time. " : "Winter Time. ");
		Serial.print("WiFi is ");
		Serial.print(WiFi.isConnected() ? "connected" : "not connected");
		Serial.print(". ");
		Serial.print("Uptime: ");
		Serial.print(NTP.getUptimeString());
		Serial.print(" since ");
		Serial.println(NTP.getTimeDateString(NTP.getFirstSync()).c_str());
		init_state = 3;
	}

	// Initialization state 3
	// Everything ready, check for time change
	if (init_state == 3)
	{
		String str_current_time = getTimeAsString();

		// Time has changed
		if (str_display_time != str_current_time)
		{
			Serial.print("Time changed: ");
			Serial.println(str_current_time);
			updateTime(str_current_time);
			str_display_time = str_current_time;
		}

		display_updater();

		if (now > nextNumberUpdate) {
			number_updater();

			nextNumberUpdate = now + 100;
		}
	}
}