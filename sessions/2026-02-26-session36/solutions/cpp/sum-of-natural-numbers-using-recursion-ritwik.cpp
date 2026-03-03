/*
Given a number n, find the sum of the first n natural numbers using recursion.
Examples:

Input: n = 3
Output: 6
Explanation: 1 + 2 + 3 = 6

Input: n = 5
Output: 15
Explanation: 1 + 2 + 3 + 4 + 5 = 15
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int naturalNumSumRecBU(int n, int sum, int i) {
        if(i == n+1) {
            return sum;
        }

        return naturalNumSumRecBU(n, sum + i, i+1);
    }

    int naturalNumSumRecTD(int n, int sum, int i) {
        if(i == 0) {
            return sum;
        }

        return naturalNumSumRecTD(n, sum + i, i - 1);
    }

    // using memoization: a top-down approach
    int naturalNumSumMemo(int n, vector<int>& memo) {
        if(n <= 0) {
            return 0;
        }

        if(memo[n] != -1) {
            return memo[n];
        }

        memo[n] = n + naturalNumSumMemo(n-1, memo);

        return memo[n];

        // TC: O(n)
        // SC: O(n)
    }

    // using tabulation: a bottom-up approach
    int naturalNumSumTab(int n) {
        if(n <= 0) {
            return 0;
        }

        int prevSum = 0;

        for(int i = 1; i <= n; i++) {
            int currSum = prevSum + i;

            prevSum = currSum;
        }

        return prevSum;

        // TC: O(n)
        // SC: O(1)
    }
};

int main() {
        int n = 5;

        Solution s;

        int ansBU = s.naturalNumSumRecBU(n, 0, 1);
        int ansTD = s.naturalNumSumRecTD(n, 0, n);
        
        cout<<ansBU<<endl<<ansTD<<endl;

        vector<int> memo(n+1, -1);

        int ansMemo = s.naturalNumSumMemo(n, memo);
        int ansTab = s.naturalNumSumTab(n);
        cout<<ansMemo<<endl<<ansTab;
    return 0;
}