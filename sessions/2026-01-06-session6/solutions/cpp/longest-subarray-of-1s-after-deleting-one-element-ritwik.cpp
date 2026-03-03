/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <string>

using namespace std;


class Solution {
public:
    /*
        We need to find the length of the biggest sub-array containing only 1's after deleting an element
        Since it is a binary array, it makes sense to focus on finding the longest subarray after deleting a 0 somewhere
        But if an array does not contain any element, we still need to delete one element

        We will do this using a standard sliding window of variable length approach using 2 pointers

        Both pointers left and right which stand for the start and end of the window are initialized to the 0th index of the array

        The right pointer moves covering subsequent elements whereas the left pointer stays fixed

        When to move right pointer? => At every iteration

        When to move left pointer? => When number of 0's is greater than 1

        At each iteration, we check if the number of zeros exceeds 1.
        If yes, then we move the left pointer towards the right to remove elements and subsequently the extra zeros

        At the end of each iteration, we check if the length of the current window is the longest
    */
    int longestSubarray(vector<int>& nums) {
        // two pointer sliding window solution
        int left = 0;
        int maxLen = 0;
        int zeros = 0;

        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) {
                zeros++;
            }
            while(zeros > 1) {
                // shrink the window
                if(nums[left] == 0) {
                    // we have seen a zero => so total number of zeros will decrease after left moves
                    zeros--;
                }
                left++;
            }
            // we need to account for the zeros since we are deleting elements and not switching them
            maxLen = max(maxLen, right - left + 1 - zeros);
        }
        if(maxLen == nums.size()) {
            // if the entire array does not contain any zero, we still need to delete one element
            return nums.size() - 1;
        }
        return maxLen;

        // TC: O(n)
        // SC: O(1)
    }
};

int main() {
        vector<int> nums = {0,1,1,1,0,1,1,0,1};

        Solution s;
        int ans = s.longestSubarray(nums);
        cout<<ans<<endl;
    return 0;
}