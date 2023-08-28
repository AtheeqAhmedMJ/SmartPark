#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
#include <LiquidCrystal.h>
LiquidCrystal lcd (2,3,10,11,12,13);//RS,EN,D4,D5,D6,D7
int trigger=7;
int echo=6;
int trigger1=5;
int echo1=4;
int trigger2=15;
int echo2=14;
int trigger3=17;
int echo3=16;
long duration;
long distance;
long duration1;
long distance1;
long duration2;
long distance2;
long duration3;
long distance3;
int count=0;
int flag=0;
void setup()
{
myservo.attach(9);  // attaches the servo on pin 9 to the servo object
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
pinMode(trigger1,OUTPUT);
pinMode(echo1,INPUT);
pinMode(trigger2,OUTPUT);
pinMode(echo2,INPUT);
pinMode(trigger3,OUTPUT);
pinMode(echo3,INPUT);
digitalWrite(trigger,LOW);
digitalWrite(trigger1,LOW);
digitalWrite(trigger2,LOW);
digitalWrite(trigger3,LOW);
Serial.begin(9600);
lcd.begin(16,2);
lcd.clear();

}
void loop()
{ 
  lcd.setCursor(1,0);
  lcd.print("SMART PARKING");
  Serial.println("SMART PARKING"); 
  digitalWrite(trigger,LOW);
  delayMicroseconds(2); // Wait for 2 microsecond(s)
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10); // Wait for 10 microsecond(s)
  digitalWrite(trigger,LOW);
  duration=pulseIn(echo,HIGH);
  distance=(duration*0.0343)/2;
  if(distance<100){
    Serial.println("Vehicle is waiting");
    //lcd.setCursor(15,0);
  //lcd.print("Vehicle is waiting");
  }else{
  Serial.println("No vehicles");
    //lcd.setCursor(15,0);
  //lcd.print("No Vehicles");
  }
  //lcd.setCursor(10,0);
  //lcd.print(distance);
  //lcd.setCursor(14,0);
  //lcd.print("cm");
  delay(100);
  
  digitalWrite(trigger1,LOW);
  delayMicroseconds(2); // Wait for 2 microsecond(s)
  digitalWrite(trigger1,HIGH);
  delayMicroseconds(10); // Wait for 10 microsecond(s)
  digitalWrite(trigger1,LOW);
  duration1=pulseIn(echo1,HIGH);
  distance1=(duration1*0.0343)/2;
  if(distance1>100){
    Serial.println("Slot 1 Parking Available");
  }else{
  Serial.println("Slot 1 Parking Filled");
  }
  //Serial.println(distance1);
  
  digitalWrite(trigger2,LOW);
  delayMicroseconds(2); // Wait for 2 microsecond(s)
  digitalWrite(trigger2,HIGH);
  delayMicroseconds(10); // Wait for 10 microsecond(s)
  digitalWrite(trigger2,LOW);
  duration2=pulseIn(echo2,HIGH);
  distance2=(duration2*0.0343)/2;
  if(distance2>100){
    Serial.println("Slot 2 Parking Available");
  }else{
  Serial.println("Slot 2 Parking Filled");
  }
  //Serial.println(distance2);
  
  digitalWrite(trigger3,LOW);
  delayMicroseconds(2); // Wait for 2 microsecond(s)
  digitalWrite(trigger3,HIGH);
  delayMicroseconds(10); // Wait for 10 microsecond(s)
  digitalWrite(trigger3,LOW);
  duration3=pulseIn(echo3,HIGH);
  distance3=(duration3*0.0343)/2;
    if(distance3>100){
    Serial.println("Slot 3 Parking Available");
  }else{
  Serial.println("Slot 3 Parking Filled");
  }
  //Serial.println(distance3);
  if (distance1>100 or distance2>100 or distance3>100){
    Serial.println("slots available");
      lcd.setCursor(0,1);
  lcd.print("slots available");
                   }else{
    Serial.println("slots are filled");
    lcd.setCursor(0,1);
  lcd.print("slots are filled");
  }
 
 
     if(distance<100&&flag==0&&(distance1>100 or distance2>100 or distance3>100))
  { for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
        myservo.write(pos);   // tell servo to go to position in variable 'pos'
   // delay(10);   // waits 15 ms for the servo to reach the position
    Serial.println("Gate is Open");
  flag=1;
  }
     }
  else if(distance>200&&flag==1)
  {
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(10);      // waits 15 ms for the servo to reach the position
    Serial.println("Gate is Closed");  
  flag=0;
    }
  }
}
                                        
                                        