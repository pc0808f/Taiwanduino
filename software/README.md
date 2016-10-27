# Software
**Arduino plugin** 中包含板子編譯資訊與外部函式庫，現在可以透過下載最新版的 Arduino IDE 並使用內建的 板子管理員 及 管理程式庫 功能來自動取得  
 - 板子編譯資訊  
	 - 請在 [檔案] → [偏好設定] → [額外的板子管理員網址]中輸入以下網址：  
	 - https://will127534.github.io/Taiwanduino/package_Taiwanduino_index.json   
	 - 進入[工具] → [板子] → [板子管理員]中輸入搜尋 Taiwanduino  
	 - 按下[ 安裝 ]按鈕  

 - 所使用的外部函式庫  
	 - [草稿碼] → [匯入程式庫] → [管理程式庫]中輸入 CapacitiveSensor 搜尋  
	 - 按下[ 安裝 ]按鈕  

**Driver** 資料夾中包含 Windows 作業系統中所需要的驅動程式 ( Mac 和 Linux 中為隨插即用)  

**bootloader** 包含 TaiwanDuino 中所預燒的 bootloader 原始碼  

**example** 為範例草稿碼的資料夾  

**tools** 內有燒錄、製作音訊時所需要的轉換工具  