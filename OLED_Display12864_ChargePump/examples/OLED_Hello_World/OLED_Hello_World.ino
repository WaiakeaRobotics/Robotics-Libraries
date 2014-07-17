#include <Wire.h>
#include <SeeedOLED.h>

int counter;
void setup()
{
  Serial.begin(115200);
  Wire.begin();
  SeeedOled.init();  //initialze SEEED OLED display
  DDRB|=0x21;        
  PORTB |= 0x21;

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