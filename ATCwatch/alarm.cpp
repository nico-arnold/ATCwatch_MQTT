#include "Arduino.h"
#include "sleep.h"
#include "menu.h"
#include "display.h"
#include "inputoutput.h"
#include "alarm.h"

#ifndef _ALARM_H_
#define _ALARM_H_

void alarm(int lvl){
  showAlarmScreen.set_alarm_level(lvl);
  change_screen((Screen*)&showAlarmScreen);
}

#endif
