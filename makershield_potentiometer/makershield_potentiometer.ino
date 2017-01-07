int led1 = 6;

int led2 = 7;

int buttonInput = 0;

int potInput = A0;

int potVal = 0;

int ledVal = 0;

void setup() {

//Declaring Outputs and inputs

pinMode(led1, OUTPUT);

pinMode(led2, OUTPUT);

pinMode(buttonInput, INPUT);

pinMode(potInput, INPUT);

}

void loop() {

//Read Potentiometer, convert to a value between 0-255 and analog write out

potVal = analogRead(potInput);

ledVal = map(potVal, 0, 1023, 0, 255);

analogWrite(led1, ledVal);

//Determine if Button is pressed, and turn it off if it is.

if (digitalRead(buttonInput) == LOW) {

digitalWrite(led2, LOW);

}

else {

digitalWrite(led2, HIGH);

}

}
