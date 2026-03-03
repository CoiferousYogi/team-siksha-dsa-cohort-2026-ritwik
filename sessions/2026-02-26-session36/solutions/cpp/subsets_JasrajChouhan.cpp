/**
 * Problem Link : https://leetcode.com/problems/subsets/
 *
 * Short Description
 * Given an integer array nums of unique elements, return all possible (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 *
 * Input: nums = [1, 2, 3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Input: nums = [1, 2]
 * Output: [ [ ], [1] , [2] , [1, 2] , [2, 1] ]
 *
 * Follow Back
 * Array of nums can have duplicates elements.
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vi;

class Solution
{
private:
  /**
   * Backtracking approach
   * 1. Sort the array
   * 2. At each level, generate subsets
   * 3. Skip duplicate elements
   *
   * Time Complexity: O(2^n)
   * Space Complexity: O(n) recursion stack
   */

  void helper(vi &nums, int start, std::vector<vi> &res, vi &temp)
  {
    // Every state is a valid subset
    res.push_back(temp);

    for (int i = start; i < nums.size(); i++)
    {
      // Skip duplicates
      if (i > start && nums[i] == nums[i - 1])
        continue;

      // Self work + recursive work
      temp.push_back(nums[i]);
      helper(nums, i + 1, res, temp);
      temp.pop_back();
    }
  }

public:
  std::vector<std::vector<int>> subsets(vi &nums)
  {
    std::vector<vi> res;
    vi temp;

    // Sort to handle duplicates
    std::sort(nums.begin(), nums.end());

    helper(nums, 0, res, temp);
    return res;
  }
};

int main()
{

  vi v = {1, 2, 2};

  Solution sol;
  std::vector<vi> res = sol.subsets(v);

  // Print all subsets
  std::cout << "[ " << std::endl;
  for (auto &row : res)
  {
    std::cout << "\t[ ";
    for (auto &ele : row)
    {
      std::cout << ele << " ";
    }

    std::cout << " ]" << std::endl;
  }

  std::cout << " ]" << std::endl;
  return 0;
}
