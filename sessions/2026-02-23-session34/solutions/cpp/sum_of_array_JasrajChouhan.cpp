/**
 * Problem Link : https://www.geeksforgeeks.org/problems/sum-of-array2326/1
 *
 * Short Description
 * You are given an integer array arr[].
 * The task is to find the sum of it.
 *
 *
 * Input: arr[] = [1, 2, 3, 4]
 * Output: 10
 * Explanation: 1 + 2 + 3 + 4 => 10
 *
 *
 * Input: arr[] = [1,3,3]
 * Output: 7
 * Explanation:  1 + 3 + 3 = 7.
 *
 * Time Complexity: O(n)
 * Auxiliary Space: O(1)
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
  /**
   * Linearly Travrase the vector
   * and add the value of each elemenets
   * into ans
   *
   * Time: O(n), Space: O(1)
   */
  int array_sum(const std::vector<int> &nums)
  {

    int n = nums.size();

    // Init a variable to store sum of elements of nums
    int ans = 0;

    // Travrase the vector nums
    for (auto &it : nums)
    {
      ans += it;
    }

    return ans;
  }

  /**
   * Calculate sum of array using recursive approach
   *
   * Sub proble is here, sum of array from next to
   * current index
   * so, f(nums , idx) = nums[idx] + f(nums , idx + 1)
   *
   * When index cross the size of nums then return the
   * zero and terminate the recursion
   *
   * Time: O(1) * n => O(n)
   * Space: O(n)
   */
  int array_sum_rec(const std::vector<int> &nums, int idx)
  {

    // Base Case
    if (idx >= nums.size())
    {
      return 0;
    }

    // Recursive Work
    int small_ans = array_sum_rec(nums, idx + 1);

    // Self Work
    int big_ans = small_ans + nums[idx];
    return big_ans;
  }
};

int main()
{

  std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int> nums2 = {1, 2, 3, -1, -4, 5, 6, 7};

  // Create an object of class Solution
  Solution sol;

  std::cout << "Iterative Approach : " << sol.array_sum(nums1) << std::endl;
  std::cout << "Recursive Approach : " << sol.array_sum_rec(nums2, 0) << std::endl;

  std::cout << "\n";

  return 0;
}