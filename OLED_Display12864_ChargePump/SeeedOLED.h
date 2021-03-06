/*
  SeeedOLED.h - SSD130x OLED Driver Library
  2011 Copyright (c) Seeed Technology Inc.  All right reserved.
 
  Author: Visweswara R
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef SeeedOLED_data_H
#define SeeedOLED_data_H

// SeeedOLED Instruction set addresses

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
#include "Wire.h"
#endif



#define SeeedOLED_Max_X 		127	//128 Pixels
#define SeeedOLED_Max_Y 		63	//64  Pixels

#define PAGE_MODE			01
#define HORIZONTAL_MODE			02


#define SeeedOLED_Address		0x3D
#define SeeedOLED_Command_Mode		0x80
#define SeeedOLED_Data_Mode		0x40
#define SeeedOLED_Display_Off_Cmd	0xAE
#define SeeedOLED_Display_On_Cmd	0xAF
#define SeeedOLED_Normal_Display_Cmd	0xA6
#define SeeedOLED_Inverse_Display_Cmd	0xA7
#define SeeedOLED_Activate_Scroll_Cmd	0x2F
#define SeeedOLED_Dectivate_Scroll_Cmd	0x2E
#define SeeedOLED_Set_Brightness_Cmd	0x81

#define Scroll_Left			0x00
#define Scroll_Right			0x01

#define Scroll_2Frames			0x7
#define Scroll_3Frames			0x4
#define Scroll_4Frames			0x5
#define Scroll_5Frames			0x0
#define Scroll_25Frames			0x6
#define Scroll_64Frames			0x1
#define Scroll_128Frames		0x2
#define Scroll_256Frames		0x3

#define Charge_Pump_Setting_Cmd      	      0x8D
#define Charge_Pump_Enable_Cmd	              0x14
#define Charge_Pump_Disable_Cmd               0x10     //default
#define Segment_Normal_map_Cmd                0xA0       //Default. column address 0 is mapped to SEG0(RESET)

//Timing & Driving Scheme Setting Command (more than one bytes command pleaserefer to SSD1some more than one bytes command please 306 datasheet for details)
#define Set_Display_Clock_Divide_Ratio_Cmd    0xD5
#define Set_Precharge_Period_Cmd              0xD9
#define Set_VCOMH_Deselect_Level_Cmd          0xDB
#define No_Operation_Cmd                      0xE3
#define Set_COM_Pins_Hardware_Config_Cmd      0xDA   
#define Set_Display_Offset_Cmd                0xD3       //Set vertical shift by COM from 0d~63d. The value is reset to 00h after RESET.

//Fundamental Command (more than one bytes command pleaserefer to SSD1306 datasheet for details)
#define Set_Contrast_Cmd                      0x81     //Double byte command to select 1 out of 256 contrast steps.Default(RESET = 0x7F)
#define Entire_Display_On_Resume_Cmd          0xA4     //Resume to RAM content display(RESET), Output follows RAM content
#define Entire_Display_On_Cmd                 0xA5     //Entire display ON, Output ignores RAM content
#define OLED_Normal_Display_Cmd	      0xA6     //Normal display (RESET)
#define OLED_Inverse_Display_Cmd	      0xA7     //Inverse display
#define OLED_Display_Off_Cmd	      0xAE     //sleep mode(RESET)
#define OLED_Display_On_Cmd	      0xAF     //normal mode

//Scrolling Command (more than one bytes command pleaserefer to SSD1306 datasheet for details)
#define Right_Horizontal_Scroll_Cmd           0x26
#define Left_Horizontal_Scroll_Cmd            0x27
#define Vertical_Right_Horizontal_Scroll_Cmd  0x29
#define Vertical_Left_Horizontal_Scroll_Cmd   0x2A
#define Activate_Scroll_Cmd                   0x2F
#define Deactivate_Scroll_Cmd                 0x2E
#define Set_Vertical_Scroll_Area_Cmd          0xA3

//Addressing Setting Command (more than one bytes command pleaserefer to SSD1306 datasheet for details)
#define Set_Memory_Addressing_Mode_Cmd        0x20

#define VERTICAL_MODE			      0x01

#define Set_Column_Address_Cmd                0x21       //Setup column start and end address. This command is only for horizontal or vertical addressing mode.
#define Set_Page_Address_Cmd                  0x22       //Setup page start and end address. This command is only for horizontal or vertical addressing mode.

//Hardware Configuration (Panel resolution & layout related) Command (more than one bytes command please refer to SSD1306 datasheet for details)
#define Segment_Remap_Cmd                     0xA1       //column address 127 is mapped to SEG0
#define Segment_Normal_map_Cmd                0xA0       //Default. column address 0 is mapped to SEG0(RESET)
#define Set_Multiplex_Ratio_Cmd               0xA8       //Set MUX ratio to N+1 MUX
#define COM_Output_Normal_Scan_Cmd            0xC0       //Normal mode (RESET). Scan from COM0 to COM[N ¨C1]
#define COM_Output_Remap_Scan_Cmd             0xC8       //Remapped mode. Scan from COM[N-1] to COM0
#define Set_Display_Offset_Cmd                0xD3       //Set vertical shift by COM from 0d~63d. The value is reset to 00h after RESET.
#define Set_COM_Pins_Hardware_Config_Cmd      0xDA   

//Timing & Driving Scheme Setting Command (more than one bytes command pleaserefer to SSD1some more than one bytes command please 306 datasheet for details)
#define Set_Display_Clock_Divide_Ratio_Cmd    0xD5
#define Set_Precharge_Period_Cmd              0xD9
#define Set_VCOMH_Deselect_Level_Cmd          0xDB
#define No_Operation_Cmd                      0xE3

#define Charge_Pump_Setting_Cmd      	      0x8D
#define Charge_Pump_Enable_Cmd	              0x14
#define Charge_Pump_Disable_Cmd               0x10     //default



class SeeedOLED {

public:

char addressingMode;


void init(void);

void setNormalDisplay();
void setInverseDisplay();

void sendCommand(unsigned char command);
void sendData(unsigned char Data);

void setPageMode();
void setHorizontalMode();

void setTextXY(unsigned char Row, unsigned char Column);
void clearDisplay();
void setBrightness(unsigned char Brightness);
void putChar(unsigned char c);
void putString(const char *String);
unsigned char putNumber(long n);
unsigned char putFloat(float floatNumber,unsigned char decimal);
unsigned char putFloat(float floatNumber);
void drawBitmap(const unsigned char *bitmaparray,int bytes);

void setHorizontalScrollProperties(bool direction,unsigned char startPage, unsigned char endPage, unsigned char scrollSpeed);
void activateScroll();
void deactivateScroll();

};

extern SeeedOLED SeeedOled;  // SeeedOLED object 

#endif


