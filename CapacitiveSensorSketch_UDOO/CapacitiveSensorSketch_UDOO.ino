#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
//CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil

const int ELwire = 3;

void setup()                    
{
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial1.begin(9600);
   
  // setup ELwire
  pinMode(ELwire, OUTPUT);
  digitalWrite(ELwire, LOW);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    //long total2 =  cs_4_6.capacitiveSensor(30);


    Serial1.print(millis() - start);        // check on performance in milliseconds
    Serial1.print("\t");                    // tab character for debug windown spacing

    Serial1.print(total1);                  // print sensor output 1
    Serial1.println("\t");
//    Serial.print(total2);                  // print sensor output 2
//    Serial.println("\t");
//    Serial.println("\n");

    
    if(total1 < 500) {
      digitalWrite(ELwire, LOW);
    } else {
      digitalWrite(ELwire, HIGH);
      delay(1000);
      digitalWrite(ELwire,LOW);
      delay(2000);
    }     
   
    delay(100);                             // arbitrary delay to limit data to serial port 
}
