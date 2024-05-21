#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

DHT dht(15, DHT11);

const char* ssid = "network-name";
const char* password = "password-name";

//Your Domain name with URL path or IP address with path
const char* serverName = "http://192.168.1.171:5000";

unsigned long lastTime = 0;

// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  delay(2000);

  dht.begin();
  delay(2000);
}

void loop() {
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;

      http.begin(client, serverName);

      float temp = dht.readTemperature();
      float humidity = dht.readHumidity();

      http.addHeader("Content-Type", "text/plain");
      int httpResponseCode = http.POST(String(temp)+","+String(humidity));

      // Free resources
      http.end();
    }
    else {
      delay(1000);
    }
    lastTime = millis();
  }
}