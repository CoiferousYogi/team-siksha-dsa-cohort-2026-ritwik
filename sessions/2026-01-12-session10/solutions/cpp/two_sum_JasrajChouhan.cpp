/**
 * Problem Link : https://leetcode.com/problems/two-sum/description/
 *
 * Short Description
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Input:  nums = [3,3], target = 6
 * Output: [0,1]
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
  // Brute Force
  // Using of two loops we try to find out current pair
  // of element is equal to target
  // Time: O(n^2), Space: O(1)

  std::vector<int> two_sum_brute(std::vector<int> &nums, int target)
  {
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      // Find target-nums[i] in next part of vector
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] + nums[j] == target)
        {
          return {i, j};
        }
      }
    }

    // dummy return statement
    return {-1, -1};
  }

  // Best Approach
  // Init a map and store (ele , index) of vector
  // If a compliment exist for an element, then return the ans
  // otherwise store inside of map (ele , index)
  // Time: O(n), Space: (n)

  std::vector<int> two_sum_best(std::vector<int> &nums, int target)
  {
    int n = nums.size();

    std::unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
      int ele = nums[i];
      int compliment = target - ele;

      if (mp.count(compliment))
      {
        return {mp[compliment], i};
      }
      mp[ele] = i;
    }

    return {-1, -1};
  }
};

int main()
{

  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  int n = nums.size();

  Solution sol;

  // std::vector<int> res = sol.two_sum_brute(nums, target);
  std::vector<int> res = sol.two_sum_best(nums, target);

  // Print the vector
  std::cout << "Result is : [";
  for (int i = 0; i < res.size() - 1; i++)
  {
    std::cout << res[i] << ", ";
  }

  std::cout << res[res.size() - 1] << "]\n";

  return 0;
}