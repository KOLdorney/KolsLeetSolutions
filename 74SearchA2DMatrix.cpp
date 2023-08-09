/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.*/

//Pretty straightforward O(n^2) solution, with some optimization (if we pretend there is no such thing as a branch predictor unit)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int end = matrix[0].size()-1;
        for (int i = 0; i < matrix.size(); i++){
            if (matrix[i][end] >= target){
                for (int j = end; j >= 0; j--){
                    if (matrix[i][j] == target) return true;
                }
            }
        }
        return false;
    }
};
