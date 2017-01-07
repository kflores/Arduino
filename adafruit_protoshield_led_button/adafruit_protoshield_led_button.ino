#include <SoftwareSerial.h> 

#define led1_pin 5 
#define led2_pin 6 
#define button2_pin 4

int state1 = 0; 
int state2 = 0; 

void setup() { 
  Serial.begin( 9600 ); 
  Serial.println( "blinky switch test!" ); 
  pinMode( button2_pin, INPUT ); // use internal pullup 
} 

void loop() { 

  digitalWrite( button2_pin, 1 ); // enable switch circuit 
  if (digitalRead( button2_pin ) == 0) { 

    if (! state2) { 
      state2 = 1; 
      state1 ^= 1; 
      Serial.println( "switch: ON!" ); 
    } 

  } 
  else { 

    if (state2) { 
      state2 = 0; 
      //state1 ^= 1; 
      Serial.println( "switch: off!" ); 
    } 

  } 

  digitalWrite( led1_pin, state1 ); 
  digitalWrite( led2_pin, state2 ); 

}

