/**
 * Problem Link : https://leetcode.com/problems/set-mismatch/
 *
 * Short Description
 * You have a set of integers s, which originally contains all the numbers from 1 to n.
 * Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set,
 * which results in repetition of one number and loss of another number.
 *
 * You are given an integer array nums representing the data status of this set after the error.
 * Find the number that occurs twice and the number that is missing and return them in the form of an array.
 *
 *
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 *
 *
 * Input: nums = [1,1]
 * Output: [1,2]
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

class Solution
{
public:
  // Brute Approach
  // We go through in whole array to try to find out which is repeat
  // and how much time repeat
  // if counter == 2 it means, respective ele is duplicate
  // if counter == 0 it means, respective ele is missing
  // Time: O(n^2), Space: O(1)

  std::vector<int> find_error_nums1(std::vector<int> &nums)
  {
    int n = nums.size();

    // Init two variable to store duplicate and missing number
    int duplicate = -1;
    int missing = -1;

    for (int i = 1; i <= n; i++)
    {
      int counter = 0;

      // Iterate in whole array or vector
      for (int &ele : nums)
      {
        if (ele == i)
        {
          counter++;
        }
      }

      if (counter == 2)
      {
        duplicate = i;
      }
      else if (counter == 0)
      {
        missing = i;
      }
    }

    return {duplicate, missing};
  }

  // Better Approach
  // Store the frequency of each elements
  // frequency = 0 => missing
  // frequency = 2 => duplicate
  // Time: O(n), Space: O(n)

  std::vector<int> find_error_nums2(std::vector<int> &nums)
  {

    // We save frequency of element and check which come
    // mulitple and which element is missing

    int missing = -1, duplicate = -1;

    int n = nums.size();
    std::vector<int> temp(n + 1, 0); // [0,0,0,........upto n]

    // Make frequency storage
    for (auto &it : nums)
    {
      temp[it]++;
    }

    for (int i = 1; i <= n; i++)
    {
      if (temp[i] == 0)
        missing = i;
      else if (temp[i] == 2)
        duplicate = i;
    }

    return {duplicate, missing};
  }

  // Better Approach (Using Set and Sum Formula)
  // Idea:
  // 1. Use a set to store unique elements and compute the sum of unique elements.
  // 2. Compute the sum of the given array.
  // 3. Compute the expected sum = n * (n + 1) / 2.
  // 4. Missing number = expected_sum - unique_sum
  // 5. Duplicate number = array_sum - unique_sum
  //
  // Time Complexity: O(n)
  // Space Complexity: O(n)

  std::vector<int> find_error_nums3(std::vector<int> &nums)
  {
    int n = nums.size();

    // Init variable to store expected_sum, unique_sum, array_sum
    int unique_sum = 0;
    int array_sum = 0;
    int expected_sum = (n * (n + 1)) / 2;

    // Init set to store unique number of vector
    // and find out unique sum of elements
    std::set<int> st(nums.begin(), nums.end());

    // calculate unique_sum
    for (auto &it : st)
    {
      unique_sum += it;
    }

    // calculate array_sum
    for (auto &it : nums)
    {
      array_sum += it;
    }

    int missing = expected_sum - unique_sum;
    int duplicate = array_sum - unique_sum;

    return {duplicate, missing};
  }

  // Better Approach (Using Hash Map)
  // Idea:
  // Store the frequency of each number from 1 to n in a hash map.
  // 1. If frequency becomes -1 (or >1 depending on implementation), it is the duplicate.
  // 2. If frequency remains 1 (or 0 depending on implementation), it is the missing number.
  //
  // Time Complexity: O(n)
  // Space Complexity: O(n)

  std::vector<int> find_error_nums4(std::vector<int> &nums)
  {

    int n = nums.size();

    // Init two variable to store duplicate and missing number
    int duplicate = -1;
    int missing = -1;

    // Declare map to store num from 1 to n and it's frequency
    std::unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
      mp[i]++;

    for (auto &it : nums)
      mp[it]--;

    for (auto &it : mp)
    {
      int key = it.first;
      int val = it.second;

      if (val == -1)
        duplicate = key;
      if (val == 1)
        missing = key;
    }

    return {duplicate, missing};
  }

  // Best / Optimal Approach (Using XOR)
  // Idea:
  // 1. XOR all numbers from 1 to n.
  // 2. XOR all elements of the array.
  // 3. The result will be XOR of (missing ^ duplicate).
  // 4. Find the rightmost set bit to separate the numbers into two groups.
  // 5. XOR both groups separately to get the two candidates.
  // 6. Check which one is present in the array to identify duplicate and missing.
  //
  // Time Complexity: O(n)
  // Space Complexity: O(1)

  std::vector<int> find_error_nums5(std::vector<int> &nums)
  {

    int n = nums.size();

    // Init two variable to store xor of natural number and all elements of vector
    int xor_all = 0;
    int xor_array = 0;

    // XOR of all natural number (1,n)
    for (int i = 1; i <= n; i++)
      xor_all ^= i;

    // XOR of all elements of vector
    for (auto &it : nums)
    {
      xor_array ^= it;
    }

    // xor_res will contains xor of duplicate and missing value
    int xor_res = (xor_all ^ xor_array);

    int right_most_set_bit = (xor_res & (-xor_res));

    int xor_set = 0, xor_not_set = 0;

    for (int i = 1; i <= n; i++)
    {
      if (i & right_most_set_bit)
      {
        xor_set ^= i;
      }
      else
      {
        xor_not_set ^= i;
      }
    }

    for (int num : nums)
    {
      if (num & right_most_set_bit)
      {
        xor_set ^= num;
      }
      else
      {
        xor_not_set ^= num;
      }
    }

    for (int num : nums)
    {
      if (num == xor_set)
      {
        return {xor_set, xor_not_set};
      }
    }

    return {xor_not_set, xor_set};
  }
};

int main()
{
  std::vector<int> nums = {1, 2, 2, 4};

  Solution sol;

  // Uncomment to use
  // std::vector<int> ans = sol.find_error_nums1(nums);
  // std::vector<int> ans = sol.find_error_nums2(nums);
  // std::vector<int> ans = sol.find_error_nums3(nums);
  // std::vector<int> ans = sol.find_error_nums4(nums);

  std::vector<int> ans = sol.find_error_nums5(nums);

  std::cout << "Duplicate: " << ans[0] << ", Missing: " << ans[1] << "\n";
  std::cout << "\n";

  return 0;
}