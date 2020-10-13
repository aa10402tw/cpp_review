## Trie/Prefix Tree
字典樹(Trie/Prefix Tree)，也被稱為單詞搜尋樹，是一種很特別的樹狀資料結構，如同其名，它就像一本⫿典，
可以讓你快速的依照⫿母插入、尋找⫿串，由於高效的特性，特別適用於大量⫿串出現的時候。

## 性質
與二分搜尋樹、堆積…等利用鍵值來建立的資料結構不同，字典樹最特別的地方就是善用字串的特性：利用每個字串的共同前綴(common prefix)當儲存依據，並以此來節省儲存空間以及加速搜尋時間 ，並以此來節省儲存空間以及加速搜尋時間。

利用樹狀結構，我們將每個節點(Node)代表一個字母(但根節點(Root)不能包含任何字母。
每個子節點分別代表字串的下個字母，而整棵樹的高度則為最長字串的長度 + 1。

從根節點往下走訪 根節點往下走訪到的每個節點都可能代表一個字串(字串長度為節點深度-1)，不一定僅限於葉子 不一定僅限於葉子，而每個字串的共同前綴都只會儲⬀一次 每個字串的共同前綴都只會儲⬀一次，有著共同前綴的⫿串
們會被擺在一起，並從代表從最長共同前綴以下才開始分歧，也就是說，最長共同前綴發生於代表兩字串最長共同前綴發生於代表兩字串節點的最近共同祖先(Least Common Ancestor LCA)上。

## 字典樹的優缺點 
Trie 最大的優點就是運作速度非常快且容易撰寫，針對查詢是否存在在以及前綴相關的問題幾乎都有非常好的效果，但缺點就是相當耗費記憶體，雖然已經把共同前綴合併，但每個節點上面還是有著 ALPHABET_SIZE 個指標，且大部分情況下都會存在在大量的空指標，用的時候需要斟酌一下。

## 用途
#### (1) 字串檢索
查詢某一個單詞是否在樹中。思路就是從根節點開始一個一個字元進行比較：
如果沿路比較，發現不同的字元，則表示該字串在集合中不存在。
如果所有的字元全部比較完並且全部相同，還需判斷最後一個節點的標誌位（標記該節點是否代表字串最後一個字元）。
#### (2) 詞頻統計
Trie樹常被搜尋引擎系統用於文字詞頻統計。
#### (3) 去除重複單詞
建立字典樹的過程就是給字串去重復的過程。
#### (4) 字串排序
這是字典樹的一個小應用，字典樹就像字典一般，按照字母查詢並印下來就會是一個順序的關係 按照字母查詢並印下來就會是一個順序的關係，所以按照字母順序進行字典樹的深度優先搜尋(DFS)就可以輕易地做到字串排序，複雜度是(節點個數)。
#### (5) 最長公共字首
查詢N個單詞的最長公共字首（Root到最近共同祖先(Least Common Ancestor LCA))
#### (6) 字首匹配
比如要找以“an”為字首的字串

 ## 例題
 1. UVAOJ 10226 Hardwood species
給定很多字串，要求按照字母順序輸出每個字串在輸入中的百分比。

## UVAOJ 409 Excuses,Excusess!
給定很多關鍵字，還有很多藉口，要求輸出關鍵字最多的藉口（可重複計算）


## 字典樹的資料結構實作 Data Structure of Trie
#### Node Structure
```
struct TrieNode
{
     struct TrieNode *children[ALPHABET_SIZE]; // ALPHABET_SIZE=26 normally
     // isEndOfWord is true if the node represents end of a word
     bool isEndOfWord;

     /* optional attribute 
     int count; // record the word frequency, it can replace the attribute isEndOfWord (count > 0 mean true)
     */
};
```
#### Create Node
```
struct TrieNode *createNode() 
{ 
    struct TrieNode *pNode =  new TrieNode(); 
  
    pNode->isEndOfWord = false; 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = nu;lptr; 
    return pNode; 
} 
```
#### Insert Node
```
// If not present, inserts key into trie 
// If the key is prefix of trie node, just marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pNode = root; 
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 'a'; 
        if (!pNode->children[index]) 
            pNode->children[index] = createNode(); 
        pNode = pNode->children[index]; 
    } 
    // mark last node as leaf 
    pNode->isEndOfWord = true; 
} 
```

#### Insert if a string appear in trie
```
// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pNode = root; 
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 'a'; 
        if (!pNode->children[index]) 
            return false; 
        pNode = pCrawl->children[index]; 
    } 
    return (pNode != nullptr && pNode->isEndOfWord); 
} 
```