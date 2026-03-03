/*
Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
    public:
    int upperBoundBrute(vector<int>& nums, int target) {
        int ub = nums.size();

        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] <= target) {
                ub = i + 1;
                break;
            }
        }
        return ub;
    }

    int upperBoundOpt(vector<int>& nums, int target) {
        int ub = nums.size();

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > target) {
                ub = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ub;
    }
};

int main() {
        vector<int> nums = {2, 3, 7, 10, 11, 11, 25};
        int target1 = 9;
        int target2 = 11;
        int target3 = 100;

        Solution s;
        int ansBrute1 = s.upperBoundBrute(nums, target1);
        int ansBrute2 = s.upperBoundBrute(nums, target2);
        int ansBrute3 = s.upperBoundBrute(nums, target3);

        int ansOpt1 = s.upperBoundOpt(nums, target1);
        int ansOpt2 = s.upperBoundOpt(nums, target2);
        int ansOpt3 = s.upperBoundOpt(nums, target3);

        cout<<"Brute force: "<<ansBrute1<<endl<<ansBrute2<<endl<<ansBrute3<<endl;

        cout<<"Optimal: "<<ansOpt1<<endl<<ansOpt2<<endl<<ansOpt3<<endl;
    return 0;
}