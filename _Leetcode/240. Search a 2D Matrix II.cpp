/* [Question Description]
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Consider the following matrix:
Given target = 5, return true.
Given target = 20, return false.
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/* Solution: based on binary serch, but in term of 4 regions (top-left, top-right, bottom-left and bottom-right)
search in [top, bottom], [left, right]
compare the middle one m = M[(t+b)/2][(l+r)/2],
if m == target, return true
if m > target, we know target can't appear in the top-left of m, so we search top-right, bottom-left and bottom-right of m
if m < target, we know target can't appear in the right-bottom of m, so we search top-left, top-right and bottom-left of m

Time Complexity: T(m*n) = 3T(m*n/4) + O(1) = O(log(mn)) = O(log(m)+log(n))
*/

bool solve(vector<vector<int>>& matrix, int target,
  int t, int b, int l, int r) {
    if (t>b || l>r) return false;
    if (t<0 || b>matrix.size() || l<0 || r>matrix[0].size()) return false;
    if (t==b && l==r) return (matrix[t][l] == target);
    if (matrix[t][l] > target || matrix[b][r] < target) return false;
    
    if (t==b) {
        int m_lr = (l+r)/2;
        if (matrix[t][m_lr] == target) return true;
        else if (matrix[t][m_lr] > target) return solve(matrix, target, t, b, l, m_lr-1);
        else return solve(matrix, target, t, b, m_lr+1, r);
    }
    if (l==r) {
        int m_tb = (t+b)/2;
        if (matrix[m_tb][l] == target) return true;
        else if (matrix[m_tb][l] > target) return solve(matrix, target, t, m_tb-1, l, r);
        else return solve(matrix, target, m_tb+1, b, l, r);
    }
    int m_lr = (l+r)/2;
    int m_tb = (t+b)/2;
    if (matrix[m_tb][m_lr] == target) return true;
    else if (matrix[m_tb][m_lr] > target) {
        return (solve(matrix, target, t, m_tb-1, l, m_lr-1)    // top-right 
                || solve(matrix, target, t, m_tb-1, m_lr, r)   // bottom-left
                || solve(matrix, target, m_tb, b, l, m_lr-1)); // bottom-right
    }
    else{
        return (solve(matrix, target, m_tb+1, b, m_lr+1, r)   // top-left
               || solve(matrix, target, t, m_tb, m_lr+1, r)   // top-right 
               || solve(matrix, target, m_tb+1, b, l, m_lr)); // bottom-left
    }  
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int M = matrix.size();
    if (M==0) return false;
    int N = matrix[0].size();
    if (N==0) return false;
    
    int row_low = 0, col_low = 0;
    int row_high = M-1, col_high = N-1;
    return solve(matrix, target, row_low, row_high, col_low, col_high);
}
