/*
  score board RECV Display v3 RGB
  gram lek
  CPU ESP32
  10/8/64
  
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2); 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


#define PIN            18
#define NUMPIXELS      267
#define BRIGHTNESS     200
#define Led_NUM        38
#define Led_MiniNum    24
int colorScoreA=0;
int colorScoreB=0;
int ClearLCD=0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // delay for half a second
unsigned int led[NUMPIXELS];

 

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
for(int i=offset+x; i<Led_NUM+offset+x; i++){  
setLedColor(i,0,0,0);  
}
}

void clearMiniNum(int digi){
int x=192;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
setLedColor(i,0,0,0);  
  }   
  }


void ClearWinDot(int digi,int x){
int z=0;
if (digi>0)
  z=5;      
for(int i=257+x+z; i<258+x+z;i++){
  setLedColor(i,0,0,0);
}
showLed();
}





void ClearWinDot1(int digi){
int x=0;  
if (digi>0)
  x=5;  
for(int i=257+x; i<258+x;i++){
  setLedColor(i,0,0,0);
}
showLed();
}

void ClearWinDot2(int digi){
int x=0;  
if (digi>0)
  x=5;  
for(int i=258+x; i<259+x;i++){
  setLedColor(i,0,0,0);
}
showLed();
}

void ClearWinDot3(int digi){
int x=0;  
if (digi>0)
  x=5;  
for(int i=259+x; i<260+x;i++){
  setLedColor(i,0,0,0);
}
showLed();
}


void ClearWinDot4(int digi){
int x=0;  
if (digi>0)
  x=5;  
for(int i=260+x; i<261+x;i++){
  setLedColor(i,0,0,0);
}
showLed();
}

void ClearWinDot5(int digi){
int x=0;  
if (digi>0)
  x=5;  
for(int i=261+x; i<262+x;i++){
  setLedColor(i,0,0,0);
}
showLed();
}




  
void num0(int digi,int r,int g,int b ){
clearBigNum(digi);  
int x=0;
int offset=digi*Led_NUM; 
for(int i=offset+x; i<Led_NUM+offset-6+x; i++){  
setLedColor(i,r,g,b);  

 
}
 showLed();
}

void num1(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
for(int i=offset+x+6; i<Led_NUM+offset-22+x; i++){  
setLedColor(i,r,g,b);  
}

showLed();
}   

void num2(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
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
for(int i=offset+x; i<Led_NUM+offset+x; i++){  
setLedColor(i,r,g,b);  
}
 showLed();
}

void num9(int digi,int r,int g,int b ){
clearBigNum(digi);
int x=0;
int offset=digi*Led_NUM;
for(int i=offset+x; i<Led_NUM+offset+x; i++){  
  if(i>offset+21+x & i<offset+27+x)
     continue;  
setLedColor(i,r,g,b);  
}
 showLed();
}


void MiniNum0(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=192;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x-4;i++){
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum1(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=192;
int offset=digi*24;
for(int i=offset+x+4; i<Led_MiniNum+offset+x-14;i++){
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum2(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=192;
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
int x=192;
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
int x=192;
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
int x=192;
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
int x=192;
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
int x=192;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x-14;i++){
setLedColor(i,r,g,b);
  }   
  showLed();
  }

void MiniNum8(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=192;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void MiniNum9(int digi,int r,int g,int b){
clearMiniNum(digi);
int x=192;
int offset=digi*24;
for(int i=offset+x; i<Led_MiniNum+offset+x;i++){
if(i>offset+13+x & i<offset+17+x)
    continue;  
setLedColor(i,r,g,b);  
  }   
  showLed();
  }

void Text (int r, int b, int g){
int x=152;
for(int i=152; i<257;i++){
if(i>191 & i<216)
  continue;
  setLedColor(i,r,g,b);
}
showLed();
}

void WinDot1(int digi,int r, int g, int b){
ClearWinDot1(digi);
int x=0;  
if (digi>0)
  x=5;  
for(int i=257+x; i<258+x;i++){
  setLedColor(i,r,g,b);
}
showLed();
}

void WinDot2(int digi,int r, int g, int b){
ClearWinDot2(digi);
int x=0;  
if (digi>0)
  x=5;  
for(int i=258+x; i<259+x;i++){
  setLedColor(i,r,g,b);
}
showLed();
}

void WinDot3(int digi,int r, int g, int b){
ClearWinDot3(digi);
int x=0;  
if (digi>0)
  x=5;  
for(int i=259+x; i<260+x;i++){
  setLedColor(i,r,g,b);
}
showLed();
}


void WinDot4(int digi,int r, int g, int b){
ClearWinDot4(digi);  
int x=0;  
if (digi>0)
  x=5;  
for(int i=260+x; i<261+x;i++){
  setLedColor(i,r,g,b);
}
showLed();
}

void WinDot5(int digi,int r, int g, int b){
  ClearWinDot5(digi);
int x=0;  
if (digi>0)
  x=5;  
for(int i=261+x; i<262+x;i++){
  setLedColor(i,r,g,b);
}
showLed();
}
 
void Win_TeamA(int n){
if (n==1)
  WinDot1(1,255,0,0);
if (n==2)
  WinDot2(1,255,0,0);
if (n==3)
  WinDot3(1,255,0,0);
if (n==4)
  WinDot4(1,255,0,0);
if (n==5)
  WinDot5(1,255,0,0);
}

void Win_TeamB(int n){
if (n==1)
  WinDot1(0,255,0,0);
if (n==2)
  WinDot2(0,255,0,0);
if (n==3)
  WinDot3(0,255,0,0);
if (n==4)
  WinDot4(0,255,0,0);
if (n==5)
  WinDot5(0,255,0,0);
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


void set(int n){
int r = 255;
int g = 0;
int b = 0;

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


int a=0;//เก็บเลขทีมA   
int x=0;//เก็บเลขทีมB
int c=0;//เก็บเลขSet
int z=0;//เก็บค่าชนะของทีมA
int v=0;//เก็บค่าชนะของทีมB

void setNum(){
int ScoreA_P = digitalRead(26); 
int ScoreA_D = digitalRead(19);
int ScoreB_P = digitalRead(5); 
int ScoreB_D = digitalRead(4);
int Set_P = digitalRead(25); 
int Set_D = digitalRead(15);
int WinA_P = digitalRead(12); 
int WinA_D = digitalRead(13);
int WinB_P = digitalRead(27); 
int WinB_D = digitalRead(14);     
if(ScoreA_P == 0){
  a+=1;
  delay(100);
  ClearLCD=1;
}
if (ScoreA_D ==0){                                                                                                                                                   
  a-=1;
  delay(100);
  if(a<0)
    a=0;
   ClearLCD=1; 
    
  }
ScoreA(a);

if(ScoreB_P == 0){
  x+=1;
  delay(100);
  ClearLCD=1;
}
if (ScoreB_D ==0){
  x-=1;
  delay(100);
  if(x<0)
    x=0;
  ClearLCD=1;  
  }
ScoreB(x);  

if(ScoreA_P==0 & ScoreA_D==0){
  colorScoreA+=1;
  if(colorScoreA>4)
    colorScoreA=0;
  
}

if(ScoreB_P==0 & ScoreB_D==0){
  colorScoreB+=1;
  if(colorScoreB>4)
    colorScoreB=0;
}

if(WinA_P==0){
  a=0;
  x=0;
}

if(WinB_P==0){
  x=0;
  a=0;
}

if(Set_P == 0){
  c+=1;
  if(c>5)
    c=5;
  delay(100);
  ClearLCD=1;
}
if (Set_D ==0){                                                                                                                                                   
  c-=1;
  delay(100);
  if(c<0)
    c=0;
  ClearLCD=1;
  }
set(c);

if(WinA_P == 0){
  z+=1;
  v+=1;
  ClearLCD=1;
  Win_TeamA(z);
  delay(100);
  if(z>5)
    z=5;
  if(v>5)
    v=5;
  ClearLCD=1;
  
}
if (WinA_D ==0){    
  z-=1;
  v-=1;
  ClearWinDot(1,z);
  ClearWinDot(0,z);
  delay(100);
  if(z<0)
    z=0;
  if(v<0)
    v=0;
     
  ClearLCD=1;  
  }
  
if(WinB_P == 0){
  z+=1;
  v+=1;
  ClearLCD=1;
  Win_TeamB(v);
  delay(100);
  if(z>5)
    z=5;
  if(v>5)
    v=5;
  ClearLCD=1;
  
}
if (WinB_D ==0){    
  z-=1;
  v-=1;
  ClearWinDot(0,z);
  ClearWinDot(1,z);
  delay(100);
  if(z<0)
    z=0;
  if(v<0)
    v=0;  
  ClearLCD=1;  
  }
    
}

void setup() {
   pixels.setBrightness(BRIGHTNESS); 
   pixels.begin(); // This initializes the NeoPixel library.
   Serial.begin(115200);
   pinMode(26, INPUT_PULLUP); //scoreA+
  pinMode(19, INPUT_PULLUP); //scoreA-
  pinMode(5, INPUT_PULLUP); //scoreB+
  pinMode(4, INPUT_PULLUP); //scoreB-
  pinMode(25, INPUT_PULLUP); //set+
  pinMode(15, INPUT_PULLUP);//set-
  pinMode(12, INPUT_PULLUP); //WInA+
  pinMode(13, INPUT_PULLUP);//WinA-
  pinMode(27, INPUT_PULLUP); //WinB+
  pinMode(14, INPUT_PULLUP);//winB-
 lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0); 
  lcd.print("  V Controller");
  lcd.setCursor(0, 1); 
  lcd.print("   BY KANDANAI");
  delay(4000);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 0);  
  lcd.print("A"); //พิมพ์ข้อความ
  lcd.setCursor(2,0);
  lcd.print(String(a)); 
  lcd.setCursor(0, 1); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("B"); //พิมพ์ข้อความ "arduinoall.com"
  lcd.setCursor(2,1);
  lcd.print(String(x));
   lcd.setCursor(11,0);
  lcd.print("SET");
  lcd.setCursor(15,0);
  lcd.print(String(c));
}






              
void loop() {
//num9(1,255,0,0); 
//test();
//MiniNum9(0,255,0,0);
Text(255,0,0);
//Win_TeamA(2);
//WinDot1(1,255,0,0);
//WinDot5(0,255,0,0);
setNum(); 
if(ClearLCD==1){
 lcd.setCursor(2,0);
  lcd.print("  ");  
   
 lcd.setCursor(2,1);
  lcd.print("  ");

  lcd.setCursor(15,0);
  lcd.print(" ");
     
 lcd.setCursor(2,0);
  lcd.print(String(a));
   lcd.setCursor(2,1);
  lcd.print(String(x));
   lcd.setCursor(15,0);
  lcd.print(String(c));
  ClearLCD=0; 
}




}
