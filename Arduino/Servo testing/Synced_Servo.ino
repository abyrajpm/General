#include <Servo.h>

int pos = 0;    // variable to store the servo position
int count=0;
int cycle=5;
int delays=20;

Servo myservo;  // create servo object to control a servo


void setup() 
{
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(12,OUTPUT); 
  myservo.write(0);  
   
}

void loop() 
  { 
digitalWrite(12,LOW);
while(count<=cycle) 
{  
    

servo(140);  
delay(250);
servo(0);
delay(250);
servo(140);
delay(250);
servo(0);

count++;
  if(count>cycle)
      {
      myservo.write(0); 
      //digitalWrite(12,LOW);
     
      }
} // end of count loop
  
} //end of void loop 


int servo(int val)
  {
  
 digitalWrite(12,LOW);  
    
    if(myservo.read()<val)
        {
          
        pos=myservo.read();
        digitalWrite(12,HIGH);
        while(myservo.read()<=val)
            {myservo.write(pos);
             pos++;
             delay(5);
                    if(myservo.read()==val)
                    { Serial.println("140 reached ");
                      digitalWrite(12,LOW); }             
             }
                    
                    
        }
        
     else if(myservo.read()>val)
        {
        pos=myservo.read();  
        digitalWrite(12,HIGH);
        while(myservo.read()>=val)
            {myservo.write(pos);
             pos--;
             delay(5);
                   if(myservo.read()==val)
                   {
                    Serial.println("Zero reached "); 
                    digitalWrite(12,LOW); }
             }

                    
                   
            
        }
    }  
