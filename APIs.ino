
#include <lvgl.h>
#include "ui.h"
#include <WiFi.h>
#include <ArduinoMqttClient.h>
#include <HTTPClient.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>
#include <Preferences.h>

extern WiFiClient espClient;
extern HTTPClient httpClientWeather;
extern HTTPClient httpClientSolar;

extern Weather weather;
extern Solar solar;

// Get weather from weatherbit.io
void get_weather_t(void *pvParameters) {

  const char apiKey[] = WEATHERBIT_API;
  String requestUrl;
  time_t t;

  while (true) {
    String callstring;
    if (now() - weather.updateTime > WEATHER_UPDATE_INTERVAL) {
      httpClientWeather.begin("http://api.weatherbit.io/v2.0/current?city_id=3369157&key=" + String(apiKey));
      int httpCode = httpClientWeather.GET();
      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
          String payload = httpClientWeather.getString();

          JsonDocument root;
          deserializeJson(root, payload);
          float weatherTemperature = root["data"][0]["temp"];
          float weatherWindSpeed = root["data"][0]["wind_spd"];
          float UV = root["data"][0]["uv"];

          const char *weatherWindDir = root["data"][0]["wind_cdir"];
          int weatherPressure = root["data"][0]["pres"];
          const char *weatherDescription = root["data"][0]["weather"]["description"];
          const char *weatherIcon = root["data"][0]["weather"]["icon"];

          weather.temperature = weatherTemperature;
          weather.pressure = weatherPressure;
          weather.windSpeed = weatherWindSpeed * 3.6;
          weather.UV = UV;
          if (weatherDescription != 0) {
            strncpy(weather.description, weatherDescription, CHAR_LEN);
          }
          if (weatherIcon != 0) {
            strncpy(weather.icon, weatherIcon, CHAR_LEN);
          }
          if (weatherWindDir != 0) {
            strncpy(weather.windDir, weatherWindDir, CHAR_LEN);
          }
          weather.updateTime = now();
          timeClient.getFormattedTime().toCharArray(weather.weather_time_string, CHAR_LEN);
          strncpy(statusMessage, "Weather updated", CHAR_LEN);
          statusMessageUpdated = true;
          storage.begin("KO");
          storage.remove("weather");
          storage.putBytes("weather", (byte *)(&weather), sizeof(weather));
          storage.end();
        }
      } else {
        Serial.printf("[HTTP] GET current weather failed, error: %s\n", httpClientWeather.errorToString(httpCode).c_str());
        strncpy(statusMessage, "Weather updated failed", CHAR_LEN);
        statusMessageUpdated = true;
      }
    }

    if (now() - weather.dailyUpdateTime > FORECAST_DAYS_UPDATE_INTERVAL) {
      httpClientWeather.begin("http://api.weatherbit.io/v2.0/forecast/daily?city_id=3369157&days=" + String(FORECAST_DAYS) + "&key=" + String(apiKey));
      int httpCode = httpClientWeather.GET();
      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
          String payload = httpClientWeather.getString();
          JsonDocument root;
          deserializeJson(root, payload);
          for (int i = 0; i < FORECAST_DAYS; i++) {
            time_t forecastTime = root["data"][i]["ts"];
            float forecastMaxTemp = root["data"][i]["max_temp"];
            float forecastMinTemp = root["data"][i]["min_temp"];
            float forecastMoon = root["data"][i]["moon_phase"];
            const char *forecastDescription = root["data"][i]["weather"]["description"];
            const char *forecastIcon = root["data"][i]["weather"]["icon"];
            time_t sunrise = root["data"][i]["sunrise_ts"];
            time_t sunset = root["data"][i]["sunset_ts"];
            forecastDays[i].dateTime = forecastTime;
            forecastDays[i].maxTemp = forecastMaxTemp;
            forecastDays[i].minTemp = forecastMinTemp;
            forecastDays[i].moonPhase = forecastMoon;
            forecastDays[i].sunrise = sunrise + TIME_OFFSET;
            forecastDays[i].sunset = sunset + TIME_OFFSET;
            if (forecastDescription != 0) {
              strncpy(forecastDays[i].description, forecastDescription, CHAR_LEN);
            }
            if (forecastIcon != 0) {
              strncpy(forecastDays[i].icon, forecastIcon, CHAR_LEN);
            }
          }
          weather.dailyUpdateTime = now();
          strncpy(statusMessage, "Forecast days updated", CHAR_LEN);
          statusMessageUpdated = true;
          storage.begin("KO");
          storage.remove("forecastDays");
          storage.remove("weather");
          storage.putBytes("forecastDays", (byte *)(forecastDays), sizeof(forecastDays));
          storage.putBytes("weather", (byte *)(&weather), sizeof(weather));
          storage.end();
        }
      } else {
        Serial.printf("[HTTP] GET daily weather failed, error: %s\n", httpClientWeather.errorToString(httpCode).c_str());
      }
      if (httpClientWeather.connected()) {
        httpClientWeather.end();
      }
    }
    delay(300000);
  }
}

