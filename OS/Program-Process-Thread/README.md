**Program, Process and Thread?** <br/>
Ans: Process 是 OS 分配 resource 的單位，相對的 Thread 是 OS 分配 CPU-time 的單位。
Process 之間的溝通相對複雜，要嘛是跟 OS 要一塊 Shared Memory，
不然就是透過 OS Message passing，
而 Thread 之間的溝通相對簡單，只要透過 Global Variable 即可，
雖然可能會有些問題（Race Condition）不過整體是比較簡單的，
再者 Thread 的切換可能不用轉到 Kernel Mode（看 Thread 如何實作）
又 Process 切換需要儲存許多資料到 PCB 而 Thread 相對少，
所以 Thread 的 Context Switch 也比 Process 快。

Program：放在二次儲存裝置中，尚沒有被Load到記憶體的一堆Code，稱之為「程式」。  (也就是還是死的)
Process：已經被Load到記憶體中，任何一行Code隨時會被CPU執行，且其宣告的在記憶體的變數的值會隨著需求而不斷變動，
         稱之為「程序」。 (也就是活的Program) => 恐龍本第三章
         一個多工作業系統(Multitasking Operating System)可以同時運行多個Process
         然而一個CPU一次只能做一件事情，但CPU的數量永遠少於運行中的Process數，
         因此每個Process使用的時間需要被排程(Scheduling) => 恐龍本第五章
         又每個Process間在記憶體中，如果擺放的方式不當，就會在記憶體中產生很多
         沒辦法用到的碎片，因此MemoryManagement是一個問題 => 恐龍本第八章
         另外，每個Process所需要的記憶體總合，也可能大於實體記憶體，因此需要另
         外用二次儲存裝置充當虛擬記憶體(Virtual Memory)，但是二次儲存裝置的速
         度肯定很慢，因此如何做到對虛擬記憶體最小的依賴，盡量避免Page Fault(電
         腦在主記憶體中找不到資料，而要去二次記憶體找，就稱為Page Fault)
         防止Thrashing的發生(因為Virtual Memory演算法不當，造成幾乎每次存取都要
         依賴二次記憶體，就是Thrashing)，以達到效能最佳化，也是個學問 => 第九章
Thread ：在同一個Process底下，有許多自己的分身，就是Thread，中文又翻成執行緒。
         以往一個Process一次只能做一件事情，因此要一面輸入文字，一面計算字數，
         這種事情是不可能的。但是有了Thread之後，可以在同一個Process底下，讓輸
         入文字是一個Thread，計算文字又是另外一個Thread，對CPU來說兩個都是類似
         一個Process，因此兩個可以同時做。
         又一個Process底下有數個Thread，而一個Process的Global Variable可以讓
         它的所有Thread共享，也就是所有Thread都可以存取同一個Process的Global
         Variable。而每個Thread自己也有自己的專屬Variable。 => 恐龍本第四章
         但是，如果有兩個Thread要存取同一個Global Variable，有可能發生問題，
         也就是說可能會存取到錯的值(例如兩個Thread同時要對一個Variable做加減，
         最後那個答案可能會是錯的)，這就是Synchronization問題 =>恐龍本第六章
         又，每一個Thread之間可能會互搶資源，而造成死結(Deadlock)，只要以下四
         個條件都滿足就有死結。(1)這個資源不能同時給兩個人用 (2)有一個人拿了一
         個資源，又想拿別人的資源 (3)如果一個人占了茅坑不拉屎，占用資源很久，仍
         不能趕他走 (4)A等B，B等C，C等D，D又等A 等成一圈。 要解決這種狀況有
         Avoid(預防) 或 避免(Prevent)兩種方式，破除以上四種其中一種即可。
         => 恐龍本第七章