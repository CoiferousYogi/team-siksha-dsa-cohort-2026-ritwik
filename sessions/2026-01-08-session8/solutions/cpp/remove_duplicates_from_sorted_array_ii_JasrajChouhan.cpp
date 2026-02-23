/**
 * Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 *
 * Short Description
 * Given an integer array nums sorted in non-decreasing order,
 * remove some duplicates in-place such that each unique element appears at most twice.
 * The relative order of the elements should be kept the same.
 *
 *
 * Since it is impossible to change the length of the array in some languages,
 * you must instead have the result be placed in the first part of the array nums.
 * More formally, if there are k elements after removing the duplicates,
 * then the first k elements of nums should hold the final result.
 * It does not matter what you leave beyond the first k elements.
 *
 * Return k after placing the final result in the first k slots of nums.
 *
 *
 * Input: nums = [1,1,1,2,2,3]
 * Output: 5, nums = [1,1,2,2,3,_]
 * Explanation:
 * Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
 *
 * Input: nums = [0,0,1,1,1,1,2,3,3]
 * Output: 7, nums = [0,0,1,1,2,3,3,_,_]
 * Explanation:
 * Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
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
  // Brute Force Approach - Using Extra Array
  // Traverse the array and keep at most two copies of each number in a temp array.
  // Then copy the temp array back to nums.
  // Time: O(n), Space: O(n)

  int remove_duplicates_brute(std::vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;

    std::vector<int> temp;

    // count of current number
    int count = 1;

    temp.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
      if (nums[i] == nums[i - 1])
      {
        count++;
      }
      else
      {
        count = 1;
      }

      if (count <= 2)
      {
        temp.push_back(nums[i]);
      }
    }

    // Copy back to nums
    for (int i = 0; i < temp.size(); i++)
    {
      nums[i] = temp[i];
    }

    return temp.size();
  }

  // Better Approach - Using Hash Map
  // Use a map to store frequency of each number.
  // Traverse nums, and keep the number only if its frequency is less than 2.
  // Time: O(n), Space: O(n)
  int remove_duplicates_better(std::vector<int> &nums)
  {
    std::unordered_map<int, int> freq;

    // write index
    int k = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (freq[nums[i]] < 2)
      {
        freq[nums[i]]++;
        nums[k] = nums[i];
        k++;
      }
    }

    return k;
  }

  // Best/Optimal Approach - Two Pointers, In-Place
  // Since the array is sorted, duplicates are adjacent.
  // Always keep the first two elements.
  // For each next element, keep it only if it is different from nums[k-2].
  // Time: O(n), Space: O(1)
  int remove_duplicates_best(std::vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 2)
      return n;

    // position to place next valid element
    int k = 2;

    for (int i = 2; i < n; i++)
    {
      if (nums[i] != nums[k - 2])
      {
        nums[k] = nums[i];
        k++;
      }
    }

    return k;
  }
};

int main()
{
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};

  Solution sol;

  // Choose one approach to test
  // int k = sol.remove_duplicates_brute(nums);
  // int k = sol.remove_duplicates_better(nums);
  int k = sol.remove_duplicates_best(nums);

  std::cout << "New length: " << k << "\n";
  std::cout << "Modified array: ";
  for (int i = 0; i < k; i++)
  {
    std::cout << nums[i] << " ";
  }
  std::cout << "\n";

  return 0;
}