/*
Given a sorted array arr[] (0-index based) of distinct integers and an integer k, find the index of k if it is present in the arr[]. If not, return the index where k should be inserted to maintain the sorted order.

Examples :

Input: arr[] = [1, 3, 5, 6], k = 5
Output: 2
Explanation: Since 5 is found at index 2 as arr[2] = 5, the output is 2.
Input: arr[] = [1, 3, 5, 6], k = 2
Output: 1
Explanation: The element 2 is not present in the array, but inserting it at index 1 will maintain the sorted order.
Input: arr[] = [2, 6, 7, 10, 14], k = 15
Output: 5
Explanation: The element 15 is not present in the array, but inserting it after index 4 will maintain the sorted order.
Constraints:
1 ≤ arr.size() ≤ 104
-103 ≤ arr[i] ≤ 103
-103 ≤ k ≤ 103

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
    public:
    // this problem is akin to finding the lower bound of an element in a sorted array
    // lower bound of an element in a sorted array is the smallest index where the element is greater than or equal to the target
    int findInsertPositionBrute(vector<int>& nums, int x) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= x) {
                return i;
            }
        }

        return nums.size();
    }

    int findInsertPositionOpt(vector<int>& nums, int x) {
        int idx = nums.size();

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == x) {
                idx = mid;
                high = mid - 1;
            }
            else if(nums[mid] < x) {
                low = mid + 1;
            }
            else {
                // nums[mid] > x
                high = mid - 1;
            }
        }
        return idx;
    }
};

int main() {
        int x = 15;
        vector<int> nums = {2, 6, 7, 10, 14};

        Solution s;
        int ansBrute1 = s.findInsertPositionBrute(nums, x);
        int ansOpt1 = s.findInsertPositionOpt(nums, x);

        cout<<ansBrute1<<endl<<ansOpt1<<endl;
    return 0;
}