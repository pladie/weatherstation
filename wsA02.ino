#include <DHT11.h>
#include <Wire.h>
#include "RTClib.h"
DHT11 dht11(6);

RTC_DS1307 RTC;

void setup () 
{
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();

  if (! RTC.isrunning()) 
     {
        Serial.println("RTC is NOT running!");
     
       //RTC.adjust(DateTime(__DATE__, __TIME__));
     } 
     
     pinMode(5, OUTPUT)  ;                    // DHT11 GND
     pinMode(7, OUTPUT) ;                     // DHT11 Vcc
     pinMode(6, INPUT_PULLUP) ;               // DHT11 pin de lectura

     digitalWrite(7, HIGH) ;                  // Damos tension
     digitalWrite(5, LOW) ;
     delay (500);
}

void loop () 
{
    DateTime now = RTC.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    int err;
     float temp, hum;

     if((err = dht11.read(hum, temp)) == 0) // Si devuelve 0 es que ha leido bien
       {   Serial.print("Temperatura: ");
           Serial.print(temp);
           Serial.print(" Humedad: ");
           Serial.print(hum);
           Serial.println();
       }
     else
       {   Serial.println();
           Serial.print("Error Num :");
           Serial.print(err);
           Serial.println();
       }
    
    delay(3000);
}

