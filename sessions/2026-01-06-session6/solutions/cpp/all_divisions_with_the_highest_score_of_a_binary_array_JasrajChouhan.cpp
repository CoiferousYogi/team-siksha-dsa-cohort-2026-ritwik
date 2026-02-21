/**
 * Problem Link : https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/
 *
 * Short Description
 * You are given a 0-indexed binary array nums of length n.
 * nums can be divided at index i (where 0 <= i <= n) into two arrays (possibly empty) numsleft and numsright:
 * 1. numsleft has all the elements of nums between index 0 and i - 1 (inclusive),
 *    while numsright has all the elements of nums between index i and n - 1 (inclusive).
 * 2. If i == 0, numsleft is empty, while numsright has all the elements of nums.
 * 3. If i == n, numsleft has all the elements of nums, while numsright is empty.
 *
 *
 * The division score of an index i is the sum of the number of 0's in numsleft and the number of 1's in numsright.
 * Return all distinct indices that have the highest possible division score. You may return the answer in any order.
 *
 * Input: nums = [0,0,1,0]
 * Output: [2,4]
 * Explanation:
 *  - 0: numsleft is []. numsright is [0,0,1,0]. The score is 0 + 1 = 1.
    - 1: numsleft is [0]. numsright is [0,1,0]. The score is 1 + 1 = 2.
    - 2: numsleft is [0,0]. numsright is [1,0]. The score is 2 + 1 = 3.
    - 3: numsleft is [0,0,1]. numsright is [0]. The score is 2 + 0 = 2.
    - 4: numsleft is [0,0,1,0]. numsright is []. The score is 3 + 0 = 3.
    Indices 2 and 4 both have the highest possible division score 3.
    Note the answer [4,2] would also be accepted.
 *
 *
 * Input: nums = [0,0,0]
 * Output: [3]
 * Explanation:
 * Division at index
  - 0: numsleft is []. numsright is [0,0,0]. The score is 0 + 0 = 0.
  - 1: numsleft is [0]. numsright is [0,0]. The score is 1 + 0 = 1.
  - 2: numsleft is [0,0]. numsright is [0]. The score is 2 + 0 = 2.
  - 3: numsleft is [0,0,0]. numsright is []. The score is 3 + 0 = 3.
  Only index 3 has the highest possible division score 3.


 * Input: nums = [1,1]
 * Output: [0]
 * Explanation:
 * Division at index
  - 0: numsleft is []. numsright is [1,1]. The score is 0 + 2 = 2.
  - 1: numsleft is [1]. numsright is [1]. The score is 0 + 1 = 1.
  - 2: numsleft is [1,1]. numsright is []. The score is 0 + 0 = 0.
  Only index 0 has the highest possible division score 2.


 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  // Brute Force
  // Time: O(n^2), Space: O(1)
  std::vector<int> solve_brute(std::vector<int> &nums)
  {
    int n = nums.size();
    int max_score = -1;
    std::vector<int> ans;

    for (int i = 0; i <= n; i++)
    {
      int zeros_left = 0;
      int ones_right = 0;

      // Count zeros in left part [0 .. i-1]
      for (int j = 0; j < i; j++)
      {
        if (nums[j] == 0)
          zeros_left++;
      }

      // Count ones in right part [i .. n-1]
      for (int j = i; j < n; j++)
      {
        if (nums[j] == 1)
          ones_right++;
      }

      int score = zeros_left + ones_right;

      if (score > max_score)
      {
        ans.clear();
        max_score = score;
        ans.push_back(i);
      }
      else if (score == max_score)
      {
        ans.push_back(i);
      }
    }

    return ans;
  }

  // Better Approach: Prefix zeros + Suffix ones
  // Time: O(n), Space: O(n)
  std::vector<int> solve_better(std::vector<int> &nums)
  {
    int n = nums.size();

    std::vector<int> prefixZero(n + 1, 0);
    std::vector<int> suffixOne(n + 1, 0);

    // Build prefixZero
    for (int i = 0; i < n; i++)
    {
      prefixZero[i + 1] = prefixZero[i] + (nums[i] == 0);
    }

    // Build suffixOne
    for (int i = n - 1; i >= 0; i--)
    {
      suffixOne[i] = suffixOne[i + 1] + (nums[i] == 1);
    }

    int max_score = -1;
    std::vector<int> ans;

    for (int i = 0; i <= n; i++)
    {
      int score = prefixZero[i] + suffixOne[i];

      if (score > max_score)
      {
        ans.clear();
        max_score = score;
        ans.push_back(i);
      }
      else if (score == max_score)
      {
        ans.push_back(i);
      }
    }

    return ans;
  }

  // Best Approach: Single Pass (O(1) extra space)
  // Time: O(n), Space: O(1)
  std::vector<int> solve_best(std::vector<int> &nums)
  {
    int n = nums.size();

    // Count total number of 1s (initial right score at i = 0)
    int totalOnes = 0;
    for (int x : nums)
    {
      if (x == 1)
        totalOnes++;
    }

    int left_score = 0;
    int right_score = totalOnes;
    int max_score = left_score + right_score;

    std::vector<int> ans;

    // Division at index 0
    ans.push_back(0);

    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
      {
        left_score++;
      }
      else
      {
        right_score--;
      }

      int current_score = left_score + right_score;

      if (current_score > max_score)
      {
        ans.clear();
        max_score = current_score;
        ans.push_back(i + 1);
      }
      else if (current_score == max_score)
      {
        ans.push_back(i + 1);
      }
    }

    return ans;
  }
};

int main()
{
  std::vector<int> nums = {0, 0, 1, 0};

  Solution sol;

  // Choose one approach to test

  // std::vector<int> result = sol.solve_brute(nums);
  // std::vector<int> result = sol.solve_better(nums);
  std::vector<int> result = sol.solve_best(nums);

  std::cout << "Indices with maximum score: ";
  for (int idx : result)
  {
    std::cout << idx << " ";
  }
  std::cout << "\n";

  return 0;
}