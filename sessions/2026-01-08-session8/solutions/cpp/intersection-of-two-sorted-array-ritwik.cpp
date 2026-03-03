/*
Given two sorted arrays arr1[] and arr2[]. Your task is to return the intersection of both arrays.
Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not count duplicate elements.
Note: If there is no intersection then return an empty array.

Examples:

Input: arr1[] = [1, 2, 3, 4], arr2[] = [2, 4, 6, 7, 8]
Output: [2, 4]
Explanation: 2 and 4 are only common elements in both the arrays.
Input: arr1[] = [1, 2, 2, 3, 4], arr2[] = [2, 2, 4, 6, 7, 8]
Output: [2, 4]
Explanation: 2 and 4 are the only common elements.
Input: arr1[] = [1, 2], arr2[] = [3, 4]
Output: []
Explanation: No common elements.
Constraints:
1 ≤ arr1.size(),arr2.size() ≤ 105
1 ≤ arr1[i], arr2[i] ≤ 106
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersectionBrute(vector<int>& a, vector<int>& b) {
        // for brute force we will merge both arrays and then use a set to take out the common elements

        vector<int> merged;

        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] == b[j]) {
                merged.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i] < b[j]) {
                merged.push_back(a[i]);
                i++;
            }
            else {
                // a[i] > b[j]
                merged.push_back(b[j]);
                j++;
            }
        }

        while(i < a.size()) {
            merged.push_back(a[i]);
        }

        while(j < b.size()) {
            merged.push_back(b[i]);
        }

        unordered_set<int> st;

        for(int ele : merged) {
            st.insert(ele);
        }

        vector<int> res(st.begin(), st.end());

        return res;

        /*
            TC: O(m+n + m+n + min(m,n)) => m+n for merging, m+n for set, min(m,n) for converting set to vector
            SC: O(m+n + min(m,n) + min(m,n)) => m+n for merging, min(m,n) for set and min(m,n) for vector result
        */
    }

    vector<int> intersectionOpt(vector<int> &arr1, vector<int> &arr2) {
        // code here
        // 2 pointer solution
        int i = 0;
        int j = 0;
        
        // making a separate vector to store the intersection
        vector<int> res;
        
        while((i < arr1.size()) && (j < arr2.size())) {
            // check the conditions
            if(arr1[i] < arr2[j]) {
                i++;
            }
            else if(arr1[i] > arr2[j]) {
                j++;
            }
            else {
                if(res.empty() || res.back() != arr1[i]) {
                    res.push_back(arr1[i]);
                }
                i++;
                j++;
            }
        }
        return res;

        /*
            TC: O(min(m,n)) => for array traversals
            SC: O(min(m,n)) => extra space for resultant vector
        */
    }

};

int main() {
    return 0;
}