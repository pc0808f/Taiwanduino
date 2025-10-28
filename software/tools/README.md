# pcm_converter
Drag and drop multiple audio files and convert it to 8bit PCM audio

First, make a shortcut of this converter pcm_converter_en.bat and move it to where your audio file locate.
Drag and drop multiple audio/video file on the shortcut at once.
After the conversion, you will be able to find 8bit PCM(.wav) files in the /export folder.
Default sample rate and export location can be changed manually in the batch program.

Notice: An auto libav downloader will be triggered at the first time you start.

# wav2txt
Extracts converted the PCM(.WAV) audio file to an array of samples, paste it in sketch and play

Drag and drop the .wav file on writeWav.exe.
It will extract a text file(.txt) which has the same name as the original.
Paste the content (array+size variable) to your Arduino sketch and upload.

Notice: only 8khz/8bit or 16bit in a audio format of PCM will be available.

# wav2uart
Programs the converted the PCM(.WAV) audio file to external EEPROM, it must be connected through a Serial converter (i.e. FTDI)

First, upload the [example/uploadToFlash](../example/uploadToFlash) to your Taiwanduino.
Start wav2uart.exe
Copy and paste your file location in.
Choose the COM port device your Taiwanduino is connected.
Enter the data offset in EEPROM (where you start to program)

Notice: only 8khz/8bit or 16bit in a audio format of PCM will be available.

***

*Read this in other languages: [English](README.md), [繁體中文](README.zh-TW.md).*
