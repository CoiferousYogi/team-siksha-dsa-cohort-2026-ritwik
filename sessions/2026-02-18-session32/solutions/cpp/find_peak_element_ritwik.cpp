#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    // brute force: using linear search
    int findPeakElementBrute(vector<int>& nums) {
        // brute force: linear search
        int idx = -1;

        // edge cases: 
        // 1. array contains single element
        if(nums.size() == 1) {
            return 0;
        }

        // 2. the elements at start and end are peaks
        if((nums.size() > 1) && (nums[0] > nums[1])) {
            return 0;
        }

        if((nums.size() > 1) && (nums[nums.size()-1] > nums[nums.size()-2])) {
            return nums.size() - 1;
        }


        // since we cannot compare the elemets at the ends, we start our loop at 2nd element (1) and end it at nums.size()-2

        for(int i = 1; i < nums.size()-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                idx =  i;
                break;
            }
        }
        return idx;

        // TC: O(n): Because linear search iterates through each element in search space. So a search space having n elements needs n computations in worst case scenario
        // SC: O(1): no extra space has been utilised. Hence, space complexity is constant
    }

    // optimal approach: binary search
    /*
        Intuition about binary search

        Apart from the small hint in the problem description that we need to write an algorithm which runs in O(log n) time, how does binary search fit into this question when the array is not guaranteed to be sorted?


        Now, we have another hint in the constrainsts nums[i] != nums[i+1] for any valid i

        So, given that condition, there exists at least 1 peak in all the arrays (can either be global or local maxima)

        There are 4 cases for an element of the array and it's neighbours

        1. The element at start is a peak (edge case)
            
             \,__,__,__,...
             
        2. The element at end is a peak (edge case)
                          
            ...,__,__,__,/

        3. There is a local maxima in between
                       
            ...,__,__,/,\,__,__,...

            There are 3 sub-scenarios for this

            3a. The (i)th element is the peak element
                If that's the case, we can return mid

            3b. The (i)th element lies at the left of the peak element
                3b1. The array is increaing towards the left till the beginning of array => 0th element is peak


                3b2. The array is increasing towards the left till an arbitrary index k such that 1 <= k <i => the kth element is the peak
            3c. The mid element lies at the right of the peak element
        
    */
    int findPeakElementOpt(vector<int>& nums) {
        // edge cases
        // 1. array contains only single element
        if(nums.size() == 1) {
            return 0;
        }

        // 1st or last element are peak elements
        if(nums.size() > 1 && nums[0] > nums[1]) {
            return 0;
        }

        if(nums.size() > 1 && nums[nums.size()-1] > nums[nums.size()-2]) {
            return nums.size()-1;
        }

        // binary search
        int low = 1;
        int high = nums.size()-2;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // check if nums[mid] is peak
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            }

            // if nums[mid] < nums[mid + 1] => nums[mid + 1] might be the peak element => search the right half
            if(nums[mid] < nums[mid + 1]) {
                // [1,2,3,4,3,5,10,5,2,8]
                low = mid + 1;
            }
            else {
                // nums[mid] < nums[mid - 1]
                high = mid - 1;
            }
        }
        return -1; // no peaks found
    }
};



int main() {
        vector<int> nums = {1,2,1,3,5,6,4}; // expected 1 or 5

        Solution s;
        int ans1 = s.findPeakElementBrute(nums);
        int ans2 = s.findPeakElementOpt(nums);
        cout<<ans1<<endl<<ans2<<endl;
    return 0;
}

/*                                                      
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, ]


    mid = nums[3] => 3
    nums[mid + 1] > nums[mid]
    => low = mid + 1 => nums[4] = 4


    high = 1
    low = 0 
    search space = [1,3]

    1, 10, 9, 8, 7, 6, 2

*/