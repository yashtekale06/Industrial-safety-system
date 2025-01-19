#include <LiquidCrystal_I2C.h> 
#include <WiFi.h> 
#include <WebServer.h> 
#include <Wire.h> 
#include <DHT.h> 
#define DHTPIN 2 // Pin where the DHT sensor is connected 
#define DHTTYPE DHT11 // Type of DHT sensor 
DHT dht(DHTPIN, DHTTYPE); 
const int motor = 15; 
const int smokeSensorPin = 33; // Pin where the smoke sensor is connected 
const int fireSensorPin = 34; // Pin where the fire sensor is connected 
const int buzzerPin = 4; // Pin where the buzzer is connected 
const int ldrSensorPin = 35; // Pin where the LDR sensor is connected 
const int LED = 5; 
const char *ssid = "ESP32-Access-Point"; // SSID for ESP32 AP 
const char *password = "123456789"; // Password for ESP32 AP 
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address, number of columns and rows on the LCD 
WebServer server(80); 
void handleRoot() 
{ 
// Read sensor data 
float humidity = dht.readHumidity(); 
float temperature = dht.readTemperature(); 
int smokeValue = analogRead(smokeSensorPin); 
int fireStatus = digitalRead(fireSensorPin); 
int ldrValue = digitalRead(ldrSensorPin); 
// Convert LDR value to day-night indicator 
String dayNight; 
if (ldrValue,LOW) 
{ 
dayNight = "Day"; 
} 
else 
{ 
dayNight = "Night"; 
} 
// Prepare HTML response with JavaScript for reloading 
String response = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta 
name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Sensor Data</title>"; 
response += "<style>body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; }";
response += "header { background-color: #333; color: #fff; padding: 10px 0; text-align: center; }"; 
response += "h1 { margin-top: 20px; text-align: center; }"; 
response += "table { width: 50%; margin: 20px auto; border-collapse: collapse; }"; 
response += "th, td { padding: 10px; border: 1px solid #ddd; text-align: left; }"; 
response += "th { background-color: #333; color: #fff; }</style>"; 
response += "<script>setTimeout(function() { location.reload(); }, 1000);</script>"; // Reload the 
page every 1000 milliseconds 
response += "</head><body><header><h1>Industrial Safety System</h1></header>"; 
response += "<table><tr><th>Parameter</th><th>Value</th></tr>"; 
response += "<tr><td>Temperature</td><td>" + String(temperature) + " &deg;C</td></tr>"; 
response += "<tr><td>Humidity</td><td>" + String(humidity) + " %</td></tr>"; 
response += "<tr><td>Smoke Value</td><td>" + String(smokeValue) + "</td></tr>"; 
response += "<tr><td>Fire Status</td><td>" + String(fireStatus == LOW ? "Fire Detected!" : "No 
Fire Detected") + "</td></tr>"; 
response += "<tr><td>Day/Night</td><td>" + dayNight + "</td></tr>"; // Display day-night 
indicator 
response += "</table></body></html>"; 
// Send HTML response to client 
server.send(200, "text/html", response); 
} 
void setup() 
{ 
lcd.init(); // initialize the LCD 
lcd.backlight(); // Turn on backlight 
Serial.begin(9600); 
// Initialize DHT sensor 
dht.begin(); 
// Set pin modes 
pinMode(buzzerPin, OUTPUT); 
pinMode(fireSensorPin, INPUT); 
pinMode(LED, OUTPUT); 
pinMode(motor, OUTPUT); 
// Start WiFi Access Point 
WiFi.softAP(ssid, password); 
IPAddress myIP = WiFi.softAPIP(); 
Serial.print("Access Point IP address: "); 
Serial.println(myIP); 
// Register handler for root URL 
server.on("/", handleRoot); 
// Start web server 
server.begin(); 
Serial.println("HTTP server started") 
} 
10 
void loop() 
{ 
// Read sensor data 
float humidity = dht.readHumidity(); 
float temperature = dht.readTemperature(); 
int smokeValue = analogRead(smokeSensorPin); 
int fireStatus = digitalRead(fireSensorPin); 
int ldrValue = digitalRead(ldrSensorPin); 
// Display sensor data on LCD 
lcd.clear(); 
lcd.setCursor(0, 0); 
lcd.print("Smo: "); 
lcd.print(smokeValue); 
lcd.setCursor(0, 1); 
lcd.print("Humidity: "); 
lcd.print(humidity); 
lcd.print("%"); 
// Print fire status for debugging 
Serial.print("Fire status: "); 
Serial.println(fireStatus); 
// Control buzzer based on fire status 
if (fireStatus == HIGH) 
{ 
Serial.println("No fire detected. Buzzer OFF."); 
digitalWrite(buzzerPin, LOW); 
} 
else 
{ 
digitalWrite(buzzerPin, HIGH); 
Serial.println("Fire detected! Buzzer ON."); 
lcd.clear(); 
lcd.setCursor(0, 0); 
lcd.print("Fire detected!"); 
} 
// Control LED based on LDR value 
if (ldrValue,LOW) 
{ 
digitalWrite(LED, HIGH); 
} 
else 
{ 
digitalWrite(LED, LOW); 
} 
// Control motor based on humidity level 
if (humidity >= 40 && humidity <= 60) 
{ 
11 
Serial.println("Humidity is normal"); 
analogWrite(motor,255); 
} 
else 
{ 
Serial.println("Humidity crossed its limit!!"); 
analogWrite(motor,0); 
} 
// Handle client requests 
server.handleClient(); 
// Delay between readings 
delay(2000); 
}