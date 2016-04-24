#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3 ,2);
int buttonPin1 = 14;
int buttonPin2 = 15;
int buttonPin3 = 16;
int buttonPin4  = 17;
const int sensorPin = A4; // temp lead from spa heater
const float baselineTemp = 20; // if temp is below relay turns on
int ledPin6  = 6;
int ledPin7  = 7;
int ledPin8 =8;
int ledPin9 = 9;
int ledPin10 = 10;
int lightsOn = 0;
int lightsOn1=0;
int lightsOn2=0;
int lightsOn3=0;// is the switch on = 1 or off = 0
int switchState=0;
int oldSwitchState=0;
int switchState1=0;
int oldSwitchState1=0;
int switchState2=0;
int oldSwitchState2=0;
int switchState3=0;
int oldSwitchState3=0;


void setup() {
  lcd.begin(16,2);
  lcd.clear();
  
  
  
  
  Serial.begin(9600);
pinMode  (buttonPin1,INPUT);
pinMode  (  buttonPin2,INPUT);
pinMode ( buttonPin3 ,INPUT);
pinMode( buttonPin4 ,INPUT);
pinMode( sensorPin ,INPUT);
pinMode(  ledPin6 ,OUTPUT);
pinMode ( ledPin7,OUTPUT);
pinMode  (ledPin8,OUTPUT);
pinMode  (  ledPin9,OUTPUT);
pinMode  (ledPin10,OUTPUT);
  
  

}

void loop() {
  
  int sensorVal = analogRead(A4);// love o meter example
  Serial.print("sensor Value"    );
  
  Serial.print(sensorVal);
  float voltage = (sensorVal / 7.6-2);
  Serial.print(",Volts:  ");
  Serial.print(voltage/7.6-2)*6+5;
  Serial.print(", degrees C  ");
  lcd.setCursor(0,0);
    lcd.print(" SET POINT 102*");
    lcd.setCursor(0,1);
    lcd.print("ACTUAL  ");
    lcd.print(        voltage /7.6-2);
  float temperature =(voltage /7.6-2)*6+5 ;
  Serial.println(temperature);
   
  if (temperature < baselineTemp + 2){
    digitalWrite(10,LOW);
  
   
    
  }
  
  switchState = digitalRead(14); // read the pushButton State
  if (switchState != oldSwitchState) // catch change
  {
    oldSwitchState = switchState;
    if (switchState == HIGH)
    {
      // toggle
      lightsOn = !lightsOn;
    }
  }

  if(lightsOn)
  {
     digitalWrite(6, HIGH);
     digitalWrite(7,LOW);// set the LED on
   } else {
      digitalWrite(6, LOW);
      digitalWrite(7,HIGH);// set the LED off
    
  
  switchState1 = digitalRead(15); // read the pushButton State
  if (switchState1 != oldSwitchState1) // catch change
  {
    oldSwitchState1 = switchState1;
    if (switchState1 == HIGH)
    {
      // toggle
      lightsOn1 = !lightsOn1;
    }
  }

  if(lightsOn1)
  {
     digitalWrite(7, HIGH);
     digitalWrite(6,LOW);// set the LED on
   } else {
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH); 
      
      switchState2 = digitalRead(16); // read the pushButton State
  if (switchState2 != oldSwitchState2) // catch change
  {
    oldSwitchState2 = switchState2;
    if (switchState2 == HIGH)
    {
      // toggle
      lightsOn2 = !lightsOn2;
    }
  }

  if(lightsOn2)
  {
     digitalWrite(8, HIGH);
     digitalWrite(9, LOW);// set the LED on
   } else {
      digitalWrite(8, LOW); 
      digitalWrite(9, HIGH);
      // set the LED off
      
       switchState3 = digitalRead(17);
       if (switchState3 != oldSwitchState3) // catch change
  {
    oldSwitchState3 = switchState3;
    if (switchState3 == HIGH)
    {
      // toggle
      lightsOn3 = !lightsOn3;
    }
  }

  if(lightsOn3)
  {
     digitalWrite(9, HIGH);
     digitalWrite(8, LOW);// set the LED on
   } else {
      digitalWrite(9, LOW); 
      digitalWrite(8, HIGH);
      delay(500);
     
      // set the LED off
    }
   
    }
   }
}
}
