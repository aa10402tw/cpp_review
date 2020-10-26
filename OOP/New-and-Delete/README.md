## 動態記憶體配置
- new int 會配置一個 int 所需要的空間，並傳回該空間的位址，所以您使用指標ptr來儲存這個位址
    - int *ptr = new int;
    - int *ptr = new int(100); // 指定儲存值
    - delete ptr; // 
- 動態配置陣列空間
    - int *arr = new int[1000];
    - delete [] arr;
