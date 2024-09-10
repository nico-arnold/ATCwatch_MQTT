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

      label_alarm_lvl = lv_label_create(lv_scr_act(), NULL);
      lv_label_set_text(label_alarm_lvl, String(alarm_level).c_str());
      lv_obj_align(label_alarm_lvl, NULL, LV_ALIGN_CENTER, 0, 0);
    }
	
	virtual void set_alarm_level(int lvl){
		alarm_level = lvl;
		lv_label_set_text(label_alarm_lvl, "TRIGGERED");//String(alarm_level).c_str());
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
};

ShowAlarmScreen showAlarmScreen;

#ifndef _ALARM_SCREEN_H_
#define _ALARM_SCREEN_H_

void alarm(){
	change_screen((Screen*)&showAlarmScreen);
}

#endif