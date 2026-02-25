/**
 * Problem Link : https://www.geeksforgeeks.org/dsa/smallest-difference-pair-values-two-unsorted-arrays/
 *
 * Short Description
 * Given two arrays of integers, compute the pair of values
 * (one value in each array) with the smallest (non-negative) difference.
 * Return the difference.
 *
 *
 * Input:  A[] = {1, 3, 15, 11, 2}, B[] = {23, 127, 235, 19, 8}
 * Output: 3
 * Explanation: That is, the pair (11, 8)
 *
 *
 * Input: A[] = {10, 5, 40}, B[] = {50, 90, 80}
 * Output: 10
 * Explanation: That is, the pair (40, 50)
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

class Solution
{
public:
  // Brute Force Approach
  // 1. We run two loop for every elements of vectors
  // 2. If any pair has diff then store it
  // 3. Always try to minimise the store diff
  // Time: O(n*m) , Space: O(1)

  int find_smallest_difference_brute(std::vector<int> &nums1, std::vector<int> &nums2, int n, int m)
  {
    // Init a variable to store minimum diff of elements from both the vector
    int res = INT_MAX;

    // Outer loop
    for (int i = 0; i < n; i++)
    {
      // Inner loop
      for (int j = 0; j < m; j++)
      {
        // Find minimum diff of both the number
        int diff = std::abs(nums1[i] - nums2[j]);
        res = std::min(res, diff);
      }
    }

    return res;
  }

  // Best Approach
  // 1. For removing the two loop we can sort the both the vector
  // 2. Init two pointer i and j and start track elements of vectors
  // 3. Store the diff (diff = nums1[i] - nums2[j])
  // 4. Always try to minimise the store diff
  // Time: O(n log n + m log m), Space: O(1)

  int find_smallest_difference_best(std::vector<int> &nums1, std::vector<int> &nums2, int n, int m)
  {

    // Sort the both the vector
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    // Init a variable to store minimum diff of elements from both the vector
    int res = INT_MAX;

    // Init two pointer so we can track both the vectors
    int i = 0, j = 0;
    while (i < n && j < m)
    {
      // Find minimum diff of both the number
      int diff = std::abs(nums1[i] - nums2[j]);
      res = std::min(res, diff);

      if (nums1[i] < nums2[j])
        i++;
      else
        j++;
    }

    return res;
  }
};

int main()
{
  std::vector<int> nums1 = {1, 3, 15, 11, 2};
  std::vector<int> nums2 = {23, 127, 235, 19, 8};

  int n = nums1.size();
  int m = nums2.size();

  Solution sol;

  int ans = sol.find_smallest_difference_brute(nums1, nums2, n, m);
  // int ans = sol.find_smallest_difference_best(nums1, nums2, n, m);

  std::cout << ans << "\n";

  return 0;
}