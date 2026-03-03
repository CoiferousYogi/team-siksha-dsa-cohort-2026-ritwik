/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
 

Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void runningSumHelper(vector<int>& nums, vector<int>& prefixSum, int currSum, int idx) {
        if(idx == nums.size()) {
            return;
        }

        currSum += nums[idx];
        prefixSum.push_back(currSum);

        runningSumHelper(nums, prefixSum, currSum, idx+1);
    }

public:
    vector<int> runningSumIter(vector<int>& nums) {
        vector<int> prefixSum;
        int sum = nums[0];

        prefixSum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            prefixSum.push_back(sum);
        }

        return prefixSum;
    }

    vector<int> runningSumRec(vector<int>& nums) {
        vector<int> prefixSum;

        // Edge case: empty arrays
        if(nums.empty()) {
            return prefixSum;
        }

        runningSumHelper(nums, prefixSum, 0, 0);

        return prefixSum;
    }
};