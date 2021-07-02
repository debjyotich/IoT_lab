/***************************************************
  This is Consentium Inc's IoT library
  ----> http://consentiuminc.online/
  Check out the links above for our tutorials and product diagrams.

  This is Consentium Inc's IoT library works only for 5v tolerant Edge Beta boards 
 
  Written by Debjyoti Chowdhury for Consentium Inc.
  MIT license, all text above must be included in any redistribution
 ****************************************************/


#include <ConsentiumThings.h>

ConsentiumThings link;   // create ConsentiumThing object

const char *ssid = "guest"; // add WiFi SSID
const char *pass = "guest123"; // add WiFi password
 
const char *ip = "consentiuminc.online";  // Consentium server address
const char *port = "80"; // Consentium server port
const char *key = "PHKKXV5B3UIX-SRFPZCPIQ";       // Write api key


void setup(){
  link.connect();   // init. IoT boad
  link.initWiFi(ssid, pass);  // begin WiFi connection
}

void loop(){
  float data_0 = analogRead(A0)*0.488; // Example sensor data read from A0
  float data_1 = analogRead(A1)*0.488; // Example sensor data read from A1
  
  float sensor_val[] = {data_0, data_1};  // sensor data array
  String info[] = {"Temperature", "Pressure"}; // sensor info. array
  
  int sensor_num = sizeof(sensor_val)/sizeof(sensor_val[0]); // number of sensors connected 
  
  link.sendREST(ip, port, key, info, sensor_num, sensor_val); // send over REST
  delay(5000); // delay
}
