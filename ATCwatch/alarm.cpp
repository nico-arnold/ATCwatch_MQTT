#include "Arduino.h"
#include "sleep.h"
#include "menu.h"
#include "display.h"
#include "inputoutput.h"
#include "alarm.h"

#ifndef _ALARM_H_
#define _ALARM_H_

void alarm(){
  change_screen((Screen*)&showAlarmScreen);
}

#endif
