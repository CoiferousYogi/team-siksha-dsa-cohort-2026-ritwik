/**
 * Problem Link : https://leetcode.com/problems/running-sum-of-1d-array/description/
 *
 * Short Description
 * Given an array nums. We define a running sum of an array as
 * runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums.
 *
 *
 * Input: arr[] = [1, 2, 3, 4]
 * Output: [1,3,6,10]
 * Explanation:
 * Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
 *
 *
 * Input: nums = [1,1,1,1,1]
 * Output: [1,2,3,4,5]
 * Explanation:
 * Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
 *
 * Input: nums = [3,1,2,10,1]
 * Output: [3,4,6,16,17]
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
   * Find running sum using itreative approach
   * Run a loop from i = 1 to n - 1
   * nums[i - 1] += nums[i]
   *
   * Time: O(n), Space: O(1)
   */

  std::vector<int> running_sum_iterative(std::vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
      nums[i] += nums[i - 1];
    }

    return nums;
  }

  /**
   * Running sum by recursive approach
   * Sub problem for this running sum proble is
   * Calcuate running sum from next index
   *
   * So, f(nums, i + 1 , nums[i]) is subproblem
   * of f(nums ,i , 0)
   *
   * When index cross the size of array then return
   *
   * Time: O(n) , Space: O(n)
   */
  std::vector<int> running_sum_recursive(std::vector<int> &nums)
  {

    helper(nums, 0, 0);
    return nums;
  }

private:
  void helper(std::vector<int> &nums, int i, int ans)
  {

    // Base case
    if (i >= nums.size())
    {
      return;
    }

    // Self Work
    nums[i] += ans;
    ans = nums[i];

    // Recursive Work
    helper(nums, i + 1, ans);
  }
};

void print(const std::vector<int> &nums)
{
  for (auto &it : nums)
  {
    std::cout << it << " ";
  }
}

int main()
{

  std::vector<int> nums1 = {1, 2, 3, 4};
  std::vector<int> nums2 = {1, 1, 1, 1, 1};

  // Create an object of class Solution
  Solution sol;

  sol.running_sum_iterative(nums1);
  sol.running_sum_recursive(nums2);

  // Print the vector
  std::cout << "Running sum of nums1 : ";
  print(nums1);

  std::cout << "\nRunning sum of nums2 : ";
  print(nums2);

  return 0;
}