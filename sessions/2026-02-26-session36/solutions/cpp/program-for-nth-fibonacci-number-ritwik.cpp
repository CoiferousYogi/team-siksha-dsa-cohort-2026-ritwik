/*
Given a positive integer n, find the nth Fibonacci number.

The Fibonacci series is a sequence where a term is the sum of previous two terms. The first two terms of the Fibonacci sequence are 0 followed by 1. The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21.

Example:

Input: n = 2
Output: 1 
Explanation: 1 is the 2nd number of Fibonacci series.

Input: n = 5
Output: 5
Explanation: 5 is the 5th number of Fibonacci series.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthFibonacciRecBU(int n) {
        if(n <= 1) {
            return n;
        }

        return nthFibonacciRecBU(n-1) + nthFibonacciRecBU(n-2);
    }

    int nthFibonacciMemo(int n, vector<int>& memo) {
        if(n <= 1) {
            return n;
        }

        if(memo[n] != -1) {
            return memo[n];
        }

        memo[n] = nthFibonacciMemo(n-1, memo) + nthFibonacciMemo(n-2, memo);

        return memo[n];
    }

    void nthFibonacciTab(int n, int t1, int t2) {
        int prev1 = t1;
        int prev2 = t2;

        for(int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        cout<<prev1<<endl;
    }
};

int main() {
        int n = 5;

        vector<int> memo(n+1,-1);

        Solution s;

        int ansRec = s.nthFibonacciRecBU(n); 

        cout<<endl;
        
        int ansMemo = s.nthFibonacciMemo(n, memo);

        s.nthFibonacciTab(n, 1, 1);
    return 0;
}