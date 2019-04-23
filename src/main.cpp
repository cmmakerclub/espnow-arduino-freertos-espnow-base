#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include <rom/rtc.h>
#include <HardwareSerial.h>
#include <CMMC_Module.h>
#include "utils.hpp"

const int MODULE_SIZE = 2;
CMMC_Module* modules[10];
RTC_DATA_ATTR static int rebootCount = -1;

/* function headers */
void appTask( void * parameter);
void initEspnow();


/* espnow */
static char sta_mac[18];
static char softap_mac[18];

void setup() {
  /* Stack size in bytes. */ /* Parameter passed as input of the task */ /* Priority of the task. */
  xTaskCreate(appTask, "appTask", 10000, NULL, 2, NULL);

  rebootCount++;
  Serial.begin(115200);

  print_reset_reason(rtc_get_reset_reason(0));
  verbose_print_reset_reason(rtc_get_reset_reason(0));

  WiFi.disconnect();
  initEspnow();
}

void initEspnow() {
  WiFi.mode(WIFI_AP_STA);
  strcpy(sta_mac, WiFi.macAddress().c_str());
  strcpy(softap_mac, WiFi.softAPmacAddress().c_str());
  Serial.printf("STA MAC: %s\r\n", sta_mac);
  Serial.printf(" AP MAC: %s\r\n", softap_mac);
  if (esp_now_init() == ESP_OK) {
    // updateStatus("ESPNow Init Success\n");
  }
  else {
    // updateStatus("ESPNow Init Failed\n");
    ESP.restart();
  }
}

void loop() {

}

void appTask(void * parameter)
{
    // rtc->setup();
    // pinMode(EXT_WDT_PIN, OUTPUT);
    while (1) {
      // rtc->loop();
      // lcd->loop();
    }
}
