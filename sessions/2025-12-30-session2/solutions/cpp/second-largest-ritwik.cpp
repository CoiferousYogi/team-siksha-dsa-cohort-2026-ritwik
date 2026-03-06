/*
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int getSecondLargestBrute(vector<int> &arr) {
        // code here
        // brute force: sorting and finding the 2nd largest
        
        // edge case: single element array
        if(arr.size()==1) {
            return -1;
        }

        sort(arr.begin(), arr.end());

        for(int i = arr.size()-1; i >= 0; i--) {
            if(arr[i] < arr[arr.size()-1]) {
                return arr[i];
            }
        }

        return -1; // if array contains same elements

        // TC: O(n*log n + n) : n*log n for sorting and n for array traversal from the back
        // SC: O(1): no extra space used
    }


    int getSecondLargestOpt(vector<int>& arr) {
            int maxEle = INT_MIN;
            int sMaxEle = INT_MIN;

            for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > maxEle) {
                sMaxEle = maxEle;
                maxEle = arr[i];
            }
            else if(arr[i] < maxEle && arr[i] > sMaxEle) {
                sMaxEle = arr[i];
            }
        }
        
        if(sMaxEle == INT_MIN) {
            return -1;
        }

        return sMaxEle;

        // TC: O(n): the for loop traverses for all elements in the array
        // SC: O(1) no extra space used
    }
};