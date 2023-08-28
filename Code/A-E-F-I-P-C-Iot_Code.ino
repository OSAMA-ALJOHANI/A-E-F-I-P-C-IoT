#define BLYNK_TEMPLATE_ID "TMPL6ZcVfecXz"
#define BLYNK_TEMPLATE_NAME "AEFPIOT"
#define BLYNK_AUTH_TOKEN "S0YqLZgVz1EGxEHkiQjY_eLcFUxVHc58"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char auth[] = "S0YqLZgVz1EGxEHkiQjY_eLcFUxVHc58";
char ssid[] = "Simoa";
char pass[] = "12345678";

// Define connections to relays
#define FAN_PIN 12 // FAN RELAY
#define PUMP_PIN 14 // PUMP RELAY
#define HP_PIN 27 // humidifier automation plate RELAY
#define LAMP_PIN 26 // LAMP RELAY

// Define connections to sensor
#define LDR_PIN 32
#define CSM_PIN 33
#define WL_PIN 35
#define DHTPIN 25  // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT 11


BlynkTimer timer;

WidgetLED FAN(V0);
WidgetLED LAMP(V14);
WidgetLED PUMP(V5);
WidgetLED HP(V11);

//Set the maximum wet and maximum dry value measured by the sensor
const int drysoil = 2800 ;  //max value when soil is dry
const int wetsoil = 930 ;  //min value when soil is wet

const int wdry = 0 ;  //max value when soil is dry
const int wwet = 1200 ;  //min value when soil is wet



int humDHT = 0;
int tempDHT = 0;
int Val = 0;
int Val1 = 0;
int waterlevel = 0;
int waterpercent = 0;
int ldrValue = 0;
int soilValue = 0;
int soilpercent = 0;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Define custom character for degree symbol
byte degreeSymbol[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(FAN_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);
  pinMode(HP_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(CSM_PIN, INPUT);
  pinMode(WL_PIN, INPUT);
  digitalWrite(FAN_PIN, LOW);
  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(LAMP_PIN, LOW);
  digitalWrite(HP_PIN, LOW);
  delay(3000);
  
  dht.begin();
  Blynk.begin(auth, ssid, pass);
  lcd.init();       // initializing the LCD
  lcd.backlight();  // Enable or Turn On the backlight
  lcd.createChar(0, degreeSymbol);

  lcd.setCursor(5, 0);
  lcd.print("I o T B A S E D");
  lcd.setCursor(6, 1);
  lcd.print("A E F I P C");
  delay(1500);
  lcd.clear();

  lcd.setCursor(7, 0);
  lcd.print("BY");
  delay(1500);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("OSAMA ALJUHANI");
  lcd.setCursor(0, 1);
  lcd.print("NAWAF ALSHEHRI");
  delay(1500);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("MOHANNAD ALI");
  lcd.setCursor(0, 1);
  lcd.print("ABDULLAH OSAIMI");
  delay(1500);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("FARIS ALANZI");
  lcd.setCursor(0, 1);
  lcd.print("ABDULKARIM FIFI");
  delay(1500);
  lcd.clear();  

}

BLYNK_WRITE(V3) {
  Val = param.asInt();
  Serial.print("The Temp Threshhold value is: ");
  Serial.println(Val);
}

BLYNK_WRITE(V12) {
  Val1 = param.asInt();
  Serial.print("The Humidity Threshhold value is: ");
  Serial.println(Val1);
}

  void controlLcd() 
  {
    int soilValue = analogRead(CSM_PIN);
    int soilpercent = map(soilValue, drysoil, wetsoil, 0, 100);
    int waterlevel = analogRead(WL_PIN);
    int waterpercent = map(waterlevel, wdry, wwet, 0, 100);
    int humDHT = dht.readHumidity();
    int tempDHT = dht.readTemperature();
  
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(tempDHT);
    lcd.write((uint8_t)0);  // Display the custom character for degree symbol
    lcd.print("C");

    lcd.setCursor(9, 0);
    lcd.print("H:");
    lcd.print(humDHT);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("S:");
    lcd.print(soilpercent);
    lcd.print("%");

    lcd.setCursor(9, 1);
    lcd.print("W:");
    lcd.print(waterpercent);
    lcd.print("%");
  }
  
  void controlLight()
  {
    int ldrValue = analogRead(LDR_PIN);

    if(ldrValue < 1500 )
    {
    digitalWrite(LAMP_PIN, HIGH);
    LAMP.on();
    Serial.println("LIGHT ON");
    }
    else
    {
    digitalWrite(LAMP_PIN, LOW);
    LAMP.off();
    Serial.println("LIGHT OFF");
    }
  }

  void controlFan()
    {
      int tempDHT = dht.readTemperature();
      if (Val > tempDHT)
      {
        digitalWrite(FAN_PIN, HIGH);
        FAN.on();
      }
      else if (Val < tempDHT)
      {
        digitalWrite(FAN_PIN, LOW);
        FAN.off();
      }
    }

  void controlHp()
    {
      int humDHT = dht.readHumidity();
      if (Val1 > humDHT)
      {
        digitalWrite(HP_PIN, HIGH);
        HP.on();
      }
      else if (Val1 < humDHT)
      {
        digitalWrite(HP_PIN, LOW);
        HP.off();
      }
    }

  void controlPump()
    {
      int soilValue = analogRead(CSM_PIN);
      int soilpercent = map(soilValue, drysoil, wetsoil, 0, 100);
      if (soilpercent < 20)
        {
          digitalWrite(PUMP_PIN, LOW);
          PUMP.off();
        }
      else if (soilpercent > 80)
        {
          digitalWrite(PUMP_PIN, HIGH);
          PUMP.on();
        }
    }

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();//Run the Blynk timer
  delay(1000);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humDHT) || isnan(tempDHT)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  int ldrValue = analogRead(LDR_PIN);
  int soilValue = analogRead(CSM_PIN);
  int soilpercent = map(soilValue, drysoil, wetsoil, 0, 100);
  int waterlevel = analogRead(WL_PIN);
  int waterpercent = map(waterlevel, wdry, wwet, 0, 100);
  int humDHT = dht.readHumidity();
  int tempDHT = dht.readTemperature();

  controlLight();
  controlFan();
  controlHp();
  controlPump();
  controlLcd();


  Serial.print("Temp: ");
  Serial.print(tempDHT);
  Serial.println("°C");

  Serial.print("Humidity: ");
  Serial.print(humDHT);
  Serial.println("%");

  Serial.print("Soil Moisture: ");
  Serial.print(soilpercent);
  Serial.println("%");

  Serial.print("Water level: ");
  Serial.println(waterpercent);

  Serial.print("LDR value: ");
  Serial.println(ldrValue);
  
   if (waterlevel < 20)
  {
    Serial.println("Water tank is empty please refill");
    Blynk.logEvent("water_alert","Water tank is empty please refill");
  }

  delay(1000);
  
  Blynk.virtualWrite(V1, tempDHT);
  Blynk.virtualWrite(V2, humDHT);
  Blynk.virtualWrite(V6, soilpercent);
}
