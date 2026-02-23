/**
 * Problem Link : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
 *
 * Short Description
 * Given two sorted arrays a[] and b[], where each array may contain duplicate elements ,
 * the task is to return the elements in the union of the two arrays in sorted order.
 * Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
 *
 *
 *
 * Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
 * Output: [1, 2, 3, 4, 5, 6, 7]
 * Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
 *
 *
 * Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
 * Output: [1, 2, 3, 4, 5]
 * Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
 *
 * Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
 * Output: [1, 2]
 * Explanation: Distinct elements including both the arrays are: 1 2.
 *
 */

/************************************* Solution **************************************************** */

#include <iostream>
#include <vector>
#include <set>

class Solution
{
public:
  // Brute Approach
  // Insert all elements into set and find out
  // union of both sorted array
  // Time: O(m + n (log(m + n))), Space: O(m + n)

  std::vector<int> find_union1(std::vector<int> &a, std::vector<int> &b)
  {

    // Declare set to store data value fo vector a,b
    std::set<int> st;
    std::vector<int> res;

    // Push all elements of vector into set
    for (auto &it : a)
    {
      st.insert(it);
    }

    // Push all elements of vector into set
    for (auto &it : b)
    {
      st.insert(it);
    }

    for (auto &it : st)
    {
      res.push_back(it);
    }

    return res;
  }

  // Best Approach
  // Init two pointer and track the elements of both the vector
  // If same element appear then add in res(vector) and move both the pointer
  // If first one is small then add small element and move resptive pointer
  // Make sure res(vector) always unique
  // Time: O(m + n), Space: O(1)

  std::vector<int> find_union2(std::vector<int> &a, std::vector<int> &b)
  {
    int n = a.size();
    int m = b.size();

    std::vector<int> res;

    // Init two pointer to track current value and index of both the array/vector
    int i = 0, j = 0;

    while (i < n && j < m)
    {
      if (a[i] == b[j])
      {
        add_if_not_duplicate(res, a[i]);
        i++;
        j++;
      }

      else if (a[i] < b[j])
      {
        add_if_not_duplicate(res, a[i]);
        i++;
      }

      else
      {
        add_if_not_duplicate(res, b[j]);
        j++;
      }
    }

    // Add remaining elements of nums1 (if any)
    add_remaining(a, i, res);

    // Add remaining elements of nums2 (if any)
    add_remaining(b, j, res);

    return res;
  }

private:
  // Adds remaining elements from an array starting at index 'idx'
  void add_remaining(std::vector<int> &nums, int idx, std::vector<int> &res)
  {
    while (idx < nums.size())
    {
      add_if_not_duplicate(res, nums[idx]);
      idx++;
    }
  }

  // Adds an element to result if it is not a duplicate of the last inserted element
  void add_if_not_duplicate(std::vector<int> &res, int ele)
  {
    if (res.empty() || res.back() != ele)
    {
      res.push_back(ele);
    }
  }
};

int main()
{
  std::vector<int> a = {1, 2, 3, 4, 5};
  std::vector<int> b = {1, 2, 3, 6, 7};

  Solution sol;

  // Uncomment to test the code

  std::vector<int> res = sol.find_union1(a, b);
  // std::vector<int> res = sol.find_union2(a, b);

  // Print the vector
  std::cout << "Union of both sorted array is : ";
  for (auto &it : res)
  {
    std::cout << it << " ";
  }
}