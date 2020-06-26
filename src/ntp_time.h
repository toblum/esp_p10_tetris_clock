// *********************************************************************
// Functions for NTP and time handling
// *********************************************************************

// *********************************************************************
// Function that updates the number to draw at a given position
// *********************************************************************
void setTimeNumber(uint8_t pos, uint8_t number)
{
	// Serial.printf("Set position %d to %d\n", pos, number);
	numstates[pos].num_to_draw = number;
	numstates[pos].fallindex = 0;
	numstates[pos].blockindex = 0;
}

// *********************************************************************
// Called when time has changed, updates numbers where necessary
// *********************************************************************
void updateTime(String str_current_time)
{
	//  Serial.print(str_display_time);
	//  Serial.print(" -> ");
	//  Serial.println(str_current_time);

	for (uint8_t pos = 0; pos < SIZE_NUM_STATES; pos++)
	{
		if (str_display_time.charAt(pos) != str_current_time.charAt(pos))
		{
			String character = str_current_time.substring(pos, pos + 1);
			int number = character.toInt();
			if (character == " ") {
				number = 10;
			}
			if (character == "C") {
				number = 11;
			}
			setTimeNumber(pos, number);
		}
	}
}

// *********************************************************************
// Returns the current NTP time as a four letter string 12:34 returns "1234"
// Also sets the seconds odd global
// *********************************************************************
String getTimeAsString()
{
	String current_time = NTP.getTimeStr();
	String hours = current_time.substring(0, 2);
	String minutes = current_time.substring(3, 5);
	String seconds = current_time.substring(6, 8);
	String str_current_time = hours + minutes;

	// Check if seconds odd
	seconds_odd = (seconds.toInt() % 2 == 1);

	return str_current_time;
}