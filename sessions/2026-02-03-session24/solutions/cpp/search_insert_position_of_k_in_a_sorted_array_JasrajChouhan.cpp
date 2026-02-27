/**
 * Problem Link : https://www.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1
 *
 * Short Description
 * Given a sorted array arr[] (0-index based) of distinct
 * integers and an integer k, find the index of k if it is present
 * in the arr[]. If not, return the index where k should be
 * inserted to maintain the sorted order.
 *
 *
 * Input: arr[] = [1, 3, 5, 6], k = 5
 * Output: 2
 * Explanation:
 * Since 5 is found at index 2 as arr[2] = 5, the output is 2.
 *
 *
 * Input: arr[] = [1, 3, 5, 6], k = 2
 * Output: 1
 * Explanation:
 * The element 2 is not present in the array, but inserting it at
 * index 1 will maintain the sorted order.
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>

class Solution
{
public:
  /**
   * Linear Approach
   * Traverse the array and find the first index i such that nums[i] >= k.
   * That index is the correct insert position.
   *
   * Time: O(n)
   * Space: O(1)
   */
  int search_insert_k_linear(const std::vector<int> &nums, int k)
  {

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      if (nums[i] >= k)
        return i;
    }

    // If k is greater than all elements, insert at end
    return n;
  }

  /**
   * Binary Search Approach
   * Use binary search to find the first position where nums[mid] >= k.
   * If k is found, return its index.
   * Otherwise, return the position where it should be inserted.
   *
   * Time: O(log n)
   * Space: O(1)
   */
  int search_insert_k_binary(const std::vector<int> &nums, int k)
  {

    int n = nums.size();

    int st = 0, end = n - 1;

    while (st <= end)
    {
      int mid = st + (end - st) / 2;

      if (nums[mid] == k)
        return mid;
      else if (nums[mid] < k)
        st = mid + 1;
      else
        end = mid - 1;
    }

    return st;
  }
};

int main()
{

  std::vector<int> nums = {1, 3, 5, 6};

  Solution sol;

  std::cout << "Linear (k = 5): " << sol.search_insert_k_linear(nums, 5) << std::endl;
  std::cout << "Linear (k = 2): " << sol.search_insert_k_linear(nums, 2) << std::endl;

  std::cout << "Binary (k = 5): " << sol.search_insert_k_binary(nums, 5) << std::endl;
  std::cout << "Binary (k = 2): " << sol.search_insert_k_binary(nums, 2) << std::endl;

  return 0;
}