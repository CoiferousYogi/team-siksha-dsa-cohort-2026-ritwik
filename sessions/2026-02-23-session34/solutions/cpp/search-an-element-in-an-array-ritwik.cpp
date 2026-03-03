/*
Given an array, arr[] of n integers, and an integer element x, find whether element x is present in the array. Return the index of the first occurrence of x in the array, or -1 if it doesn't exist.

Examples:

Input: arr[] = [1, 2, 3, 4], x = 3
Output: 2
Explanation: For array [1, 2, 3, 4], the element to be searched is 3. Since 3 is present at index 2, the output is 2.
Input: arr[] = [10, 8, 30, 4, 5], x = 5
Output: 4
Explanation: For array [10, 8, 30, 4, 5], the element to be searched is 5 and it is at index 4. So, the output is 4.
Input: arr[] = [10, 8, 30], x = 6
Output: -1
Explanation: The element to be searched is 6 and it is not present, so we return -1.
Constraints:
1 ≤ arr.size ≤ 106
0 ≤ arr[i] ≤ 106
0 ≤ x ≤ 105
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int searchLinear(vector<int>& arr, int x) {
        // code here
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == x) {
                return i;
            }
        }
        return -1;
    }

    int searchLinearRecTD(vector<int>& arr, int idx, int x) {
        // top-down recursion

        if(idx == -1) {
            return -1;
        }

        if(arr[idx] == x) {
            return idx;
        }

        searchLinearRecTD(arr, idx-1, x);
    }

    int searchLinearRecBU(vector<int>& arr, int idx, int x) {
        // bottom-up recursion

        if(idx == arr.size()) {
            return -1;
        }

        if(arr[idx] == x) {
            return idx;
        }

        searchLinearRecBU(arr, idx+1, x);
    }

    int searchBinarySearchIter(vector<int>& arr, int x) {
        // iterative binary search
        // WARNING: ARRAY MUST BE SORTED
        // assuming input array is sorted
        
        int low = 0;
        int high = arr.size()-1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] == x) {
                return mid;
            }
            if(arr[mid] > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }

    int searchBinarySearchRec(vector<int>& arr, int low, int high, int x) {
        // assuming input array is sorted
        
        if(low > high) {
            return -1;
        }

        int mid = low + (high - low) / 2;

        if(arr[mid] == x) {
            return mid;
        }
        else if(arr[mid] < x) {
            return searchBinarySearchRec(arr, mid+1, high, x);
        }
        else {
            return searchBinarySearchRec(arr,low, mid-1, x);
        }

    }

};