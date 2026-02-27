/**
 * Problem Link : https://www.geeksforgeeks.org/problems/factorial5739/1
 *
 * Short Description
 * Given a positive integer, n. Find the factorial of n.
 * n! = n*(n-1)*(n-2).....1
 *
 *
 * Input: n = 5
 * Output: 120
 * Explanation:
 * 1 x 2 x 3 x 4 x 5 = 120
 *
 *
 * Input: nums = 4
 * Output: 24
 * Explanation:
 * 1 x 2 x 3 x 4 = 24
 *
 * Note: 1 <= n <= 12
 * Try for 1 <= n <= 25
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>

class Solution
{
public:
  // Using of recursion
  /**
   * Sub problem is here find the factorial
   * of n-1
   * So f(n) = n * f(n-1), f(n) respresent n!
   * Base case of f(n) at n = 0, and n = 1
   *
   *
   * Time: time of one call * no of call total
   * Time: 1 * n => O(n)
   *
   * Space: O(n), n stack frame we used to
   * calculate n!
   */
  long long factorial_by_rec(int n)
  {
    // Base Case
    // 0! = 1, 1! = 1
    if (n == 0 || n == 1)
    {
      return 1;
    }

    // Recursive work
    long long small_ans = factorial_by_rec(n - 1);

    // Selft Work
    long long ans = n * small_ans;

    return ans;
  }

  /**
   * Best Approach using loop
   * We know n! = n*(n-1)*(n-2).....1
   * So we can run a loop from i = 1 to i = n
   * and multiply the num and store into result
   *
   * Time: O(n), Space: O(1)
   */
  long long factorial(int n)
  {

    // 0! = 1, 1! = 1
    if (n == 0 || n == 1)
    {
      return 1;
    }

    long long res = 1;

    for (int i = 2; i <= n; i++)
    {
      res *= i;
    }
    return res;
  }
};

int main()
{
  int n = 12;

  Solution sol;
  std::cout << sol.factorial(n) << std::endl;
  std::cout << sol.factorial_by_rec(n) << std::endl;
  return 0;
}