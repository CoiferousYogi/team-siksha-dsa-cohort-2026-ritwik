/**
 *
 * Problem Link : https://www.geeksforgeeks.org/problems/reverse-an-array/1
 *
 * Short Description
 * You are given an array of integers arr[]. You have to reverse the given array.
 * Note: Modify the array in place.
 *
 * Input: arr = [1, 4, 3, 2, 6, 5]
 * Output: [5, 6, 2, 3, 4, 1]
 * Explanation: The elements of the array are [1, 4, 3, 2, 6, 5]. After reversing the array, the first element goes to the last
 * position, the second element goes to the second last position and so on. Hence, the answer is [5, 6, 2, 3, 4, 1].
 *
 *
 * Input: arr = [4, 5, 2]
 * Output: [2, 5, 4]
 * Explanation: The elements of the array are [4, 5, 2]. The reversed array will be [2, 5, 4].
 *
 * Input: arr = [1]
 * Output: [1]
 * Explanation: The array has only single element, hence the reversed array is same as the original.
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  // Brute Force: Extra Space
  void reverse_array_brute(std::vector<int> &arr)
  {
    int n = arr.size();
    std::vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
      temp[i] = arr[n - 1 - i];
    }

    // Copy back to original array
    for (int i = 0; i < n; i++)
    {
      arr[i] = temp[i];
    }
  }

  // Better: STL
  void reverse_array_better(std::vector<int> &arr)
  {
    std::reverse(arr.begin(), arr.end());
  }

  // Best: Two Pointer (In-place)
  void reverse_array_best(std::vector<int> &arr)
  {
    // Init two variable to track swaping element index
    int st = 0;
    int end = arr.size() - 1;

    while (st < end)
    {
      std::swap(arr[st], arr[end]);
      st++;
      end--;
    }
  }
};

int main()
{
  std::vector<int> v = {1, 4, 3, 2, 6, 5};

  Solution sol;

  // Choose ONE of the approaches to test

  // sol.reverse_array_brute(v);   // Brute Force
  // sol.reverse_array_better(v);  // Better (STL)
  sol.reverse_array_best(v); // Best (Two Pointer)

  // Print the reversed array
  for (int x : v)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
  return 0;
}