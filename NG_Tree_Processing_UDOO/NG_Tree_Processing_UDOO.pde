import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

import processing.serial.*;

Minim minim;
AudioPlayer tree1;
AudioPlayer tree2;

Serial myPort;
String val;

void setup(){
  String portName = Serial.list()[0]; // calls on the port which teensy is on
  myPort = new Serial(this, portName, 2400);
  println(Serial.list()); // prints list of ports that processing can access

  //setup sound
  minim = new Minim(this);
  tree1 = minim.loadFile("tree1.aif");
  tree2 = minim.loadFile("tree2.aif");
}

void draw()
{
  if (myPort.available() > 0) {
    val = myPort.readStringUntil('\n');
    if (val!=null){
    //String[] strList = split(val, "\\t");
    int[] list = int(split(val, '\t')); // splits string into list based on tab after

   //print(val); // prints out string data from arduino
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;

    sum = sum + list[0];
    sum1 = sum1 + list[1];
    sum2 = sum2 + list[2];
      
    print(sum);
    print('\t');
    print(sum1);
    print('\t');
    print(sum2);
    print('\t');
    print('\n');
       
    if (sum1 > 500) {
      tree1.play(0);
      } else if (sum1 <500){
        tree1.pause();
      }

    if (sum2 > 500) {
      tree2.play(0);
    } else if (sum2 <500){
    }
     }
  }
}



