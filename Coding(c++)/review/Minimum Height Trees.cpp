#include <iostream>
#include <string>
#include <queue>
#include <vector>

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    // 每次刪除 degree = 1 之點（leaf）
    std::unordered_map<int, std::unordered_set<int>> hash;
    for(auto e:edges) {
        int i=e[0], j=e[1];
        hash[i].insert(j);
        hash[j].insert(i);
    }
    
    std::queue<int> Q;
    for (int i=0; i<n; i++)
        if (hash[i].size() == 1) 
            Q.push(i);
    
    while (hash.size() > 2) {
        std::queue<int> tmp;
        while (!Q.empty()) {
            int src = Q.front();
            Q.pop();
            int dst = *(hash[src].begin());
            hash.erase(src);
            hash[dst].erase(src);
            if (hash[dst].size() == 1)
                tmp.push(dst);
        }
        Q = tmp;
    }
    
    std::vector<int> result;
    for (auto pair:hash) {
        result.push_back(pair.first);
    }
    return result;

}
