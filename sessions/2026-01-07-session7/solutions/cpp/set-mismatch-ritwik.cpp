/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104
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
    // ans in the form of {missing_no, repeated_no}
    vector<int> findErrorNumsBrue(vector<int>& nums) {
        // brute force approach: make use of a hash map
        int n = nums.size();

        unordered_map<int, int> freqMap;

        int duplicate = -1;
        int missing = -1;

        // iterate over the array and find the frequency of each memeber
        for(int i : nums) {
            freqMap[i] += 1;

            if(freqMap[i] > 1) {
                duplicate = i;
            }
        } 

        // find the missing element
        for(int i = 1; i <= n; i++) {
            if(freqMap.find(i) == freqMap.end()) {
                missing = i;
                break;
            }
        }

        return {duplicate, missing};

        // TC: O(n): for array traversal
        // SC: O(n): extra space used for the hash map
    }

    // ans in the form of {missing_no, repeated_no}
    vector<int> findErrorNumsOpt(vector<int>& nums) {
        // optimal solution: making use of mathematical formulae
        // we will optimize for the space: O(n) -> O(1)
        // we know that sum of natural numbers is: n*(n+1) / 2 (say X)
        // let sum of array elements be Y
        // we need to find X and Y
        // a^2 + b^2 = (a+b)*(a-b)
        // a+b = (a^2 + b^2) // (a-b)
        
        // first calculate the array sum
        long long arrSum = 0;
        long long natSum = 0;
        long long natSumSq = 0;
        long long arrSumSq = 0;
        for(int i = 1; i <= nums.size(); i++) {
            natSum = natSum + i;
            arrSum = arrSum + nums[i-1];
            natSumSq += i*i;
            arrSumSq += ((long long) nums[i-1] * nums[i-1]);
        }

        long long diff = natSum - arrSum; // y - x
        long long sqDiff = natSumSq - arrSumSq; // y^2 - x^2
        
        long long sum = sqDiff / diff; // y + x => (y^2-x^2) / (y-x)
        long long missing = (diff + sum) / 2; // y+x + y-x = 2y => 2y/2 = y
        long long repeated = sum - missing;

        return {(int)repeated,(int)missing};

        // TC: O(n)
        // SC: O(1)
    }
};

int main() {
    return 0;
}