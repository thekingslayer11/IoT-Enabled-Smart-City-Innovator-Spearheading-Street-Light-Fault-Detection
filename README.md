# IoT-Enabled-Smart-City-Innovator-Spearheading-Street-Light-Fault-Detection
Author MD Ashif Hussain<br>
Email: ashifhussain609@gmail.com<br>
Date: 13/04/2024<br>
Revision: version#<br>
License: Public Domain<br>

Project: Streetlight Fault Detection using IoT

Desc:
Developed a comprehensive system for detecting and reporting faults in street lights, including bulb burnouts, electrical issues, and physical damage. The system should be able to associate each fault with the unique ID of the respective street light for efficient maintenance and repair. The location of the damaged streetlight along with the timestamp will be sent to the concerned authority.

Step 1: Installation

1. Open this file
2. Edit as you like
3. Release to the World!

Step 2: Assemble the circuit

Assemble the circuit following the diagram layout.png attached to the sketch

Step 3: Load the code

Upload the code contained in this sketch on to your board

Folder structure
<pre>

 sketch                   => Arduino sketch folder<br>
  ├── sketches            => main files<br>
  ├── schematics.png      => image of the required schematics<br>
  ├── layout.png          => image of the layout<br>
  └── README.md           => this file<br>
</pre>
Contributing
To contribute to this project please contact: Me 

BOM
<pre>
| ID | Part name                                            |     Part number       |  Quantity |<br>
| R1 | 10k Resistor                                         |          -            |    6      |<br>
| L1 | White LED                                            |          -            |    6      |<br> 
| A1 | Arduino UNO                                          |         R3            |    1      |<br>  
| E1 | ESP                                                  |         12F           |    1      |<br>
| S1 | Digital LDR Module                                   |          -            |    6      |<br>
| C1 | Tiny RTC Real Time Clock                             | DS1307 I2C IIC Module |    1      |<br>
| S2 | PIR Motion Sensor                                    |         HCSR501       |    2      |<br>
| G1 | GPRS GSM Module Core Board Quad-band TTL Serial Port |         SIM800L       |    1      |<br>
</pre>
Help
This document is written in the _AsciiDoc_ format, a markup language to describe documents. 
If you need help you can search the http://www.methods.co.nz/asciidoc[AsciiDoc homepage]
or consult the http://powerman.name/doc/asciidoc[AsciiDoc cheatsheet]
