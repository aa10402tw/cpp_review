## KMP(Knuth-Morris-Pratt) String Matching
KMP主要利用「次長的相同前綴後綴」(Longest Proper prefix which is also suffix) 來省下重複的比對過程
- Time Complexity: O(m+n), while brute force take O(m*n)
- 需要先計算 pattern P 之 Failure Function (每個索引值前字串的最長相同前綴後綴)
  - Failure Function = F(k) = the length of the longest prefix of P that is also a suffix of P[1..k].
  - i.e., P[0:F(k)] == P[(k+1)-F(k):(k+1)]
  - e.g. P = "abaaba", F = [001123]
  - 計算 failure function: 
    - 用 DP，設定 k = F[j-1] (已知 P[0:k] == P[(j-k):j])
    - j 位置的新元素去跟 k-th 的元素比較 (P[k] == P[j]?)
      - 若不同，k = F[k] 
        - 直到 P[k+1] == P[j] 或 k = 0 
      - 檢查是否 (P[k] == P[j]) 若滿足，P[j] = k+1

- KMP 邏輯:  
  - i 代表 string pos, j 代表 patten pos （初始皆為0）
  - 每一步比較 s[i] 與 p[j]
    - 若 s[i] == p[j] -> i++, j++
    - 若 s[i] != p[j]
      - 若 j==0 -> i++
      - else -> j = F(j-1)
      - （設 k=F[j-1], 已知 p[0:k] == p[(j-k):j]，所以可以直接從 F(j-1)+1 開始比）
  - 例子 S = "abaabc"，P = "abaaba" 比到最後一個字元時不相符，但已知 F[4] = 2（代表 [ab]a[ab]），因此把 j 移動到已知最長前綴後綴的下一個(ab[a]ab) 與 c 做比較 
    - 比較最後一個位元一開始
      - [abaab"c"]
      - [**ab**a**ab**"a"]
    - 下一步
      - [abaab"c"]
      - [---**ab**"a"**ab**a]
- 程式碼:
```
std::vector<int> getFailureFunction(std::string pattern) {
    int n = pattern.size();
    std::vector<int> failure(n, 0); 
    for (int j = 1; j < n; j++) {
        int k = failure[j - 1]; // P[0:k] == P[(j-k):j]
        while ((pattern[j] != pattern[k]) && k > 0) { // check P[k] == P[j]
            k = failure[k];
        }
        if (pattern[j] == pattern[k]) {
            failure[j] = k + 1;
        }
    }
    return failure;
}
```
```
std::vector<int> KMP(std::string target, std::string pattern) {
    int m = target.size();
    int n = pattern.size();
    std::vector<int> failure = getFailureFunction(pattern);
    std::vector<int> matchIdxs;

    int i = 0, j = 0;
    while (i < m && j < n) {
        if (target[i] == pattern[j]) {
            if (j == pattern.size()-1) {
                matchIdxs.push_back(i - n + 1);
                j = failure[j] - 1; 
            }
            else {
                i += 1;
                j += 1;
            }
        }
        else {
            if (j == 0) i += 1;
            else j = failure[j-1];
        }
    }
    return matchIdxs;
}
```

