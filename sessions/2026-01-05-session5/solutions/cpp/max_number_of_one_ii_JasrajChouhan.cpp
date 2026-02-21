/**
 * Problem Link : https://www.geeksforgeeks.org/dsa/max-number-of-one-ii/
 *
 * Short Description
 * You are given a binary array arr[], containing only 0s and 1s.
 * You are allowed to flip at most one 0 to 1.
 * Your task is to determine the maximum length of consecutive 1s that can be obtained
 * in the array after performing at most one such flip.
 *
 *
 * Input: arr[] = [0, 1, 0, 1, 1]
 * Output: 4
 * Explanation:
 * If we flip the first zero, nums becomes [1,1,0,1,1] and we have 2 consecutive ones.
 * If we flip the second zero, nums becomes [0,1,1,1,1] and we have 4 consecutive ones.
 * The max number of consecutive ones is 4.
 *
 *
 * Input: arr[] = [0, 1, 0]
 * Output: 2
 * Explanation:
 * If we flip the first zero, nums becomes [1,1,0] and we have 2 consecutive ones.
 * If we flip the second zero, nums becomes [0,1,1] and we have 2 consecutive ones.
 * The max number of consecutive ones is 2.
 *
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  // Sliding Window: At most one 0 can be flipped
  // Time: O(n), Space: O(1)
  int max_consecutive_one(std::vector<int> &arr, int N)
  {
    int left = 0;       // Left Pointer of sliding window
    int zero_count = 0; // Count the no of zeroes in a sliding window
    int max_len = 0;    // Track the max length of sliding window

    for (int right = 0; right < N; right++)
    {
      // If current element is zero, increase the zero_count
      if (arr[right] == 0)
      {
        zero_count++;
      }

      // If more than one zero in window, shrink from left
      while (zero_count > 1)
      {
        if (arr[left] == 0)
        {
          zero_count--;
        }
        left++;
      }

      // Update maximum length
      max_len = std::max(max_len, right - left + 1);
    }

    return max_len;
  }
};

int main()
{
  std::vector<int> arr = {0, 1, 0, 1, 1};
  int n = arr.size();

  Solution sol;
  int result = sol.max_consecutive_one(arr, n);

  std::cout << "Maximum consecutive 1s after at most one flip: " << result << std::endl;

  return 0;
}