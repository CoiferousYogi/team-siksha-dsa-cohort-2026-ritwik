/*
Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

Examples:

Input: mat[][] = [[1, 3, 5], 
                [2, 6, 9], 
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
Input: mat[][] = [[2, 4, 9],
                [3, 6, 7],
                [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
Constraints:
1 ≤ n, m ≤ 400
1 ≤ mat[i][j] ≤ 2000

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    int medianBrute(vector<vector<int>>& mat) {
        // brute force: put all elements of matrix in an array, sort it and then find the median
        vector<int> matrix;

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                matrix.push_back(mat[i][j]);
            }
        }

        sort(matrix.begin(), matrix.end());

        int n = matrix.size();

        return matrix[(n+1)/2];

        /*
            TC: O(m*n + m*n log(m*n)) : m*n for traversing the matrix, m*n log(m*n) for sorting the matrix array
            SC: O(m*n): space for matrix array
        */
    }

    int upperBoundCount(vector<vector<int>> &mat, int rowIndex, int target){
        
        int low = 0;
        int high = mat[0].size() - 1;
        int ansIndex = mat[0].size();  // Initialize to size, not size-1
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(mat[rowIndex][mid] > target){
                ansIndex = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return ansIndex;  // Return ansIndex, not ansIndex+1
    }
    
    int medianOpt(vector<vector<int>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        int medianIndex = (n * m + 1) / 2;
        
        for(int i = 0; i < n; i++){
            if(mat[i][0] < mini)
                mini = mat[i][0];
            
            if(mat[i][m-1] > maxi)
                maxi = mat[i][m-1];
        }
        
        int low = mini;
        int high = maxi;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low) / 2;
            int count = 0;
            
            for(int i = 0; i < n; i++){
                count += upperBoundCount(mat, i, mid);
            }
            
            if(count >= medianIndex){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;

        /*
            TC: O(n log m * log(maxi – mini))
            SC: O(1)
        */
    }
};

int main() {
    return 0;
}