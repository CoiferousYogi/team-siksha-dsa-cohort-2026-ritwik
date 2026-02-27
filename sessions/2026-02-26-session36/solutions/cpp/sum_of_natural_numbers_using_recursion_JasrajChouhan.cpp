/**
 * Problem Link : https://www.geeksforgeeks.org/sum-of-natural-numbers-using-recursion/
 *
 * Short Description
 * Given a number n, find the sum of the first n natural numbers using recursion.
 *
 *
 * Input: n = 3
 * Output: 6
 * Explanation: 1 + 2 + 3 = 6
 *
 *
 * Input: n = 5
 * Output: 15
 * Explanation: 1 + 2 + 3 + 4 + 5 = 15
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>

class Solution
{
public:
  /**
   * Using standare farmula of
   * sum of n natural number
   * sum = (n * (n + 1))/2
   *
   * Time: O(1), Space: O(1)
   */
  int sum(int n)
  {
    /* Sum of n natural number is
    sum = (n * (n + 1))/2 */

    int ans = (n * (n + 1)) / 2;
    return ans;
  }

  /**
   * Travrase linearly form n = 1 to n = N
   * and store into a res
   *
   * res = 1 + 2 + 3 ..... n
   *
   * Time: O(n), Space: O(1)
   */
  int sum_by_itertaive(int n)
  {

    /* Init a variable to store sum
    of n natural number */
    int ans = 0;

    // Travrase from n = 1 to n = N
    for (int i = 1; i <= n; i++)
    {
      ans += i;
    }

    return ans;
  }

  /**
   * Calcualte sum of n natural number
   * using recursion
   *
   * Sub problem is f(n - 1) is for f(n)
   * When n is 0 base case is hit and return 0
   *
   * Time: O(n), Space: O(n)
   */

  int sum_by_recursive(int n)
  {

    // Base Case
    if (n == 0)
      return 0;

    // Recursive Work
    int small_ans = sum_by_recursive(n - 1);

    // Self Work
    int ans = small_ans + n;
    return ans;
  }
};

int main()
{
  int n = 12;

  Solution sol;
  std::cout << "Using standrand farmula : " << sol.sum(n) << std::endl;
  std::cout << "Using itertavie approach : " << sol.sum_by_itertaive(n) << std::endl;
  std::cout << "Using recursive approach : " << sol.sum_by_recursive(n) << std::endl;
  return 0;
}