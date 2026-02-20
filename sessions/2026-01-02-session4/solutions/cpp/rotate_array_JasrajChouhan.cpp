/**
 * Problem Link : https: // leetcode.com/problems/rotate-array/description/
 *
 * Short Description
 * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 * Note: Modify the array in place.
 *
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 *
 *
 * Input: nums = [-1,-100,3,99], k = 2
 * Output:  [3,99,-1,-100]
 * Explanation:
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 *
 * Next:
 * Do the same problem for k = 1 and array rotate in left direction by k steps
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  // Brute Force: Rotate one step k times
  // Time: O(n * k), Space: O(1)
  void rotate_brute(std::vector<int> &nums, int k)
  {
    int n = nums.size();
    if (n == 0)
      return;

    k = k % n;

    for (int i = 0; i < k; i++)
    {
      int last = nums[n - 1];
      for (int j = n - 1; j > 0; j--)
      {
        nums[j] = nums[j - 1];
      }
      nums[0] = last;
    }
  }

  // Better: Using extra array
  // Time: O(n), Space: O(n)
  void rotate_better(std::vector<int> &nums, int k)
  {
    int n = nums.size();
    if (n == 0)
      return;

    k = k % n;
    std::vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
      temp[(i + k) % n] = nums[i];
    }

    nums = temp;
  }

  // Best: Reversal Algorithm (In-place)
  // Time: O(n), Space: O(1)
  void rotate_best(std::vector<int> &nums, int k)
  {
    int n = nums.size();
    if (n == 0)
      return;

    k = k % n;

    // Reverse whole array
    reverse_array(nums, 0, n - 1);

    // Reverse first k elements
    reverse_array(nums, 0, k - 1);

    // Reverse remaining elements
    reverse_array(nums, k, n - 1);
  }

private:
  void reverse_array(std::vector<int> &nums, int st, int end)
  {
    while (st < end)
    {
      std::swap(nums[st], nums[end]);
      st++;
      end--;
    }
  }
};

int main()
{
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;

  Solution sol;

  // Choose ONE to test

  // sol.rotateBrute(v, k);
  // sol.rotateBetter(v, k);
  sol.rotate_best(v, k);

  // Print result
  for (int x : v)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";

  return 0;
}