// Get solar values from Solarman
void get_solar_t(void *pvParameters) {

  String solar_url = SOLAR_URL;
  String solar_appid = SOLAR_APPID;
  String solar_secret = SOLAR_SECRET;
  String solar_username = SOLAR_USERNAME;
  String solar_passhash = SOLAR_PASSHASH;
  String solar_statioid = SOLAR_STATIONID;
  String token = "";
  char currentDate[CHAR_LEN];
  char currentYearMonth[CHAR_LEN];
  char previousMonthYearMonth[CHAR_LEN];


  // Get token code
  while (token.length() == 0) {
    httpClientSolar.begin("https://" + solar_url + "/account/v1.0/token?" + "appId=" + solar_appid);
    httpClientSolar.addHeader("Content-Type", "application/json");

    int httpCode = httpClientSolar.POST("{\n\"appSecret\" : \"" + solar_secret + "\", \n\"email\" : \"" + solar_username + "\",\n\"password\" : \"" + solar_passhash + "\"\n}");

    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        String payload = httpClientSolar.getString();
        JsonDocument root;
        deserializeJson(root, payload);
        const char *rec_token = root["access_token"];
        const char *success_msg = root["success"];
        if (strcmp (success_msg, "true") == 0) {
            strncpy(statusMessage, "Solar token obtained", CHAR_LEN);
            statusMessageUpdated = true;
            token = rec_token;
            token = "bearer " + token;
          }
        else {
          strncpy(statusMessage, "Solar token error", CHAR_LEN);
        }
      }
    } else {
      Serial.printf("[HTTP] GET solar token failed, error: %s\n", httpClientSolar.errorToString(httpCode).c_str());
      strncpy(statusMessage, "Getting solar token failed", CHAR_LEN);
      statusMessageUpdated = true;
    }
    delay(10000);
  }

  // Get station status
  while (true) {
    if (now() - solar.updateTime > SOLAR_UPDATE_INTERVAL) {
      httpClientSolar.begin("https://" + solar_url + "//station/v1.0/realTime?language=en");
      httpClientSolar.addHeader("Content-Type", "application/json");
      httpClientSolar.addHeader("Authorization", token);
      int httpCode = httpClientSolar.POST("{\n\"stationId\" : \"" + solar_statioid + "\"\n}");
      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
          String payload = httpClientSolar.getString();
          JsonDocument root;
          deserializeJson(root, payload);
          bool rec_success = root["success"];
          if (rec_success == true) {
            float rec_batteryCharge = root["batterySoc"];
            float rec_usingPower = root["usePower"];
            float rec_gridPower = root["wirePower"];
            float rec_batteryPower = root["batteryPower"];
            time_t rec_time = root["lastUpdateTime"];
            float rec_solarPower = root["generationPower"];

            struct tm ts;
            char time_buf[80];

            rec_time += TIME_OFFSET;
            ts = *localtime(&rec_time);
            strftime(time_buf, sizeof(time_buf), "%H:%M:%S", &ts);
            solar.updateTime = now();
            solar.solarPower = rec_solarPower / 1000;
            solar.batteryPower = rec_batteryPower / 1000;
            solar.usingPower = rec_usingPower / 1000;
            solar.batteryCharge = rec_batteryCharge;
            solar.gridPower = rec_gridPower / 1000;
            solar.time = time_buf;


            // Reset at midnight
            if (timeClient.getHours() == 0 && solar.minmax_reset == false) {
              solar.today_battery_min = 100;
              solar.today_battery_max = 0;
              solar.minmax_reset = true;
              storage.begin("KO");
              storage.remove("solarmin");
              storage.remove("solarmmax");
              storage.putFloat("solarmin", solar.today_battery_min);
              storage.putFloat("solarmmax", solar.today_battery_max);
              storage.end();
            } else {
              if (timeClient.getHours() != 0) {
                solar.minmax_reset = false;
              }
            }
            // Set minimum
            if ((solar.batteryCharge < solar.today_battery_min) && solar.batteryCharge != 0) {
              solar.today_battery_min = solar.batteryCharge;
              storage.begin("KO");
              storage.remove("solarmin");
              storage.putFloat("solarmin", solar.today_battery_min);
              storage.end();
            }
            // Set maximum
            if (solar.batteryCharge > solar.today_battery_max) {
              solar.today_battery_max = solar.batteryCharge;
              storage.begin("KO");
              storage.remove("solarmax");
              storage.putFloat("solarmax", solar.today_battery_max);
              storage.end();
            }

            strncpy(statusMessage, "Solar status updated", CHAR_LEN);
            statusMessageUpdated = true;
          }
        } else {
          Serial.printf("[HTTP] GET solar staus failed, error: %s\n", httpClientSolar.errorToString(httpCode).c_str());
          String payload = httpClientSolar.getString();
          strncpy(statusMessage, "Getting solar status failed", CHAR_LEN);
          statusMessageUpdated = true;
        }
      }
      delay(1000);
      /*
        timeType 1 with start and end date of today gives array of size "total", then in stationDataItems -> batterySoc to get battery min/max for today
        timeType 2 with start and end date of today gives today's buy ammount as stationDataItems -> buyValue
        timeType 3 with start and end date of today (but now date only year month) gives this months's buy ammount as stationDataItems -> buyValue
        */
      time_t now = timeClient.getEpochTime();
      struct tm CurrenTimeInfo = *localtime(&now);
      time_t previousMonth = now - 30 * 24 * 3600;  // One month ago
      struct tm previousMonthTimeInfo = *localtime(&previousMonth);

      strftime(currentDate, sizeof(currentDate), "%Y-%m-%d", &CurrenTimeInfo);
      strftime(currentYearMonth, sizeof(currentYearMonth), "%Y-%m", &CurrenTimeInfo);
      strftime(previousMonthYearMonth, sizeof(previousMonthYearMonth), "%Y-%m", &previousMonthTimeInfo);

      // Get the today buy amount (timetype 2)
      httpClientSolar.begin("https://" + solar_url + "//station/v1.0/history?language=en");
      httpClientSolar.addHeader("Content-Type", "application/json");
      httpClientSolar.addHeader("Authorization", token);

      httpCode = httpClientSolar.POST("{\n\"stationId\" : \"" + solar_statioid + "\",\n\"timeType\" : 2,\n\"startTime\" : \"" + currentDate + "\",\n\"endTime\" : \"" + currentDate + "\"\n}");
      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
          String payload = httpClientSolar.getString();
          JsonDocument root;
          deserializeJson(root, payload);
          bool rec_success = root["success"];
          if (rec_success == true) {
            float today_buy = root["stationDataItems"][0]["buyValue"];
            solar.today_buy = today_buy;
            strncpy(statusMessage, "Solar history updated", CHAR_LEN);
            statusMessageUpdated = true;
          } else {
            String rec_msg = root["msg"];
            Serial.printf("rec_msg from get today buy is %s\n", rec_msg);
          }
        } else {
          Serial.printf("[HTTP] GET solar today buy value failed, error: %s\n", httpClientSolar.errorToString(httpCode).c_str());
          String payload = httpClientSolar.getString();
          strncpy(statusMessage, "Getting solar today buy value failed", CHAR_LEN);
          statusMessageUpdated = true;
        }
      }

      delay(1000);
      // Get month buy value timeType 3
      httpClientSolar.begin("https://" + solar_url + "//station/v1.0/history?language=en");
      httpClientSolar.addHeader("Content-Type", "application/json");
      httpClientSolar.addHeader("Authorization", token);

      httpCode = httpClientSolar.POST("{\n\"stationId\" : \"" + solar_statioid + "\",\n\"timeType\" : 3,\n\"startTime\" : \"" + currentYearMonth + "\",\n\"endTime\" : \"" + currentYearMonth + "\"\n}");
      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
          String payload = httpClientSolar.getString();
          JsonDocument root;
          deserializeJson(root, payload);
          bool rec_success = root["success"];
          if (rec_success == true) {
            float month_buy = root["stationDataItems"][0]["buyValue"];

            solar.month_buy = month_buy;
            strncpy(statusMessage, "Solar history updated", CHAR_LEN);
            statusMessageUpdated = true;
          }
        } else {
          Serial.printf("[HTTP] GET solar month buy value failed, error: %s\n", httpClientSolar.errorToString(httpCode).c_str());
          String payload = httpClientSolar.getString();
          strncpy(statusMessage, "Getting solar month buy value failed", CHAR_LEN);
          statusMessageUpdated = true;
        }
      }
    }
    delay(1000);
  }
}
