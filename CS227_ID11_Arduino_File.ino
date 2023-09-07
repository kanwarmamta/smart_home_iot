#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2); 
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  mySerial.println("Ready");                       //Checking if the Bluetooth is connected 
  Serial.println("Ready to take voice commands");  // Checking if serial monitor is connected
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  if (mySerial.available() > 0) {
    //The code is taking in a single character input from the android app
    // if the command given matches with the prewritten commands.
    //Based on the single character received we can control the appliances going ON or OFF

    String value = mySerial.readString();
    mySerial.println(value);
    Serial.println(value);
    // "Turn on all appliances" is encoded as "A" by the android application
    if (value == "A") {
      digitalWrite(13, HIGH);
      digitalWrite(5, LOW);
    }
    //"Turn off all appliances" is encoded as "a" by the android application
    if (value == "a") {
      digitalWrite(13, LOW);
      digitalWrite(5, HIGH);
    }
    //"Turn on blue LED" is encoded as "C" by the android application
    if (value == "C") {
      digitalWrite(13, HIGH);
    }
    //"Turn Off blue LED" is encoded as "c" by the android application
    if (value == "c") {
      digitalWrite(13, LOW);
    }
    //"Turn on fan" is encoded as "B" by the android application
    if (value == "B") {
      digitalWrite(5, LOW);
    }
    //"Turn Off fan" is encoded as "b" by the android application
    if (value == "b") {
      digitalWrite(5, HIGH);
    }
    delay(200);
  }
}