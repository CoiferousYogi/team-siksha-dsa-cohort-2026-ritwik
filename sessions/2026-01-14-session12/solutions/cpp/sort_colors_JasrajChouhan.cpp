/**
 * Problem Link : https://leetcode.com/problems/sort-colors/description/
 *
 * Short Description
 * Given an array nums with n objects colored red, white, or blue,
 * sort them in-place so that objects of the same color are adjacent,
 * with the colors in the order red, white, and blue.
 *
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function.
 *
 *
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Explanation:
 *
 *
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
  void sort_colors(std::vector<int> &nums)
  {
    // Standard method sort the array
    std::sort(nums.begin(), nums.end());
  }

  /*
   * Use Bubble Sort
   * Time Complexity: O(n^2)
   * Space Complexity: O(1)
   */
  void sort_colors_brute(std::vector<int> &nums)
  {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = 0; j < n - i - 1; j++)
      {
        if (nums[j] > nums[j + 1])
        {
          std::swap(nums[j], nums[j + 1]);
        }
      }
    }
  }

  /**
   * Using linear approach
   * Initilize three variable to store count
   * of 1,2 and O's.
   *
   * After that, we place O,1 and 2 excat count
   * of each number.
   *
   * Time: O(n) , Space: O(1)
   */
  void sort_colors_better(std::vector<int> &nums)
  {

    // Init three variable to count 1's, 2's and 0's.
    int count_one = 0, count_two = 0, count_zero = 0;

    for (auto &it : nums)
    {
      if (it == 0)
        count_zero++;
      else if (it == 1)
        count_one++;
      else
        count_two++;
    }

    // Place 0's, 1's and 2's and correct possition
    int k = 0;
    while (count_zero--)
    {
      nums[k] = 0;
      k++;
    }

    while (count_one--)
    {
      nums[k] = 1;
      k++;
    }

    while (count_two--)
    {
      nums[k] = 2;
      k++;
    }
  }

  /*
   * Use 3 pointers
   * low -> position of next 0
   * mid -> current element
   * high -> position of next 2
   *
   * Time: O(n), Space: O(1)
   */
  void sort_colors_best(std::vector<int> &nums)
  {
    int low = 0, mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
      if (nums[mid] == 0)
      {
        std::swap(nums[low], nums[mid]);
        low++;
        mid++;
      }
      else if (nums[mid] == 1)
      {
        mid++;
      }
      else // nums[mid] == 2
      {
        std::swap(nums[mid], nums[high]);
        high--;
      }
    }
  }
};

int main()
{
  std::vector<int> nums = {2, 0, 2, 1, 1, 0};

  Solution sol;

  // sol.sort_colors_brute(nums);
  // sol.sort_colors_better(nums);
  sol.sort_colors_best(nums);

  std::cout << "Sorted Colors: ";
  for (int num : nums)
    std::cout << num << " ";

  std::cout << "\n";
  return 0;
}