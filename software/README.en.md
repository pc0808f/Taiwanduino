# Software
  
**Arduino plugin** contains our board configuration.
   If you have the latest Arduino IDE, you can also use *Board Manager* and *Library Manager* to download and import these automatically.
   
   - Board Configs  
	 - [File] → [Preferences] → [Additional Board Manager URLs] and insert the URL below:
	   https://pc0808f.github.io/Taiwanduino/taiwanduino_pc0808f_index.json   
	 - [Tools] → [Board: ""] → [Board Manager] and search for "Taiwanduino".  
	 - Click the [Install] button.  
 
 - External libraries   
	 - [Sketch] → [Iclude library] → [Manage Libraries] and search for "CapacitiveSensor"  
	 - Click the [Install] button.  
	 - The library could be found in  [PaulStoffregen/CapacitiveSensor](https://github.com/PaulStoffregen/CapacitiveSensor) if you want to import it manually.
  
**Driver** contains drivers for Windows systems ( it's a plug and play device for UNIX based systems like OS X or Linux ).  
  
**bootloader** contains the source code of the pre-programmed bootloader in TaiwanDuino.  
  
**example** is the folder of example sketches.  
  
**tools** includes EEPROM programmer and audio converters.  
  
***
  
*Read this in other languages: [English](README.en.md), [正體中文](README.md).*  
