/*
Given a binary array arr[] containing only 0s and 1s and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.

Examples:

Input: arr[] = [1, 0, 1], k = 1
Output: 3
Explanation: By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1’s.

Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
Output: 5
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.

Input: arr[] = [1, 1], k = 2
Output: 2
Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2.

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ k ≤ arr.size()
0 ≤ arr[i] ≤ 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <string>

using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        // similar to the question where we were allowed to flip just one 0
        
        int left = 0;
        int countZeros = 0;
        int maxLen = 0;
        
        for(int right = 0; right < arr.size(); right++) {
            if(arr[right] == 0) {
                countZeros++;
            }
            while(countZeros > k) {
                if(arr[left] == 0) {
                    countZeros--;
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        
        return maxLen;
        
        // TC: O(n)
        // SC: O(1)
        
    }
};


int main() {
        vector<int> nums = {1, 0, 0, 1, 0, 1, 0, 1};
        int k = 2;

        Solution s;

        int ans = s.maxOnes(nums, k);
        cout<<ans<<endl;
    return 0;
}