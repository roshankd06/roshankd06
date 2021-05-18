

void setup()
{
pinMode(A0,INPUT);
Serial.begin(9600);
}
void loop()
{
int sv=analogRead(A0);
Serial.print("AQI=");
Serial.print(sv);

Serial.println(" PPM");
delay(1000);
}
