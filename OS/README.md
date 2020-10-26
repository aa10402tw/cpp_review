**什麼是OS?** <br/>
Ans: 確保 Process 可以正確執行，不會讓 Process 跟 Process 之間互相干擾，
並透過 kernel mode 跟 user mode 保護硬體，
並提供 high level 的 system call 讓使用者不能直接操作硬體，
簡化操作，也更加有效率等。

**CPU怎麼處理interrupt ? 處理的時候會做什麼?**
● Interrupt 的種類
  I. External Interrupt（外部中斷）: CPU 外的週邊元件所引起的。
    （I/O Complete Interrupt, I/O Device error）
  II. Internal Interrupt（內部中斷）:不合法的用法所引起的。
    （Debug、Divide-by-zero、overflow）
  III. Software Interrupt（軟體中斷）：使用者程式在執行時，若需要OS 提供服
      務時，會藉由System Call 來呼叫OS 執行對應的service routine，完成服務請求
      後，再將結果傳回給使用者程式。
● Interrupt 的處理流程
Setps
  1. 暫停目前process 之執行。
  2. 保存此process 當時執行狀況。
  3. OS 會根據Interrupt ID 查尋Interrupt vector。
  4. 取得ISR（Interrupt Service Routine）的起始位址。
  5. ISR 執行。
  6. ISR 執行完成，回到原先中斷前的執行。
 
Interrupt I/O（中斷式I/O）
  其運作處理方式如下

Steps
  1. 發出I/O 要求給CPU（OS）。
  2. CPU 設定I/O commands 給I/O Device controller。
  3. I/O Device 運作執行。
  4. PA 等待 I/O 完成。
  5. PB 取得CPU 執行。
  6. 當I/O 運作完成，則I/O 會發出一個「I/O Complete Interrupt」（I/O完成中斷）
     通知OS。
  7. OS 暫停目前process 的執行。
  8. OS根據Interrupt ID 去查詢Interrupt vector，取出對應的ISR（Interrupt
     Service Routine）的起始位址。
  9. CPU 執行ISR。
  10.ISR 執行完畢，OS 通知PA 其I/O 要求完成，將PA 的狀態改成Ready。
  11.由CPU 排班挑選process 執行。
  
ISR:
ISR簡單來說就是中斷會跳去執行的函式,而他跟task或process不同的地方是,
做context switch的時候ISR只會PUSH部份暫存器,而task或process會push所有的暫存器

**System Call**
System call 是 process 與作業系統之間的介面。
System call 是由 Linux kernel 所實作並提供給使用者，
user-space program 可透過 system call 與Linux kernel 溝通
作為user program執行時與OS之間的溝通介面，當user program需要OS提供服務時，
藉由呼叫system call(伴隨trap to monitor mode)通知OS，
OS可依據system call ID查表，啟動service routine執行，
得到結果，再傳回給user program，完成服務請求

System Call種類：(P3-8~3-9)
Process Control
File Management
Device Management
Information Maintenance
Communication

行程控制(Process Control)系統呼叫
如前述，CPU 抓取主記憶體(Main Memory)的程式(Program)並執行其工作(Job)如此是謂“行程(Process)”。
執行過程中，凡遇行程衝撞系統的動作，均須作系統呼叫，
由具有安全性的即定程序引導執行。行程作系統呼叫的項目有：
1. 行程的起動與終止：
(a)呼叫作業系統執行載入(Load)，將程式指令從主記憶體抓取至 CPU 執行(Execute)之；
(b)呼叫作業系統執行建立行程(Create Process)，執行完畢後，呼叫作業系統執行終止行程(Terminate Process)；
(c)在正常情況下，呼叫作業系統執行終止程式(End Program)，在有錯誤的情況下，摒棄程式(Abort Program)，並印出錯誤信息。

2. 記憶體分配 (Allocate and Free Memory)：
當執行行程時，須配合主記憶體的空間、或 CPU 內的暫存器作資料(Data)儲存，
這些動作均須呼叫作業系統執行記憶體分配(Allocate)、或釋出記憶體(Free)。

3. 行程屬性 (Process Attributes)：
在執行過程中，為了配合其他行程的需要，往往要了解其他行程的屬性，
此時呼叫作業系統讀取其他行程的屬性(Get Process Attributes)；
亦或呼叫系統設定本身行程的屬性(Set Process Attributes)，以供其他行程觀察使用。

4. 行程等待 (Wait)：
在執行過程中，有許多情況需要行程(Process)作等待，
等待進入 CPU、等待滑鼠事件、等待鍵盤事件等等，
為了執行過程井然有序，呼叫作業系統執行行程等待。

