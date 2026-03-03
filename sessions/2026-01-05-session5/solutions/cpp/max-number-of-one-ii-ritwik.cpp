/*
You are given a binary array arr[], containing only 0s and 1s. You are allowed to flip at most one 0 to 1.
Your task is to determine the maximum length of consecutive 1s that can be obtained in the array after performing at most one such flip.

Example:

Input: arr[] = [0, 1, 0, 1, 1]
Output: 4
Explanation: 
If we flip the first zero, nums becomes [1,1,0,1,1] and we have 2 consecutive ones.
If we flip the second zero, nums becomes [0,1,1,1,1] and we have 4 consecutive ones.
The max number of consecutive ones is 4.

Input: arr[] = [0, 1, 0]
Output: 2
Explanation:  
If we flip the first zero, nums becomes [1,1,0] and we have 2 consecutive ones. 
If we flip the second zero, nums becomes [0,1,1] and we have 2 consecutive ones. 
The max number of consecutive ones is 2.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
    public:
    /*
        The longest subarray of 1's where we can flip at most one 0 to 1 is the longest subarray of 1's with just one 0.

        Since we only need to find the length of such subarray, we only keep a record of the counts of elements
        We need to track the maximum length of the valid subarray, number of 1's and number of 0's

        Sliding window + greedy approach
        We start from the beginning and then work our way towards the end of the array
        Whenever we get a 1, we increment countOnes
        If nums[i] == 1:
            countOnes += 1
            subLen++
        
        if nums[i] == 0:
            subLen = countOnes + 1 // this ensures we take only 1 zero in account for length of sub-array
            countOnes = 0
    */
    int maxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int subLen = 0;
        int countOnes = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                countOnes++;
                subLen++;
            }
            else {
                // nums[i] == 0
                subLen = countOnes + 1;
                countOnes = 0;
            }
            maxLen = max(maxLen, subLen);
        }

        return maxLen;

        /*
            TC: O(n)
            SC: O(1)
        */
    }
};

int main() {
        vector<int> nums = {0, 1, 0, 1, 1}; // exp: 4

        Solution s;

        int ans = s.maxConsecutiveOnes(nums);
        cout<<ans<<endl;
    return 0;
}