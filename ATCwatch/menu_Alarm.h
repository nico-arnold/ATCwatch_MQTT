/*
 * Copyright (c) 2020 Aaron Christophel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include "Arduino.h"
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


class AlarmScreen : public Screen
{
  public:
    virtual void pre()
    {
      label_screen = lv_label_create(lv_scr_act(), NULL);
      lv_label_set_text(label_screen, "ALARM");
      lv_obj_align(label_screen, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

      btn1 = lv_btn_create(lv_scr_act(), NULL);
      lv_obj_set_event_cb(btn1, lv_event_handler);
      lv_obj_align(btn1, NULL, LV_ALIGN_CENTER, -55, -50);
      btn1_label = lv_label_create(btn1, NULL);
      lv_label_set_text(btn1_label, "0");
      
      //lv_style_t st1 = lv_obj_get_style(btn1);
      lv_style_copy( &st1, &lv_style_plain );
      st1.body.main_color = lv_color_hex(0x000000);
      st1.body.grad_color = lv_color_hex(0x146152);
      st1.text.color = lv_color_hex(0xFFFFFF);
      lv_obj_set_style(btn1, &st1);

      btn2 = lv_btn_create(lv_scr_act(), NULL);
      lv_obj_set_event_cb(btn2, lv_event_handler);
      lv_obj_align(btn2, NULL, LV_ALIGN_CENTER, 55, -50);
      btn2_label = lv_label_create(btn2, NULL);
      lv_label_set_text(btn2_label, "1");
      lv_style_copy( &st2, &st1 );
      st2.body.grad_color = lv_color_hex(0xB4CF66);
      lv_obj_set_style(btn2, &st2);

      btn3 = lv_btn_create(lv_scr_act(), NULL);
      lv_obj_set_event_cb(btn3, lv_event_handler);
      lv_obj_align(btn3, NULL, LV_ALIGN_CENTER, -55, 50);
      btn3_label = lv_label_create(btn3, NULL);
      lv_label_set_text(btn3_label, "2");
      lv_style_copy( &st3, &st1 );
      st3.body.grad_color = lv_color_hex(0xFFEC5C);
      lv_obj_set_style(btn3, &st3);

      btn4 = lv_btn_create(lv_scr_act(), NULL);
      lv_obj_set_event_cb(btn4, lv_event_handler);
      lv_obj_align(btn4, NULL, LV_ALIGN_CENTER, 55, 50);
      btn4_label = lv_label_create(btn4, NULL);
      lv_label_set_text(btn4_label, "3");
      lv_style_copy( &st4, &st1 );
      st4.body.grad_color = lv_color_hex(0xFF5A33);
      lv_obj_set_style(btn4, &st4);
    }

    virtual void main()
    {
    }

    virtual void up()
    {
    }

    virtual void down()
    {
      display_home();
    }

    virtual void right()
    {
      display_home();
    }

    virtual void lv_event_class(lv_obj_t * object, lv_event_t event)
    {
      if (object == btn1 && event == LV_EVENT_SHORT_CLICKED) {
        //change_screen((Screen*)&settingsDateScreen);
        ble_write("AT+ALMON=0");
      } else if (object == btn2 && event == LV_EVENT_SHORT_CLICKED) {
        //change_screen((Screen*)&settingsTimeScreen);
        ble_write("AT+ALMON=1");
      } else if (object == btn3 && event == LV_EVENT_SHORT_CLICKED) {
        //change_screen((Screen*)&settingsColorScreen);
        ble_write("AT+ALMON=2");
      } else if (object == btn4 && event == LV_EVENT_SHORT_CLICKED) {
        //change_screen((Screen*)&settingsBrightnessScreen);
        ble_write("AT+ALMON=3");
      }
    }

  private:
    lv_style_t st1, st2, st3, st4;
    lv_obj_t *label_screen;
    lv_obj_t *btn1, *btn2, *btn1_label, *btn2_label;
    lv_obj_t *btn3, *btn4, *btn3_label, *btn4_label;
};

AlarmScreen alarmScreen;
