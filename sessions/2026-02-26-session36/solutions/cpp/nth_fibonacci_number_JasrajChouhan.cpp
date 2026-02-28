/**
 * Problem Link : https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
 *
 * Short Description
 * Given a positive integer n, find the nth Fibonacci number.
 * The Fibonacci series is a sequence where a term is the sum of previous two terms.
 * The first two terms of the Fibonacci sequence are 0 followed by 1.
 * The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21.
 *
 *
 * Input: n = 2
 * Output: 1
 * Explanation: 1 is the 2nd number of Fibonacci series.
 *
 *
 * Input: n = 5
 * Output: 5
 * Explanation: 5 is the 5th number of Fibonacci series.
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>

class Solution
{
public:
  /**
   * Base Case F(n) = n, where n = 0, 1
   * F(n) = F(n - 1) + F(n - 2) where n >= 2
   *
   * Time: O(2^n) , T(n) = T(n - 1) + T(n - 2) + k
   * When we calcualte time complexity
   * we can assume T(n - 2) approx T(n - 1)
   *
   * So, T(n) = 2T(n - 1) + k
   * Space: O(n)
   */
  int nth_fibonacci_by_recursive(int n)
  {

    // Base Case
    if (n == 0 || n == 1)
      return n;

    // Recursive Work
    int prev = nth_fibonacci_by_recursive(n - 1);
    int prev_last = nth_fibonacci_by_recursive(n - 2);

    // Self Work
    int ans = prev + prev_last;
    return ans;
  }

  /**
   * Using linear approach
   * Store current and previous and last previous-last value
   * and travrase from n = 2 -> n = n
   *
   * Time: O(n), Space: O(1)
   */

  int nth_fibonacci_by_iterative(int n)
  {
    if (n == 0 || n == 1)
      return n;

    // Current store or track the current fibo number
    int current = 0;

    // Store last two previous fibo number
    int prev1 = 1, prev2 = 0;

    for (int i = 2; i <= n; i++)
    {
      current = prev2 + prev1;
      prev2 = prev1;
      prev1 = current;
    }

    return current;
  }

  /**
   * Iterative bottom up approach
   * Use the extra space to store previous
   * fibo number.
   * By this it is easy to calculate next
   * fibo number
   *
   * Time: O(n), Space: (n)
   */

  int nth_fibonacci_by_bottom_up(int n)
  {
    // Base Case
    if (n == 0 || n == 1)
      return n;

    /* Init a store variable (v) to store
    fibonacci number and start from 0 and 1 */
    std::vector<int> v(n + 1, -1);
    v[0] = 0, v[1] = 1;

    /* Travrase from i = 2 -> n to
    store fibonacci number */
    for (int i = 2; i <= n; i++)
    {
      v[i] = v[i - 1] + v[i - 2];
    }

    return v[n];
  }

  /**
   * Using memoization approach
   * See very carefully, we make multiple call
   * for calculating big fibonacci number
   *
   * for ex n = 5, we call f(3) two times
   * that's why we can store result of function
   * call and use it in future
   *
   * F(n) = n, for n = 1,0 is Base Case
   * Time: O(n) , Space: O(n)
   */

  int nth_fibonacci_by_memoization(int n)
  {
    std::vector<int> v(n + 1, -1);

    return helper(n, v);
  }

private:
  int helper(int n, std::vector<int> &dp)
  {
    // Base Case
    if (n == 0 || n == 1)
    {
      return n;
    }

    /* Check if result already store in utility
    vector if yes then use it or return it */
    if (dp[n] != -1)
      return dp[n];

    /* Calculate fibo number and store it */
    dp[n] = helper(n - 1, dp) + helper(n - 2, dp);

    return dp[n];
  }
};

int main()
{

  int n = 20;

  // Create an instance of class Solution
  Solution sol;

  std::cout << "Using iterative approach : " << sol.nth_fibonacci_by_iterative(n) << std::endl;
  std::cout << "Using recursive approach : " << sol.nth_fibonacci_by_recursive(n) << std::endl;
  std::cout << "Using bottom-up approach : " << sol.nth_fibonacci_by_bottom_up(n) << std::endl;
  std::cout << "Using Memoization approach : " << sol.nth_fibonacci_by_memoization(n) << std::endl;

  return 0;
}