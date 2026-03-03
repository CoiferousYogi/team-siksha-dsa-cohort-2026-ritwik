/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
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
    vector<int> sortedSquaresBrute(vector<int>& nums) {
        // brute force: square each element and then sort them
        for(auto& ele : nums) {
            ele = ele * ele;
        }

        sort(nums.begin(), nums.end());

        return nums;

        // TC: O(n + n*log n)
        // SC: O(1)
    }


    vector<int> sortedSquaresOpt(vector<int>& nums) {
        // divide and conquer
        // divide the array into negative and non-negative halves
        // then merge the two parts in a sorted manner 

        vector<int> merged;

        // finding the negative part of the array
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                count++;
            }
            else {
                break;
            }
        }

        // the negative part of the array is from 0 to count-1
        // the non-negative part of the array is from count to nums.size()-1
        int low = count-1;
        int high = count;

        while(low >= 0 && high < nums.size()) {
            int lowSq = nums[low] * nums[low];
            int highSq = nums[high] * nums[high];

            if(lowSq <= highSq) {
                merged.push_back(lowSq);
                low--;
            }
            else {
                // nums[low] > nums[high]
                merged.push_back(highSq);
                high++;
            }
        }

        while(low >= 0) {
            merged.push_back(nums[low] * nums[low]);
            low--;
        }

        while(high < nums.size()) {
            merged.push_back(nums[high] * nums[high]);
            high++;
        }


        return merged;

        /*
            TC: O(n + n)
            SC: O(n): extra space for merged array
        */
    }
};
