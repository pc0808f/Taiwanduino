# wav2txt
把WAV轉成程式碼，然後就可以貼上example播放  

使用方式是把聲音檔案拖到.exe檔案裡面  
之後會在同個地點多出一個txt檔案,把這檔案內容複製到  
Arduino的Code裡面就可以撥放  

要注意的是只吃8khz/8bit or 16bit的音效檔案  

# wav2uart
把WAV轉檔案之後，直接輸出到COM port上傳到外部EEPROM

首先要先到example把uploadToFlash傳到板子  
在來就是打開exe檔案  
輸入檔案的路徑，選擇COM port，輸入要從哪裡開始寫  

要注意的是只吃8khz/8bit or 16bit的音效檔案  


# pcm_converter
把有帶音訊資料的任意影音檔案，透過拖曳的方式快速轉檔   
  
直接將主程式 ( .bat ) 檔建立一個捷徑並傳送到音效檔得資料夾  
比所要轉換的一個或多個音效檔案拖曳到剛剛建立的捷徑上面即可完成轉檔  
第一次使用會先下載一份libav的轉檔器  
所輸出的檔案將會是 8位元的 PCM 編碼 WAV 檔  
預設取樣率和輸出資料夾可以至程式中進行手動更改  