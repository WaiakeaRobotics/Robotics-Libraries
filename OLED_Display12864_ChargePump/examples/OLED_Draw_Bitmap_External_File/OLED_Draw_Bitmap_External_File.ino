#include <Wire.h>
#include <SeeedOLED.h>
#include <avr/pgmspace.h>
#include "bitmap.h"

int counter;
SeeedOLED Oled;

void setup()
{
  Serial.begin(115200);
  Wire.begin();	
  Oled.init();  //initialze  OLED display
  DDRB|=0x21;         
  PORTB |= 0x21;

  Oled.clearDisplay();               // clear the screen and set start position to top left corner
  Oled.drawBitmap(bitmap,1024);   // 1024 = 128 Pixels * 64 Pixels / 8
  
    Oled.clearDisplay();          //clear the screen and set start position to top left corner
  Oled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  Oled.setPageMode();           //Set addressing mode to Page Mode
  Oled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column  
  Oled.putString("Hello World!"); //Print the String
  
  
  Oled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column  
  Oled.putString("Hello World!"); //Print the String
  Oled.setTextXY(1,0);          //Set the cursor to Xth Page, Yth Column 
  Oled.putString("Waiakea Robotics"); //Print the String
  Oled.setTextXY(2,0);          //Set the cursor to Xth Page, Yth Column
  Oled.putString("Yaw: "); //Print the String 
  Oled.setTextXY(2,6);          //Set the cursor to Xth Page, Yth Column
  Oled.putNumber(counter); //Print the String
  Serial.print("Buttons: ");

}

void loop()
{
    counter ++;
  Oled.setTextXY(2,5);     //Set the cursor to Vertical Page, Horizontal Column 
  Oled.putNumber(counter); //Print the number
  Oled.setTextXY(3,5);     //Set the cursor to Vertical Page, Horizontal Column 
  Oled.putNumber(counter); //Print the number
    Oled.setTextXY(4,5);     //Set the cursor to Vertical Page, Horizontal Column 
  Oled.putNumber(counter); //Print the number
    Oled.setTextXY(5,5);     //Set the cursor to Vertical Page, Horizontal Column 
  Oled.putNumber(counter); //Print the number
    Oled.setTextXY(6,5);     //Set the cursor to Vertical Page, Horizontal Column 
  Oled.putNumber(counter); //Print the number
  Serial.println("Buttons: ");
}