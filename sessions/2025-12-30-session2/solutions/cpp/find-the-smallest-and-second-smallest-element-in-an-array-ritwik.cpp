/*
Given an array, arr[] of integers, your task is to return the smallest and second smallest element in the array. If the smallest and second smallest do not exist, return -1.

Examples:

Input: arr[] = [2, 4, 3, 5, 6]
Output: [2, 3] 
Explanation: 2 and 3 are respectively the smallest and second smallest elements in the array.
Input: arr[] = [1, 1, 1]
Output: [-1]
Explanation: Only element is 1 which is smallest, so there is no second smallest element.
Constraints:
1 ≤ arr.size ≤105
1 ≤ arr[i] ≤ 105
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
  public:
    vector<int> minAnd2ndMinBrute(vector<int>& arr) {
        // brute force: using 2 separate loops
        int fSmall = INT_MAX;
        int sSmall = INT_MAX;

        for(const int& e : arr) {
            if(e < fSmall) {
                fSmall = e;
            }
        }

        for(const int& e : arr) {
            if(e < sSmall && e > fSmall) {
                sSmall = e;
            }
        }

        if(sSmall == INT_MAX) {
            return {-1};
        }

        return {fSmall, sSmall};

        // TC: O(n + n) : for 2 separate loops
        // SC: O(1) : no extra space used
    }


    vector<int> minAnd2ndMinOpt(vector<int> &arr) {
        // code here
        
        // optimised approach: finding the smallest and 2nd smallest in one pass
        
        int smallestEle = INT_MAX;
        int secondSmallestEle = INT_MAX; // if there is no 2nd smallest, 
        // we are supposed to return -1
        
        for(auto ele : arr) {
            if(ele < smallestEle) {
                secondSmallestEle = smallestEle;
                smallestEle = ele;
            }
            else if((ele < secondSmallestEle) && (ele != smallestEle)) {
                secondSmallestEle = ele; 
            }
        }
        
        // if the array contains only one element or if all the values are same,
        // the secondSmallestEle variable never gets updated, hence we check that
        // before returning the values of smallestEle and secondSmallestEle
        if(secondSmallestEle == INT_MAX) {
            return {-1};
        }
        
        return {smallestEle, secondSmallestEle};

        // TC: O(n) : one whole traversal of arr
        // SC: O(1) : no extra space used
    }
};