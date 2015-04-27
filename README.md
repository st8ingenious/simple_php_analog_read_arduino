
#Simple PHP Analog Read Arduino
    
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
     >> REPLACE "yourwebsitehere" in line 39 of the arduino sketch, 
     with your website (without www) and upload it to Arduino UNO.
     
     No other configuration is required, just connect your Arduino to any router.
     
     <<See the result at "http:// example.com/analog/" (change " example.com" with your own site URL)>>
     
 ![screenshot] (https://github.com/st8ingenious/simple_php_analog_read_arduino/blob/master/screenshot.jpg?raw=true)
     
 Original can be found at https://github.com/st8ingenious/simple_php_analog_read_arduino
