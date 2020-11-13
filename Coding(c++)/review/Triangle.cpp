/*
Determine whether a triangle can be built from a given set of edges.
A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].
*/

#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    if (N < 3) return 0;
    std::sort(A.begin(), A.end());
    
    for (int m=1; m<N-1; m++) {
        long long int low = A[m-1], mid=A[m], high=A[m+1];
        if (low+mid>high) return 1;
    }
    return 0;
}
