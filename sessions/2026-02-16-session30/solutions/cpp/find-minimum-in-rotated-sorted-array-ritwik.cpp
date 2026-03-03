#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    int findMinBrute(vector<int>& nums) {
        // brute force: linear search approach
        int minEle = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < minEle) {
                minEle = nums[i];
            }
        }

        return minEle;
    }

    int findMinOpt(vector<int>& nums) {
        // optimised approach using binary search
        int minEle = INT_MAX;

        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // check if the array is sorted or if no. of rotations(k) is s.t n % k = 0
            if(nums[low] < nums[high]) {
                // array is sorted
                minEle = min(minEle, nums[low]);
                break;
            }

            // if(nums[low] <= nums[mid]) => left half is sorted => nums[low] might be the answer
            if(nums[low] <= nums[mid]) {
                minEle = min(minEle, nums[low]);
                // eliminate left half to search for elements, nums[i] st nums[i] < minEle
                low = mid + 1; 
            }
            else {
                // nums[low] > nums[mid] => nums[mid] might be the answer
                minEle = min(minEle, nums[mid]);
                // discard right half to search for elements smaller than nums[mid]
                high = mid - 1;
            }
        }
        return minEle;
    }
};

int main() {
        vector<int> arr1 = {3,4,5,1,2};
        vector<int> arr2 = {2};
        vector<int> arr3 = {1,2,3,4,5};
        vector<int> arr4 = {11,13,15,17};
        
        Solution s;

        int ans1 = s.findMinBrute(arr1);
        int ans2 = s.findMinOpt(arr1);
        
        cout<<ans1<<endl<<ans2<<endl;
    return 0;
}