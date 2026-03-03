/*
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

 

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
 

Constraints:

1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    int arrayPairSumBrute(vector<int>& nums) {
        // brute force: sort the array and then make pairs from even positions
        sort(nums.begin(), nums.end());
        
        // [1,4,3,2] => [1,2,3,4]
        // now all the minimum elements of pairs are at even index
        // so we add them
        int pairSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0) {
                pairSum += nums[i];
            }
        }
        return pairSum;
    }


    int arrayPairSumOpt(vector<int>& nums) {
        // optimal: sort the array and then make pairs from the end
        sort(nums.begin(), nums.end());
        
        // [1,4,3,2] => [1,2,3,4]
        // now all the minimum elements of pairs are at even index
        // so we add them
        int pairSum = 0;
        for(int i = 0; i < nums.size(); i+=2) {
            pairSum += nums[i];
        }
        return pairSum;
    }
    // TC: O(n*log n + n/2): n*log n for sorting and n/2 for iteration
    // SC: O(1)
};


int main() {
        vector<int> nums = {6,2,6,5,1,2}; //exp : 9
        Solution s;

        int ansBrute = s.arrayPairSumBrute(nums);
        int ansOpt = s.arrayPairSumOpt(nums);

        cout<<ansBrute<<endl<<ansOpt<<endl;
    return 0;
}