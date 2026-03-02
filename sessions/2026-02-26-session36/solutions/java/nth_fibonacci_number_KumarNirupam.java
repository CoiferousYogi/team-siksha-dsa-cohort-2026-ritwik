/*
 This program returns the nth Fibonacci number using recursion.

 - The function nthFibonacci(n) calls a helper function fibo(n).
 - The fibo function recursively calculates Fibonacci numbers.
 - If n == 0, it returns 0 (base case).
 - If n < 0, it returns 1 (this condition is logically incorrect for Fibonacci).
 - Otherwise, it returns fibo(n-1) + fibo(n-2),
   which follows the Fibonacci formula:
   F(n) = F(n-1) + F(n-2).

*/
class Solution {
    public int nthFibonacci(int n) {
        // code here
        return fibo(n);
    }
    
    private int fibo(int n){
        if(n == 0) return 0;
        if( n < 0 ) return 1;
        
        return fibo(n-1) + fibo(n-2);
    }
}