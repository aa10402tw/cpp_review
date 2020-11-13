#include <iostream> 
using namespace std; 
  
// Find the index of first number that greater than target (return -1 if not found)
int next(int arr[], int target, int end) 
{ 
    int start = 0; 
    int ans = -1; 
    while (start <= end) 
    { 
        int mid = (start + end) / 2; 
  
        // Move to right side if target is greater. 
        if (arr[mid] <= target) 
            start = mid + 1; 
  
        // Move left side. 
        else
        { 
            ans = mid; 
            end = mid - 1; 
        } 
    } 
    return ans; 
} 
