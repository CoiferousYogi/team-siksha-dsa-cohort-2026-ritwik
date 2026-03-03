/**
 * Problem Link : https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * Short Description
 * Given a binary array nums, return the maximum number of consecutive 1's in the array.
 *
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation:
 * The first two digits or the last three digits are consecutive 1s.
 * The maximum number of consecutive 1s is 3.
 *
 *
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
 * Explanation:
 * At index 0, 2, 5 no of ones is repectively is 1, 2 and 1
 * The mazimum number of consecutive 1s is 2
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  // Brute Force: Check each subarray and try to find out how many consecutive 1s
  // The inner loop run O(n) in worse case when every element is 1
  // Time: O(n * n), Space: O(1)

  int find_max_consecutive_ones1(std::vector<int> &nums)
  {
    int n = nums.size();

    // Init a variable to store max no consecutive 1s
    int max_count = 0;

    for (int i = 0; i < n; i++)
    {

      int current_count = 0;

      for (int j = i; j < n; j++)
      {
        // In particular subarray we count the 1s
        // and set to max_count

        if (nums[j] == 1)
        {
          current_count++;
          max_count = std::max(max_count, current_count);
        }
        else
        {
          break;
        }
      }
    }

    return max_count;
  }

  // Best Approach: Single Pass Counter
  // Traverse into array if element is 1 then increase the current_counter by one
  // and save into max_count
  // if element is other than 1 then current_counter is zero
  // Time: O(n), Space: O(1)

  int find_max_consecutive_ones2(std::vector<int> &nums)
  {
    // Init a variable to store max no consecutive 1s
    int max_count = 0;
    int current_count = 0;

    for (auto &ele : nums)
    {
      if (ele == 1)
      {
        current_count++;
        max_count = std::max(max_count, current_count);
      }
      else
      {
        current_count = 0;
      }
    }

    return max_count;
  }

  // Best Approach: Two pointer / zero-boundary method
  // Split the array into parts separated by 0s and find the maximum length
  // of consecutive 1s in those parts.
  // Time: O(n), Space: O(1)

  int find_max_consecutive_ones3(std::vector<int> &nums)
  {

    int n = nums.size();

    // Init two pointer i, j
    // i point a position in array where next sequence start from 1
    // j show the current index and check for this element is 0 or 1
    int i = -1;
    int j = 0;
    int count = 0;

    while (j < n)
    {

      if (nums[j] != 0)
      { // for ones
        j++;
        continue;
      }

      count = std::max(count, j - i - 1);
      i = j;
      j++;
    }

    count = std::max(count, j - i - 1);
    return count;
  }
};

int main()
{
  std::vector<int> nums = {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0};

  Solution sol;

  // Choose one approach to test

  // int result = sol.find_max_consecutive_ones1(nums);
  int result = sol.find_max_consecutive_ones2(nums);
  // int result = sol.find_max_consecutive_ones3(nums);

  std::cout << "Maximum consecutive 1s: " << result << "\n";

  return 0;
}