#pragma once

#include "Buggy.h"
#include "CommTrans.h"

#include "Arduino.h"

class UltraSonic {
 private:
  Buggy* buggy;
  const CommTrans* comms;

  const unsigned short groundPin = 16;
  const unsigned short powerPin = 17;
  const unsigned short ultraPin = 18;
  const unsigned long tresholdDistance = 12; // cm
  const unsigned long pingInterval = 250; // ms
  unsigned long lastPingTime = 0;

  bool obstacle = false;

  unsigned long measureDistance() const;

 public:
  UltraSonic(Buggy* b, CommTrans* c) : buggy(b),
                                       comms(c) {
    pinMode(groundPin, OUTPUT);
    pinMode(powerPin, OUTPUT);
    digitalWrite(groundPin, LOW);
    digitalWrite(powerPin, HIGH);
  }

  void ultraLoop();
};
