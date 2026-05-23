/************************ Adafruit IO Config *******************************/

// visit io.adafruit.com   you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME    "YOUR_AIO_USERNAME"
#define IO_KEY         "YOUR_AIO_KEY"

#define WIFI_SSID       "YOUR_WIFI_SSID"
#define WIFI_PASS       "YOUR_WIFI_PASSWORD"

// comment out the following two lines if you are using fona or ethernet
#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
