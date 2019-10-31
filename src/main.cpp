#include <Arduino.h>
#include <string.h>
#include <drone.h>
#include <joystick.h>

String ssid = "TELLO-FE2F50";
String password = "";

Drone drone(ssid, password);
Joystick joystick(15, 34, 35); // pins: btn, x, y

void setup()
{
  Serial.begin(9600);
//& betyder - brug denne location
  drone.joystick = &joystick; 

  for (size_t i = 0; i < 5; i++)
  {
    Serial.println(i);
    delay(1000);
  }

  joystick.addButtonListener(&drone);
  
  drone.connect();
  drone.setIp ("192.168.10.1");

  
}

void loop()
{
  joystick.loop();
  drone.loop();
} 