#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(17,19);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(17,15);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil

const int ELwire1 = 2;
const int ELwire2 = 4;
int Test = 10;

void setup()                    
{
 // cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   
   //setup ELwire
   // if Elwire not connected then serial read will be slow
  pinMode(ELwire1, OUTPUT);
  digitalWrite(ELwire1, LOW);
  pinMode(ELwire2, OUTPUT);
  digitalWrite(ELwire2, LOW);
  pinMode(Test, OUTPUT);
  digitalWrite(Test, HIGH);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_6.capacitiveSensor(30);


    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\t");
    Serial.print(total2);                  // print sensor output 2
    Serial.println("\t");
   //Serial.print("\n");

    
    if(total1 < 200) {
      digitalWrite(ELwire1, LOW);
    } else {
      digitalWrite(ELwire1, HIGH);
//      delay(1000);
//      digitalWrite(ELwire1,LOW);
//      delay(2000);
    }  
    
    if(total2 < 500) {
      digitalWrite(ELwire2, LOW);
    } else {
      digitalWrite(ELwire2, HIGH);
//      delay(1000);
//      digitalWrite(ELwire2,LOW);
//      delay(2000);
    }     
   
    delay(100);                             // arbitrary delay to limit data to serial port 
}
