#include <Adafruit_VC0706.h>
#include <SPI.h>
#include <SD.h>

#include <SoftwareSerial.h>
// uncomment this line if using Arduino V23 or earlier
// #include <NewSoftSerial.h>    

#include <Wire.h>
#include <RTClib.h>

File file;  // test file
const uint8_t SD_CS = 10; // SD chip select
RTC_DS1307 RTC;  // define the Real Time Clock object
//------------------------------------------------------------------------------
// call back for file timestamps
void dateTime(uint16_t* date, uint16_t* time) {
  DateTime now = RTC.now();

  // return date using FAT_DATE macro to format fields
  *date = FAT_DATE(now.year(), now.month(), now.day());

  // return time using FAT_TIME macro to format fields
  *time = FAT_TIME(now.hour(), now.minute(), now.second());
}
//------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!RTC.begin()) {
    Serial.println("RTC failed");
    while(1);
  };
  // set date time callback function
  SdFile::dateTimeCallback(dateTime); 

  if (!SD.begin(SD_CS)) {
    Serial.println("SD.begin failed");
    while(1);
  }
  file = SD.open("TEST_SD.TXT", FILE_WRITE);
  file.close();
  Serial.println("Done");
}
//------------------------------------------------------------------------------
void loop() {}
