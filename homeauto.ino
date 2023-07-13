#include <WiFi.h>
#include <ESP32Servo.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>


#define BLYNK_TEMPLATE_ID "TMPL3HN3UJmj-"
#define BLYNK_TEMPLATE_NAME "home automation"
#define BLYNK_AUTH_TOKEN "ur0Celf6s58cw-fvy_eR7ANGcTlWo311"
#define SEALEVELPRESSURE_HPA (1013.25)
#define irPin 18  //14
#define pump3 13 //15
#define fan 27
#define relayOut 25
#define relayOut4 4  //2
#define soilsensor 33

Adafruit_BME280 bme;
Servo gateServo;

char auth[] = "ur0Celf6s58cw-fvy_eR7ANGcTlWo311";
char ssid[] = "beep";
char pass[] = "abcdefgh";
float humid = 0;
float temp = 0;
float altitude1 = 0;
float pressure1 = 0;
int moisturepercentage;
int analogoutput;

BLYNK_WRITE(V4)
{
  int pValue1 = param.asInt();
if(pValue1 == 0)
      digitalWrite(25,HIGH);
    else
      digitalWrite(25,LOW);

}

BLYNK_WRITE(V8)
{
  int pValue1 = param.asInt();
if(pValue1 == 0)

      digitalWrite(4,HIGH);

    else
      digitalWrite(4,LOW);
}


void setup() {
  Serial.begin(115200);

  
  Blynk.begin( auth, ssid , pass );
  pinMode(soilsensor, INPUT);
  
  digitalWrite(relayOut,HIGH);
  pinMode(relayOut, OUTPUT);
  

  digitalWrite(relayOut4,HIGH);
  pinMode(relayOut4, OUTPUT);
   
   digitalWrite(fan,HIGH);
   pinMode(fan, OUTPUT);

   pinMode(irPin, INPUT_PULLUP);
   gateServo.attach(32);
   
    digitalWrite(pump3,HIGH);
    pinMode(pump3, OUTPUT);

  bool status;
  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}


void loop() {


  Blynk.run();
  delay(2000);

   if(digitalRead(irPin) == LOW) {
    gateServo.write(90);
    delay(2000);
    gateServo.write(0);
  }

  analogoutput = analogRead(soilsensor);
  moisturepercentage = (100-((analogoutput/4095.00)*100));

  humid = bme.readHumidity();
  temp = bme.readTemperature();
  pressure1 = bme.readPressure();
  altitude1 = bme.readAltitude(SEALEVELPRESSURE_HPA);


  if(moisturepercentage<40)              
  digitalWrite(pump3,LOW);   

else 
  digitalWrite(pump3,HIGH); 


  if (isnan(humid) || isnan(temp))
  {
    Serial.println("Failed to read from bme sensor!");
    return;
  }
 
  if (temp > 35)
    digitalWrite(fan, LOW);
  else 
    digitalWrite(fan, HIGH);
 
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, humid);
  Blynk.virtualWrite(V2, altitude1);
  Blynk.virtualWrite(V3, pressure1);
   Blynk.virtualWrite(V7,moisturepercentage);  
  
}
void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");
  
  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");
  
  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");
  
  Serial.println();
}


