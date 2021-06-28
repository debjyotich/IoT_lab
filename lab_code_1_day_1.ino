// set pin numbers
const int buttonPin = 4;     // the number of the pushbutton pin
const int ledPin =  5;       // the number of the LED pin

// variable for storing the pushbutton status
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    Serial.println("LED On");
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off
    Serial.println("LED Off");
    digitalWrite(ledPin, LOW);
  }
}
