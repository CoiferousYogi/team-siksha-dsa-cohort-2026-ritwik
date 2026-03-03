#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;


class Solution {
  public:

  // brute force solution: using linear search
  bool searchRowMatrixBrute(vector<vector<int>>& mat, int x) {
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            if(mat[i][j] == x) {
                return true;
            }
        }
    }

    return false;
  }

  //----------------------------------------------------------------------------------
  // Optimal Solution: Using binary search

  // funtion for binary search
    bool binarySearchRow(vector<int>& row, int x) {
        int low = 0;
        int high = row.size()-1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(row[mid] == x) {
                return true;
            }
            
            if(row[mid] < x) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;

        /*
            TC: O(rows*cols): linear search traverses each element in worst case
            SC: O(1): no extra space used
        */
    } 
    
    bool searchRowMatrixOpt(vector<vector<int>> &mat, int x) {
        // code here
        // optimal approach: binary search
        /*
            Since all rows are sorted, we can apply binary search on the rows
            But there is no guarantee that the columns will be sorted
            So to find the suitable row, we will first check the range of each row
            and check if mat[row][0] <= x <= mat[row][n-1] 
            Then apply binary search on the selected row
        */
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        // finding the suitable rows
        for(int i = 0; i < rows; i++) {
            if(mat[i][0] <= x && x <= mat[i][cols-1]) {
                bool find = binarySearchRow(mat[i], x);
                
                if(find) {
                    return true;
                } 
            }
        }
        
        return false;

        /*
        TC: O(rows * log(cols)) => For the worst case scenario, the range of each row will include the target => We will search for the suitable row (rows) times. The binary search operation for each row takes log(cols) where cols = no. of columns
        SC: O(1) => no extra space utilized.
        */
    }
};


int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int target = 10;

    Solution s;

    bool ans1 = s.searchRowMatrixBrute(mat, target);
    bool ans2 = s.searchRowMatrixOpt(mat, target);

    cout<<ans1<<endl<<ans2<<endl;
}