/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void findSubsets(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int idx) {
        if(idx == nums.size()) {
            res.push_back(subset);
            return;
        }

        // choose the element at idx
        subset.push_back(nums[idx]);

        findSubsets(nums, subset, res, idx+1);

        // backtrack => do not choose the element at idx
        subset.pop_back();

        findSubsets(nums, subset, res, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;

        findSubsets(nums, subset, res, 0);

        return res;
    }
};


int main() {
        vector<int> nums = {1,2,3};

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