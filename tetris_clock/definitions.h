// *********************************************************************
// Holds all central definitions and globals
// *********************************************************************

Ticker display_ticker;          // Ticker that triggers redraw of the screen
Ticker timer_ticker;            // Ticker that triggers one revolution in the falling animation

// NTP
int8_t timeZone = 1;            // Timezone for NTP client
int8_t minutesTimeZone = 0;     // Minutes difference for time zone

// Globals
uint8_t init_state = 0;         // Hold the current state of the initialization process
String str_display_time = "0000"; // Holds the currently displayed time as string
bool seconds_odd = false;       // True when the seconds are currently odd

// WiFiManager
WiFiManager wifiManager;        // Global WiFiManager object
#define AP_NAME "tetris_clock"
#define AP_PASS "tetromino"
#define AP_TIMEOUT 300


// Pins for LED MATRIX
#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_OE 2
P10_MATRIX display(P_LAT, P_OE, P_A, P_B, P_C);
