/* This is sample code for the DS3502 high voltage digital potentiometer.
It will continuously cycle through the full spectrum of the digital
potentiometer (0-127), displaying the value on the serial monitor. To 
see the effects of the changing values you can connect an LED to the
output on the breakout board. A detailed schematic should be provided.*/

// Code has been provided by CryoArchive.net

#include <Wire.h>

#define pot_address 0x28; //device address in hexadecimal
#define pot_read_address 0x00; //device read value address in hexidecimal

int potVal = 0; // Initial value of the digital potentiometer


void setup()
{
  Wire.begin(); //initializes the I2C bus
}

void PotControl() //class defining the loop to cycle through pot values and reads pot value
{
  
  if (potVal == 0) {
    for (potVal; potVal <= 127; potVal++)
    {
      Wire.beginTransmission(pot_address);  // Starts transmission to specified device
      Wire.write(potVal);                   // Sends value to potentiometer
      Wire.endTransmission();               // Stops sending value data
      delay(500);
    }
  } else if (potVal == 127) {
    for (potVal; potVal >= 0; potVal--)
    {
      Wire.beginTransmission(pot_address);  // Starts transmission to specified device
      Wire.write(potVal);                   // Sends value to potentiometer
      Wire.endTransmission();               // Stops sending value data
      delay(500);
    }
  }
}

void loop()
{
  PotControl();
}
  

