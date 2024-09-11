/*
 * Copyright (c) 2020 Aaron Christophel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include "Arduino.h"
#include "ble.h"
#include "class.h"
#include "images.h"
#include "menu.h"
#include "display.h"
#include "ble.h"
#include "time.h"
#include "battery.h"
#include "accl.h"
#include "push.h"
#include "heartrate.h"

void alarm();

class ShowAlarmScreen : public Screen
{
  public:
  
	int alarm_level = 0;
  
    virtual void pre()
    {
      label_screen = lv_label_create(lv_scr_act(), NULL);
      lv_label_set_text(label_screen, "ALARM");
      lv_obj_align(label_screen, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

      lv_style_copy( &st, &lv_style_plain );
      st.text.color = lv_color_hsv_to_rgb(10, 5, 95);
      st.text.font = &mksd50;

      label_alarm_lvl = lv_label_create(lv_scr_act(), NULL);
      lv_obj_set_style( label_alarm_lvl, &st );
      lv_label_set_text(label_alarm_lvl, "4");
      lv_obj_align(label_alarm_lvl, lv_scr_act(), LV_ALIGN_CENTER, -20, 20);
    }
	
  	virtual void set_alarm_level(int lvl){
      alarm_level = lvl;
      switch(alarm_level){
        case 0:
          st.text.color = lv_color_hex3(0x146152);
          lv_label_set_text(label_alarm_lvl, "0");
        break;
        case 1:
          st.text.color = lv_color_hex3(0xB4CF66);
          lv_label_set_text(label_alarm_lvl, "1");
        break;
        case 2:
          st.text.color = lv_color_hex3(0xFFEC5C);
          lv_label_set_text(label_alarm_lvl, "2");
        break;
        case 3:
          st.text.color = lv_color_hex3(0xFF5A33);
          lv_label_set_text(label_alarm_lvl, "3");
        break;
      }
      lv_obj_set_style( label_alarm_lvl, &st );
  	}

    virtual void main()
    {
    }

    virtual void up()
    {
		display_home();
    }

    virtual void down()
    {
		display_home();
    }

    virtual void right()
    {
      display_home();
    }

    /*virtual void lv_event_class(lv_obj_t * object, lv_event_t event)
    {
      if (object == sw_enable_alarm && event == LV_EVENT_VALUE_CHANGED) {
        if (lv_sw_get_state(sw_enable_alarm)){
          ble_write("AT+BEEP");
        }else{
          display_home();
        }
      } else if (object == btn2 && event == LV_EVENT_SHORT_CLICKED) {
        change_screen((Screen*)&settingsTimeScreen);
      } else if (object == btn3 && event == LV_EVENT_SHORT_CLICKED) {
        change_screen((Screen*)&settingsColorScreen);
      } else if (object == btn4 && event == LV_EVENT_SHORT_CLICKED) {
        change_screen((Screen*)&settingsBrightnessScreen);
      }
    }*/

  private:
    lv_obj_t *label_screen, *label_alarm_lvl;
    lv_style_t st;
};

ShowAlarmScreen showAlarmScreen;

#ifndef _ALARM_SCREEN_H_
#define _ALARM_SCREEN_H_

void alarm(){
	change_screen((Screen*)&showAlarmScreen);
}

#endif
