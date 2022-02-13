#include <Arduino.h>
#include <pinDefinitions.h>

#include <Bounce2.h>



bool Calibrated = FALSE;

 //instantiate debounce buttons
  Bounce originB = Bounce();
  Bounce jogMinus = Bounce();
  Bounce jogPlus = Bounce();
  Bounce cycleStartB = Bounce();
  

void setup() {
  Serial.begin(9600);
  //setup buttons
  originB.attach( BOUNCE_PIN ,  INPUT_PULLUP ); // USE INTERNAL PULL-UP
  originB.interval(5); // interval in ms

  jogMinus.attach( BOUNCE_PIN ,  INPUT_PULLUP ); // USE INTERNAL PULL-UP
  jogMinus.interval(5); // interval in ms

  jogPlus.attach( BOUNCE_PIN ,  INPUT_PULLUP ); // USE INTERNAL PULL-UP
  jogPlus.interval(5); // interval in ms

  cycleStartB.attach( BOUNCE_PIN ,  INPUT_PULLUP ); // USE INTERNAL PULL-UP
  cycleStartB.interval(5); // interval in ms
}

void loop() {
  //which mode are we in?

  //calibrate
  //jog x+/- with UI, set origin
  calibrate();

  //get design instructions
  //what is coil pitch, in inches?
  //how many turns??
  //which direction to translate?

  //confirm design instructions
  // - display settings
  // - are they correct? -> "cycle start"

  //execute design instructions
  //turn A,X axis simultaneously
}


void calibrate(){
  Serial.println("Calibration Mode: Set X Origin")
  while(!Calibrated){
    originB.update();

  }
}

