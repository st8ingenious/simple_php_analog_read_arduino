/* 
                     Simple PHP Analog Read Arduino
    
    Copyright (C) 2015  Efstathios Kladis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
       GNU GENERAL PUBLIC LICENSE
          Version 2, June 1991
            
            
   Description     
     Send analog pin readings from Arduino UNO with Ethernet shield to a webserver directly.
     No need for SQL database or Arduino local webserver
     All values are stored in a txt file on the server.
     
     Setup:
     >> Upload "analog" folder to your server (like this "yoursite.com/analog/").
     >> REPLACE "yourwebsitehere" in line 39 of the arduino sketch, with your website (without www) and upload it to Arduino UNO.
     
     No other configuration is required, just connect your Arduino to any router.
     
     <<See the result at "http:// example.com/analog/" (change " example.com" with your own site URL)>>
     
     
 Original can be found at https://github.com/st8ingenious/simple_php_analog_read_arduino
*/


#include <Ethernet.h>
#include <SPI.h>

//////////////////////////////////////////////////////////////////////////////////
//SETTINGS
//////////////////////////////////////////////////////////////////////////////////
//byte server[] = { , , , }; //ip Address of the server you will connect to, OR
char server[] = "yourwebsitehere";                                               //replace with your website 
// if need to change the MAC address (Very Rare)
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//////////////////////////////////////////////////////////////////////////////////

EthernetClient client;

char inString[32]; // string for incoming serial data
int stringPos = 0; // string index counter
boolean startRead = false; // is reading?
int an[6];
void setup(){
  Serial.begin(9600);
  Ethernet.begin(mac);
  Serial.println(Ethernet.localIP());
}

void loop(){
  for (int a=0; a<6; a++){
     an[a] = analogRead(a);                                        //Reading analog inputs, just for demo
     Serial.print("Analog pin ");
     Serial.print(a);
     Serial.print(" is: ");
     Serial.println(an[a]);
  delay(50);   
  }  
  
  //connect to the server

  Serial.println("connecting...");

  //port 80 is typical of a www page
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /analog/index.php?");
    client.print("an0=");
    client.print( an[0] );
     client.print("&");
    client.print("an1=");
    client.print( an[1] );
     client.print("&");
    client.print("an2=");
    client.print( an[2] );
     client.print("&");
    client.print("an3=");
    client.print( an[3] );
     client.print("&");
    client.print("an4=");
    client.print( an[4] );
     client.print("&");
    client.print("an5=");
    client.print( an[5] );
    client.print("&");
    client.print("nf=NO");
    client.println( " HTTP/1.1");
    client.print("Host: ");
    client.println(server); 
  // client.println("Authorization: Basic <<replace with user and pass with base64_encode>> ");        //if htaccess password is enabled 
   // client.println( "Content-Type: application/x-www-form-urlencoded" );
    client.println( "Connection: close" );
    client.println();
    client.stop();
    Serial.println("Done");

    //Connected - Read the page
   // return readPage(); //go and read the output

  }else{
     Serial.println("connection failed");
  }
  delay(3000); //wait 3 seconds before connecting again
}
