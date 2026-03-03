#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    // brute force solution: applying linear search on the matrix
    bool searchMatrixBrute(vector<vector<int>>& matrix, int target) {
        // brute force: linear search for the target
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
        // TC: O(n*m)
        // SC: O(1)
    }

    // better solution: applying binary search on rows
    /*
        Since rows and columns both are sorted, we can find the target easily if we search for its
        range in the rows.
    */
    bool binarySearchRow(vector<int>& row, int target) {
        int low = 0;
        int high = row.size();

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(row[mid] == target) {
                return true;
            }
            else if(row[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // finding suitable rows
        for(int i = 0; i < rows; i++) {
            if(matrix[i][0] <= target && target <= matrix[i][cols-1]) {
                bool isFound = binarySearchRow(matrix[i], target);

                if(isFound) {
                    return true;
                }
            }
        }
        return false;

        // TC: O(rows * log(cols))
        // SC: O(1)
    }

    // optimal solution: step search
    /*
        For any element (m[i][j]) in a row-wise and column-wise sorted matrix,
        the element on its left and above will always be smaller than itself and
        the element on its right and below will always be bigger than itself
        So we start at the top-right corner m[0][cols-1] and then use these properties 
        to navigate through the matrix and find our target
    */
    bool searchMatrixOpt(vector<vector<int>>& matrix, int target) {
       // optimal approach: using step search
       int rows = matrix.size();
       int cols = matrix[0].size();

       int r = 0;
       int c = cols-1;

       while(r < rows && c >= 0) {
        if(matrix[r][c] == target) {
            return true;
        }
        if(matrix[r][c] > target) {
            // move left
            c--;
        }
        else {
            // move to next row
            r++;
        }
       }
       return false;
       // TC: O(rows + cols)
       // SC: O(1)
    }
};

int main() {
        vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        int target = 3;

        Solution s;
        
        bool ansBrute = s.searchMatrixBrute(matrix, target);
        bool ansBetter = s.searchMatrixBetter(matrix, target);
        bool ansOpt = s.searchMatrixOpt(matrix, target);

        cout<<ansBrute<<endl<<ansBetter<<endl<<ansOpt<<endl;
    return 0;
}