/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

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

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicatesBrute(vector<int>& nums) {
        // brute force solution: using a map
        unordered_map<int, int> mp;

        int idx = 0; // tells us when to drop elements

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            
            // check the frequency of nums[i]
            if(mp[nums[i]] <= 2) {
                nums[idx] = nums[i];
                idx++; 
            }
        }
        return idx;

        /*
            TC: O(n): for traversing over the array
            SC: O(n): Extra space needed for map
        */
    }

    int removeDuplicatesOpt(vector<int>& nums) {
        // optimal solution: using 2 pointers

        int n = nums.size();
        
        // edge case: the array contains <= 2 elements
        // since an element can appear at most twice, all arrays with <= 2 elements are valid
        if(n <= 2) {
            return n;
        }

        /*
            2 pointer logic: since the array is sorted and any element can appear at most twice
            We start at the 2nd index of the array using 2 pointers left and right
            The left pointer is for comparison with the right pointer

            nums = [1,1,1,2,2,3]
            For the right pointer we just need to check if the element at left pointer appears >= 3 times or not
            Initially, left = 2 and right = 2
                    nums[left] = 1 and nums[right] = 1
                    nums[left-1] = 1 and nums[left-2] = 1
                    => nums[right] = nums[left-1] = nums[left-2] => 1 is repeated thrice
                    => left does not move but right is incremented

                    left = 2 and right = 3
                    nums[left] = 1 and nums[right] = 2
                    nums[left-1] = 1 and nums[left-2] = 1
                    => nums[right] != nums[left-1] and nums[right] != nums[left-2]
                    => left++

                    left = 3 and right = 4
                    nums[left] = 2 and nums[right] = 2
                    nums[left-1] = 1 and nums[left-2] = 1
                    => nums[right] != nums[left-1] and nums[right] != nums[left-2]
        */

        int left = 2;
        for(int right = 2; right < n; right++) {
            // check for the conditions
            if(nums[right] != nums[left - 1] && nums[right] != nums[left - 2]) {
                left++;
            }
        }

        return left;

        /*
            TC: O(n) => array traversal
            SC: O(1) => no extra space used
        */
    }
};

int main() {
        vector<int> nums = {0,0,1,1,1,1,2,3,3};
        
        Solution s;
        int ansBrute = s.removeDuplicatesBrute(nums);
        int ansOpt = s.removeDuplicatesOpt(nums);

        cout<<ansBrute<<endl<<ansOpt<<endl;
    return 0;
}