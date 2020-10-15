//  Written by : GODSON THOMAS


#include<SoftwareSerial.h>
SoftwareSerial mySerial(0,1);  //RX,TX
void setup()
{
  //MOTOR DECLARATION
  
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  
  mySerial.begin(9600);

  //STARTING SERIAL COMMUNICATION
  
  Serial.begin(9600);
}
void loop()
{
  
  char x;
  //CHECKING AVAILABLES BY BLUETOOTH MODULE
  
  if(Serial.available()>0)
  {
    x=mySerial.read();
     

    if(x=='F') //data sent from the  controller app  on your android phone
    {
      Serial.print("FO");
        
  //FORWARD
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  
  
    }
 
if(x=='B') //data sent from the  controller app  on your android phone
  {  

    Serial.print("BA");
    
  //BACKWARD
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);

 

  }
  
if(x=='R') //data sent from the  controller app  on your android phone
  {
    
  Serial.print("RI");
  //RIGHT
 
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);

  }
  
 if(x=='L') //data sent from the  controller app  on your android phone
  {

  Serial.print("LE");
  //LEFT
  
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);  
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  
}

if(x=='S') //data sent from the  controller app  on your android phone
{
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);  
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}
}

  }
