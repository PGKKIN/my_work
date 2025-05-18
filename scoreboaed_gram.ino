/*
  score board RECV Display v3 RGB
  gram lek
  CPU ESP32
  10/8/64
  
 */
#include <WiFi.h>
#include<esp_now.h> 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


#define PIN            15
#define NUMPIXELS      410
#define BRIGHTNESS     150
#define Led_NUM        38
#define Led_MiniNum    24
#define BELL_PIN       26
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // delay for half a second
unsigned int led[NUMPIXELS];
//----Data Show int Scoreboard-----------------
byte min_s=0;
byte sec_s=0;
byte scoreA=0;
byte scoreB=0;
byte pt=0;
boolean arrow_a=true;
byte period=0;
byte foulA=0;
byte foulB=0;
byte typeColor=0;
byte colorScoreA=0;
byte colorScoreB=0;
byte colorTime=0;
//---------------------------
typedef struct data_struct {
  byte min_s;
  byte sec_s;
  byte ms100;
  byte pt;
  byte score_a;
  byte score_b;
  byte arrow_a;
  byte quarter;
  byte foul_a;
  byte foul_b;
  byte typecolor;
  byte colorScoreA;
  byte colorScoreB;
  byte colorTime=0;
  byte bell;
} data_struct;
//Create a struct_message called myData
data_struct sdata;
void setTime(int m,int s)
{
  min_s=m;
  sec_s=s;  
}

void setScoreA(byte score)
{
  scoreA=score;  
}

void setScoreB(byte score)
{
  scoreA=score;  
}

void setPeriod(byte p)
{
   period=p; 
}

void setArrowA(bool b)
{
  arrow_a=b;
}

void setFoulA(byte a)
{
   foulA=a; 
}
void setFoulB(byte b)
{
   foulA=b; 
}


 

void setLedColor(int i,int r,int g,int b)
{
  if(i<NUMPIXELS){
    unsigned int c= pixels.Color(r,g,b);
    led[i]=c;
  }
}
//-----------------------------------
// clear all led
//-----------------------------------
void clearLed()
{
  for(int i=0;i<NUMPIXELS;i++)
  {  led[i]=0;
      pixels.setPixelColor(i, 0);  
  }
  //pixels.show();      
}
//-------------------------------------
// show All Led
//-------------------------------------
void showLed()
{
  for(int i=0;i<NUMPIXELS;i++)
  {  
     pixels.setPixelColor(i, led[i]);
  }
  pixels.show(); 
  delay(delayval);
    
}
//---------------------------------------------------------------------
//-----Code -----------------------------------------------------------





//---------------------------------------------------------------------

void test()
{
   clearLed();
   for(int i=0;i<NUMPIXELS;i++)
  {  
      setLedColor(i,255,0,0);
      showLed();
      delay(10); 
  }     
}

void clearBigNum (int digi){
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+x; i<Led_NUM+offset+x; i++){  
setLedColor(i,0,0,0);  
}
}

void clearNum100(int digi){
int x=0;
int offset=digi*76;
if(digi>0)
  x+=10;
for(int i=offset+x; i<Led_NUM+offset+x; i++){
  if(i>9+offset+x)
  continue;
setLedColor(i,0,0,0);    
  }
}


void clearMiniNum(int digi){
int x=332;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
setLedColor(i,0,0,0);  
  }   
  }

void num(int i,int no,int r,int g,int b)
{
   if(i==0)
   num0(i,r,g,b);
   else if(i==1)
   num1(i,r,g,b);
   else if(i==2)
    num2(i,r,g,b);
   else if(i==3)
    num3(i,r,g,b);
   else if(i==4)
    num4(i,r,g,b);
   else if(i==5)
    num5(i,r,g,b);
   else if(i==6)
    num6(i,r,g,b);
   else if(i==7)
    num7(i,r,g,b);
   else if(i==18)
    num8(i,r,g,b);
   else if(i==9)
    num9(i,r,g,b);

   
}
void test_NUM(){
for(int b=0; b<9; b++){  
  for(int a=0; a<8; a++){  
  num(b,a,50,0,0);
  delay(2000);
  }
clearLed();  
}
}
void num0(int digi,int r,int g,int b ){
clearBigNum(digi);  
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;     
for(int i=offset+x; i<Led_NUM+offset-6+x; i++){  
setLedColor(i,r,g,b);  

 
}
 showLed();
}