檔案管理(File Management)系統呼叫
一組資料(Data)或一個程式(Program)儲存於連續的記憶體內，
以一個名稱代表之，是謂“檔案(File)”。
在記憶體建立檔案、存取檔案等等作為，均須作系統呼叫由作業系統導引執行，
其中項目有：
1. 檔案之建立與刪除(Create / Delete File)：建立或刪除一個檔案，均會改變記憶體的使用情況，必須呼叫作業系統導引執行。
2. 檔案資料存取 (Read / Write)：存取檔案資料必經之過程為：
(a)開啟檔案(Open File)、(b)存取檔案(Read / Write)、(c)關閉檔案(Close File)。
為了安全，均須呼叫作業系統導引執行。
3. 檔案屬性 (File Attributes)：為了配合存取檔案的需要，往往需要了解其他檔案的屬性，此時呼叫作業系統讀取其他檔案的屬性(Get File Attributes)；亦或呼叫作業系統設定本身檔案的屬性(Set File Attributes)，以供其他檔案讀取使用

資料維護(Information Maintenance)系統呼叫
隨著時間的改變，將資料更新是謂“資料維護(Information Maintenance)”，如果是系統資料的更新，為了安全，須作系統呼叫執行：
1. 設定時間或日期(Set Time or Date)：電腦內部有計時裝置，配合計時器的運轉，作業系統對映顯示時間及日期，因是作業系統的管轄部份，如果更新顯示時間或日期，需呼叫作業系統導引執行。
2. 存取系統資料 (Get / Set System Data)：作業系統的資料牽涉電腦的整體運作，故其任何更新之改變需呼叫作業系統導引執行。
3. 存取行程、檔案、或裝置之屬性 (Get / Set Process、File、or Device Attributes)：如前述，行程、檔案、或裝置資料之存取，需呼叫作業系統導引執行，其屬性亦應呼叫作業系統導引執行。

連線通訊(Communication)系統呼叫
分散式系統是將散置各處的電腦以連線連通，執行訊息傳遞等 I/O 存取行為，故須作系統呼叫執行：
1. 建立或中斷連通連線 (Create / Delete Communication Connection)：實體連線的連接屬於網路實體層，如要改變現狀，需呼叫作業系統導引執行。
2. 輸入輸出網路資料 (Send / Receive Messages)：網路資料的輸入輸出牽涉甚多，除了 I/O 機制外，還有網路機制等問題，絕非程式本身可單獨執行者，為了安全，為了克服重重機制，需呼叫作業系統導引執行。
3. 狀態資訊之轉換 (Transfer Status Information)：為了配合不同的環境條件，系統須對某些區塊設定狀態旗標 (Status Flag)，媒合執行行程，如要轉換這些狀態資訊，需呼叫作業系統導引執行。
4. 使用遠端裝置 (Attach / Detach Remote Devices)：當使用網路遠端其他電腦或裝置時，系統應有相對之使用訊息，以供資源分配的依據，如果使用情況改變，需呼叫作業系統導引執行改變對應之使用訊息。

**OSI模型**
第7層應用層（Application Layer）
	提供為應用軟體而設的介面，以設定與另一應用軟體之間的通訊。例如：HTTP，HTTPS，FTP，TELNET，SSH，SMTP，POP3等。
第6層表達層（Presentation Layer）
	把資料轉換為能與接收者的系統格式相容並適合傳輸的格式。
第5層會議層（Session Layer）
	負責在資料傳輸中設定和維護電腦網路中兩台電腦之間的通訊連接。
第4層傳輸層（Transport Layer）
	把傳輸表頭（TH）加至資料以形成資料包。傳輸表頭包含了所使用的協定等傳送資訊。例如：傳輸控制協定義（TCP）等。
第3層網路層（Network Layer）
	決定資料的路徑選擇和轉寄，將網路表頭（NH）加至資料包，以形成封包。網路表頭包含了網路資料。例如：網際網路協定（IP）等。
第2層資料鏈結層（Data Link Layer）
	負責網路尋址、錯誤偵測和改錯。當表頭和表尾被加至資料包時，會形成了影格。資料鏈表頭（DLH）是包含了實體位址和錯誤偵測及改錯的方法。資料鏈表尾（DLT）是一串指示資料包末端的字串。例如乙太網、無線區域網路（Wi-Fi）和通用分組無線服務（GPRS）等。
	分為兩種子層：logic link control sublayer & media access control sublayer
