#include <SoftwareSerial.h> // TX RX software library for bluetooth

#include <Servo.h> // servo library 
Servo myservo; // servo name

int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  myservo.attach(9); // attach servo signal wire to pin 9
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
  myservo.write(5);
  
}

void loop()
{
  
  if(bluetooth.available() ) // receive number from bluetooth
  {
    char servopos = bluetooth.read(); // save the received number to servopos
    Serial.println(servopos); // serial print servopos current number received from bluetooth
  //Read from bluetooth and write to usb serial
    
   if(servopos == 'o'){
    myservo.write(180); // roate the servo the angle received from the android app
   }
   else if(servopos == 'l'){
    myservo.write(5); // roate the servo the angle received from the android app
   }
   
   }
   
 
  

}
