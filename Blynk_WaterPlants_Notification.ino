#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

int sensorPin = A0;    // select the input pin for the SENSOR

int sensorValue = 0;

char auth[] = "GN7HXpAr_Dklyn9vCQOi37pr2ounAGUd";

// Your WiFi credentials.

// Set password to “” for open networks.

char ssid[] ="Eternal";

char pass[] = "bicky006";

WidgetLCD lcd(V1);

void setup()

{

  // Debug console

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  // You can also specify server:

  //Blynk.begin(auth, ssid, pass, “blynk-cloud.com”, 8442);

  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  lcd.clear(); //Use it to clear the LCD Widget

  lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, “Message you want to print”)

  // Please use timed events when LCD printintg in void loop to avoid sending too many commands

  // It will cause a FLOOD Error, and connection will be dropped

}

void loop()

{

  lcd.clear();

  lcd.print(0, 0, "moisture"); // use: (position X: 0-15, position Y: 0-1, “Message you want to print”)

 sensorValue = analogRead(sensorPin);

 Serial.println( sensorValue);

  lcd.print(7, 1,  sensorValue);

  Blynk.run();

  delay(3500);

}