void num1(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+x+6; i<Led_NUM+offset-22+x; i++){  
setLedColor(i,r,g,b);  
}

showLed();
}   

void num2(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+x; i<Led_NUM+offset+x; i++){  
  if(i>offset+10+x & i<offset+16+x)
    continue;
  if(i>offset+26+x & i<offset+32+x)
    continue;  
setLedColor(i,r,g,b);  
} 
showLed();
}

void num3(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+x; i<Led_NUM+offset+x; i++){
   if(i>offset+21+x & i<offset+32+x)
     continue; 
setLedColor(i,r,g,b);      
}
showLed();  
}

void num4(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+6+x; i<Led_NUM+offset+x; i++){ 
  if(i>offset+15+x & i<offset+27+x) 
     continue;
setLedColor(i,r,g,b);       
}
showLed();
}

void num5(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+x; i<Led_NUM+offset+x; i++){ 
 if(i>offset+5+x & i<offset+11+x)
     continue;
 if(i>offset+21+x & i<offset+27+x)
     continue;
setLedColor(i,r,g,b);       
}
showLed();
}

void num6(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+x; i<Led_NUM+offset+x; i++){ 
  if(i>offset+5+x & i<offset+11+x)
     continue;
setLedColor(i,r,g,b);       
}
showLed();
}

void num7(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+x; i<Led_NUM+offset+x; i++){ 
  if(i>offset+15+x)
     continue;
setLedColor(i,r,g,b);       
}
showLed();
}

void num8(int digi,int r,int g,int b ){
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+x; i<Led_NUM+offset+x; i++){  
setLedColor(i,r,g,b);  
}
 showLed();
}

void num9(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
if(digi>-1)
  x+=10;
if(digi>1)
  x+=10; 
if(digi>5)
  x+=2;
for(int i=offset+x; i<Led_NUM+offset+x; i++){  
  if(i>offset+21+x & i<offset+27+x)
     continue;  
setLedColor(i,r,g,b);  
}
 showLed();
}

void num100(int digi,int r,int g,int b){
clearNum100(digi);
int x=0;
int offset=digi*76;
if(digi>0)
  x+=10;
for(int i=offset+x; i<Led_NUM+offset+x; i++){
  if(i>9+offset+x)
  continue;
setLedColor(i,r,g,b);    
  }
showLed();
}

