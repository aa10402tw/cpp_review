/*
for each query a,b,k
add [a...b] by k
return the maximum value in the resultant array
*/

/* Solution
For a value k, we can mark its left endpoint a in the original array, 
along with its right endpoint b in the original array. 

To distinguish between a and b we can store +k for a and -k for b. 
Now, we technically have stored all information that the m operations represent, 
into an array. Most importantly, we stored it in O(m) time.

The next step is to actually find the maximum value based off of our unique representation of the data. 
We traverse our array from left to right. Whenever we reach a left endpoint a (which we represented with a positive number), 
we just add that to our sum. Whenever we reach a right endpoint b (which we represented with a negative number), 
we subtract that from our sum (well, technically we add a negative value). 
By doing so, the value sum represents the value that array[i] would have if we had applied all m operations to it. 
The maximum value of sum that we get while traversing the array is the value we return. 
If this algorithm is still unclear to you, try walking through HackerRank's Testcase 0 with the code above.
*/ 

long arrayManipulation(int n, vector<vector<int>> queries) {
    std::vector<long long int> arr(n+1, 0);
    for (auto q:queries) {
        int a=q[0], b=q[1], k=q[2];
        arr[a-1] += static_cast<long long int>(k);
        arr[b] -= static_cast<long long int>(k); 
    }
    long ans = 0;
    long sum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
        ans = std::max(ans, sum);
    }
    return ans;
}

