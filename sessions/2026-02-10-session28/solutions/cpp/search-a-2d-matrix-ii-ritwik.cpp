#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    bool searchMatrixBrute(vector<vector<int>>& matrix, int target) {
        // brute force: linear search

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == target) {
                    return true;
                }
            }
        }

        return false;

        // TC: O(m*n)
        // SC: O(1)
    }


    // Better solution: Binary search on row and column
    bool binarySearchRow(vector<int>& row, int target) {
        int low = 0;
        int high = row.size()-1;

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
        /*
            Since the rows and columns are independently sorted, we can find the range of each row
            and then truncate our search space to those rows only
        */        

        int rows = matrix.size();
        int cols = matrix[0].size();

        // finding suitable rows
        for(int i = 0; i < rows; i++) {
            if(matrix[i][0] <= target && target <= matrix[i][cols-1]) {
                bool isTargetPresent = binarySearchRow(matrix[i], target);
                if(isTargetPresent) {
                    return true;
                }
            }
        }

        return false;
        /*
            TC: O(m * log n): For the worst case, each row's range has the target and each row takes log n time to finish binary search => m binary searches => m * log n
            SC: O(1) : no extra space used.
        */
    }


    // Optimal Solution: Step search
    /*
        target = 5
        Consider a matrix mat = [1,4,7,11]
                                [2,5,8,12]
                                [3,6,9,16]

        We start at the top right index 
        Start at Top-Right: 11. (11 > 5) => Too big Step Left.
        Current: 7. (7 > 5) => Too big. Step Left.
        Current: 4. (4 < 5) => Too small. Step Down.
        Current: 5. (5 == 5) => Target Found

    */
    bool searchMatrixOpt(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = 0;
        int j = cols - 1;
        
        while((i <= rows-1) && (j >= 0))
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(matrix[i][j] > target) // decrement j to go left
            {
                j--;
            }
            else // increment i to go right
            {
                i++;
            }
        }
        return false;
    }
};


int main() {
        vector<vector<int>> mat = {{1,4,7,11}, {2,5,8,12}, {3,6,9,16}};
        int target = 5;

        Solution s;
        bool ans1 = s.searchMatrixBrute(mat, target);
        bool ans2 = s.searchMatrixBetter(mat, target);
        bool ans3 = s.searchMatrixOpt(mat, target);

        cout<<ans1<<endl<<ans2<<endl<<ans3<<endl;
    return 0;
}