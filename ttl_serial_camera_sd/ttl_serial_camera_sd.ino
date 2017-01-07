#include <SoftwareSerial.h>
#include <Adafruit_VC0706.h>
#include <SD.h>
#define FORCE_THRESHOLD 400
#define ONBOARD_LED 13
#define FORCE_SENSOR 0
#define chipSelect 10
// Set the XBee serial transmit/receive digital pins
SoftwareSerial XBeeSerial = SoftwareSerial(2, 3);
SoftwareSerial cameraconnection = SoftwareSerial(4, 5);
Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);
int force_value = 0;
byte force_state = 0;

void setup()
{
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect))
  {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  } 
// for serial window debugging
Serial.begin(9600);
// for XBee transmission
XBeeSerial.begin(9600);
// set pin for onboard led
pinMode(ONBOARD_LED, OUTPUT);
}

void SendDeliveryAlert(int force_value, int force_state)
{
digitalWrite(ONBOARD_LED, force_state ? HIGH : LOW);
if (force_state)
{
Serial.print("Package delivered, force_value=");
Serial.println(force_value);
XBeeSerial.println("Delivery");
[color=red][color=red][b][glow=yellow,2,300]Serial.println("VC0706 Camera snapshot");
 
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect))
  {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  } 
 
  // Try to locate the camera
  if (cam.begin())
  {
    Serial.println("Camera Found:");
  }
  else
  {
    Serial.println("No camera found?");
    return;
  }
  Serial.println("Snap in 3 secs...");
  delay(1000);

  if (! cam.takePicture())
    Serial.println("Failed to snap!");
  else
    Serial.println("Picture taken!");
 [/glow][/b][/color][/color]
  // Create an image with the name IMAGExx.JPG
  char filename[13];
  strcpy(filename, "IMAGE00.JPG");
  for (int i = 0; i < 100; i++)
  {
    filename[5] = '0' + i/10;
    filename[6] = '0' + i%10;
    // create if does not exist, do not open existing, write, sync after write
    if (! SD.exists(filename))
    {
      break;
    }
  }
 
  // Open the file for writing
  File imgFile = SD.open(filename, FILE_WRITE);

  // Get the size of the image (frame) taken 
  uint16_t jpglen = cam.frameLength();
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
 
}
else
{
Serial.print("Package removed, force_value=");
Serial.println(force_value);
XBeeSerial.println("Empty");
[color=yellow]Serial.println("VC0706 Camera snapshot");
delay(2000);
 
 
  // Try to locate the camera
  if (cam.begin())
  {
    Serial.println("Camera Found:");
  }
  else
  {
    Serial.println("No camera found?");
    return;
  }[/color]
  Serial.println("Snap in 1 secs...");
  delay(1000);

  if (! cam.takePicture())
    Serial.println("Failed to snap!");
  else
    Serial.println("Picture taken!");
 
  // Create an image with the name IMAGExx.JPG
  char filename[13];
  strcpy(filename, "IMAGE00.JPG");
  for (int i = 0; i < 100; i++)
  {
    filename[5] = '0' + i/10;
    filename[6] = '0' + i%10;
    // create if does not exist, do not open existing, write, sync after write
    if (! SD.exists(filename))
    {
      break;
    }
  }
 
  // Open the file for writing
  File imgFile = SD.open(filename, FILE_WRITE);

  // Get the size of the image (frame) taken 
  uint16_t jpglen = cam.frameLength();
 

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
  }
}
void loop()
{
// wait a second each loop iteration
delay(1000);
// poll FLEX_SENSOR voltage
force_value = analogRead(FORCE_SENSOR);
switch (force_state)
{
 
case 0: // check if package was delivered
if (force_value >= FORCE_THRESHOLD)
{
force_state = 1;
SendDeliveryAlert(force_value, force_state);
}
break;
case 1: // check if package was removed
if (force_value < FORCE_THRESHOLD)
{
force_state = 0;
SendDeliveryAlert(force_value, force_state);
}
break;
}
}
