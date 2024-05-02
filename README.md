# IoT-Enabled-Smart-City-Innovator-Spearheading-Street-Light-Fault-Detection
:Author: MD Ashif Hussain
:Email: ashifhussain609@gmail.com
:Date: 13/04/2024
:Revision: version#
:License: Public Domain

= Project: Streetlight Fault Detection using IoT

Desc:
Developed a comprehensive system for detecting and reporting faults in street lights, including bulb burnouts, electrical issues, and physical damage. The system should be able to associate each fault with the unique ID of the respective street light for efficient maintenance and repair. The location of the damaged streetlight along with the timestamp will be sent to the concerned authority.
![image](https://github.com/thekingslayer11/IoT-Enabled-Smart-City-Innovator-Spearheading-Street-Light-Fault-Detection/assets/93860728/3f825d2b-da22-405f-9e99-dbbb753372bc)


== Step 1: Installation

1. Open this file
2. Edit as you like
3. Release to the World!

== Step 2: Assemble the circuit

Assemble the circuit following the diagram layout.png attached to the sketch

== Step 3: Load the code

Upload the code contained in this sketch on to your board

=== Folder structure

....
 sketch123                => Arduino sketch folder
  ├── sketch123.ino       => main Arduino file
  ├── schematics.png      => (optional) an image of the required schematics
  ├── layout.png          => (optional) an image of the layout
  └── README.md        => this file
....

=== Contributing
To contribute to this project please contact: Me

=== BOM

|===
| ID | Part name                                            | Part number           |  Quantity |
| R1 | 10k Resistor                                         |          -            |    6      | 
| L1 | White LED                                            |          -            |    6      | 
| A1 | Arduino UNO                                          |         R3            |    1      |  
| E1 | ESP                                                  |         12F           |    1      |
| S1 | Digital LDR Module                                   |          -            |    6      |
| C1 | Tiny RTC Real Time Clock                             | DS1307 I2C IIC Module |    1      |
| S2 | PIR Motion Sensor                                    |         HCSR501       |    2      |
| G1 | GPRS GSM Module Core Board Quad-band TTL Serial Port |         SIM800L       |    1      |

=== Help
This document is written in the _AsciiDoc_ format, a markup language to describe documents. 
If you need help you can search the http://www.methods.co.nz/asciidoc[AsciiDoc homepage]
or consult the http://powerman.name/doc/asciidoc[AsciiDoc cheatsheet]
