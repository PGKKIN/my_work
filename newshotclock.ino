// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        4 // On Trinket or Gemma, suggest changing this to 1
#define PIN1         5
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 38// Popular NeoPixel ring size
#define ALLDIGI 76

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS*2, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels1(NUMPIXELS*2, PIN1, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 20 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(150);
   pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels1.setBrightness(150);

  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  
}
void clear(){
  int num=NUMPIXELS*2;
   for(int i=0; i<num; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(0,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(0,0,0 ));
      // Send the updated pixel colors to the hardware.
    }
    delay(20);
  }
//=================================================================
void num0(int digi){
  int offset=digi*NUMPIXELS;
  for(int i=offset; i<NUMPIXELS+offset-6; i++) { // For each pixel...
     
    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.

   }
   delay(DELAYVAL);
   pixels.show();
   pixels1.show();
  
}
void num1(int digi){
  int offset=digi*NUMPIXELS;
for(int i=offset+6; i<NUMPIXELS+offset-22; i++) { // For each pixel...
 
 pixels.setPixelColor(i, pixels.Color(55,0,0 ));
  pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.

    
     }
      delay(DELAYVAL);
       pixels.show();
       pixels1.show();
       
}

void num2(int digi){
  int offset=digi*NUMPIXELS;
 for(int i=offset; i<NUMPIXELS+offset; i++) { // For each pixel...
   if(i>offset+10 & i<offset+16)
     continue;
   if(i>offset+26 & i<offset+32)
     continue;
   pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
    
    }
     delay(DELAYVAL);
   pixels.show();
   pixels1.show();
    
  
}





void num3(int digi){
   int offset=digi*NUMPIXELS;
 for(int i=offset; i<NUMPIXELS+offset; i++) { // For each pixel...
   if(i>offset+21 & i<offset+32)
     continue;
     pixels.setPixelColor(i, pixels.Color(55,0,0 ));
     pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
    
    }
     delay(DELAYVAL);
   pixels.show();
   pixels1.show();
    
  
}



void num4(int digi){
  int offset=digi*NUMPIXELS;
 for(int i=offset+6; i<NUMPIXELS+offset; i++) { // For each pixel...
   if(i>offset+15 & i<offset+27)
     continue;
    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.

    }
    delay(DELAYVAL);
    pixels.show();
    pixels1.show();   
    
  
}



void num5(int digi){
  int offset=digi*NUMPIXELS;
 for(int i=offset; i<NUMPIXELS+offset; i++) { // For each pixel...
   if(i>offset+5 & i<offset+11)
     continue;
   if(i>offset+21 & i<offset+27)
     continue;
    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
    }
     delay(DELAYVAL);
   pixels.show();
   pixels1.show();
   
  
}

void num6(int digi){
   int offset=digi*NUMPIXELS;
 for(int i=offset; i<NUMPIXELS+offset; i++) { // For each pixel...
   if(i>offset+5 & i<offset+11)
     continue;
      pixels.setPixelColor(i, pixels.Color(55,0,0 ));
      pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
    
    }
     delay(DELAYVAL);
   pixels.show();
   pixels1.show();
   
  
}



void num7(int digi){
  int offset=digi*NUMPIXELS;
 for(int i=offset; i<NUMPIXELS+offset; i++) { // For each pixel...
   if(i>offset+15)
     continue;
      pixels.setPixelColor(i, pixels.Color(55,0,0 ));
      pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
    
    }
     delay(DELAYVAL);
   pixels.show();
   pixels1.show();
  
  
}



void num8(int digi){
   int offset=digi*NUMPIXELS;
 for(int i=offset; i<NUMPIXELS+offset; i++) { // For each pixel...
  pixels.setPixelColor(i, pixels.Color(55,0,0 ));
  pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
    
    }
     delay(DELAYVAL);
   pixels.show();
   pixels1.show();
  
}

void num9(int digi){
  int offset=digi*NUMPIXELS;
 for(int i=offset; i<NUMPIXELS+offset; i++) { // For each pixel...
   if(i>offset+21 & i<offset+27)
     continue;
 pixels.setPixelColor(i, pixels.Color(55,0,0 ));
 pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
    
    }
   delay(DELAYVAL);
   pixels.show();
   pixels1.show();
  
  
}

void shownum(int n){
int o;

 if(n<10)
 num0(0);
 if(n>9 & n<20)
 num1(0);
 if(n>19 & n<30)
 num2(0);
 if(n>29 & n<40)
 num3(0);
 if(n>39 & n<50)
 num4(0);
 if(n>49 & n<60)
 num5(0);
 if(n>59 & n<70)
 num6(0);
 if(n>69 & n<80)
 num7(0);
 if(n>79 & n<90)
 num8(0);
 if(n>89 & n<100)
 num9(0);
o=n%10; 
  if(o==0)
 num0(1);
 if(o==1)
 num1(1);
 if(o==2)
 num2(1);
 if(o==3)
 num3(1);
 if(o==4)
 num4(1);
 if(o==5)
 num5(1);
 if(o==6)
 num6(1);
 if(o==7)
 num7(1);
 if(o==8)
 num8(1);
 if(o==9)
 num9(1);
 
  
  }

unsigned long  time_d=0; //time
unsigned long  time_a=0;
 int a=0;
 int x=0;
int s=24;
void shotclock(){
int shotclock14=digitalRead(8);
int shotclock24=digitalRead(9);
int stop_shotclock=digitalRead(10);
int delete_shotclock=digitalRead(11);
int street_ball_3x3=digitalRead(12);

if(stop_shotclock == 0){
 if(millis()-time_d>865)
 {
     s-=1;
     clear();
     time_d=millis();
 }
}
else
  time_d=millis();




if (street_ball_3x3 == 0){
time_d=millis();
if(s!=12)
  clear();
s=12;
  }
if (shotclock14 == 0){
time_d=millis();
if(s!=14)
  clear();
s=14;
  
}
if (shotclock24 == 0){
time_d=millis();
if(s!=24)
  clear();
s=24;  
//
}


if(delete_shotclock==0){
delay(200);
clear();  

s-=1;
}



if(s<=0)
time_a=millis();  

if(millis()-time_a<500){
  digitalWrite(3,HIGH);
  }
else
  digitalWrite(3,LOW);
  
    
if(s<0){

  
  s=24;
}

shownum(s);
  }
  




void loop() {

 
shotclock();
  }
 
  

 
  
