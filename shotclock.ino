//SHOTCLOCK BASKETBALL🏀
//BY KANDANAI KIDNGAN





// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        4// On Trinket or Gemma, suggest changing this to 1
#define PIN1         5
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 135// Popular NeoPixel ring size


// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels1(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 5 // Time (in milliseconds) to pause between pixels

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
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
}
void clear(){
   for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
   pixels.setPixelColor(i, pixels.Color(0,0,0 ));
   pixels1.setPixelColor(i, pixels.Color(0,0,0 ));
      // Send the updated pixel colors to the hardware.
    
    
    }
 //  pixels.show();
  }


void num0(int x){
for(int i=25-x; i<NUMPIXELS; i++) { // For each pixel...
if(i>27-x & i<31+x)
continue;
if(i>31+x & i<35+x)
continue;
if(i>35+x & i<54-x)
continue;
if(i>54-x & i<58-x)
continue; 
if(i>58-x & i<61+x)
continue;
if(i>61+x & i<65+x)
continue;
if(i>65+x & i<84-x)
continue;
if(i>84-x & i<88-x)
continue;
if(i>88-x & i<91+x)
continue;
if(i>91+x & i<95+x)
continue;
if(i>95+x & i<115-x)
continue;
if(i>117-x)
continue;

    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
  
    
    }
    delay(DELAYVAL);
  pixels.show();
   pixels1.show();
  
  
  
  }


//int x=0;
void num1(int x){
 if(x>10)
   return;
  for(int i=28-x; i<NUMPIXELS; i++ ) { // For each pixel...
     //Serial.println("i:"+String(i)); 
     if(i>28-x & i<30+x)
     continue;
     
     if(i>31+x & i<58-x)
     continue;
       if(i>58-x & i<61+x)
     continue;
       if(i>61+x & i<88-x)
     continue;
       if(i>88-x & i<91+x)
     continue;
       if(i>91+x & i<117-x)
     continue;
       if(i>119-x)
     continue;

  
    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
  
    
    }
    delay(DELAYVAL);
  pixels.show();
   pixels1.show();
  
}


void num2(int x){

  for(int i=26-x; i<NUMPIXELS; i++) { // For each pixel...
     if(i>28-x & i<30+x)
     continue;
     if(i>30+x & i<34+x)
     continue;
       if(i>34+x & i<55-x)
     continue;
       if(i>55-x & i<63+x)
     continue;
       if(i>63+x & i<87-x)
      continue;
        if(i>87-x & i<91+x)
     continue;
       if(i>91+x & i<115-x)
     continue;
       if(i>119-x)
     continue;
    
    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
  
    
    }
    delay(DELAYVAL);
  pixels.show();
   pixels1.show();
  
}
void num3(int x){
     for(int i=26-x; i<NUMPIXELS; i++) { // For each pixel...
     if(i>28-x & i<30+x)
     continue;
     if(i>30+x & i<34+x)
     continue;
       if(i>34+x & i<55-x)
     continue;
     if (i>55-x & i<63+x)
     continue;
     if(i>63+x & i<85-x)
     continue;
     if(i>85-x & i<90+x)
     continue;
     if(i>90+x & i<94+x)
     continue;
     if(i>94+x & i<116-x)
     continue;
     if(i>118-x)
     continue;
   

    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
  
    
    }
    delay(DELAYVAL);
  pixels.show();
   pixels1.show();
  
  }
void num4(int x){
for(int i=26-x; i<NUMPIXELS; i++) { // For each pixel...
if(i>26-x & i<32+x)
continue;
if(i>33+x & i<56-x)
continue;
if(i>56-x & i<58-x)
continue;
if(i>58-x & i<60+x)
continue;
if(i>60+x & i<63+x)
continue;
if(i>63+x & i<85-x)
continue;
if(i>89-x & i<93+x)
continue;
if(i>93+x & i<116-x)
continue;
if(i>116-x)
continue;


 
    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
  
    
    }
    delay(DELAYVAL);
  pixels.show();
   pixels1.show();
  
  
  }
  
void num5ByLek(int x)
{
  x=10-x;
  for(int i=15+x;i<20+x;i++){
    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
  }

  for(int i=19+55-x;i>=15+55-x;i--)
  {
     pixels.setPixelColor(i, pixels.Color(55,0,0 ));
  }
   for(int i=105+x;i<110+x;i++){
    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
  }
   pixels.setPixelColor(20+20-x, pixels.Color(55,0,0 ));
   pixels.setPixelColor(20+20+9+x, pixels.Color(55,0,0 ));
   pixels.setPixelColor(20+20+35+x, pixels.Color(55,0,0 ));
   pixels.setPixelColor(20+20+40+24-x, pixels.Color(55,0,0 ));

  //for(int i=15+55+x;i<20+55+x;i++){
  //  pixels.setPixelColor(i, pixels.Color(55,0,0 ));
  //}
   pixels.show();
}  
void num5(int x){
for(int i=24-x; i<NUMPIXELS; i++) { // For each pixel...
if(i>28-x & i<31+x)
continue;
if(i>31+x & i<58-x)
continue;
if(i>58-x & i<61+x)
continue;
if(i>65+x & i<84-x)
continue;
if(i>84-x & i<95+x)
continue;
if(i>95+x & i<114-x)
continue;
if(i>118-x)
continue;

   
    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
  
    
    }
    delay(DELAYVAL);
  pixels.show();
   pixels1.show();
  
  }

