#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
int ELwire1 = 3;
int ELwire2 = 9;

void setup()                    
{
   //cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial1.begin(2400);
   pinMode(ELwire1, OUTPUT);
   digitalWrite(ELwire1, LOW);
   pinMode(ELwire2, OUTPUT);
   digitalWrite(ELwire2, LOW);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_6.capacitiveSensor(30);
//    long total3 =  cs_4_8.capacitiveSensor(30);

    Serial1.print(millis() - start);        // check on performance in milliseconds
    Serial1.print("\t");                    // tab character for debug windown spacing

    Serial1.print(total1);                  // print sensor output 1
    Serial1.print("\t");
    Serial1.print(total2);                  // print sensor output 2
    Serial1.println("\t");
//    Serial1.println(total3);                // print sensor output 3

    delay(1);                             // arbitrary delay to limit data to Serial1 port 

    if(total1 < 500) {
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

}
