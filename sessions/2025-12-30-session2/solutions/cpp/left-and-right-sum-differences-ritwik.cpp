/*
You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

 

Example 1:

Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
Example 2:

Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifferenceBrute(vector<int>& nums) {
        if(nums.size() == 1) {
            return {0};
        }

        int preSum = 0;
        int suffSum = 0;

        // prefix sum
        vector<int> prefixSum(nums.size(), 0);

        // suffix sum
        vector<int> suffixSum(nums.size(), 0);

        // first calculate the prefix sum
        for(int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        // calculating the suffix sum
        for(int i = nums.size() - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i+1] + nums[i+1];
        }

        // now calculate the difference
        if(prefixSum.size() != suffixSum.size()) {
            return {-1};
        }

        vector<int> leftRightDiff;

        for(int i = 0; i < prefixSum.size(); i++) {
            int diff = abs(prefixSum[i] - suffixSum[i]);
            leftRightDiff.push_back(diff);
        }

        return leftRightDiff;

        /*
            TC: O(n + n + n) => O(n) for prefixSum; O(n) for suffixSum and O(n) for calculating leftRightDiff
            SC: O(n) : for leftRightDiff vector
        */
    }

    vector<int> leftRightDifferenceOpt(vector<int>& nums) {
        // two pass solution using no extra space
        // sliding window
        // first we will calculate the total sum of the array
        // then from the total sum keep subtracting the current element which gives us leftSum
        // the remainder is the rightSum
        // we then calculate the difference between the two and replace the element at i with that difference
        int leftSum = 0; 
        int rightSum = 0; 
        int n = nums.size();

        for(const int& num : nums) {
            rightSum += num;
        }

        for(int i = 0; i < n; i++) {
            int val = nums[i];
            rightSum -= val;
            nums[i] = abs(leftSum - rightSum);
            leftSum += val;
        }
        return nums;

        /*
        TC: O(n + n) => O(n) for calculating total sum (rightSum) and O(n) for calculating the difference between leftSum and rightSum
        SC: O(1) => no extra space used
        */
    }

    void printVector(vector<int>& v) {
        for(int i = 0; i < v.size(); i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

};

int main() {
        vector<int> nums = {10,4,8,3};

        Solution s;

        vector<int> ansBrute = s.leftRightDifferenceBrute(nums);
        vector<int> ansOpt = s.leftRightDifferenceOpt(nums);

        s.printVector(ansBrute);
        s.printVector(ansOpt);
    return 0;
}