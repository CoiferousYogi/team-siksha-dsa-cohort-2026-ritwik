/**
 * Problem Link : https://leetcode.com/problems/3sum/description/
 *
 * Short Description
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 *
 *
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

class Solution
{
public:
  // Brute Force Approach
  // Try all triplets and store unique ones in a set
  // Time: O(n^3 * log k), Space: O(k) where k is number of unique triplets

  std::vector<std::vector<int>> three_sum_brute(std::vector<int> &nums)
  {
    // Init n to store size of vector
    int n = nums.size();

    // Init st set of vector<int> to store unique triplet
    std::set<std::vector<int>> st;

    // Check all possible triplet
    for (int i = 0; i < n - 2; i++)
    {
      for (int j = i + 1; j < n - 1; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          if (nums[i] + nums[j] + nums[k] == 0)
          {
            // Found a triplet which sum is zero
            std::vector<int> temp = {nums[i], nums[j], nums[k]};

            // Sort the triplet and store into set
            std::sort(temp.begin(), temp.end());
            st.insert(temp);
          }
        }
      }
    }

    // convert set to vector
    return std::vector<std::vector<int>>(st.begin(), st.end());
  }

  // Better Approach Using Hash Set
  // Fix one element, and find two-sum for the rest using a set
  // Time: O(n^2 * log k), Space: O(n) + O(k)

  std::vector<std::vector<int>> three_sum_better(std::vector<int> &nums)
  {
    int n = nums.size();

    // Set to store unique triplets
    std::set<std::vector<int>> result;

    // Check all possible triplets
    for (int i = 0; i < n; i++)
    {
      // Set to store all unique elements far in the loop
      std::set<int> seen;
      for (int j = i + 1; j < n; j++)
      {
        // Calculate compliment element of triplet
        int third = -(nums[i] + nums[j]);

        if (seen.count(third))
        {
          // Found a triplet which sum is zero
          // Sort the triplet ans insert inot set
          std::vector<int> temp = {nums[i], nums[j], third};
          std::sort(temp.begin(), temp.end());
          result.insert(temp);
        }

        // Insert the current element
        // into seen set for future checks
        seen.insert(nums[j]);
      }
    }
    // Covert set to vector
    return std::vector<std::vector<int>>(result.begin(), result.end());
  }

  // Best Approach using Sorting and Two Pointers
  // Time: O(n^2), Space: O(1)
  std::vector<std::vector<int>> three_sum_best(std::vector<int> &nums)
  {
    std::vector<std::vector<int>> res;
    int n = nums.size();

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue; // skip duplicates for i

      int left = i + 1;
      int right = n - 1;

      while (left < right)
      {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum == 0)
        {
          res.push_back({nums[i], nums[left], nums[right]});

          left++;
          right--;

          // skip duplicates for left and right
          while (left < right && nums[left] == nums[left - 1])
            left++;
          while (left < right && nums[right] == nums[right + 1])
            right--;
        }
        else if (sum < 0)
        {
          left++;
        }
        else
        {
          right--;
        }
      }
    }

    return res;
  }
};

int main()
{
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};

  Solution sol;

  // std::vector<std::vector<int>> res = sol.three_sum_brute(nums);
  // std::vector<std::vector<int>> res = sol.three_sum_better(nums);
  std::vector<std::vector<int>> res = sol.three_sum_best(nums);

  std::cout << "Triplets:\n";
  for (auto &triplet : res)
  {
    std::cout << "[ ";
    for (int x : triplet)
      std::cout << x << " ";
    std::cout << "]\n";
  }

  return 0;
}