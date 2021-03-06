#include <Wire.h>
#include <SeeedOLED.h>
#include <avr/pgmspace.h>

int counter;

static unsigned char SeeedLogo[] PROGMEM ={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xC0, 0xF0,
0xFC, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xC0, 0xF0, 0xFC, 0xFF, 0xFF, 0x7F, 0x1F, 0x07,
0x60, 0x70, 0x70, 0x78, 0x78, 0x38, 0x38, 0x38, 0x38, 0xF8, 0xF8, 0xF8, 0xF0, 0xE0, 0x00, 0x00,
0x00, 0xF0, 0xFB, 0xFB, 0xFB, 0xFB, 0x1B, 0x00, 0x60, 0x70, 0x70, 0x78, 0x78, 0x38, 0x38, 0x38,
0x38, 0xF8, 0xF8, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0xC0,
0xE0, 0xF0, 0x78, 0x78, 0x38, 0x18, 0x08, 0xC0, 0xE0, 0xF0, 0xF0, 0xF8, 0x78, 0x38, 0x38, 0x78,
0xF8, 0xF8, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x60, 0x70, 0x70, 0x78, 0x78, 0x38, 0x38, 0x38, 0x38,
0xF8, 0xF8, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0x1F,
0x07, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0x7F, 0x0F, 0x03, 0x00, 0x00, 0x38,
0x7C, 0xFE, 0xFE, 0xFE, 0xE6, 0xE7, 0xE3, 0x73, 0x7B, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xC0,
0xFE, 0xFF, 0xFF, 0xFF, 0x3F, 0x01, 0x00, 0x38, 0x7C, 0xFE, 0xFE, 0xFE, 0xE6, 0xE7, 0xE3, 0x73,
0x7B, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xC0, 0xFE, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x07, 0x0F,
0x7F, 0xFF, 0xFF, 0xFC, 0xE0, 0x80, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xF7, 0xE6, 0xE6, 0xE6, 0xF6,
0x77, 0x77, 0x37, 0x17, 0x07, 0x00, 0x38, 0x7C, 0xFE, 0xFE, 0xFE, 0xE6, 0xE7, 0xE3, 0x73, 0x7B,
0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0xF0, 0xF0,
0xF0, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xE0,
0xE0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x70, 0x70, 0x70, 0x70, 0x10, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFE, 0xFF, 0xFF, 0xFF, 0x3F, 0x3B, 0x38,
0x78, 0xF8, 0xF8, 0xF8, 0xFC, 0xFF, 0x1F, 0x1F, 0x0F, 0xE7, 0xF8, 0xFC, 0xFE, 0xFE, 0x1F, 0x0F,
0x07, 0x07, 0x0F, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0x00, 0x00, 0xC0, 0xFE, 0xFF, 0xFF, 0xFF, 0x1F,
0x07, 0x06, 0x07, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0x00, 0xE0, 0xF8, 0xFC, 0xFE, 0xFE, 0x1F, 0x0F,
0x07, 0x07, 0x0F, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0x00, 0x00, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
0x07, 0x07, 0x07, 0x00, 0x00, 0xC0, 0xFE, 0xFF, 0xFF, 0xFF, 0x3F, 0x03, 0xE0, 0xF8, 0xFC, 0xFE,
0xFE, 0x1F, 0x0F, 0x07, 0x07, 0x07, 0x0F, 0x1E, 0x1E, 0x1C, 0x18, 0x00, 0x00, 0x00, 0x38, 0x7E,
0x7E, 0x7F, 0xE7, 0xE7, 0xE7, 0xEF, 0xCF, 0xCF, 0x8E, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1F, 0x1F, 0x1F, 0x1F, 0x07, 0x00, 0x00, 0x00,
0x00, 0x00, 0x03, 0x1F, 0x1F, 0x1F, 0x1F, 0x1C, 0x10, 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x1E, 0x1C,
0x1C, 0x1E, 0x1F, 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x18, 0x1F, 0x1F, 0x1F, 0x1F, 0x07, 0x0E,
0x1C, 0x1C, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x1E, 0x1C,
0x1C, 0x1E, 0x1F, 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1C,
0x0C, 0x00, 0x00, 0x00, 0x18, 0x1F, 0x1F, 0x1F, 0x1F, 0x07, 0x00, 0x00, 0x03, 0x0F, 0x0F, 0x1F,
0x1F, 0x1E, 0x1C, 0x1C, 0x1C, 0x1E, 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x06, 0x0E, 0x1E, 0x1E,
0x1E, 0x1C, 0x1C, 0x1C, 0x1C, 0x1F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};

void setup()
{
  Serial.begin(115200);
  Wire.begin();	
  SeeedOled.init();  //initialze SEEED OLED display
  DDRB|=0x21;         
  PORTB |= 0x21;

  SeeedOled.clearDisplay();               // clear the screen and set start position to top left corner
  SeeedOled.drawBitmap(SeeedLogo,1024);   // 1024 = 128 Pixels * 64 Pixels / 8
  
    SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();           //Set addressing mode to Page Mode
  SeeedOled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column  
  SeeedOled.putString("Hello World!"); //Print the String
  
  
  SeeedOled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column  
  SeeedOled.putString("Hello World!"); //Print the String
  SeeedOled.setTextXY(1,0);          //Set the cursor to Xth Page, Yth Column 
  SeeedOled.putString("Waiakea Robotics"); //Print the String
  SeeedOled.setTextXY(2,0);          //Set the cursor to Xth Page, Yth Column
  SeeedOled.putString("Yaw: "); //Print the String 
  SeeedOled.setTextXY(2,6);          //Set the cursor to Xth Page, Yth Column
  SeeedOled.putNumber(counter); //Print the String
  Serial.print("Buttons: ");

}

void loop()
{
    counter ++;
  SeeedOled.setTextXY(2,5);     //Set the cursor to Vertical Page, Horizontal Column 
  SeeedOled.putNumber(counter); //Print the number
  SeeedOled.setTextXY(3,5);     //Set the cursor to Vertical Page, Horizontal Column 
  SeeedOled.putNumber(counter); //Print the number
    SeeedOled.setTextXY(4,5);     //Set the cursor to Vertical Page, Horizontal Column 
  SeeedOled.putNumber(counter); //Print the number
    SeeedOled.setTextXY(5,5);     //Set the cursor to Vertical Page, Horizontal Column 
  SeeedOled.putNumber(counter); //Print the number
    SeeedOled.setTextXY(6,5);     //Set the cursor to Vertical Page, Horizontal Column 
  SeeedOled.putNumber(counter); //Print the number
  Serial.println("Buttons: ");
}