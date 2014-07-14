/*
 Print
 
 Just like Serial.print/println
 
 Circuit:
 * I2C OLED Panel attached to pins SDA, SCL
 * Power inputs attached to pins 3V3, +5V,GND,GND,VIN
 
 Created 17 Jan 2012
 by: Jimbo.we(www.geekonfire.com)
 
 */

#include <Wire.h>
#include <OLED.h>

OLED OLED;

void setup()
{
  // default slave address is 0x3D
  OLED.init(0x3D);  //initialze  OLED display
  
  OLED.display(); // show splashscreen
  delay(2000);
  OLED.clearDisplay();
  
  OLED.setTextSize(1);
  OLED.setTextColor(WHITE);
  OLED.setCursor(0,0);
  OLED.println("Hello, world!");
    OLED.println("Hello, world!");
      OLED.println("Hello, world!");
        OLED.println("Hello, world!");
          OLED.println("Hello, world!");
            OLED.println("01234567890123456789"); // 20 characters fill up one full line of text
  OLED.display();

}

void loop()
{
  
}