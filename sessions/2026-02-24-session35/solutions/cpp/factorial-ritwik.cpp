/*
Given a positive integer, n. Find the factorial of n.

Examples :

Input: n = 5
Output: 120
Explanation: 1 x 2 x 3 x 4 x 5 = 120
Input: n = 4
Output: 24
Explanation: 1 x 2 x 3 x 4 = 24
Constraints:
0 ≤ n ≤ 12
*/

#include <iostream>
using namespace std;

class Solution {
  private:
    int factorialHelper(int n, int i, int prod) {
        if(i == n+1) {
            return prod;
        }

        prod = prod * i;

        return factorialHelper(n, i+1, prod);
    }
  public:
    int factorialItr(int n) {
        // code here
        if(n <= 1) {
            return n;
        }
        
        int prod = 1;
        for(int i = 2; i <= n; i++) {
            prod = prod*i;
        }
        
        return prod;
    }

    int factorialRec(int n) {
        if(n <= 1) {
            return n;
        }

        int fact = factorialHelper(n, 2, 1);

        return fact;
    }
};

int main() {
        int n = 5;
        Solution s;

        int ansItr = s.factorialItr(n);
        int ansRec = s.factorialRec(n);

        cout<<ansItr<<endl<<ansRec<<endl;
    return 0;
}