#include <iostream>
#include <vector>

int binary_search_row(std::vector<std::vector<int>>& matrix, int target, int low, int high) {
    if (low >= high) return low;
    int n_col = matrix[0].size();
    int mid = (low + high) / 2;
    if (matrix[mid][n_col-1] < target) 
        return binary_search_row(matrix, target, mid+1, high);
    else 
        return binary_search_row(matrix, target, low, mid); 
}

int binary_search_col(std::vector<std::vector<int>>& matrix, int row, int target, int low, int high) {
    if (low > high) return -1;
    int mid = (low+high) / 2;
    if (matrix[row][mid] == target) 
        return mid;
    else if (matrix[row][mid] < target)
        return binary_search_col(matrix, row, target, mid+1, high);
    else
        return binary_search_col(matrix, row, target, low, mid-1);
}

std::pair<int, int> search(std::vector<std::vector<int>>& matrix, int target) {
    int M = matrix.size();	
    int N = matrix[0].size();
    int row = binary_search_row(matrix, target, 0, M-1);
    int col = binary_search_col(matrix, row, target, 0, N-1);
    if (col == -1) return std::make_pair(-1, -1);
    else return std::make_pair(row, col);
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) return false;
    std::pair<int, int> pos = search(matrix, target);
    return pos.first != -1;
}
