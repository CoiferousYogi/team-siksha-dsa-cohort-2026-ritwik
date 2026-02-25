/**
 * Problem Link : https://www.geeksforgeeks.org/problems/reverse-an-array/1
 *
 * Short Description
 * You are given an array of integers arr[]. You have to reverse the given array.
 * Note: Modify the array in place
 *
 *
 * Input: arr = [1, 4, 3, 2, 6, 5]
 * Output: [5, 6, 2, 3, 4, 1]
 * Explanation:
 * The elements of the array are [1, 4, 3, 2, 6, 5].
 * After reversing the array, the first element goes to the last position,
 * the second element goes to the second last position and so on. Hence,
 * the answer is [5, 6, 2, 3, 4, 1].
 *
 *
 * Input: arr = [4, 5, 2]
 * Output: [2, 5, 4]
 * Explanation: The elements of the array are [4, 5, 2]. The reversed array will be [2, 5, 4].
 *
 * Input: arr = [1]
 * Output: [1]
 * Explanation: The array has only single element, hence the reversed array is same as the original.
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  /**
   * Iterative Approach
   * Init two index st and end
   * continue swaping nums[st], nums[end]
   * move both pointer
   *
   * Time: O(n), Space: O(1)
   */
  void reverse_array(std::vector<int> &nums, int st, int end)
  {

    while (st < end)
    {
      std::swap(nums[st], nums[end]);
      st++;
      end--;
    }
  }

  /**
   * Recursive Approach
   * Sub problem is here, swapping is done by recursion
   * from index st + 1 to end - 1
   * Self work is swapping nums[st], nums[end]
   *
   * Base Case: When st index cross end index
   * or came at same position
   *
   * Time: O(n), Space: O(n)
   * In recursion time complexity is => Time of one call * Total no of call
   * In recursion space complexity is => Total stack space + extra space
   */

  void reverse_array_by_rec(std::vector<int> &nums, int st, int end)
  {

    // Base Case
    if (st >= end)
      return;

    // Self Work
    std::swap(nums[st], nums[end]);

    // Recursive Work
    reverse_array_by_rec(nums, st + 1, end - 1);
  }

  void print(std::vector<int> &nums)
  {
    for (int &it : nums)
    {
      std::cout << it << " ";
    }
  }
};

int main()
{

  std::vector<int> nums1 = {1, 4, 3, 2, 6, 5};
  std::vector<int> nums2 = {1, 6, 9, 7, 3, 5};

  Solution sol;

  sol.reverse_array(nums1, 0, nums1.size());
  sol.reverse_array_by_rec(nums2, 0, nums2.size());

  // Print the reversed array
  sol.print(nums1);
  std::cout << "\n";

  sol.print(nums2);
  std::cout << "\n";

  return 0;
}