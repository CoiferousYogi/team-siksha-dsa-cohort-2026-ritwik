/**
 * Problem Link : https://www.geeksforgeeks.org/problems/equal-to-product3836/1
 *
 * Short Description
 * Given an array, arr[] of positive integers, and a number x,
 * find if there is a pair in arr[] with a product equal to x.
 * Return true if there exists such pair otherwise false.
 *
 *
 * Input: arr[] = [10, 20, 9, 40], x = 400
 * Output: true
 * Explanation: As 10 * 40 = 400, the answer is true.
 *
 *
 * Input: arr[] = [-10, 20, 9, -40], x = 30
 * Output: false
 * Explanation: No pair exists with product 30.
 *
 * Expected Time Complexity: O(n)
 * Expected Space Complexity: O(n)
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution
{
public:
  // Brute Force Approach
  // Try all possible pairs and check if their product equals x.
  // Time: O(n^2), Space: O(1)

  bool is_product_brute(std::vector<int> arr, long long x)
  {
    int n = arr.size();

    // A single element can't make a pair
    if (n == 1)
      return false;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        long long product = 1LL * arr[i] * arr[j];

        if (product == x)
        {
          return true;
        }
      }
    }

    return false;
  }

  // Better/Optimal Approach Using Hash Set
  //
  // For each element a:
  //  1. If a == 0, then we need x == 0 and another 0 already seen.
  //  2. Otherwise, if x % a == 0 and (x / a) exists in the set, we found the pair.
  // Store elements in a set while traversing.
  //
  // Time: O(n), Space: O(n)

  bool is_product_hash(const std::vector<int> &arr, long long x)
  {
    int n = arr.size();
    if (n < 2)
      return false;

    std::unordered_set<long long> st;

    for (int a : arr)
    {
      if (a == 0)
      {
        // else just insert 0 and continue
        if (x == 0 && st.count(0))
          return true;
      }
      else
      {
        if (x % a == 0)
        {
          long long need = x / a;
          if (st.count(need))
            return true;
        }
      }
      st.insert(a);
    }
    return false;
  }

  // Best Approach - Two Pointers after Sorting
  // This approach works correctly when all numbers are NON-NEGATIVE / POSITIVE.
  // For mixed negatives, hash-based approach is safer.
  //
  // Sort the array, use two pointers left and right.
  // Compare product and move pointers accordingly.
  //
  // Time: O(n log n), Space: O(1)

  bool is_product_two_pointers(std::vector<int> arr, long long x)
  {
    int n = arr.size();
    if (n < 2)
      return false;

    std::sort(arr.begin(), arr.end());

    // Init two pointer to track vector from left and right
    int i = 0, j = n - 1;

    while (i < j)
    {
      long long product = 1LL * arr[i] * arr[j];

      if (product == x)
        return true;
      else if (product < x)
        i++;
      else
        j--;
    }

    return false;
  }
};

int main()
{

  std::vector<int> arr1 = {10, 20, 9, 40};
  long long x1 = 400;

  std::vector<int> arr2 = {-10, 20, 9, -40};
  long long x2 = 30;

  Solution sol;

  std::cout << "Brute (arr1): " << sol.is_product_brute(arr1, x1) << "\n";
  std::cout << "Hash  (arr1): " << sol.is_product_hash(arr1, x1) << "\n";
  std::cout << "2Ptr  (arr1): " << sol.is_product_two_pointers(arr1, x1) << "\n\n";

  std::cout << "Brute (arr2): " << sol.is_product_brute(arr2, x2) << "\n";
  std::cout << "Hash  (arr2): " << sol.is_product_hash(arr2, x2) << "\n";

  // Two pointers may not work correctly for mixed negatives, so we skip it here.

  return 0;
}