#include <NewPing.h>

#define FRONT_TRIGGER_PIN  33  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define FRONT_ECHO_PIN     32  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing front_sonar(FRONT_TRIGGER_PIN, FRONT_ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 29;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin
#define ena 3
#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define enb 8
#define led 13
#define sens1 23
#define sens2 24
#define sens3 25
#define sens4 27
#define sens5 28
#define sens6 29

void setup() {
	Serial.begin(9600);
	pinMode(ena, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	pinMode(enb, OUTPUT);

	pinMode(led, OUTPUT);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

	pinMode(sens1, INPUT);
	pinMode(sens2, INPUT);
	pinMode(sens3, INPUT);
	pinMode(sens4, INPUT);
	pinMode(sens5, INPUT);
	pinMode(sens6, INPUT);

}

int leftSpeed = 0;
int rightSpeed = 0;
void loop() {
  int front_distance = front_sonar.ping_cm();

  if(front_distance<30 && front_distance>0 ){
    while(true){
      digitalWrite(13,HIGH);
      leftSpeed = 0;
      rightSpeed = 0;
			analogWrite(ena, leftSpeed);
			analogWrite(enb, rightSpeed);
    }
  }
	// check if the pushbutton is pressed. If it is, the buttonState is HIGH:
	if (digitalRead(sens1) == LOW) {
		while(digitalRead(sens4) != LOW) {
			digitalWrite(in1, LOW);
			digitalWrite(in2, HIGH);
			digitalWrite(in3, HIGH);
			digitalWrite(in4, LOW);
			leftSpeed = 70;
			rightSpeed = 70;
			analogWrite(ena, leftSpeed);
			analogWrite(enb, rightSpeed);
		}
	}
	else if (digitalRead(sens2) == LOW) {

		digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
		digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
		leftSpeed = 70;
		rightSpeed =  0;
	}
	else  if (digitalRead(sens3) == LOW) {

		digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
		digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
		leftSpeed = 70;
		rightSpeed = 0;
	}
	else  if (digitalRead(sens4) == LOW) {

		digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
		digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
		leftSpeed = 0;
		rightSpeed =  70;
	}
	else if (digitalRead(sens5) == LOW) {

		digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
		digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
		leftSpeed = 0;
		rightSpeed = 70;
	}
	else if (digitalRead(sens6) == LOW) {
		while(digitalRead(sens3) != LOW) {
			digitalWrite(in1, HIGH);
			digitalWrite(in2, LOW);
			digitalWrite(in3, LOW);
			digitalWrite(in4, HIGH);
			leftSpeed = 70;
			rightSpeed = 70;
			analogWrite(ena, leftSpeed);
			analogWrite(enb, rightSpeed);

		}
	}

/*
	if (digitalRead(sens6) != LOW &&
	        digitalRead(sens5) != LOW &&
	        digitalRead(sens4) != LOW &&
	        digitalRead(sens3) != LOW &&
	        digitalRead(sens2) != LOW &&
	        digitalRead(sens1) != LOW) {
    
    digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
		digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);

		while(digitalRead(sens6) != LOW &&
		        digitalRead(sens5) != LOW &&
		        digitalRead(sens4) != LOW &&
		        digitalRead(sens3) != LOW &&
		        digitalRead(sens2) != LOW &&
		        digitalRead(sens1) != LOW) {
              digitalWrite(led,HIGH);
			leftSpeed = 50;
			rightSpeed = 50;
			analogWrite(ena, leftSpeed);
			analogWrite(enb, rightSpeed);
		}
	}
*/
	analogWrite(ena, leftSpeed);
	analogWrite(enb, rightSpeed);
	Serial.print(leftSpeed);
	Serial.print(' ');
	Serial.println(rightSpeed);
	delay(50);
}
