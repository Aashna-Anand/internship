// #include <Arduino.h>
// #include <WiFi.h>
// #include <ESPAsyncWebServer.h>
// #include <SPIFFS.h>

// const char* ssid = "Airtel_Anjay";
// const char* password = "Priyanka@10";

// #define LED_PIN 2

// AsyncWebServer server(80);

// bool ledState = false;

// void setup()
// {
//     Serial.begin(115200);

//     pinMode(LED_PIN, OUTPUT);
//     digitalWrite(LED_PIN, LOW);

// WiFi.mode(WIFI_STA);
// WiFi.disconnect(true);
// delay(1000);

// WiFi.begin(ssid, password);

// Serial.print("Connecting to ");
// Serial.println(ssid);

// int retry = 0;

// while (WiFi.status() != WL_CONNECTED && retry < 20) {
//     delay(500);
//     Serial.print(".");
//     retry++;
// }

// Serial.println();

// if (WiFi.status() == WL_CONNECTED) {
//     Serial.println("WiFi Connected!");
//     Serial.print("IP Address: ");
//     Serial.println(WiFi.localIP());
// }
// else {
//     Serial.println("Failed to connect!");
//     Serial.print("WiFi Status = ");
//     Serial.println(WiFi.status());
// }

//     Serial.println();
//     Serial.println("Connected");
//     Serial.println(WiFi.localIP());

//     if(!SPIFFS.begin(true))
//     {
//         Serial.println("SPIFFS Failed");
//         return;
//     }

//     server.serveStatic("/",SPIFFS,"/")
//           .setDefaultFile("index.html");

//     // Turn ON
//     server.on("/on",HTTP_GET,[](AsyncWebServerRequest *request){

//         ledState=true;
//         digitalWrite(LED_PIN,HIGH);

//         request->send(200,"text/plain","ON");
//     });

//     // Turn OFF
//     server.on("/off",HTTP_GET,[](AsyncWebServerRequest *request){

//         ledState=false;
//         digitalWrite(LED_PIN,LOW);

//         request->send(200,"text/plain","OFF");
//     });

//     // Status API
//     server.on("/status",HTTP_GET,[](AsyncWebServerRequest *request){

//         if(ledState)
//             request->send(200,"text/plain","ON");
//         else
//             request->send(200,"text/plain","OFF");

//     });

//     server.begin();

//     Serial.println("Server Started");
// }

// void loop()
// {

// }



// #include <Arduino.h>

// #define BUTTON_PIN 4

// void setup()
// {
//     Serial.begin(115200);

//     pinMode(BUTTON_PIN, INPUT_PULLUP);
// }

// void loop()
// {
//     int buttonState = digitalRead(BUTTON_PIN);

//     Serial.println(buttonState);

//     delay(200);
// }

// #include <Arduino.h>
// #include <WiFi.h>
// #include <ESPAsyncWebServer.h>

// const char* ssid = "Airtel_Anjay";
// const char* password = "Priyanka@10";

// #define LED_PIN 2

// AsyncWebServer server(80);

// void setup() {

//     Serial.begin(115200);

//     pinMode(LED_PIN, OUTPUT);

//     WiFi.begin(ssid, password);

//     Serial.print("Connecting");

//     while (WiFi.status() != WL_CONNECTED) {
//         delay(500);
//         Serial.print(".");
//     }

//     Serial.println("\nWiFi Connected");
//     Serial.print("IP Address: ");
//     Serial.println(WiFi.localIP());

//     // Turn ON GPIO
//     server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request) {

//         digitalWrite(LED_PIN, HIGH);

//         Serial.println("GPIO HIGH");

//         request->send(200, "text/plain", "LED ON");
//     });

//     // Turn OFF GPIO
//     server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request) {

//         digitalWrite(LED_PIN, LOW);

//         Serial.println("GPIO LOW");

//         request->send(200, "text/plain", "LED OFF");
//     });

//     server.begin();

//     Serial.println("Server Started");
// }

// void loop() {
// }

//------servo motor rotation-----
// #include <Arduino.h>
// #include <WiFi.h>
// #include <ESPAsyncWebServer.h>
// #include <ESP32Servo.h>

// const char* ssid = "Airtel_Anjay";
// const char* password = "Priyanka@10";

// #define SERVO_PIN 13

// Servo myServo;
// AsyncWebServer server(80);

// void setup()
// {
//     Serial.begin(115200);

   
//     myServo.attach(SERVO_PIN);
//     myServo.write(0);      

//     WiFi.begin(ssid, password);

//     Serial.print("Connecting");

//     while (WiFi.status() != WL_CONNECTED)
//     {
//         delay(500);
//         Serial.print(".");
//     }

//     Serial.println();
//     Serial.println("WiFi Connected");
//     Serial.print("IP : ");
//     Serial.println(WiFi.localIP());

//     server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request)
//     {
//         Serial.println("Servo -> 360");
//         myServo.write(360);

//         request->send(200, "text/plain", "Servo at 360");
//     });


//     server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request)
//     {
//         Serial.println("Servo -> 0");
//         myServo.write(0);

//         request->send(200, "text/plain", "Servo at 0");
//     });

//     server.begin();
//     Serial.println("Server Started");
// }

// void loop()
// {
// }

// with push button
#include <Arduino.h>
#include <ESP32Servo.h>

#define SERVO_PIN 13
#define BUTTON_PIN 4

Servo servo;

void setup()
{
    Serial.begin(115200);

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    servo.attach(SERVO_PIN);

    servo.write(0);

    Serial.println("Ready...");
}

void loop()
{
    if (digitalRead(BUTTON_PIN) == LOW)
    {
        servo.write(180);
        Serial.println("Button Pressed");
    }
    else
    {
        servo.write(0);
        Serial.println("Button Released");
    }

    delay(100);
}