#include "CMMC_DUMMY.h"

CMMC_DUMMY::CMMC_DUMMY() {
}

void CMMC_DUMMY::configLoop() {
  yield();
}

void CMMC_DUMMY::configSetup() {
  yield();
}

void CMMC_DUMMY::setup() {
  Serial.println("setup() is called.");
}


void CMMC_DUMMY::loop() {
  counter++;
  Serial.println(counter);
  delay(1000);
}


int CMMC_DUMMY::getCounter() {
  return counter;
}
