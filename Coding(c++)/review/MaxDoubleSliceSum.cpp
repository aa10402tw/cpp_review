/*
A triplet (X, Y, Z), such that 0 ? X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of 
A[X + 1] + A[X + 2] + ... + A[Y - 1] + 
A[Y + 1] + A[Y + 2] + ... + A[Z - 1].

returns the maximal sum of any double slice.
*/

/* Solution:
the max slice sum of Y=i is the sum of max subarray [X+1...Y-1] and max subarray[Y+1...Z-1]  
1. compute the max subarray [X+1...i] for all i in [1...N-2] -> O(N)
2. compute the max subarray [i...Z-1] for aii i in [1...N-2] -> O(N)
3. iterate all Y, compute max slice sum of Y by sum([X+1...Y-1], [Y+1...Z-1]) = L[Y-1] + R[Y+1] -> O(N)
*/

int solution(vector<int> &A) {
    int N = A.size();
    std::vector<int> maxSubArrL(N, 0); // max sub array [X+1...i]
    std::vector<int> maxSubArrR(N, 0); // max sub array [i...Z-1]
    
    for (int i=1; i<N; i++) {
        maxSubArrL[i] = std::max(maxSubArrL[i], A[i]);
        if (i > 1) maxSubArrL[i] = std::max(maxSubArrL[i], A[i]+maxSubArrL[i-1]);
    }
    for (int i=N-2; i>=0; i--) {
        maxSubArrR[i] = std::max(maxSubArrR[i], A[i]);
        if (i < N-2) maxSubArrR[i] = std::max(maxSubArrR[i], A[i]+maxSubArrR[i+1]);
    }
    int maxSlice = 0;
    for (int Y=1; Y<N-1; Y++) {
        maxSlice = std::max(maxSlice, maxSubArrL[Y-1]+maxSubArrR[Y+1]);
    }
    return maxSlice;
}
