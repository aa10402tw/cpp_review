/* [Question Description]
Given an integer, write a function to determine if it is a power of three.
Follow up:
Could you do it without using any loop / recursion?

# Example 1
Input: 27
Output: true

# Example 2
Input: 0
Output: false

# Example 3
Input: 9
Output: true

# Example 4
Input: 45
Output: false
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/* 
We start search the matrix from top right corner, initialize the current position to top right corner, 
if the target is greater than the value in current position, then the target can not be in entire row of current position because the row is sorted, 
if the target is less than the value in current position, then the target can not in the entire column because the column is sorted too. 
We can rule out one row or one column each time, so the time complexity is O(m+n).
*/ 
public boolean searchMatrix(int[][] matrix, int target) {
    if(matrix == null || matrix.length < 1 || matrix[0].length <1) {
        return false;
    }
    int col = matrix[0].length-1;
    int row = 0;
    while(col >= 0 && row <= matrix.length-1) {
        if(target == matrix[row][col]) {
            return true;
        } else if(target < matrix[row][col]) {
            col--;
        } else if(target > matrix[row][col]) {
            row++;
        }
    }
    return false;
}
