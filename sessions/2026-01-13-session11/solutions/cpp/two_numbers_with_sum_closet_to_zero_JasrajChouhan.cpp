/**
 * Problem Link : https://www.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero1737/1
 *
 * Short Description
 * Given an integer array of N elements.
 * You need to find the maximum sum of two elements such that sum is closest to zero.
 *
 *
 * Input: N = 3, arr[] = {-8 -66 -60}
 * Output: -68
 * Explanation:
 * Sum of two elements closest to
 * zero is -68 using numbers -60 and -8.
 *
 *
 * Input: N = 6, arr[] = {-21 -67 -37 -18 4 -65}
 * Output: -14
 * Explanation:
 * Sum of two elements closest to
 * zero is -14 using numbers -18 and 4.
 *
 * Expected Time Complexity: O(N*logN).
 * Expected Auxiliary Space: O(1).
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
  // Brute Force Approach
  // Try all possible pairs and compute their sum.
  // Track the sum whose absolute value is minimum.
  // Time: O(n^2), Space: O(1)

  int two_sum_closest_to_zero_brute(std::vector<int> &arr)
  {
    int n = arr.size();

    // Edge case
    if (n < 2)
      return 0;

    int best_sum = arr[0] + arr[1];
    int min_abs = std::abs(best_sum);

    // Travrase the vector, outer loop
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int curr_sum = arr[i] + arr[j];
        int curr_abs = std::abs(curr_sum);

        if (curr_abs < min_abs)
        {
          min_abs = curr_abs;
          best_sum = curr_sum;
        }
      }
    }

    return best_sum;
  }

  // Best/Optimal Approach
  // 1. Sort the array
  // 2. Use two pointers: left at start, right at end
  // 3. Compute sum = arr[left] + arr[right]
  // 4. Update answer if abs(sum) is smaller
  // 5. If sum < 0, move left++ to increase sum
  //    else move right-- to decrease sum
  // Time: O(n log n), Space: O(1)

  int two_sum_closest_to_zero_best(std::vector<int> &arr)
  {
    int n = arr.size();
    if (n < 2)
      return 0;

    std::sort(arr.begin(), arr.end());

    // Init left and right pointer to track vector from both side
    int left = 0, right = n - 1;
    int best_sum = arr[left] + arr[right];
    int min_abs = std::abs(best_sum);

    // Travrase the vector
    while (left < right)
    {
      int curr_sum = arr[left] + arr[right];
      int curr_abs = std::abs(curr_sum);

      if (curr_abs < min_abs)
      {
        min_abs = curr_abs;
        best_sum = curr_sum;
      }

      if (curr_sum < 0)
        left++;
      else
        right--;
    }

    return best_sum;
  }
};

int main()
{

  std::vector<int> arr1 = {-8, -66, -60};
  std::vector<int> arr2 = {-21, -67, -37, -18, 4, -65};

  Solution sol;

  // int ans1 = sol.two_sum_closest_to_zero_brute(arr1);
  int ans1 = sol.two_sum_closest_to_zero_best(arr1);

  // int ans2 = sol.two_sum_closest_to_zero_brute(arr2);
  int ans2 = sol.two_sum_closest_to_zero_best(arr2);

  std::cout << "Answer for arr1: " << ans1 << "\n";
  std::cout << "Answer for arr2: " << ans2 << "\n";

  return 0;
}