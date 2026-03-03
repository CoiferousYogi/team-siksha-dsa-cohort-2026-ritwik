/*
    Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.

    For a sorted array, the lower bound of an element is the first position at which the element can be inserted without disturbing the order.

Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
    public:
    int lowerBoundBrute(vector<int>& nums, int target) {
        int lb = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= target) {
                lb = i;
                break;
            }
        }

        return lb;

        // TC: O(n)
        // SC: O(1)
    }

    int lowerBoundOpt(vector<int>& nums, int target) {
        /*
            optimal approach using binary search
            Since the given array is sorted, we can apply binary search
            We need to find the first index, idx such that nums[idx] >= target
        */
        
        int lb = nums.size();

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target) {
                // mid might be an answer
                lb = mid;
                // search for index lower than mid
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return lb;
    }
};

int main() {
        vector<int> nums = {2, 3, 7, 10, 11, 11, 25};
        int target1 = 9;
        int target2 = 100;
        int target3 = 0;

        Solution s;
        int ansBrute1 = s.lowerBoundBrute(nums, target1);
        int ansBrute2 = s.lowerBoundBrute(nums, target2);
        int ansBrute3 = s.lowerBoundBrute(nums, target3);

        int ansOpt1 = s.lowerBoundOpt(nums, target1);
        int ansOpt2 = s.lowerBoundOpt(nums, target2);
        int ansOpt3 = s.lowerBoundOpt(nums, target3);

        cout<<"Brute force: "<<ansBrute1<<endl<<ansBrute2<<endl<<ansBrute3<<endl;

        cout<<"Optimal: "<<ansOpt1<<endl<<ansOpt2<<endl<<ansOpt3<<endl;
    return 0;
}