## 常見 Linux Terminal 指令
```
mkdir: Make Directory
cd: Change Directory

pwd: Print Working Directory
ls: List
grep: Global Regular Expression Print

touch: The touch command allows you to create a blank new file through the Linux command line
	- touch filename
cp: copy file 
	- cp src_path dst_path
rm: remove file (-r 遞迴刪除, -f 強制刪除)
	- rm filename
	- rm -r dirname/ (遞迴刪除, 會把目錄內所有檔案及目錄) 
echo: This command is used to move some data into a file 
	- echo "Hello, my name is John" >> name.txt
cat: Concatenate
	- cat filename (view contain of file)
	- cat > filename (creates a new file)
	- cat f1 f2 > f3 joins two files (1 and 2) and stores the output of them in a new file (3)
head: The head command is used to view the first lines of any text file
	- head filename
tail: The tail command will display the last ten lines of a text file
	- tail filename

find: searches for files and directories
chown: change or transfer the ownership of a file to the specified username (e.g., chown linuxuser2 file.ext)
	
chmod: Change Mod (read, write, and execute permissions of files and directories)
uname: print detailed information about your Linux system

hostname: the name of your host/network
ping: check your connectivity status to a server
	- ping google.com
wget: download files from the internet
curl: 是一個在 Linux 上用來透過 HTTP Protocol（HTTP HyperText Transfer Protocol 定義存取網路資源的協定，讓我們可以使用 client / server 模式來取得網路資源）下載和上傳檔案的指令（比起 wget 只能下載強大許多）
ssh: secure connection to the SSH server on a remote machine
	- ssh hostname command (remote machine)

kill: terminate program (kill [signal option] PID.)
top: display a list of running processes and how much CPU each process uses
history: review the commands you’ve entered before

zip/unzip: compress your files into a zip archive, extract the zipped files from a zip archive
```

## Advance usage 
ls: List (列出目前目錄中的檔案與目錄列表)
```
-l 參數可以顯示檔案與目錄的詳細資訊
-a 參數可以顯示隱藏的檔案與目錄
-R 參數可以靠遞迴的方式列出所有子目錄的檔案
-S 可以讓檔案依照檔案的大小來排序
-d 參數可以讓 ls 只列出目錄
--color 參數可以調整檔案輸出時是否要加上顏色(always, never, auto)
```

grep: (使用關鍵字或正規表示法（regular expression）篩選出想要尋找的資料，並且顯示出來)
```
grep 關鍵字 檔案1 檔案2 ...
在 /etc/os-release 檔案中搜尋 Ubuntu 關鍵字
grep Ubuntu /etc/os-release
在 /etc/os-release 檔案中搜尋 Ubuntu 關鍵字
```

|: pipe (將兩個獨立的程式給串接起來，把前面程式的輸出當作下一個程式的輸入)
```
# use file globs
ls ./A/*.cpp
ls ./A/*.{c, cpp}

# use pipe
ls -a /usr | grep '^[prs]'
ls -l | grep -E "\.(c|cpp)$"
```

## Module
```
insmod : insert module
lsmod  : list modules
rmmod  : remove module
```