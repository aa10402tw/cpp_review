/*
return an integer representing the minimum number of swaps to sort the array.
*/

/* Solution
For each one circle of length C, we need C-1 swap
e.g., 
[(3,2,1),(6,5,4)] two circle, ans = 6 - 2 = 4
*/ 

int minimumSwaps(vector<int> arr) {
    // For each one circle of length C, we need C-1 swap
    int N = arr.size();
    std::vector<bool> visited(N, false);
    int n_circle = 0;
    for (int i=0; i<arr.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            int src = i;
            int dst = arr[i] - 1;
            while (dst != i) {
                visited[dst] = true;
                dst = arr[dst] - 1;
            }
            n_circle += 1;
        } 
    }
    return N - n_circle;
}
