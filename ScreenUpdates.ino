
#include <lvgl.h>
#include "ui.h"
#include <WiFi.h>
#include <ArduinoMqttClient.h>
#include <HTTPClient.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>
#include <Preferences.h>

extern Readings readings[];
extern Weather weather;
extern Solar solar;

// Set solar values in GUI
void set_solar_values() {
  char tempString[CHAR_LEN];
  // Set screen values
  if (solar.updateTime > 0) {
    lv_arc_set_value(ui_BatteryArc, solar.batteryCharge);
    snprintf(tempString, CHAR_LEN, "%2.0f%%", solar.batteryCharge);
    lv_label_set_text(ui_BatteryLabel, tempString);

    lv_arc_set_value(ui_SolarArc, solar.solarPower * 10);
    snprintf(tempString, CHAR_LEN, "%2.1fkW", solar.solarPower);
    lv_label_set_text(ui_SolarLabel, tempString);

    lv_arc_set_value(ui_UsingArc, solar.usingPower * 10);
    snprintf(tempString, CHAR_LEN, "%2.1fkW", solar.usingPower);
    lv_label_set_text(ui_UsingLabel, tempString);

    // Define and set vlaue for remaining times
    // Avoid messages for very small discharging
    if (solar.batteryPower > 0.1) {
      snprintf(tempString, CHAR_LEN, "Discharging %2.1fkW", solar.batteryPower);
      lv_label_set_text(ui_ChargingLabel, tempString);

      float remain_hours = (solar.batteryCharge / 100.0 - BATTERY_MIN) * BATTERY_CAPACITY / solar.batteryPower;
      int remain_minutes = 60.0 * remain_hours;
      int remain_minutes_round = 10 * (round(remain_minutes / 10));  // Round to 10 mins

      struct tm ts_end;
      time_t end_time = solar.updateTime + remain_minutes_round * 60;  // find time of estimated end of battery charge
      char time_buf_end[80];
      ts_end = *localtime(&end_time);
      strftime(time_buf_end, sizeof(time_buf_end), "%H:%M:%S", &ts_end);

      if ((floor(remain_hours) == 1) && (remain_minutes > 0)) {
        snprintf(tempString, CHAR_LEN, "%2.0f hour %i mins\n remaining\n Until %s", remain_hours, remain_minutes_round % 60, time_buf_end);
      } else {
        if (remain_minutes > 0 && remain_hours < MAX_SOLAR_TIME_STATUS) {
          snprintf(tempString, CHAR_LEN, "%2.0f hours %i mins\n remaining\n Until %s", remain_hours, remain_minutes_round % 60, time_buf_end);
        }
      }
      lv_label_set_text(ui_ChargingTime, tempString);
      lv_obj_set_style_arc_color(ui_BatteryArc, lv_color_hex(COLOR_RED), LV_PART_INDICATOR | LV_STATE_DEFAULT);  // Set arc to red
      lv_obj_set_style_bg_color(ui_BatteryArc, lv_color_hex(COLOR_RED), LV_PART_KNOB | LV_STATE_DEFAULT);        // Set arc to red
    } else {
      // Avoid messages for very small charging
      if (solar.batteryPower < -0.1) {
        snprintf(tempString, CHAR_LEN, "Charging %2.1fkW", -solar.batteryPower);
        lv_label_set_text(ui_ChargingLabel, tempString);

        float remain_hours = -(0.99 - solar.batteryCharge / 100) * BATTERY_CAPACITY / solar.batteryPower;
        int remain_minutes = 60.0 * remain_hours;
        int remain__minutes = 10 * (round(remain_minutes / 10));

        if ((floor(remain_hours) == 1) && (remain_minutes > 0)) {
          snprintf(tempString, CHAR_LEN, "%2.0f hour %i mins to\n fully charged", remain_hours, remain__minutes % 60);
        } else {
          if (remain_minutes > 0 && remain_hours < MAX_SOLAR_TIME_STATUS) {
            snprintf(tempString, CHAR_LEN, "%2.0f hours %i mins to\n fully charged", remain_hours, remain__minutes % 60);
          }
        }

        if (remain_minutes == 0) {
          snprintf(tempString, CHAR_LEN, "");
        }

        lv_label_set_text(ui_ChargingTime, tempString);

        lv_obj_set_style_arc_color(ui_BatteryArc, lv_color_hex(COLOR_GREEN), LV_PART_INDICATOR | LV_STATE_DEFAULT);  // Set arc to green
        lv_obj_set_style_bg_color(ui_BatteryArc, lv_color_hex(COLOR_GREEN), LV_PART_KNOB | LV_STATE_DEFAULT);        // Set arc to green
      } else {
        lv_label_set_text(ui_ChargingLabel, "");
        lv_label_set_text(ui_ChargingTime, "");
        lv_obj_set_style_arc_color(ui_BatteryArc, lv_color_hex(0x2095F6), LV_PART_INDICATOR | LV_STATE_DEFAULT);  // Set arc to red
        lv_obj_set_style_bg_color(ui_BatteryArc, lv_color_hex(0x2095F6), LV_PART_KNOB | LV_STATE_DEFAULT);        // Set arc to red
      }
      lv_obj_set_style_arc_color(ui_SolarArc, lv_color_hex(COLOR_GREEN), LV_PART_INDICATOR | LV_STATE_DEFAULT);  // Set arc to green
      lv_obj_set_style_bg_color(ui_SolarArc, lv_color_hex(COLOR_GREEN), LV_PART_KNOB | LV_STATE_DEFAULT);        // Set arc to green
    }

    // Define and set value for min and max solar
    snprintf(tempString, CHAR_LEN, "Min %2.0f\nMax %2.0f", solar.today_battery_min, solar.today_battery_max);
    lv_label_set_text(ui_SolarMinMax, tempString);
    // Set solar update times
    struct tm ts;
    char time_buf[80];
    ts = *localtime(&solar.updateTime);
    strftime(time_buf, sizeof(time_buf), "%H:%M:%S", &ts);
    snprintf(tempString, CHAR_LEN, "Values as of %s\nRecieved at %s", solar.time, time_buf);
    lv_label_set_text(ui_AsofTimeLabel, tempString);

    // Set grid bought ammounts
    if (solar.today_buy != 0.0 || solar.month_buy != 0.0) {
      snprintf(tempString, CHAR_LEN, "Bought\nToday %.1fkWh - R%.0f\nThis month %.1fkWh - R%.0f",
               solar.today_buy, solar.today_buy * ELECTRICY_PRICE, solar.month_buy, solar.month_buy * ELECTRICY_PRICE);
      lv_label_set_text(ui_GridBought, tempString);
    }
  }
}



