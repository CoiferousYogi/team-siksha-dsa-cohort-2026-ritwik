/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

int linearSearch(vector<int>& nums, int target) {
    int ans = -1;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == target) {
            ans = i;
            break;
        }
    }
    return ans;

    /*
        TC: O(n)
        SC: O(1)
    */
}


int binarySearch(vector<int>& nums, int target) {   
        // edge cases
        if(nums[0] == target) {
            return 0;
        }     
        if(nums[nums.size()-1] == target) {
            return nums.size()-1;
        }

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    return -1;

    /*
        TC: O(log n)
        SC: O(1)
    */
}

int main() {
        vector<int> nums = {1,2,3,4,5};
        int target = 3;

        int ans = binarySearch(nums, target);
        cout<<ans<<endl;
    return 0;
}