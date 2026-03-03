/**
 * Problem Link : https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1
 *
 *
 * Short Description
 * Given two sorted arrays arr1[] and arr2[]. Your task is to return the intersection of both arrays.
 * Intersection of two arrays is said to be elements that are common in both arrays.
 * The intersection should not count duplicate elements.
 * Note: If there is no intersection then return an empty array.
 *
 *
 * Input: arr1[] = [1, 2, 3, 4], arr2[] = [2, 4, 6, 7, 8]
 * Output: [2,4]
 * Explanation:
 * 2 and 4 are only common elements in both the arrays.
 *
 * Input: arr1[] = [1, 2, 2, 3, 4], arr2[] = [2, 2, 4, 6, 7, 8]
 * Output: [2,4]
 * Explanation:
 * 2 and 4 are only common elements in both the arrays.
 *
 * Input: arr1[] = [1, 2], arr2[] = [3, 4]
 * Output: []
 * Explanation:
 * No commen elements.
 */

#include <iostream>
#include <vector>

class Solution
{
public:
  // Brute Force Approach
  // For each element in nums1, try to find it in nums2.
  // Use a visited array to make sure we don't take the same element twice from nums2.
  // Also avoid inserting duplicates into the result.
  // Time: O(n*m), Space: O(m)

  std::vector<int> intersection_array_brute(std::vector<int> &nums1, std::vector<int> &nums2)
  {

    int n = nums1.size();
    int m = nums2.size();

    // Init a vector to store common elements of both the vector
    std::vector<int> temp;

    // Init a visted vector to mark visited item of vector
    std::vector<int> visited(m, 0);

    // Travase in both the vector
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {

        // If nums1[i] == nums2[j] and nums2[j] is not visited
        if (nums1[i] == nums2[j] && visited[j] == 0)
        {
          temp.push_back(nums1[i]);
          visited[j] = 1;
          break;
        }
        // If num2[j] is greater than nums1[i] break out of the loop
        else if (nums2[j] > nums1[i])
          break;
      }
    }

    return temp;
  }

  // Best Approach (Two Pointers)
  // Since both arrays are sorted, use two pointers.
  // When elements are equal, add to result and skip all duplicates of that element in both arrays.
  // Time: O(n + m), Space: O(1)

  std::vector<int> intersection_array_best(std::vector<int> &nums1, std::vector<int> &nums2)
  {

    int n = nums1.size();
    int m = nums2.size();

    // Init two pointer to track or travase in both the vector/array
    int i = 0, j = 0;

    // Init a vector to store common elements of both the vector
    std::vector<int> temp;

    while (i < n && j < m)
    {
      if (nums1[i] == nums2[j])
      {
        temp.push_back(nums1[i]);
        i++;
        j++;
      }
      else if (nums1[i] < nums2[j])
        i++;
      else
        j++;
    }

    return temp;
  }
};

int main()
{
  std::vector<int> nums1 = {1, 2, 3, 4};
  std::vector<int> nums2 = {2, 4, 6, 7, 8};

  Solution sol;
  // std::vector<int> ans = sol.intersection_array_brute(nums1, nums2);
  std::vector<int> ans = sol.intersection_array_best(nums1, nums2);

  // Print the vector
  std::cout << "Intersection of both the array : ";
  for (auto &it : ans)
  {
    std::cout << it << " ";
  }
  std::cout << "\n";
  return 0;
}