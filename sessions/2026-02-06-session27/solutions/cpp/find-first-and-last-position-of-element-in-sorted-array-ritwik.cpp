#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    // brute force solution: using linear search
    int firstOccuranceLinear(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    int lastOccuranceLinear(vector<int>& nums, int target) {
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
    vector<int> searchRangeBrute(vector<int>& nums, int target) {
        // brute force: 2 linear search
        int fo = firstOccuranceLinear(nums, target);
        int lo = lastOccuranceLinear(nums, target);

        return {fo, lo};

        // TC: O(n + n)
        // SC: O(1)
    }


    // optimal solution: using binary search
    int firstOccurance(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int idx = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                idx = mid; // mid is a probable answer
                // discard right half to find first occurance
                high = mid - 1;
            }
            else if(nums[mid] > target) {
                high = mid - 1;
            }
            else {
                // nums[mid] < target
                low = mid + 1;
            }
        }
        return idx;
    }

    int lastOccurance(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int idx = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                idx = mid; 
                low = mid + 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid -1;
            }
        }
        return idx;
    } 
    vector<int> searchRangeOpt(vector<int>& nums, int target) {
        // optimal approach: 2 binary search
        int fo = firstOccurance(nums, target);
        int lo = lastOccurance(nums, target);

        return {fo, lo};

        // TC: O(log n + log n)
        // SC: O(1)
    }
};

int main() {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 8;

        Solution s;

        vector<int> ansBrute = s.searchRangeBrute(nums, target);
        vector<int> ansOpt = s.searchRangeOpt(nums, target);

        for(int i = 0; i < ansBrute.size(); i++) {
            cout<<ansBrute[i]<<" ";
        }
        cout<<endl;

        for(int i = 0; i < ansOpt.size(); i++) {
            cout<<ansOpt[i]<<" ";
        }
        cout<<endl;
    return 0;
}