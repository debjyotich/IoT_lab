// initializes or defines the output pin of the LM35 temperature sensor
int temp_sensor= A0;

//this sets the ground pin to LOW and the input voltage pin to high
void setup() {
  Serial.begin(9600); 
}

void loop(){
  int analogValue = analogRead(temp_sensor); // 0-1023
  float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
  float celsius = millivolts/10;
  Serial.print("DegreeC: ");
  Serial.print(celsius);

  //---------- Here is the calculation for Fahrenheit ----------//

  float fahrenheit = ((celsius * 9)/5 + 32);
  Serial.print(" Farenheit: ");
  Serial.println(fahrenheit);
  delay(1000); // 1s
}
