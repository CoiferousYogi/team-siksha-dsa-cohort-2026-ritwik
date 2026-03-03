/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <set>

using namespace std;

class Solution {
public:
    int removeDuplicatesBrute(vector<int>& nums) {
        // brute force: using a set and then traversing the array
        // and putting elements from the set in the array
        set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        // now we will traverse the array and put elements of set in the array
        int idx = 0;
        for(int ele : st) {
            nums[idx] = ele;
            idx++;
        }

        return st.size();

        // TC: O(n+n)
        // SC: O(n): Extra space for set
    }


    int removeDuplicatesOpt(vector<int>& nums) {
        // optimal approach: using 2 pointers
        int n = nums.size();

        if(n == 1) {
            return 1;
        }

        int left = 1;
        for(int right = 1; right < n; right++) {
            if(nums[left-1] != nums[right]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;

        // TC: O(n)
        // SC: O(1)
    }
};