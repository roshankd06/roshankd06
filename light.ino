


#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define led D1
#define sensor A0
char auth[] = "GN7HXpAr_Dklyn9vCQOi37pr2ounAGUd";
char ssid[] = "Eternal";
char pass[] = "bicky006";

BlynkTimer timer;


void setup()
{
  // Debug console
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(500L, sendSensor);

}

void loop()
{
  Blynk.run();
  timer.run();
}

void sendSensor()
{
  int LDR = analogRead(sensor);
    if(LDR <150)
  {
    digitalWrite(led, HIGH);
    Blynk.notify("Light ON");
  }
  else
  {
    digitalWrite(led, LOW);
   
  }

  Blynk.virtualWrite(V0, LDR);

}
