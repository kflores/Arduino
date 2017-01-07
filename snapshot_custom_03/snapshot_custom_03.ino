// This is a basic snapshot sketch using the VC0706 library.
// On button press, the Arduino will find the camera and SD card,
// snap a photo, and sa it to the SD card.
// Green LED will indicate "Ready" status, Red LED is "Saving" status

#include <Adafruit_VC0706.h>
#include <SPI.h>
#include <SD.h>

#include <SoftwareSerial.h>
// uncomment this line if using Arduino V23 or earlier
// #include <NewSoftSerial.h>     

// Create a global variable to hold the 
// state of the switch. This variable is persistent 
// throughout the program. Whenever you refer to 
// switchState, you’re talking about the number it holds
int switchstate = 0;

#define buttonPin 4 // analog input pin to use as a digital input
#define ledPinGreen 5 // LED pin for output
#define ledPinRed 7 // LED pin for output
#define chipSelect 10 // SD card chip select; Adafruit SD shields and modules: pin 10

// Pins for camera connection are configurable.
// With the Arduino Uno, etc., most pins can be used, except for
// those already in use for the SD card (10 through 13 plus
// chipSelect, if other than pin 10).

// Using SoftwareSerial (Arduino 1.0+) or NewSoftSerial (Arduino 0023 & prior):
#if ARDUINO >= 100
// On Uno: camera TX connected to pin 2, camera RX to pin 3:
SoftwareSerial cameraconnection = SoftwareSerial(2, 3);
// On Mega: camera TX connected to pin 69 (A15), camera RX to pin 3:
//SoftwareSerial cameraconnection = SoftwareSerial(69, 3);
#else
NewSoftSerial cameraconnection = NewSoftSerial(2, 3);
#endif

Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);

void setup() {
  // declare the switch pin as an input
  pinMode(buttonPin, INPUT);
  // declare the LED pins as outputs 
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  digitalWrite(ledPinGreen, HIGH);  // turn the Green LED on to start!
  //start serial communication
  Serial.begin(9600);

  // When using hardware SPI, the SS pin MUST be set to an
  // output (even if not connected or used).  If left as a
  // floating input w/SPI on, this can cause lockuppage.
#if !defined(SOFTWARE_SPI)
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  if(chipSelect != 53) pinMode(53, OUTPUT); // SS on Mega
#else
  if(chipSelect != 10) pinMode(chipSelect, OUTPUT); // SS on Uno, etc.
#endif
#endif

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  } 

}


void loop() {
  // read the value of the switch; digitalRead() checks to see if there is voltage on the pin or not  
  switchstate = digitalRead(buttonPin);

  // if the button is NOT pressed
  if (switchstate == HIGH) {
    digitalWrite(ledPinGreen, HIGH);  // turn the Green LED on
    digitalWrite(ledPinRed, LOW);  // turn the Red LED off
    //Serial.println("Waiting");

  }
  else {
    digitalWrite(ledPinGreen, LOW);  // turn the Green LED off
    digitalWrite(ledPinRed, HIGH);  // turn the Red LED on
    //Serial.println("Button Pressed");
    snapPhoto();
    // delay(1000);
  }
}


void snapPhoto() {
  Serial.println("VC0706 Camera snapshot");

  // Try to locate the camera
  if (cam.begin()) {
    Serial.println("Camera Found:");
  } 
  else {
    Serial.println("No camera found?");
    return;
  }
  /* Print out the camera version information (optional)
   char *reply = cam.getVersion();
   if (reply == 0) {
   Serial.print("Failed to get version");
   } 
   else {
   Serial.println("-----------------");
   Serial.print(reply);
   Serial.println("-----------------");
   }
   */
  // Set the picture size - you can choose one of 640x480, 320x240 or 160x120 
  // Remember that bigger pictures take longer to transmit!

  cam.setImageSize(VC0706_640x480);        // biggest
  //cam.setImageSize(VC0706_320x240);        // medium
  //cam.setImageSize(VC0706_160x120);          // small

  // You can read the size back from the camera (optional, but maybe useful?)
  // uint8_t imgsize = cam.getImageSize();
  // Serial.print("Image size: ");
  // if (imgsize == VC0706_640x480) Serial.println("640x480");
  // if (imgsize == VC0706_320x240) Serial.println("320x240");
  // if (imgsize == VC0706_160x120) Serial.println("160x120");

  Serial.println("Snap in 1 sec...");
  delay(1000);

  if (! cam.takePicture()) 
    Serial.println("Failed to snap!");
  else 
    Serial.println("Picture taken!");

  // Create an image with the name IMAGExx.JPG
  char filename[13];
  strcpy(filename, "IMAGE00.JPG");
  for (int i = 0; i < 100; i++) {
    filename[5] = '0' + i/10;
    filename[6] = '0' + i%10;
    // create if does not exist, do not open existing, write, sync after write
    if (! SD.exists(filename)) {
      break;
    }
  }

  // Open the file for writing
  File imgFile = SD.open(filename, FILE_WRITE);

  // Get the size of the image (frame) taken  
  uint16_t jpglen = cam.frameLength();
  Serial.print("Storing ");
  Serial.print(jpglen, DEC);
  Serial.print(" byte image.");

  int32_t time = millis();
  pinMode(8, OUTPUT);
  // Read all the data up to # bytes!
  byte wCount = 0; // For counting # of writes
  while (jpglen > 0) {
    // read 32 bytes at a time;
    uint8_t *buffer;
    uint8_t bytesToRead = min(32, jpglen); // change 32 to 64 for a speedup but may not work with all setups!
    buffer = cam.readPicture(bytesToRead);
    imgFile.write(buffer, bytesToRead);
    if(++wCount >= 64) { // Every 2K, give a little feedback so it doesn't appear locked up
      Serial.print('.');
      wCount = 0;
    }
    //Serial.print("Read ");  Serial.print(bytesToRead, DEC); Serial.println(" bytes");
    jpglen -= bytesToRead;
  }
  imgFile.close();

  time = millis() - time;
  Serial.println("done!");
  Serial.print(time); 
  Serial.println(" ms elapsed");

}
