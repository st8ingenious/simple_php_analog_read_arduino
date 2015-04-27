<!-- 
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
-->

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Simple PHP Analog Read Arduino</title>
<script type="text/javascript">
//<![CDATA[
window.onload = function() { setInterval(countdown, 1000); }
function countdown() {
	var num = parseInt(document.getElementById('timer').innerHTML);
	if(--num < 1) location.reload(true)
	else document.getElementById('timer').innerHTML = num;
}
//]]>
</script>
</head>
<body>
<?PHP
#Manual reset values to zero by adding this "/analog/index.php?an0=0&an1=0&an2=0&an3=0&an4=0&an5=0&nf=NO" at the end of your website URL
if ($_GET["an0"]>-1){
$myfile = fopen("values.txt", "w") or die("Unable to open file!");
$txt = $_GET["an0"] . "\n";
fwrite($myfile, $txt);
$txt = $_GET["an1"] . "\n";
fwrite($myfile, $txt);
$txt = $_GET["an2"] . "\n";
fwrite($myfile, $txt);
$txt = $_GET["an3"] . "\n";
fwrite($myfile, $txt);
$txt = $_GET["an4"] . "\n";
fwrite($myfile, $txt);
$txt = $_GET["an5"] . "\n";
fwrite($myfile, $txt);
fclose($myfile);}

$handle = fopen("values.txt", "r");
if ($handle) {
echo "<table border='1'>
<tr>
<th>Analog Values from Arduino</th>
</tr>";
$pin=0;
    while (($line = fgets($handle)) !== false) {
		echo "<tr>";
  echo "<td> Analog Pin " . $pin . ": " . $line . "</td>";
  echo "</tr>";
 $pin=$pin+1;
     }
echo "</table>";

    
}
fclose($handle);

?>
<br>
<?php if ($_GET["nf"]!== "NO"): ?>
Auto refresh in <span id="timer">5</span> seconds
<br>
<?php endif ?>
<pre>
©2015 http://bettercallstathis.com 
   All rights reserved
   </pre>
</body>
</html>
