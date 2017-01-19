/*
 *  Garage Door Opener via Web Browser and log to IFTTT.com
 *  ESP8266 NodeMCU Board using Arduino IDE
 *  WhiskyTangoHotel.Com    DEC2106
 *  
 *  Blue on board LED is active LOW on GPIO2 (D4 on silkscreen)
 *  Relay to control Garage Door is active HIGH on GPIO5 (D1 on silkscreen)
 *  
 *  Opening 192.168.0.28/long_confusing_URL_to_activate_relay is called.  Every effort is made to keep the relay off  
 *  so the door does not close/activate by accident.
 *  
 *  A 'test' message is display on browser to see if server is up by calling root at:.
 *  192.168.0.28/  This WILL NOT ACTIVATE THE RELAY.  Only tests the server
 *  
 *  The 'meat' is at 192.168.0.28/long_confusing_URL_to_activate_relay. This will send a msg to the browser AND open/close the door.
 *  
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// WiFi Information
const char* ssid = "YOUR-SSID";
const char* password = "ASCII-PASSCODE-FOR-YOUR-SSID";

// IFTTT Information
String MAKER_SECRET_KEY = "xxx-yyy-zzz-123-456-789"; // your maker key here
String TRIGGER_NAME = "IFTTT_Maker_name_to_activate_relay";  // this is the Maker IFTTT trigger name for relay activation
const char* host = "maker.ifttt.com";

ESP8266WebServer server(80);

// Output pins
const int led = 2;  // Blue on board LED
const int relay = 5;  // Relay control line

int randNumber;  // Random# generated just to show a change in the screen.  Help to verify updated page call.

void handleRoot() {
  // This is called if 192.168.0.28/ is requested.  The root.
  // The 'meat' is at /long_confusing_URL_to_activate_relay.
  // This is just here to test the ESP8266 connectivity of the WiFi network without moving the relay
  // Show a message and flash the on board LED.
  randNumber = random(1, 10000);  // Random number just to show a change on the webpage at reload.
  server.send(200, "text/plain", "Testing ESP8266.  Response is: " + String(randNumber));
  digitalWrite(led, 0);  // Active LOW.  Turn On board LED On
  delay(2000);
  digitalWrite(led, 1);  // Active LOW.  Turn On board LED Off
}

void handleNotFound(){
  digitalWrite(led, 1);  // Keep the LED off.
  digitalWrite(relay, 0);  // Keep Relay OFF
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void){
  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(led, 1);  // LED Off
  digitalWrite(relay, 0);  // on power to relay
  Serial.begin(115200);  // serial prints to PC for debug use only
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Trying to connect to ");
    Serial.print(ssid);
    Serial.print(" on ");
    Serial.print(WiFi.localIP());
    Serial.println(".");
  }
  Serial.println("");
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  
  // Write to Google Sheet via IFTTT Maker channel that the ESP8266 has started/restarted

  // Now we trigger the IFTTT Maker Channel to update a Google sheet with the activity of the server starting/restarting
  // This can help log power outs, etc.  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // Create the request for IFTTT GARAGE_trigger_serverstart.  This can help log power outs, etc. 
  String url = "https://maker.ifttt.com/trigger/GARAGE_trigger_serverstart/with/key/" + MAKER_SECRET_KEY;
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This sends the request to the IFTTT server
  client.print(String("POST ") + url + " HTTP/1.1\r\n" +
  "Host: " + host + "\r\n" + 
  "Connection: close\r\n\r\n");
  
  delay(500);  // Delay to for web traffic; maybe not required.
  }

  server.on("/", handleRoot);

  server.on("/long_confusing_URL_to_activate_relay", [](){
    // This is called when 192.168.0.28/long_confusing_URL_to_activate_relay is called
    randNumber = random(1, 10000);  // Random number just to show a change on the webpage at reload.
    server.send(200, "text/plain", "Relay activated @ESP8266.  Code: " + String(randNumber));
    digitalWrite(led, 0);  // Active LOW.  Turn On board LED On
    digitalWrite(relay, 1);  // Relay ON

    // Know we trigger the IFTTT Maker Channel to update a Google sheet with the activity.  
    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
    }
  
    // Create the request for IFTTT
    String url = "https://maker.ifttt.com/trigger/" + TRIGGER_NAME + "/with/key/" + MAKER_SECRET_KEY;
    Serial.print("Requesting URL: ");
    Serial.println(url);
  
    // This sends the request to the IFTTT server
    client.print(String("POST ") + url + " HTTP/1.1\r\n" +
    "Host: " + host + "\r\n" + 
    "Connection: close\r\n\r\n");
    
    delay(2000);  // Delay to keep the relay closed.
    digitalWrite(led, 1);  // Active LOW.  Turn On board LED Off
    digitalWrite(relay, 0);  //Relay OFF
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
