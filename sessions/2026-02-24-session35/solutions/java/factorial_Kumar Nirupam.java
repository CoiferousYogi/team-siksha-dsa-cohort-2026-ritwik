/*
Approach Used: Recursive (Top-Down) Approach

1. The factorial(int n) function acts as a wrapper function.
2. The actual logic is implemented in a helper function fact(n).
3. We use recursion to break the problem into smaller subproblems.
4. Base Condition:
   - If n <= 1, return 1.
   - This stops the recursion.
5. Recursive Case:
   - Return n * fact(n - 1)
   - This means factorial of n is n multiplied by factorial of (n-1).
6. The recursion continues until it reaches the base condition.

Time Complexity: O(n)
Space Complexity: O(n) due to recursive call stack.
*/


class Solution {
    // Function to calculate factorial of a number.
    int factorial(int n) {
        // code here
        return fact(n);
    }
    private int fact(int n){
        
        //base condition
        if(n<=1) 
        {
            return 1;
        }
        
        return n * fact(n-1);
    }
}
