/**
 * Problem Link : https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
 *
 * Short Description
 * You are given an array arr of positive integers.
 * Your task is to find all the leaders in the array.
 * An element is considered a leader if it is greater than or equal to all elements to its right.
 * The rightmost element is always a leader.
 *
 *
 * Input: arr = [16, 17, 4, 3, 5, 2]
 * Output: [17, 5, 2]
 * Explanation:
 * Note that there is nothing greater on the right side of 17, 5 and, 2.
 *
 *
 * Input: arr = [10, 4, 2, 4, 1]
 * Output: [10, 4, 4, 1]
 * Explanation:
 * Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side
 *
 *
 * Input: arr = [5, 10, 20, 40]
 * Output: [40]
 * Explanation:
 * When an array is sorted in increasing order, only the rightmost element is leader.
 *
 *
 * Input: arr = [30, 10, 10, 5]
 * Output: [30, 10, 10, 5]
 * Explanation:
 * When an array is sorted in non-increasing order, all elements are leaders.
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  // Brute Force Approach
  // For every element of vector, we serach in entire vector
  // if any element which have greater then right side element
  // then store in res vector
  // Time: O(n * n) , Space: O(1)

  std::vector<int> array_leaders_brute(std::vector<int> &nums)
  {
    int n = nums.size();

    // Edge case
    if (n == 1)
    {
      return nums;
    }

    // Init a vector to store leaders of a vector
    std::vector<int> res;

    for (int i = 0; i < n; i++)
    {
      int ele = nums[i];

      int j = i + 1;
      while (j < n)
      {
        if (nums[j] > ele)
          break;
        j++;
      }

      if (j == n)
        res.push_back(ele);
    }
    return res;
  }

  // Best Approach - Move from right side
  // We init a pointer and start tracking next leader of vector
  // by traversing right to left
  // Note: rightmost element always a leader element of vector
  // After that we reverse that res vector
  // Time: O(n), Space: O(1)

  std::vector<int> array_leaders_best(std::vector<int> &nums)
  {
    int n = nums.size();

    // Edge case
    if (n == 1)
    {
      return nums;
    }

    // Init a vector to store leaders of a vector
    std::vector<int> res;

    // Rightmost element always an array leader
    int maxi = nums[n - 1];
    res.push_back(maxi);

    for (int idx = n - 2; idx >= 0; idx--)
    {
      if (nums[idx] >= maxi)
      {
        maxi = nums[idx];
        res.push_back(maxi);
      }
    }

    std::reverse(res.begin(), res.end());

    return res;
  }
};

int main()
{

  std::vector<int> nums = {16, 17, 4, 3, 5, 2};

  Solution sol;
  // std::vector<int> ans = sol.array_leaders_brute(nums);
  std::vector<int> ans = sol.array_leaders_best(nums);

  // Print the vector
  std::cout << "Array of leaders : ";
  for (auto &it : ans)
  {
    std::cout << it << " ";
  }

  std::cout << "\n";
}