/**
 * Problem Link : https://leetcode.com/problems/move-zeroes/description/
 *
 * Short Description
 * Given an integer array nums, move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * Note: that you must do this in-place without making a copy of the array.
 *
 *
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 *
 * Input: nums = [0]
 * Output: [0]
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>

class Solution
{
public:
  // Brute Force Approach
  // We compare adjcent elements if non desirble element
  // come then we swap both the numbers (Bubble sort)
  // Time: O(n^2), Space: O(1)

  void move_zeroes_brute(std::vector<int> &nums)
  {

    int n = nums.size();

    // Edge case
    if (n == 1)
      return;

    for (int i = 0; i < n - 1; i++)
    {
      bool flag = false;
      for (int j = 0; j < n - i - 1; j++)
      {
        if (nums[j] == 0 && nums[j + 1] != 0)
        {
          std::swap(nums[j], nums[j + 1]);
          flag = true;
        }
      }

      if (!flag)
      { // Flag not change, means swaping never happend
        break;
      }
    }
  }

  // Better Approach
  // Use extra space and save non zero elements
  // Also count no of zeroes while looping
  // push no of zeroes into extra space
  // Time: O(n), Space: O(n)

  void move_zeroes_better(std::vector<int> &nums)
  {
    int n = nums.size();

    // Edge case
    if (n == 1)
      return;

    // count the zeroes
    int count_zeroes = 0;

    // push all non-zero element into new array
    std::vector<int> ans;
    for (auto it : nums)
    {
      if (it != 0)
        ans.push_back(it);
      else
        count_zeroes++;
    }

    // Move all zeroes to end of an array
    while (count_zeroes--)
    {
      ans.push_back(0);
    }

    // Combine the result
    for (int i = 0; i < n; i++)
    {
      nums[i] = ans[i];
    }
  }

  // Best Approach
  // We init two pointer i and j
  // Divide the whole array into two parts
  // 0 =>  i-1 which have only non zero elements
  // i => n - 1 which have only zeroes
  // Time: O(n), Space: O(1)

  void move_zeroes_best(std::vector<int> &nums)
  {

    int n = nums.size();

    // Edge case
    if (n == 1)
      return;

    // init two pointer to track
    // 0 => i-1 non zero elements
    // i => zero elements

    int i = -1, j = 0;

    while (j < n)
    {
      if (nums[j])
      {
        std::swap(nums[j], nums[i + 1]);
        i++;
      }
      j++;
    }
  }
};

int main()
{
  std::vector<int> nums = {0, 1, 2, 0, 0, 3, 12, 0};

  // Create an object of class Solution
  Solution sol;

  sol.move_zeroes_brute(nums);
  sol.move_zeroes_better(nums);
  sol.move_zeroes_best(nums);

  std::cout << "After moving zeroes to end : ";
  for (auto &it : nums)
  {
    std::cout << it << " ";
  }
}