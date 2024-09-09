
/*************************************************************
  Download latest ERa library here:
    https://github.com/eoh-jsc/era-lib/releases/latest
    https://www.arduino.cc/reference/en/libraries/era
    https://registry.platformio.org/libraries/eoh-ltd/ERa/installation

    ERa website:                https://e-ra.io
    ERa blog:                   https://iotasia.org
    ERa forum:                  https://forum.eoh.io
    Follow us:                  https://www.fb.com/EoHPlatform
 *************************************************************/

// Enable debug console
// Set CORE_DEBUG_LEVEL = 3 first
#define ERA_DEBUG

#define DEFAULT_MQTT_HOST "mqtt1.eoh.io"

// You should get Auth Token in the ERa App or ERa Dashboard
#define ERA_AUTH_TOKEN "e77f938c-ed69-4a05-b404-655fe46cfa1c"

#include <Arduino.h>
#include <ERa.hpp>
#include <ERa/ERaTimer.hpp>

const char ssid[] = "Wokwi-GUEST";
const char pass[] = "";

float a = 10;
int speed = 0;

ERaTimer timer;

/* This function print uptime every second */
void timerEvent() {
    ERA_LOG("Timer", "Uptime: %d", ERaMillis() / 1000L);
}

void setup() {
    /* Setup debug console */
    Serial.begin(115200);

    ERa.begin(ssid, pass);
    
  ERa.virtualWrite(V0, 10.8420797); 
  ERa.virtualWrite(V1, 106.7090958); 
  ERa.virtualWrite(V4, 0); 

    /* Setup timer called function every second */
    timer.setInterval(1000L, timerEvent);
}

void loop() {
    ERa.run();
    timer.run();

    ERa.virtualWrite(V0, a);
  ERa.virtualWrite(V1, 105.660172); 
  ERa.virtualWrite(V4, speed); 
  Serial.println(a);
  Serial.print(speed);

  a += 0.0001;
  speed += 3;
  if (a > 10.06) {
    a = 10;  
  }
  if (speed > 100) {
    speed = 0;  
  }

  delay(1000);  

  

}

