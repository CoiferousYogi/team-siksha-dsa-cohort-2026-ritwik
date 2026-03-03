/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnesOpt(vector<int>& nums) {
        // brute force: initiate count to 0, increment count when nums[i] == 1 and reset count if nums[i] == 0
        int count = 0;
        int maxCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
            }
            else {
                count = 0;
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;

        /*
            TC: O(n)
            SC: O(1)
        */
    }
};

int main() {
        vector<int> nums = {1,0,1,1,0,1};

        Solution s;
        
        int ans = s.findMaxConsecutiveOnesOpt(nums);
        cout<<ans<<endl;
    return 0;
}