void num6(int x){
for(int i=25-x; i<NUMPIXELS; i++) { // For each pixel...
if(i>27-x & i<31+x)
continue;
if(i>31+x & i<35+x)
continue;
if(i>35+x & i<58-x)
continue;
if(i>58-x & i<61+x)
continue;
if(i>64+x & i<84-x)
continue;
if(i>84-x & i<88-x)
continue;
if(i>88-x & i<91+x)
continue;
if(i>91+x & i<95+x)
continue;
if(i>95+x & i<115-x)
continue;
if(i>117-x)
continue;


    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
  
    
    }
    delay(DELAYVAL);
  pixels.show();
   pixels1.show();
  
  
  }

void num7(int x){
for(int i=24-x; i<NUMPIXELS; i++) { // For each pixel...
if(i>28-x & i<31+x)
continue;  
if(i>31+x & i<35+x)
continue;
if(i>35+x & i<54-x)
continue;
if(i>54-x & i<65+x)
continue;
if(i>65+x & i<84-x)
continue;
if(i>84-x & i<95+x)
continue;
if(i>95+x & i<114-x)
continue;
if(i>114-x )
continue;

    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
  
    
    }
    delay(DELAYVAL);
  pixels.show();
   pixels1.show();
  
  
  }
  
void num8(int x){
for(int i=25-x; i<NUMPIXELS; i++) { // For each pixel...
if(i>27-x & i<31+x)
continue;
if(i>31+x & i<35+x)
continue;
if(i>35+x & i<54-x)
continue;
if(i>54-x & i<58-x)
continue; 
if(i>58-x & i<61+x)
continue;
if(i>65+x & i<84-x)
continue;
if(i>84-x & i<88-x)
continue;
if(i>88-x & i<91+x)
continue;
if(i>91+x & i<95+x)
continue;
if(i>95+x & i<115-x)
continue;
if(i>117-x)
continue;


    pixels.setPixelColor(i, pixels.Color(55,0,0 ));
    pixels1.setPixelColor(i, pixels.Color(55,0,0 ));
      // Send the updated pixel colors to the hardware.
    
  
    
    }
    delay(DELAYVAL);
  pixels.show();
   pixels1.show();
  
  }
void num9(int x){
for(int i=25-x; i<NUMPIXELS; i++) { // For each pixel...
if(i>27-x & i<31+x)
continue;
if(i>31+x & i<35+x)
continue;
if(i>35+x & i<54-x)
continue;
if(i>54-x & i<58-x)
continue; 
if(i>58-x & i<62+x)
continue;
if(i>65+x & i<84-x)
continue;
if(i>84-x & i<91+x)
continue;
if(i>91+x & i<95+x)
continue;

if(i>95+x & i<115-x)
continue;
if(i>117-x)
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
 num0(1);
 if(n>9 & n<20)
 num1(3);
 if(n>19 & n<30)
 num2(2);
 if(n>29 & n<40)
 num3(2);
 if(n>39 & n<50)
 num4(2);
 if(n>49 & n<60)
 num5(1);
 if(n>59 & n<70)
 num6(1);
 if(n>69 & n<80)
 num7(1);
 if(n>79 & n<90)
 num8(1);
 if(n>89 & n<100)
 num9(1);
o=n%10; 
  if(o==0)
 num0(7);
 if(o==1)
 num1(9);
 if(o==2)
 num2(8);
 if(o==3)
 num3(8);
 if(o==4)
 num4(8);
 if(o==5)
 num5(7);
 if(o==6)
 num6(7);
 if(o==7)
 num7(7);
 if(o==8)
 num8(7);
 if(o==9)
 num9(7);
 
  
  }
int s=24;
void shotclock(){
int shotclock14=digitalRead(8);
int shotclock24=digitalRead(9);
int stop_shotclock=digitalRead(10);
int delete_shotclock=digitalRead(11);
if (shotclock14 == 0){
  clear();
  s=14;
  
}
if (shotclock24 == 0){
  clear();
s=24;  
}

shownum(s);
if(stop_shotclock == 0){
s-=1;
delay(800);
clear();
}

delay(200);
if(s<0)
s=24;
if(delete_shotclock==0){
clear();  

s-=1;
}

  }
  

  

       
int x=0;
int y=0;
int z=-1;
void test(){
  x=(x+1)%13;
  y=(y+1)%11;
    z=(z+1)%10;
  num6(z);       
  delay(1000);
  clear();
}
int xz=0;
void loop() {
 // pixels.clear(); // Set all pixel colors to 'off' 


shotclock();
//num9(0);


//test();
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
 //Serial.println("++++++++++++++++++++++++++");

  
  }
 
  
