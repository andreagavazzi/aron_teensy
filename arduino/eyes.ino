#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"
#include <ros.h>   
#include <std_msgs/String.h> 
#include <ros/time.h>

// Define pins for display interface
#define OLED1_DC  7
#define OLED1_CS 10
#define OLED2_DC  6
#define OLED2_CS 36
//#define OLED_RST 8
//#define OLED_BL 9

#define BLUE 0x9cfb
#define GREEN 0x0665
#define YELLOW 0xdfa0
#define basecolor 0x0665

// Display constructors
Adafruit_GC9A01A OLED1 = Adafruit_GC9A01A(OLED1_CS, OLED1_DC);
Adafruit_GC9A01A OLED2 = Adafruit_GC9A01A(OLED2_CS, OLED2_DC);

ros::NodeHandle nh;

//uint16_t color = 0;  //Color for eyes
String color = 0x0665;


void colorMessageCb(const std_msgs::String &teensy_eyes) 
{ 
color = teensy_eyes.data;
uint16_t colorVal = atoi (color.substring(1, 3).c_str());

//String data = "#255101987";
//uint8_t first  = atoi (data.substring(1, 3).c_str ());   



if(color=="blue"){  
    OLED1.fillScreen(0x9cfb);
    OLED2.fillScreen(0x9cfb); 
} 
  else if(color=="yellow"){ 
    OLED1.fillScreen(YELLOW);
    OLED2.fillScreen(YELLOW);  
  } 
  else if(color=="green"){ 
    OLED1.fillScreen(GREEN);
    OLED2.fillScreen(GREEN);   
  } 
  else { 
    OLED1.fillScreen(0xf800);
    OLED2.fillScreen(0xf800);   
  } 


}   

ros::Subscriber<std_msgs::String> sub("teensy_eyes", &colorMessageCb ); 



void setup() {
  // put your setup code here, to run once:

  OLED1.begin();
  OLED2.begin();

  OLED1.fillScreen(basecolor);
  OLED2.fillScreen(basecolor);

  nh.initNode();
  nh.subscribe(sub); 
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();

}

