#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    // brute force approach using linear search
    bool searchBrute(vector<int>& nums, int target) {
            // brute force: using linear search
            // edge case : array contains a single element
            if(nums.size() == 1 && nums[0] != target) {
                return false;
            }

            bool ans = false;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == target) {
                    ans = true;
                    return ans;
                }
            }

        return ans;
        // TC: O(n)
        // SC: O(1)
    }

    // Optimized approach using binary search
    bool searchOpt(vector<int>& nums, int target) {
        // optimal approach: using binary search
        
        // edge case: single element array
        if(nums.size() == 1) {
            return nums[0] == target;
        }

        // first or last element is the target 
        if(nums[0] == target || nums[nums.size()-1] == target) {
            return true;
        }

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                return true;
            }

            // since there can be repetitions and the array is rotated
            // there is a chance that nums[low] == nums[mid] == nums[high]
            if(nums[low] == nums[mid] && nums[high] == nums[mid]) {
                low++;
                high--;
                continue;
            }

            // search for rotated half
            if(nums[low] <= nums[mid]) {
                // left half is sorted => can apply binary search
                // check if target is present in left half
                if(nums[low] <= target && target < nums[mid]) {
                    // target might be present in left half => discard right half
                    high = mid - 1;
                }
                else {
                    // target is not present in left half
                    low = mid + 1;
                }
            }
            else {
                // nums[low] > nums[mid] => left half is not sorted
                // check if target exists in right half
                if(nums[mid] < target && target <= nums[high]) {
                    // target is present in right half
                    low = mid + 1;
                }
                else {
                    // target is not present in right half
                    high = mid - 1;
                }
            }
        }
        return false;

        /*
            TC: O(log n)
            SC: O(1)
        */
    }
};

int main() {
    vector<int> arr1 = {1,0,1,1,1};
    vector<int> arr2 = {2,5,6,0,0,1,2};
    int target1 = 0;
    int target2 = 3;

    Solution s;

    int ans1 = s.searchBrute(arr1, target1);
    int ans2 = s.searchOpt(arr1, target1);

    cout<<ans1<<endl<<ans2<<endl;
}