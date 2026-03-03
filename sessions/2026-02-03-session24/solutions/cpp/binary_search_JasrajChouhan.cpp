/**
 * Problem Link : https://leetcode.com/problems/binary-search/description/
 *
 * Short Description
 * Given an array of integers nums which is sorted in ascending order,
 * and an integer target, write a function to search target in nums.
 * If target exists, then return its index. Otherwise, return -1.
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation:
 * 9 exists in nums and its index is 4
 *
 *
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation:
 * 2 does not exist in nums so return -1
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>

class Solution
{
public:
  /**
   * Implement Binary Search using iterative approach
   * Time Complexity: O(logn)
   * Space Complexity: O(1)
   */
  int binary_search_iterative(const std::vector<int> &nums, int target)
  {

    int n = nums.size();

    /* Init two pointer to track
    start and end position on nums */
    int st = 0, end = n - 1;

    while (st <= end)
    {
      // Middle index of search space
      int mid = st + (end - st) / 2;

      // if target at middle index
      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] < target)
      {
        /* Target lie in left side of vector
        move start pointer next to mid index */
        st = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }

    // Target not found
    return -1;
  }

  /**
   * Implement Binary Search using recursion
   * Time Complexity: O(logn)
   * Space Complexity: O(logn)
   */
  int binary_search_recursive(const std::vector<int> &nums, int st, int end, int target)
  {
    // Base Case
    if (st > end)
    {
      return -1;
    }

    // Self Work
    int mid = st + (end - st) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }

    // Recursive Work
    if (nums[mid] < target)
    {
      return binary_search_recursive(nums, mid + 1, end, target);
    }
    return binary_search_recursive(nums, st, mid - 1, target);
  }
};

int main()
{

  std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int n = nums.size();

  // Create an instance of Class Solution
  Solution sol;

  std::cout << "[Iterative] Index of 3 in nums : " << sol.binary_search_iterative(nums, 3) << std::endl;
  std::cout << "[Iterative] Index of 6 in nums : " << sol.binary_search_iterative(nums, 6) << std::endl;

  std::cout << "[Recursive] Index of 3 in nums : " << sol.binary_search_recursive(nums, 0, n - 1, 3) << std::endl;
  std::cout << "[Recursive] Index of 6 in nums : " << sol.binary_search_recursive(nums, 0, n - 1, 6) << std::endl;

  std::cout << "\n";

  return 0;
}