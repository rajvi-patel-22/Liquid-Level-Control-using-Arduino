#include <CapacitiveSensor.h>


//#include <CapSense.h>

int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int output = 6;
int mpin = 3;
int button = 13;
int buttonState = 0;

unsigned int frequency = 220;

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil

void setup()                    
{
  
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(button, OUTPUT);
pinMode(mpin, OUTPUT);

   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pinMode(output,OUTPUT);

}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    
  
    // buttonState = digitalRead(button);

 
 // if (buttonState == HIGH) 
 // {
     

    Serial.println(total1);                  // print sensor output 1
    
    
    delay(100);                             // arbitrary delay to limit data to serial port 
    digitalWrite(mpin, HIGH);
    if(total1 > 0 && total1<300)
    {
      setColor(255, 255, 0); // red
            if(digitalRead(13) == LOW)
            {

      digitalWrite(mpin, HIGH);
            }
            else
            {
              digitalWrite(mpin, HIGH);
            }
      //delay(2000);
      delay(100);
    }
    if(total1 > 400 && total1 < 700)
    {
      setColor(0, 255, 255);
      if(digitalRead(13) == LOW)
      {
            digitalWrite(mpin, LOW);
// green
      delay(100);
      }
    }
    if(total1>800)
    {
       setColor(255, 0, 255);
      
      digitalWrite(mpin, LOW);
      
      delay(100);
    }
    if(total1>900)
    {
      setColor(255, 0, 255); // blue
      
      digitalWrite(mpin, LOW);
      
      delay(100);
    }
    if(total1>1300)
    {
    tone(output, frequency, 500);
    digitalWrite(mpin, LOW);
   delay(100);
    }
 /*   digitalWrite(mpin, HIGH);
    delay(2000);
    digitalWrite(mpin, LOW);
    delay(2000);
  */  
//}
  
/*  else 
  {
    Serial.println("BUTTON IS OFF");
//    break;
//Serial.end();
  }
 */
}

 

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
red = 255 - red;
green = 255 - green;
blue = 255 - blue;
#endif
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}



