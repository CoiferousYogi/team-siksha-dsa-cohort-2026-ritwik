/*
Given an array arr[]. Your task is to find the minimum and maximum elements in the array.

Examples:

Input: arr[] = [1, 4, 3, 5, 8, 6]
Output: [1, 8]
Explanation: minimum and maximum elements of array are 1 and 8.
Input: arr[] = [12, 3, 15, 7, 9]
Output: [3, 15]
Explanation: minimum and maximum element of array are 3 and 15.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 109
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        // optimal approach: intialize variables to store min and max
        // traverse the array and compare elements
        
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] < minEle) {
                minEle = arr[i];
            }
            if(arr[i] > maxEle) {
                maxEle = arr[i];
            }
        }

        /*
            For C++ one can also use the range based loop
            for(const int& e : arr) {
                if(e > maxEle) {
                    maxEle = e;
                }

                if(e < minEle) {
                    minEle = e;
                }
            }
            It is much faster and uses less memory since the const keyword ensures that the type of variable is not changed and the & ensures we are comparing the original elements and not making a copy of it
        */
        
        return {minEle, maxEle};
    }
};

int main() {
        vector<int> arr = {12, 3, 15, 7, 9};

        Solution s;
        vector<int> minMax = s.getMinMax(arr);
        cout<<minMax[0]<<" "<<minMax[1]<<endl;
    return 0;
}