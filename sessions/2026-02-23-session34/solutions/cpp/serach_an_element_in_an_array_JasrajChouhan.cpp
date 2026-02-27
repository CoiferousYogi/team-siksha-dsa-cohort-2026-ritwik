/**
 * Problem Link : https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1
 *
 * Short Description
 * Given an array, arr[] of n integers, and an integer element x,
 * find whether element x is present in the array. Return the index of the
 * first occurrence of x in the array, or -1 if it doesn't exist.
 *
 *
 * Input: arr[] = [1, 2, 3, 4], x = 3
 * Output: 2
 * Explanation:
 * For array [1, 2, 3, 4], the element to be searched is 3.
 * Since 3 is present at index 2, the output is 2.
 *
 *
 * Input: arr[] = [10, 8, 30, 4, 5], x = 5
 * Output: 4
 * Explanation:
 * For array [10, 8, 30, 4, 5], the element to be searched is 5
 * and it is at index 4. So, the output is 4.
 *
 * Input: arr[] = [10, 8, 30], x = 6
 * Output: -1
 * Explanation:
 * The element to be searched is 6 and it is not present, so we return -1.
 *
 * Time Complexity: O(n)
 * Auxiliary Space: O(1)
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
  /**
   * Search Linear by Recursive Approach
   * Sub-problem is find target ele in
   * idx + 1 to n - 1 index of nums
   *
   * So, f(nums , x , idx + 1) is sub-problem
   * for f(nums, x, idx)
   *
   * When current index crosses size of array
   * return -1 (Because target not found in array)
   *
   * Time: O(n), Space: O(n)
   */

  int search_linear_recursive_helper(const std::vector<int> &nums, int x, int idx)
  {

    // Base Case
    if (idx >= nums.size())
    {
      return -1;
    }

    // Self Work
    if (nums[idx] == x)
      return idx;

    // Recursive Work
    return search_linear_recursive_helper(nums, x, idx + 1);
  }

  /**
   * Linearly Traverse the vector
   * If any one element is equal to search element
   * It means we found out, return index
   * If x is not present is nums, return -1
   *
   * Time: O(n), Space: O(1)
   */

  int search_linear_iterative(const std::vector<int> &nums, int x)
  {
    int n = nums.size();

    // Traverse the vector nums
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == x)
        return i;
    }

    return -1;
  }

  int search_linear_recursive(const std::vector<int> &nums, int x)
  {

    int ans = search_linear_recursive_helper(nums, x, 0);
    return ans;
  }

  /**
   * While array may be sorted so we first sorted
   * After sorting original index can be change
   *
   * So, we store (ele , original index) as
   * pair of vector
   *
   * After sort the array, we can apply binary search
   * Time: O(n log n), Space: O(n)
   */

  int search_binary(const std::vector<int> &nums, int x)
  {

    int n = nums.size();

    // Store ele with original index
    std::vector<std::pair<int, int>> arr;

    // Store into vector of pair
    for (int i = 0; i < n; i++)
    {
      arr.push_back({nums[i], i});
    }

    // Sort the array, so we can apply binary search
    std::sort(arr.begin(), arr.end());

    // Applied Binary Search on Sorted arr value based
    int st = 0, end = n - 1;

    while (st <= end)
    {
      int mid = st + (end - st) / 2;

      int ele = arr[mid].first;
      int idx = arr[mid].second;

      if (ele == x)
      {
        return idx;
      }
      else if (ele < x)
      {
        st = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }

    // Target not found
    return -1;
  }
};

int main()
{

  std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int> nums2 = {1, 2, 3, -1, -4, 5, 60, 7};

  // Create an object of class Solution
  Solution sol;

  std::cout << "Linear Iterative (find 4 in nums1): "
            << sol.search_linear_iterative(nums1, 4) << std::endl;

  std::cout << "Linear Recursive (find 5 in nums2): "
            << sol.search_linear_recursive(nums2, 5) << std::endl;

  std::cout << "Binary Search (find 5 in nums2): "
            << sol.search_binary(nums2, 5) << std::endl;

  std::cout << "Binary Search (find 6 in nums2): "
            << sol.search_binary(nums2, 6) << std::endl;

  std::cout << "\n";

  return 0;
}