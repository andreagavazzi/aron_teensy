#include <ros.h>   
#include <std_msgs/String.h> 
#include <ros/time.h>
#include "SPI.h" 
#include "Adafruit_GFX.h" 
#include "Adafruit_GC9A01A.h" 
#include "Fonts/FreeMono12pt7b.h" 

//Definitions for OLEDS
#define SCREEN_WIDTH 240 
#define SCREEN_HEIGHT 240 
#define OLED1_DC 7 
#define OLED1_CS 10 
#define OLED2_DC 6 
#define OLED2_CS 36 
#define OLED_BL 9 
// #define OLED_RST PINNR 

// Display constructor for SPI connections 
Adafruit_GC9A01A tft1 = Adafruit_GC9A01A(OLED1_CS, OLED1_DC); 
Adafruit_GC9A01A tft2 = Adafruit_GC9A01A(OLED2_CS, OLED2_DC); 

ros::NodeHandle nh; 
char color[6];  //il valore che ricevo da ros per il colore occhi 

void colorMessageCb(const std_msgs::string &togglecolor) 
{ 
input = togglecolor.data; 
//Example 0x9cfb

}   

ros::Subscriber<std_msgs::Int32> sub("toggle_color", &colorMessageCb );   

void setup()   
{ 
  // Backlight ON 
  #if defined(OLED_BL) 
    pinMode(OLEd_BL, OUTPUT); 
    digitalWrite(OLED_BL, HIGH); // Backlight on 
  #endif  

 

String text1 = "OLED 1"; 

String text2 = "OLED 2"; 

 

Serial.begin(9600); 

Serial.println("Started"); 
  
  // TODO: gli oled prendono il colore di default
  leds.init();  
  leds.setColorRGB(0, 0, 0, 0); 
  leds.setColorRGB(1, 0, 0, 0);  
  nh.initNode();   
  nh.subscribe(sub);   
}   

void loop()   
{ 
// publisher would be herewe are not publishing anythingcurrentMillis = millis(); 
  nh.spinOnce();   
} 
