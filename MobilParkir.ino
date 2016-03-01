#include <ultrasonic.h>

#define LEDHijau 9
#define LEDKuning 10
#define LEDMerah 11
#define Mode1 A0
#define Mode2 A1
#define Mode3 A2
#define Mode4 A3
#define Mode5 A4
#define Mode6 A5
#define buzzer 12

ultrasonic ultrasoniku(7,8);
double jarak;

double jarakHijau = 30; // jarak aman 30 CM
double jarakKuning;
double jarakMerah;

void setup(){
  Serial.begin(115200);
  
  pinMode(LEDHijau, OUTPUT);
  pinMode(LEDKuning, OUTPUT);
  pinMode(LEDMerah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(Mode1, INPUT_PULLUP);
  pinMode(Mode2, INPUT_PULLUP);
  pinMode(Mode3, INPUT_PULLUP);
  pinMode(Mode4, INPUT_PULLUP);
  pinMode(Mode5, INPUT_PULLUP);
  pinMode(Mode6, INPUT_PULLUP);
  
  tone(buzzer,2000,500);
}

void loop(){
  
  
  
  if(digitalRead(Mode1) == LOW){
    jarakHijau = 30; //CM
  }
  if(digitalRead(Mode2) == LOW){
    jarakHijau = 40; //CM
  }
  if(digitalRead(Mode3) == LOW){
    jarakHijau = 50; //CM
  }
  if(digitalRead(Mode4) == LOW){
    jarakHijau = 60; //CM
  }
  if(digitalRead(Mode5) == LOW){
    jarakHijau = 70; //CM
  }
  if(digitalRead(Mode6) == LOW){
    jarakHijau = 80; //CM
  }
  
  jarakKuning = jarakHijau * 2 / 3 ;
  jarakMerah = jarakHijau * 1 / 3;

  jarak = ultrasoniku.baca(CM);
  //Serial.print(jarak);
  
  if(jarak <= jarakMerah){
    
    digitalWrite(LEDHijau, LOW);
    digitalWrite(LEDKuning, LOW);
    digitalWrite(LEDMerah, HIGH);
    tone(buzzer,2000,500);
    //Serial.println(" Merah");
  
  }else if(jarak > jarakMerah && jarak <= jarakKuning){
    
    digitalWrite(LEDHijau, LOW);
    digitalWrite(LEDKuning, HIGH);
    digitalWrite(LEDMerah, LOW);
    //Serial.println(" Kuning");
    
  }else if(jarak > jarakKuning && jarak <= jarakHijau){
    
    digitalWrite(LEDHijau, HIGH);
    digitalWrite(LEDKuning, LOW);
    digitalWrite(LEDMerah, LOW);
    //Serial.println(" Hijau");
  }
  else{
    
    digitalWrite(LEDHijau, LOW);
    digitalWrite(LEDKuning, LOW);
    digitalWrite(LEDMerah, LOW);
    //Serial.println();
    
  }
  
  delay(100);
}