void MiniNum0(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x-4;i++){
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum1(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x+4; i<Led_MiniNum+offset+x-14;i++){
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum2(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
if(i>offset+6+x & i<offset+10+x)
    continue;
  if(i>offset+17+x & i<offset+20+x)
    continue;   
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum3(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
if(i>offset+13+x & i<offset+20+x)
    continue;
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum4(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x+4; i<Led_MiniNum+offset+x;i++){
if(i>offset+9+x & i<offset+14+x)
    continue;
if(i>offset+13+x & i<offset+17+x)
  continue;       
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum5(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
if(i>offset+3+x & i<offset+7+x)
    continue;
  if(i>offset+13+x & i<offset+17+x)
    continue;   
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum6(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
if(i>offset+3+x & i<offset+7+x)
    continue;  
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum7(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x-14;i++){
setLedColor(i,r,g,b);
  }   
  showLed();
  }

void MiniNum8(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum9(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=332;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
if(i>offset+13+x & i<offset+17+x)
    continue;  
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void clearleft(){
int x=326;
for(int i=x; i<NUMPIXELS-78;i++){  
setLedColor(i,0,0,0);
}
  }



void clearright(){  
int x=404;
for(int i=x; i<NUMPIXELS;i++){
setLedColor(i,0,0,0);  
}
}

void right(int r,int g,int b){
clearleft();
int x=404;
for(int i=x; i<NUMPIXELS;i++){
setLedColor(i,r,g,b);  
}
showLed();
  }  
 
void left(int r,int g,int b){
clearright();
int x=326;
for(int i=x; i<NUMPIXELS-78;i++){  
setLedColor(i,r,g,b);
}
showLed();
  }

 

void Point(int r,int b,int g){
int x=248;
for(int i=x; i<250;i++){
setLedColor(i,r,g,b);  
}
showLed();
  }
   
void ScoreA(int n){  
int c;
c=n/100;
int o;
int r = 255;
int g = 0;
int b = 0;
if (colorScoreA==0){
r = 80;
g = 255;
b = 0;
}
if (colorScoreA==1){
r = 255;
g = 0;
b = 0;
}
if (colorScoreA==2){
r = 255;
g = 255;
b = 0;
}
if (colorScoreA==3){
r = 0;
g = 80;
b = 255;
}
if (colorScoreA==4){
r = 80;
g = 0;
b = 255;
}
 if(n<10)
 num0(0,r,g,b);
 if(n>9 & n<20 )
 num1(0,r,g,b);
 if(n>19 & n<30 )
 num2(0,r,g,b);
 if(n>29 & n<40 )
 num3(0,r,g,b);
 if(n>39 & n<50 )
 num4(0,r,g,b);
 if(n>49 & n<60 )
 num5(0,r,g,b);
 if(n>59 & n<70 )
 num6(0,r,g,b);
 if(n>69 & n<80 )
 num7(0,r,g,b);
 if(n>79 & n<90 )
 num8(0,r,g,b);
 if(n>89 & n<99 )
 num9(0,r,g,b);
 if(c==1)
 num100(0,r,g,b);

if(n>99 & n<109)
 num0(0,r,g,b);
 if(n>109 & n<120 )
 num1(0,r,g,b);
 if(n>119 & n<130 )
 num2(0,r,g,b);
 if(n>129 & n<140 )
 num3(0,r,g,b);
 if(n>139 & n<150 )
 num4(0,r,g,b);
 if(n>149 & n<160 )
 num5(0,r,b,g);
 if(n>159 & n<170 )
 num6(0,r,g,b);
 if(n>169 & n<180 )
 num7(0,r,g,b);
 if(n>179 & n<190 )
 num8(0,r,g,b);
 if(n>189 & n<200 )
 num9(0,r,g,b);
 
o=n%10; 
  if(o==0)
 num0(1,r,g,b);
 if(o==1)
 num1(1,r,g,b);
 if(o==2)
 num2(1,r,g,b);
 if(o==3)
 num3(1,r,g,b);
 if(o==4)
 num4(1,r,g,b);
 if(o==5)
 num5(1,r,g,b);
 if(o==6)
 num6(1,r,g,b);
 if(o==7)
 num7(1,r,g,b);
 if(o==8)
 num8(1,r,g,b);
 if(o==9)
 num9(1,r,g,b);
 
  
  }


void ScoreB(int n){
int c;
c=n/100;
int o;
int r = 255;
int g = 0;
int b = 0;
if (colorScoreB==0){
r = 80;
g = 255;
b = 0;
}
if (colorScoreB==1){
r = 255;
g = 0;
b = 0;
}
if (colorScoreB==2){
r = 255;
g = 255;
b = 0;
}
if (colorScoreB==3){
r = 0;
g = 80;
b = 255;
}
if (colorScoreB==4){
r = 80;
g = 0;
b = 255;
}
 if(n<10)
 num0(2,r,g,b);
 if(n>9 & n<20 )
 num1(2,r,g,b);
 if(n>19 & n<30 )
 num2(2,r,g,b);
 if(n>29 & n<40 )
 num3(2,r,g,b);
 if(n>39 & n<50 )
 num4(2,r,g,b);
 if(n>49 & n<60 )
 num5(2,r,g,b);
 if(n>59 & n<70 )
 num6(2,r,g,b);
 if(n>69 & n<80 )
 num7(2,r,g,b);
 if(n>79 & n<90 )
 num8(2,r,g,b);
 if(n>89 & n<99 )
 num9(2,r,g,b);
 if(c==1)
 num100(1,r,g,b);
if(n>99 & n<109)
 num0(2,r,g,b);
 if(n>109 & n<120 )
 num1(2,r,g,b);
 if(n>119 & n<130 )
 num2(2,r,g,b);
 if(n>129 & n<140 )
 num3(2,r,g,b);
 if(n>139 & n<150 )
 num4(2,r,g,b);
 if(n>149 & n<160 )
 num5(2,r,g,b);
 if(n>159 & n<170 )
 num6(2,r,g,b);
 if(n>169 & n<180 )
 num7(2,r,g,b);
 if(n>179 & n<190 )
 num8(2,r,g,b);
 if(n>189 & n<200 )
 num9(2,r,g,b);
 
o=n%10; 
  if(o==0)
 num0(3,r,g,b);
 if(o==1)
 num1(3,r,g,b);
 if(o==2)
 num2(3,r,g,b);
 if(o==3)
 num3(3,r,g,b);
 if(o==4)
 num4(3,r,g,b);
 if(o==5)
 num5(3,r,g,b);
 if(o==6)
 num6(3,r,g,b);
 if(o==7)
 num7(3,r,g,b);
 if(o==8)
 num8(3,r,g,b);
 if(o==9)
 num9(3,r,g,b);
 
  
  }

void minute(int n){
int o;
int r = 255;
int g = 0;
int b = 0;
if (colorTime==0){
r = 255;
g = 255;
b = 255;
}
if (colorTime==1){
r = 234;
g = 71;
b = 148;
}
if (colorTime==2){
r = 227;
g = 236;
b = 117;
} 
 if(n<10)
 num0(4,r,g,b);
 if(n>9 & n<20 )
 num1(4,r,g,b);
 if(n>19 & n<30 )
 num2(4,r,g,b);
 if(n>29 & n<40 )
 num3(4,r,g,b);
 if(n>39 & n<50 )
 num4(4,r,g,b);
 if(n>49 & n<60 )
 num5(4,r,g,b);
 if(n>59 & n<70 )
 num6(4,r,g,b);
 if(n>69 & n<80 )
 num7(4,r,g,b);
 if(n>79 & n<90 )
 num8(4,r,g,b);
 if(n>89 & n<99 )
 num9(4,r,g,b);
 o=n%10; 
  if(o==0)
 num0(5,r,g,b);
 if(o==1)
 num1(5,r,g,b);
 if(o==2)
 num2(5,r,g,b);
 if(o==3)
 num3(5,r,g,b);
 if(o==4)
 num4(5,r,g,b);
 if(o==5)
 num5(5,r,g,b);
 if(o==6)
 num6(5,r,g,b);
 if(o==7)
 num7(5,r,g,b);
 if(o==8)
 num8(5,r,g,b);
 if(o==9)
 num9(5,r,g,b);  
  }

void second(int n){
int o;
int r = 255;
int g = 0;
int b = 0;
if (colorTime==0){
r = 255;
g = 255;
b = 255;
}
if (colorTime==1){
r = 234;
g = 71;
b = 148;
}
if (colorTime==2){
r = 227;
g = 236;
b = 117;
} 
 if(n<10)
 num0(6,r,g,b);
 if(n>9 & n<20 )
 num1(6,r,g,b);
 if(n>19 & n<30 )
 num2(6,r,g,b);
 if(n>29 & n<40 )
 num3(6,r,g,b);
 if(n>39 & n<50 )
 num4(6,r,g,b);
 if(n>49 & n<60 )
 num5(6,r,g,b);
 if(n>59 & n<70 )
 num6(6,r,g,b);
 if(n>69 & n<80 )
 num7(6,r,g,b);
 if(n>79 & n<90 )
 num8(6,r,g,b);
 if(n>89 & n<99 )
 num9(6,r,g,b);
 o=n%10; 
  if(o==0)
 num0(7,r,g,b);
 if(o==1)
 num1(7,r,g,b);
 if(o==2)
 num2(7,r,g,b);
 if(o==3)
 num3(7,r,g,b);
 if(o==4)
 num4(7,r,g,b);
 if(o==5)
 num5(7,r,g,b);
 if(o==6)
 num6(7,r,g,b);
 if(o==7)
 num7(7,r,g,b);
 if(o==8)
 num8(7,r,g,b);
 if(o==9)
 num9(7,r,g,b);    
  }
void FoulA(int n){
int r = 255;
int g = 0;
int b = 0;

if (n==0){
r = 51;
g = 170;
b = 174;
}  
if (n==1){
r = 51;
g = 170;
b = 174;;
}  
if (n==2){
r = 51;
g = 170;
b = 174;
}  
if (n==3){
r = 51;
g = 170;
b = 174;
}  
if (n==4){
r = 226;
g = 239;
b = 63;
}

if (n==5){
r = 255;
g = 54;
b = 38;
}
if(n==0)
MiniNum0(0,r,g,b);

if(n==1)
MiniNum1(0,r,g,b);

if(n==2)
MiniNum2(0,r,g,b);

if(n==3)
MiniNum3(0,r,g,b);

if(n==4)
MiniNum4(0,r,g,b);

if(n==5)
MiniNum5(0,r,g,b);  
  }

void FoulB(int n){
int r = 255;
int g = 0;
int b = 0;
if (n==0){
r = 51;
g = 170;
b = 174;
}  
if (n==1){
r = 51;
g = 170;
b = 174;;
}  
if (n==2){
r = 51;
g = 170;
b = 174;
}  
if (n==3){
r = 51;
g = 170;
b = 174;
}  
if (n==4){
r = 226;
g = 239;
b = 63;
}

if (n==5){
r = 255;
g = 54;
b = 38;
}
if(n==0)
MiniNum0(2,r,g,b);

if(n==1)
MiniNum1(2,r,g,b);

if(n==2)
MiniNum2(2,r,g,b);

if(n==3)
MiniNum3(2,r,g,b);

if(n==4)
MiniNum4(2,r,g,b);

if(n==5)
MiniNum5(2,r,g,b);  
  }

void Quarter(int n){
int r = 255;
int g = 0;
int b = 0;
if (typeColor==0){
r = 0;
g = 125;
b = 125;
}  
if(n==0)
MiniNum0(1,r,g,b);

if(n==1)
MiniNum1(1,r,g,b);

if(n==2)
MiniNum2(1,r,g,b);

if(n==3)
MiniNum3(1,r,g,b);

if(n==4)
MiniNum4(1,r,g,b);
  
  }

void side(int n){
int r = 255;
int g = 0;
int b = 0;
if (colorTime==0){
r = 255;
g = 255;
b = 255;
}
if (colorTime==1){
r = 234;
g = 71;
b = 148;
}
if (colorTime==2){
r = 227;
g = 236;
b = 117;
}  
if(n==0)
left(r,g,b);
else{
right(r,g,b);  
} 
}
 
void ms(int n){
int r = 255;
int g = 0;
int b = 0;
if (colorTime==0){
r = 255;
g = 255;
b = 255;
}
if (colorTime==1){
r = 234;
g = 71;
b = 148;
}
if (colorTime==2){
r = 227;
g = 236;
b = 117;
} 
if(n==0)
Point(r,g,b);  
  }  

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&sdata, incomingData, sizeof(sdata));
  
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("min_s: ");
  Serial.println(sdata.min_s);
  Serial.print("sec: ");
  Serial.println(sdata.sec_s);
  Serial.println();
  colorTime=sdata.colorTime;
  colorScoreA=sdata.colorScoreA;
  colorScoreB=sdata.colorScoreB;
  minute(sdata.min_s);
  second(sdata.sec_s);
  ScoreA(sdata.score_a);
  ScoreB(sdata.score_b);
  FoulA(sdata.foul_a);
  FoulB(sdata.foul_b);
  Quarter(sdata.quarter);
  side(sdata.arrow_a);
  ms(sdata.pt);
  if(sdata.bell==1)
    digitalWrite(BELL_PIN,HIGH);
  else
    digitalWrite(BELL_PIN,LOW);  
    
 
  

} 
void setup() {
   pixels.setBrightness(BRIGHTNESS); 
   pixels.begin(); // This initializes the NeoPixel library.
   Serial.begin(115200);
  //Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  //Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
  pinMode(BELL_PIN,OUTPUT);
}

              
void loop() {
//num0(1,0,255,0);  
test();
//num100(1,50,0,0);
//test_NUM();
//ScoreA(186);
//ScoreB(141);
//minute(9);
//second(12);
//FoulA(4);
//FoulB(3);
//side(1);
//Quarter(3);
//ms(0);
}
