/*
 * Sketch that uses temperature sensor to get temperature and
 * display it to LCD screen.  Additionally, depending on the
 * temperature, it will progressively light up 3 LEDs.
 */



#include <LiquidCrystal.h>
#include <math.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// LEDs
int ledG = 6;
int ledY = 9;
int ledR = 10;

const int sensorPin = A0;
const float baselineTemp = 20.0;


void setup() {
  Serial.begin(9600); // open a serial port

    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hot in here?");

  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  
  digitalWrite(ledG, LOW);
  digitalWrite(ledY, LOW);
  digitalWrite(ledR, LOW);

 // for(int pinNumber = 2; pinNumber<5; pinNumber++){
 //   pinMode(pinNumber,OUTPUT);
 //   digitalWrite(pinNumber, LOW);
 // }

}

void loop() {  
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  // Temperature Celcius
  float temperature = (voltage - .5) * 100;
  Serial.print(temperature);
  Serial.print(", degrees F: ");
   // Temperature Fahrenheit
  float temperatureF = (temperature * 9.0 / 5.0) + 32.0;
  Serial.println(temperatureF);

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  // lcd.print(millis() / 1000);
  lcd.print(round(temperature));
  lcd.print(" C / ");
  lcd.print(round(temperatureF));
  lcd.print(" F");

  if(temperature < baselineTemp){
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
  } else if(temperature >=baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
  } else if(temperature >=baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);
  } else if(temperature >= baselineTemp+6){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
  }
  delay(1);
}
