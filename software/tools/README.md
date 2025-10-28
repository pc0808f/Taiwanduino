# pcm_converter
Drag and drop multiple audio files and convert it to 8bit PCM audio (拖曳音訊檔案快速轉檔)

First, make a shortcut of this converter pcm_converter_tw.bat and move it to where your audio file locate.
(將 pcm_converter_tw.bat 建立捷徑並傳送到音效檔案的資料夾)
Drag and drop multiple audio/video file on the shortcut at once.
(將一個或多個音效檔案拖曳到捷徑上面即可完成轉檔)
After the conversion, you will be able to find 8bit PCM(.wav) files in the /export folder.
(輸出的檔案將會是 8 位元的 PCM 編碼 WAV 檔)
Default sample rate and export location can be changed manually in the batch program.
(預設取樣率和輸出資料夾可以在程式中手動更改)

Notice: An auto libav downloader will be triggered at the first time you start.
(注意事項：第一次使用會先下載 libav 轉檔器)

# wav2txt
Extracts converted the PCM(.WAV) audio file to an array of samples, paste it in sketch and play
(把 WAV 轉成程式碼，然後就可以貼到 example 中播放)

Drag and drop the .wav file on writeWav.exe.
(使用方式是把聲音檔案拖到 .exe 檔案裡面)
It will extract a text file(.txt) which has the same name as the original.
(會在同個地點產生一個 txt 檔案)
Paste the content (array+size variable) to your Arduino sketch and upload.
(把檔案內容複製到 Arduino Code 裡面就可以播放)

Notice: only 8khz/8bit or 16bit in a audio format of PCM will be available.
(注意事項：本程式只支援 8khz/8bit or 16bit 的 PCM 音效檔案)

# wav2uart
Programs the converted the PCM(.WAV) audio file to external EEPROM, it must be connected through a Serial converter (i.e. FTDI)
(把 WAV 轉檔後直接輸出到 COM port 上傳到外部 EEPROM)

First, upload the [example/uploadToFlash](../example/uploadToFlash) to your Taiwanduino.
(首先要把 example/uploadToFlash 上傳到板子)
Start wav2uart.exe
(打開 exe 檔案)
Copy and paste your file location in.
(輸入檔案的路徑)
Choose the COM port device your Taiwanduino is connected.
(選擇 COM port)
Enter the data offset in EEPROM (where you start to program)
(輸入要從哪裡開始寫入的初始位置位移量)

Notice: only 8khz/8bit or 16bit in a audio format of PCM will be available.
(注意事項：本程式只支援 8khz/8bit or 16bit 的 PCM 音效檔案)  
  
***
  
*Read this in other languages: [English](README.en.md), [正體中文](README.md).*  
