# Arduino_Taiwan Bootloader

Modify from Adafruit ProTrinket
Change USB pin to 2/3
also change USB PID/VID

#using Avrdude to upload  

.\avrdude.exe  -c usbasp -p m328p -v -e  -U flash:w:main.hex -U lfuse:w:0xFF:m -U hfuse:w:0xD0:m -U efuse:w:0x06:m  
