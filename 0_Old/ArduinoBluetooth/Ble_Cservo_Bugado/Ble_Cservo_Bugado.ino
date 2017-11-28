#include <AltSoftSerial.h>
AltSoftSerial BTserial; 
// https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html 
char c=' ';
boolean NL = true;

#define servo1 5
void servo0graus();
void servo90graus();
void servo180graus();
boolean aberta = false;

 
void setup() 
{
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");
 
    BTserial.begin(9600);  
    Serial.println("BTserial started at 9600");

    pinMode(servo1, OUTPUT); //saída para o servo1

}
 
void loop()
{
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    {
        c = BTserial.read();
        Serial.write(c);
        if (aberta == true){
            servo0graus();

          } 
          if (aberta == false){
            servo180graus();
            }
    }
 
    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        c = Serial.read();
                if (aberta == true){
             for(char i=0;i<100;i++) servo0graus();

          }
                if (aberta == false) {
            for(char i=0;i<100;i++) servo180graus();
            }
       
 
        // do not send line end characters to the HM-10
        if (c!=10 & c!=13 ) 
        {  
             BTserial.write(c);
        }
 
        // Echo the user input to the main window. 
        // If there is a new line print the ">" character.
        if (NL) { Serial.print("\r\n>");  NL = false; }
        Serial.write(c);
        if (c==10) { NL = true; }
         
    }
}

void servo0graus()              //Posiciona o servo em 0 graus
{
   digitalWrite(servo1, HIGH);  //pulso do servo
   delayMicroseconds(600);      //0.6ms
   digitalWrite(servo1, LOW);   //completa periodo do servo
   for(int i=0;i<32;i++)delayMicroseconds(600);
                               // 20ms = 20000us
                               // 20000us - 600us = 19400us
                               // 19400/600 = ~~32
   aberta = false;
} //end servo0graus
void servo90graus()             //Posiciona o servo em 90 graus
{
   digitalWrite(servo1, HIGH);  //pulso do servo
   delayMicroseconds(1500);     //1.5ms
   digitalWrite(servo1, LOW);   //completa periodo do servo
   for(int i=0;i<12;i++)delayMicroseconds(1500);
                               // 20ms = 20000us
                               // 20000us - 1500us = 18500us
                               // 18500/1500 = ~~12 
} //end servo0graus
void servo180graus()             //Posiciona o servo em 180 graus
{
   digitalWrite(servo1, HIGH);  //pulso do servo
   delayMicroseconds(2400);     //2.4ms
   digitalWrite(servo1, LOW);   //completa periodo do servo
   for(int i=0;i<7;i++)delayMicroseconds(2400);
                               // 20ms = 20000us
                               // 20000us - 2400us = 17600us
                               // 17600/2400 = ~~7
    aberta = true;
} //end servo0graus
