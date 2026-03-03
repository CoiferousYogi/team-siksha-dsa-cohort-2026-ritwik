#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


class Solution {
public:
    int searchBrute(vector<int>& nums, int target) {
        // brute force: using linear search
        int idx = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                idx = i;
                break;
            }
        }
        return idx;

        /*
            TC: O(n) Since linear search goes through every element iteratively, a search space having n elements needs n computations in worst case. 
            SC: O(1): No extra space has been used
        */
    }

    int searchOpt(vector<int>& nums, int target) {
        // optimal approach: using binary search
        int idx = -1;

        int low = 0;
        int high = nums.size()-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                idx = mid;
            }

            // we first determine which half of the array is sorted w.r.t mid
            if(nums[0] <= nums[mid]) {
                // since the array does not contain duplicate elements => above case implies left half is sorted => we can apply binary search
                // determine if the target is present in left half
                if(nums[0] <= target && target <= nums[mid]) {
                    // target is presnt in left half => discard right half
                    high = mid - 1;
                }
                else {
                    // target is not present in left half => discard left half
                    low = mid + 1;
                }
            }
            else {
                // nums[0] > nums[mid] => left half is not sorted
                // check if target is present in right half
                if(nums[mid] <= target && target <= nums[high]) {
                    // target is present in right half
                    low = mid + 1;
                }
                else {
                    // target is not present in right half
                    high = mid - 1; 
                }
            }
        }

        return idx;

        /*
            TC: O(log n): binary search halves the search space at every iteration
            SC: O(1): no extra space used. 
        */
    }
};