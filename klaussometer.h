// 
#define STORED_READING 6
#define READINGS_ARRAY  \
{"Cave", "cave/tempset-ambient/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_TEMPERATURE, 0, 0}, \
  {"Living room", "livingroom/tempset-ambient/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_TEMPERATURE, 0,0},\
  {"Henry's room", "guest/tempset-ambient/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_TEMPERATURE, 0,0}, \
  {"Bedroom", "bedroom/tempset-ambient/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_TEMPERATURE, 0,0}, \
  {"Outside", "outside/tempset-ambient/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_TEMPERATURE, 0,0}, \
  {"Cave", "cave/tempset-humidity/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_HUMIDITY, 0,0}, \
  {"Living room", "livingroom/tempset-humidity/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_HUMIDITY, 0,0},\
  {"Henry's room", "guest/tempset-humidity/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_HUMIDITY, 0,0}, \
  {"Bedroom", "bedroom/tempset-humidity/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_HUMIDITY, 0,0}, \
  {"Outside", "outside/tempset-humidity/set", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_HUMIDITY, 0,0}, \
  {"Outside", "outside/tempset-humidity/battery", NO_READING, 0.0, {0.0}, CHAR_BLANK, false, DATA_BATTERY, 0,0}


#define CHAR_LEN 255

struct Readings {                   // Array to hold the incoming measurement
  const char description[50];       // Currently set to 50 chars long
  const char topic[50];             // MQTT topic
  char output[10];                  // To be output to screen - expected to be 2 chars long
  float currentValue;               // Current value received
  float lastValue[STORED_READING];  // Defined that the zeroth element is the oldest
  byte changeChar;                  // To indicate change in status
  bool enoughData;                  // to inidate is a full set of STORED_READING number of data points received
  int dataType;                     // Type of data received
  int readingIndex;                 // Index of current reading max will be STORED_READING
  unsigned long lastMessageTime;    // Millis this was last updated
};

struct Weather {
  float temperature;
  int pressure;
  float humidity;
  float windSpeed;
  float UV;
  char windDir[CHAR_LEN];
  char overal[CHAR_LEN];
  char description[CHAR_LEN];
  char icon[CHAR_LEN];
  long timeOffset;
  time_t updateTime;
  time_t dailyUpdateTime;
  char weather_time_string[CHAR_LEN];
};

struct Solar {
  time_t updateTime;
  float batteryCharge;
  float usingPower;
  float gridPower;
  float batteryPower;
  float solarPower;
  String time;
  float today_battery_min;
  float today_battery_max;
  bool minmax_reset;
  float today_buy;
  float month_buy;
};

struct ForecastDays {
  time_t dateTime;
  float maxTemp;
  float minTemp;
  char description[CHAR_LEN];
  char icon[CHAR_LEN];
  float moonPhase;
  time_t sunrise;
  time_t sunset;
};

struct ForecastHours {
  char localTime[CHAR_LEN];
  char icon[CHAR_LEN];
};

#define NO_READING "--"
// Character settings
#define CHAR_UP 'a'    // Based on epicycles font
#define CHAR_DOWN 'b'  // Based on epicycles ADF font
#define CHAR_SAME ' '  // Based on epicycles ADF font as blank if no chnage
#define CHAR_BLANK 32
#define CHAR_NO_MESSAGE 'f'  // Based on epicycles ADF font

// Data type definition for array
#define DATA_TEMPERATURE 0
#define DATA_HUMIDITY 1
#define DATA_SETTING 2
#define DATA_ONOFF 3
#define DATA_BATTERY 4

// Define constants used
#define MAX_NO_MESSAGE_SEC 3600LL            // Time before CHAR_NO_MESSAGE is set in seconds (long)
#define TIME_RETRIES 100                     // Number of time to retry getting the time during setup
#define WEATHER_UPDATE_INTERVAL 3600         // Interval between weather updates
#define SOLAR_UPDATE_INTERVAL 30             // Interval between solar updates
#define FORECAST_DAYS_UPDATE_INTERVAL 7200   // Interval between days forecast updates
#define FORECAST_HOURS_UPDATE_INTERVAL 3600  // Interval between hour forecast updates
#define FORECAST_DAYS 16                     // Number of day's forecast to request
#define FORECAST_HOURS 16                    // Number of hours's forecast to request
#define STATUS_MESSAGE_TIME 5                // Seconds an status message can be displayed

#define SCREEN_W 1024
#define SCREEN_H 600
#define TOUCH_ROTATION ROTATION_INVERTED

#define I2C_SDA_PIN 17
#define I2C_SCL_PIN 18
#define TOUCH_INT -1
#define TOUCH_RST 38
#define TFT_BL 10

#define WIFI_RETRIES 100  // Number of times to retry the wifi before a restart
#define CHAR_LEN 255

#define PIN_SD_CMD 11
#define PIN_SD_CLK 12
#define PIN_SD_D0 13

#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x205602
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
