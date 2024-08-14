/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// /* Fill-in information from Blynk Device Info here */
// #define BLYNK_TEMPLATE_ID           "TMPL3s50cpx9S"
// #define BLYNK_TEMPLATE_NAME         "Quickstart Template"
// #define BLYNK_AUTH_TOKEN            "AxQfEq0g5ptmgl0U6qMgO_sS41mRGVii"
#define BLYNK_TEMPLATE_ID "TMPL3yyUwXR1r"
#define BLYNK_TEMPLATE_NAME "Theft alert"
#define BLYNK_AUTH_TOKEN "Jw7t0go8UepZxMk0zqPVnUcG0DVU7BgZ"
#define SENSOR_PIN 15
#define relaypin 16
#define ledpin 4

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Apna Chlao";
char pass[] = "12345678";



BlynkTimer timer;

void notifyOnTheft(){
   int isTheftAlert = digitalRead(SENSOR_PIN);
  Serial.println(isTheftAlert);
  if (isTheftAlert==1) {
    Serial.println("Theft Alert in Home");
    // Blynk.email("shameer50@gmail.com", "Alert", "Theft Alert in Home");
    //Blynk.notify("Alert : Theft Alert in Home");
    digitalWrite(relaypin, HIGH); 
    digitalWrite(ledpin, HIGH);
    Blynk.logEvent("theft_alert","Theft Alert in Home");

//    flag=1;
  }
  else if (isTheftAlert==0)
  {
   // flag=0;
   digitalWrite(relaypin, LOW); 
   digitalWrite(ledpin, LOW); 
  }
}

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
pinMode(SENSOR_PIN, INPUT);
pinMode(relaypin, OUTPUT); 
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, notifyOnTheft);

}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
