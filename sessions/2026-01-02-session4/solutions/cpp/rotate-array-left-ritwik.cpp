/*
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.
Constraints:
1 <= arr.size(), d <= 105
0 <= arr[i] <= 105
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
  public:
    void rotateArrLeftBrute(vector<int>& arr, int d) {
        // code here
        // brute force: create a separate array and push the elements as required
        vector<int> nums;
        int n = arr.size();
        
        d = d % n;
        
        // first push the elements from d to n-1 to the new array
        for(int i = d; i < n; i++) {
            nums.push_back(arr[i]);
        }
        
        // push elements from 0 to d-1 from original to the new array
        for(int i = 0; i < d; i++) {
            nums.push_back(arr[i]);
        }
        
        for(int i = 0; i < nums.size(); i++) {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        
        return;
        
    }

    // optimal: using reverse on sub-arrays
    // 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 => 8, 10, 12, 14, 16, 18, 20, 2, 4, 6
    /*
        Reverse the entire array to place elements in correct sections
        20, 18, 16, 14, 12, 10, 8, 6, 4, 2

        Reverse the elements from 0 till n-1-k
        8, 10, 12, 14, 16, 18, 20, 6, 4, 2

        Reverse the elements from n-k till n-1
        8, 10, 12, 14, 16, 18, 20, 2, 4, 6 => result
    */
    
    vector<int> reverseSubArray(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }

        return nums;
    }
    void rotateArrayLeftOpt(vector<int>& nums, int d) {
            int n = nums.size();
            d = d % n;

            // reverse the entire array
            reverseSubArray(nums, 0, n-1);

            // reverse the elements from 0 till n-1-d
            reverseSubArray(nums, 0, n-1-d);

            // reverse the elements from n-d till n-1
            reverseSubArray(nums, n-d, n-1);

            for(int i = 0; i < n; i++) {
                cout<<nums[i]<<" ";
            }
            cout<<endl;
        return;
    }
};

int main() {
        int d = 9;
        vector<int> nums = {7, 3, 9, 1}; // expected: 3 9 1 7

        Solution s;
        s.rotateArrLeftBrute(nums, d);

        s.rotateArrayLeftOpt(nums, d);
    return 0;
}