// Sets UV color based on value
int uv_color(float UV) {
  if (UV < 1) {
    return (0x658D1B);
  }
  if (UV < 2) {
    return (0x84BD00);
  }
  if (UV < 3) {
    return (0x97D700);
  }
  if (UV < 4) {
    return (0xF7EA48);
  }
  if (UV < 5) {
    return (0xFCE300);
  }
  if (UV < 6) {
    return (0xFFCD00);
  }
  if (UV < 7) {
    return (0xECA154);
  }
  if (UV < 8) {
    return (0xFF8200);
  }
  if (UV < 9) {
    return (0xEF3340);
  }
  if (UV < 10) {
    return (0xDA291C);
  }
  if (UV < 11) {
    return (0xBF0D3E);
  }
  return (0x4B1E88);
}

// Sets all text field to defined color for day/night mode
void set_basic_text_color(lv_color_t color) {

  lv_obj_set_style_text_color(ui_TempLabelFC, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_UVLabel, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_UsingLabel, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_SolarLabel, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_BatteryLabel, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_RoomName1, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_RoomName2, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_RoomName3, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_RoomName4, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_RoomName5, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TempLabel1, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TempLabel2, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TempLabel3, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TempLabel4, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TempLabel5, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_HumidLabel1, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_HumidLabel2, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_HumidLabel3, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_HumidLabel4, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_HumidLabel5, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_StatusMessage, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_Time, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TextRooms, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TextForecastName, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TextBattery, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TextSolar, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TextUsing, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TextUV, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_FCConditions, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_FCWindSpeed, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_FCUpdateTime, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_ChargingLabel, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_AsofTimeLabel, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_ChargingTime, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_TextKlaussometer, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_SolarMinMax, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_GridBought, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_FCMin, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_FCMax, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_Direction1, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_Direction2, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_Direction3, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_Direction4, color, LV_PART_MAIN);
  lv_obj_set_style_text_color(ui_Direction5, color, LV_PART_MAIN);
}
