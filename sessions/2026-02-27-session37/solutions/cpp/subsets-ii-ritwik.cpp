/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtracking(vector<int>& nums, vector<int> ds, vector<vector<int>>& res, int idx) {
        // add the subset to the answer
        res.push_back(ds);

        // select other elements
        for(int i = idx; i < nums.size(); i++) {
            // select the element at i
            ds.push_back(nums[i]);
            // move down the recursive tree by selecting the element at i
            backtracking(nums, ds, res, i + 1);
            // backtrack by removing the selected element which simulates not choosing element at i
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds; // vector for subset
        vector<vector<int>> res; // final answer 

        backtracking(nums, ds, res, 0);

        return res;
    }
};


int main() {
        vector<int> nums = {1,2,2};

        Solution s;
        vector<vector<int>> res = s.subsets(nums);

        for (const auto& row : res) {
        for (const auto& elem : row) {
            cout<<elem<< " ";
        }
        cout <<endl; 
    }

    return 0;
}