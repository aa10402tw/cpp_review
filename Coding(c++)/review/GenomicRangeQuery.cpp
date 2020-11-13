#include <unordered_map>

/* find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).*/
 
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = S.size();
    int M = Q.size();
    
    std::unordered_map<char, int> dict;
    dict['A'] = 1;
    dict['C'] = 2;
    dict['G'] = 3;
    dict['T'] = 4;
    
    std::vector<std::vector<int>> prefixCount(N+1, std::vector<int>(5, 0));
    for (int i=1; i<=N; i++) {
        prefixCount[i] = prefixCount[i-1];
        int idx = dict[S[i-1]];
        prefixCount[i][idx] += 1;
        // std::cout << prefixCount[i][1] << "," << prefixCount[i][2] << "," << prefixCount[i][3] << "," << prefixCount[i][4] << "," << std::endl;
    }
    
    std::vector<int> result(M);
    for (int i=0; i<M; i++) {
        int s=P[i], e=Q[i];
        for (int k=1; k<=4; k++) {
            if (prefixCount[e+1][k] - prefixCount[s][k] > 0) {
                result[i] = k;
                break;
            }
        }
    }
    
    return result;

}
