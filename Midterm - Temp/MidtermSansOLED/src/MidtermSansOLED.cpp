/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "hue.h"
#include "wemo.h"
#include "neopixel.h"
//#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(MANUAL);

// Run the application and system concurrently in separate threads
//SYSTEM_THREAD(ENABLED);

const int PIEZOBUTTON = D14; 
int pinState;
int timerCurrent;
int timerPrior;
int maximum;
int strike;
int lastTime;
const int LEDPIN = D7;
const int YELLOWBUTTON = D6;
const int PIXELCOUNT = 12;
const int NEOPIXEL = D18;

Adafruit_NeoPixel pixel(PIXELCOUNT, SPI1, WS2812B);

void setup() {
  // Put initialization like pinMode and begin functions here
  Serial.begin(9600);
waitFor(Serial.isConnected,10000);
Serial.println("up and running\n");
pinMode(PIEZOBUTTON,INPUT_PULLDOWN);


WiFi.on();
 WiFi.clearCredentials(); // prevent from connecting to DDCIOT
 WiFi.setCredentials("IoTNetwork");
 // If network requires a password
 // setCredentials ( const "" NetworkName ", " Password ");

 WiFi.connect();
 while(WiFi.connecting()) {
 Serial.printf(".");
 }
 Serial.printf("\n\n");

delay(10000);
setHue(4, true, HueGreen, 255, 255);
pinMode (LEDPIN,OUTPUT);
pinMode (YELLOWBUTTON,INPUT);
pinMode (NEOPIXEL, OUTPUT);  //Tell the D18 pin to function on output mode

    // this block gets the neopixels running with begin turning them on.  A basic brightness default, and pixel.show
    // to actually allow them to display.
    pixel.begin();
    pixel.setBrightness(30);
    pixel.show();

}


void loop() {

// setting the inital time state for millis
timerCurrent = millis();

// the piezo sensor requires analog as it can give more than two values.
// pinState records the current input information from the sensor.
//pinState = analogRead(PIEZOBUTTON);


// outputs a descriptive sentence and then the current value of pinState.
//Serial.printf("Hit Detected with force: %i \n", pinState);

//digitalWrite (PIEZOBUTTON, pinState);

//bool setHue(int lightNum, bool HueOn, int HueColor=HueBlue, int HueBright=255, int HueSat=255);


// Takes the value of Maximum at zero and compares it every 250 milliseconds to determine what the higest value recorded
// during that time period was.  
maximum = 0;
lastTime = millis();
while((millis() - lastTime)< 250) {
    strike = analogRead(PIEZOBUTTON);
    if(maximum<strike) {
        maximum = strike;
    }
}
Serial.printf("Armour Sensor Value = %i\n",maximum);

//if (timerCurrent-timerPrior<=500){

  // Average baseline for the sensor is about 25.  Any significant change in pressure shoul push the value above 50.
  if(maximum>50) {
    //delay(1000);
    setHue(4, true, HueRed, 255, 255);
    //delay(1000);
    switchON(0);
    switchON(3);
    switchON(4);
    delay(1000);
    switchOFF(0);
    switchOFF(3);
    switchOFF(4);
    //delay(1000);
    // SwitchON and OFF activate and deactivat the HUE outlets lighting the arious objects in the room.  While they
    // initially are using a delay this will be replaced in later version.
    digitalWrite(D7, HIGH);
    delay(1000);
  } else {
    //delay(1000);
    setHue(4, true, HueGreen, 255, 255);
    digitalWrite(D7, LOW);



    //timerCurrent=timerPrior;
  }



pinState = digitalRead(YELLOWBUTTON);
Serial.printf("The value of the button is %i \n", pinState);

  if (pinState<1){
    digitalWrite (D7, HIGH);
  }
  //digitalWrite(D7, LOW);
  //delay(10000);
  //digitalWrite(D7, HIGH);
  //delay(10000);

    pixel.setPixelColor(3, 100, 100, 100); // selects pixel and defines its color with RGB values.

    digitalWrite(D18, HIGH);  // Activate pin D18 

    pixel.clear();            // Clear refreshes all values to default off
    pixel.show();             // Show activates the new cleared values.
  delay(1000);

}
