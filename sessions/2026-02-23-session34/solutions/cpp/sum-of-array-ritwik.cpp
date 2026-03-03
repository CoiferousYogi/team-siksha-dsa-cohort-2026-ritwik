/*
You are given an integer array arr[]. The task is to find the sum of it.

Examples:

Input: arr[] = [1, 2, 3, 4]
Output: 10
Explanation: 1 + 2 + 3 + 4 = 10.
Input: arr[] = [1, 3, 3]
Output: 7
Explanation: 1 + 3 + 3 = 7.
Constraints:
1 <= arr.size <= 105
1 <= arr[i] <= 104
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int sumOfArrayItr(vector<int>& nums) {
        int sum = 0;
        for(int e : nums) {
            sum += e;
        }

        return sum;
    }

    int sumOfArrayRecBU(vector<int>& nums, int sum, int idx) {
        // bottom-up recursion
        if(idx == nums.size()) {
            return sum;
        }

        return sumOfArrayRecBU(nums, sum+nums[idx], idx+1);

        /*
            top-down recursion

            if(idx == -1) {
                return sum;
            }

            return sumOfArrayRec(nums, sum+idx, idx-1)
        */
    }

    int sumOfArrayRecTD(vector<int>& nums, int sum, int idx) {
        // top-down recursion
        if(idx == -1) {
            return sum;
        }

        return sumOfArrayRecTD(nums, sum+nums[idx], idx-1);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, -1, -4, 5, 6, 7}; // exp: 19
    Solution s;

    int ansRecBU = s.sumOfArrayRecBU(nums, 0, 0);

    int ansRecTD = s.sumOfArrayRecTD(nums, 0, nums.size()-1);

    cout<<ansRecBU<<endl<<ansRecTD<<endl;
}