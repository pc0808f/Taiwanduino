# Software

**Arduino plugin** contains our board configuration (板子編譯資訊)
   If you have the latest Arduino IDE, you can also use *Board Manager* and *Library Manager* to download and import these automatically (可以透過 Arduino IDE 內建的*板子管理員*及*管理程式庫*功能來自動取得)

 - Board Configs (板子編譯資訊)
	 - [File] → [Preferences] → [Additional Board Manager URLs] and insert the URL below:
	   ([檔案] → [偏好設定] → [額外的板子管理員網址]中輸入以下網址)
	   https://pc0808f.github.io/Taiwanduino/taiwanduino_pc0808f_index.json
	 - [Tools] → [Board: ""] → [Board Manager] and search for "Taiwanduino"
	   ([工具] → [板子] → [板子管理員]中搜尋 Taiwanduino)
	 - Click the [Install] button (按下 [安裝] 按鈕)

 - External libraries (外部函式庫)
	 - [Sketch] → [Include library] → [Manage Libraries] and search for "CapacitiveSensor"
	   ([草稿碼] → [匯入程式庫] → [管理程式庫]中搜尋 CapacitiveSensor)
	 - Click the [Install] button (按下 [安裝] 按鈕)
	 - The library could be found in [PaulStoffregen/CapacitiveSensor](https://github.com/PaulStoffregen/CapacitiveSensor) if you want to import it manually
	   (手動匯入請至此處下載)

**Driver** contains drivers for Windows systems (it's a plug and play device for UNIX based systems like OS X or Linux)
(Windows 作業系統所需驅動程式，OS X 和 Linux 為隨插即用)

**bootloader** contains the source code of the pre-programmed bootloader in TaiwanDuino
(TaiwanDuino 中所預燒的 bootloader 原始碼)

**example** is the folder of example sketches (範例草稿碼資料夾)

**tools** includes EEPROM programmer and audio converters (燒錄、製作音訊時所需的轉換工具)  
  
***
  
*Read this in other languages: [English](README.en.md), [正體中文](README.md).*  
