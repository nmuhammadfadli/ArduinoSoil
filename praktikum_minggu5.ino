#include "DHT.h"
#define DHTPIN D5
#define DHTTYPE DHT11

#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

// Include Firebase token helper
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

DHT dht(DHTPIN, DHTTYPE);

// Insert your network credentials
#define WIFI_SSID "Redmi Note 9 Pro"
#define WIFI_PASSWORD "hanyafadli"

// Insert Firebase project API Key
#define API_KEY "AIzaSyDcvrIWJPPO6RSUzCPDb-J7O2D5tv-SWM8"

// Insert RTDB URL
#define DATABASE_URL "https://arduinoproject-5cb02-default-rtdb.asia-southeast1.firebasedatabase.app/"

// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

bool signupOK = false;

// Inisialisasi LCD dan sensor kelembapan tanah
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHTesp.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHTesp dht22;

#define SOIL_SENSOR_PIN A0  // Pin untuk sensor kelembapan tanah
unsigned long previousMillis = 0;
const long interval = 5000;

bool showTemperature = true;

void setup(){
  pinMode(DHTPIN, INPUT);
  dht.begin();
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  // Konfigurasi Firebase
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("Firebase SignUp OK");
    signupOK = true;
  }
  else{
    Serial.printf("Firebase SignUp Failed: %s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Inisialisasi LCD
  Wire.begin(D2, D1);
  lcd.init();
  lcd.backlight();

  // Inisialisasi DHT22
  dht22.setup(D0, DHTesp::DHT22);
}

void loop() {
  unsigned long currentMillis = millis();

  float temperature = dht22.getTemperature();
  float humidity = dht22.getHumidity();
  float soilMoisture = (100.00 - ((analogRead(SOIL_SENSOR_PIN) / 1023.00) * 100.00));

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    return;
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (showTemperature) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temperature);
      lcd.print("C");

      lcd.setCursor(0, 1);
      lcd.print("Humidity: ");
      lcd.print(humidity);
      lcd.print("%");

      showTemperature = false;
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Soil Moisture: ");
      lcd.setCursor(0, 1);
      lcd.print(soilMoisture);
      lcd.print("%");

      showTemperature = true;
    }
  }

  // Mengirim data ke Firebase
  if (Firebase.ready() && signupOK) {
    String path = "/sensorData";
    
    FirebaseJson json;
    json.set("temperature", temperature);
    json.set("humidity", humidity);
    json.set("soilMoisture", soilMoisture);
    
    if (Firebase.RTDB.setJSON(&fbdo, path.c_str(), &json)) {
      Serial.println("Data sent to Firebase successfully");
    } else {
      Serial.printf("Failed to send data: %s\n", fbdo.errorReason().c_str());
    }
  }

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("% Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C"));

  Serial.print(F("Soil Moisture(in Percentage) = "));
  Serial.print(soilMoisture);
  Serial.println(F("%"));

  delay(100);
}