第1層實體層（Physical Layer）
	在局部區域網路上傳送影格，它負責管理電腦通訊裝置和網路媒體之間的互通。包括了針腳、電壓、線纜規範、集線器、中繼器、網卡、主機介面卡等

**Real-time operating system, RTOS**
實時作業系統與一般的作業系統相比，最大的特色就是其「實時性」，
也就是說，如果有一個任務需要執行，
實時作業系統會馬上（在較短時間內）執行該任務，
不會有較長的延時。這種特性保證了各個任務的及時執行
設計實時作業系統的首要目標不是高的吞吐量，而是保證任務在特定時間內完成

**3 / 4 way handshake**
```
[SYN]              我: 哈嚕, 有沒有聽到聲音?
[SYN, ACK]      A: 有聽到，那我呢?有沒有聽到聲音
[ACK]              我: 有滴~
```
```
[FIN, ACK]
[ACK]
是四向交握協定Four-way Handshake，用來關閉連線的
1. (B) --> ACK/FIN --> (A)
2. (B) <--     ACK    <-- (A)
3. (B) <-- ACK/FIN <-- (A)
4. (B) -->    ACK     --> (A)
```

**stack/heap overflow**
stack：區域變數
堆疊區段（stack segment）用於儲存函數的區域變數，以及各種函數呼叫時需要儲存的資訊（例如函數返回的記憶體位址還有呼叫者函數的狀態等），每一次的函數呼叫就會在堆疊區段建立一個 stack frame，儲存該次呼叫的所有變數與狀態，這樣一來同一個函數重複被呼叫時就會有不同的 stack frame，不會互相干擾，遞迴函數就是透過這樣的機制來執行的。
區域變數(local variable)、函式參數(function/method parameter)、函數的返回位址(function/method return address)

int foo()
{
    return foo();  //這裡出現自我呼叫
}

heap：動態配置變數
heap 區段的記憶體空間用於儲存動態配置的變數，例如 C 語言的 malloc 以及 C++ 的 new 所建立的變數都是儲存於此。
堆疊區段一般的狀況會從低記憶體位址往高記憶體位址成長，而 heap 剛好從對面以相反的方向成長。

Heap中的資料如果沒有正常的回收，將會逐步成長到將記憶體消耗殆盡

**Memory Hierarchy**
Register – Cache – Main Memory – Disk –Tape
愈快 ← 速度 → 愈慢
愈昂貴 ← 價格 → 愈便宜
愈小 ← 容量 → 愈大

SRAM (Static RAM)：用Flip/Flop儲存，速度快，密度低(元件大)，成本高，作Cache等快速記憶體，不須Refresh。
DRAM (Dynamic RAM)：用電容器製作，速度慢，密度高(元件小)，成本低，為Main Memory的主體，須Refresh
儲存的電荷會隨著時間漸漸消失，因此需要有個再充電（Refresh）的動作保持電容儲存的資料

**User space/ Kernel space**
簡單說，Kernel space 是 Linux 內核的運行空間，User space 是用戶程序的運行空間。
為了安全，它們是隔離的，即使User的程序崩潰了，內核也不受影響。
Kernel space 可以執行任意命令，調用系統的一切資源；
User space 只能執行簡單的運算，不能直接調用系統資源，必須通過系統接口（又稱 system call），才能向內核發出指令。
```
str = "my string" // 用戶空間
x = x + 2
file.write(str) // 切換到內核空間

y = x + 4 // 切換回用戶空間
```

**DMA是什麼，好處是？請簡單在白板上畫出他的架構圖。**
直接記憶體存取（Direct Memory Access，DMA）
是電腦科學中的一種記憶體存取技術。
它允許某些電腦內部的硬體子系統（電腦外設），
可以獨立地直接讀寫系統記憶體，而不需中央處理器（CPU）介入處理 。
在同等程度的處理器負擔下，DMA是一種快速的資料傳送方式。
很多硬體的系統會使用DMA，包含硬碟控制器、繪圖顯示卡、網路卡和音效卡。

DMA是所有現代電腦的重要特色，它允許不同速度的硬體裝置來溝通，
而不需要依於中央處理器的大量中斷負載。
否則，中央處理器需要從來源把每一片段的資料複製到暫存器，
然後把它們再次寫回到新的地方。
在這個時間中，中央處理器對於其他的工作來說就無法使用。

**Synchronous call 跟 Asynchronous call**
Async是接收到需求，不用一直等到需求完成再執行其他需求(0)
Async與Sync的差別在於：發送需求的人是否需要等到需求完成才可以執行其他事情。