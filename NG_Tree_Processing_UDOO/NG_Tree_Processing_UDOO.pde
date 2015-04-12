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
float vol = 0.0;

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
    float sum1 = 0.0;
    float sum2 = 0;

    //sum = sum + list[0];
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
      float m = map(sum1, 0.0, 3500.0, -60.0, 0.0);
      println(m);
      tree1.setGain(m);
      if (tree1.isPlaying()==false){
      tree1.play(0);
      } else if (sum1 <500){
        tree1.pause();
      }
    }

    if (sum2 > 500) {
      float m2 = map(sum2, 0.0, 1500.0, -60.0, 0.0);
      println(m2);
      tree2.setGain(m2);
      if (tree2.isPlaying()==false){
      tree2.play(0);
    } else if (sum2 <500){
     // tree2.pause();
    }
     }
    }
  }
}



