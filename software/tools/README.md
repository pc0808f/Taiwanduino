# wav2txt
一個把WAV轉成程式碼,然後就可以貼上example播放  
使用方式是把聲音檔案拖到.exe檔案裡面  
之後會在同個地點多出一個txt檔案,把這檔案內容複製到  
Arduino的Code裡面就可以撥放  

要注意的是只吃8khz/8bit or 16bit的音效檔案

# wav2uart
一個把WAV轉檔案之後,直接輸出到COM port  
首先要先到example把uploadToFlash傳到板子  
在來就是打開exe檔案  
輸入檔案的路徑，選擇COM port，輸入要從哪裡開始寫  

要注意的是只吃8khz/8bit or 16bit的音效檔案