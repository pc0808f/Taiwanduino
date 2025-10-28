# Software

**板子管理員安裝**（建議使用）
   可以透過下載最新版的 Arduino IDE 並使用內建的*板子管理員*及*管理程式庫*功能來自動安裝

   註：板子配置檔案位於 `/hardware/Taiwanduino/avr/` 目錄

 - 板子編譯資訊
	 - 請在 [檔案] → [偏好設定] → [額外的板子管理員網址]中輸入以下網址：
	   https://pc0808f.github.io/Taiwanduino/taiwanduino_pc0808f_index.json
	 - 進入 [工具] → [板子] → [板子管理員]中搜尋 Taiwanduino
	 - 按下 [安裝] 按鈕

 - 所使用的外部函式庫
	 - [草稿碼] → [匯入程式庫] → [管理程式庫]中搜尋 CapacitiveSensor
	 - 按下 [安裝] 按鈕
	 - 手動匯入外部程式庫請至 [PaulStoffregen/CapacitiveSensor](https://github.com/PaulStoffregen/CapacitiveSensor) 下載

**Driver** 資料夾中包含 Windows 作業系統所需驅動程式（OS X 和 Linux 為隨插即用）

**bootloader** 包含 TaiwanDuino 中所預燒的 bootloader 原始碼

**example** 為範例草稿碼的資料夾

**tools** 內有燒錄、製作音訊時所需的轉換工具

***

*其他語言版本: [English](README.md), [繁體中文](README.zh-TW.md).*
