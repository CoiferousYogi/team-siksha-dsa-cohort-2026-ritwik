/*
Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: [1, 2, 3, 4, 5, 6, 7]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: [1, 2, 3, 4, 5]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
Output: [1, 2]
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  ≤  a.size(), b.size()  ≤  105
-109 ≤ a[i], b[i] ≤109
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
    vector<int> findUnionBrute(vector<int> &a, vector<int> &b) {
        // code here
        // for the brute force approach, we will use a set
        // make a set and traverse through both the arrays
        unordered_set<int> st;
        
        // traverse the first array
        for(int i = 0; i < a.size(); i++) {
            st.insert(a[i]);
        }
        
        // traverse the 2nd array
        for(int i = 0; i < b.size(); i++) {
            st.insert(b[i]);
        }
        
        // converting the set to a vector
        vector<int> res(st.begin(), st.end());
        
        // sorting the vector since we need the union in a sorted fashion
        sort(res.begin(), res.end());
        return res;
    }

    vector<int> findUnionOpt(vector<int> &a, vector<int> &b) {
        // code here
        // for the optimal approach, we will be using 2 pointers
        int left = 0; // for vector a
        int right = 0; // for vector b
        
        // making a separate vector for the union
        vector<int> un;
        
        while((left < a.size()) && (right < b.size())) {
            // compare the elements and push the smallest to the new vector
            if(a[left] <= b[right]) {
                // check if the union is empty and take the last element
                if(un.empty() || un.back() != a[left]) {
                    un.push_back(a[left]);
                }
                left++;
            }
            else {
                // arr[left] > arr[right]
                if(un.empty() || un.back() != b[right]) {
                    un.push_back(b[right]);
                }
                right++;
            }
        }
        
        // now we have to check and push the remaining elements of either a or b
        while(left < a.size()) {
            if(un.empty() || a[left] != un.back()) {
                un.push_back(a[left]);
            }
            left++;
        }
        
        while(right < b.size()) {
            if(un.empty() || b[right] != un.back()) {
                un.push_back(b[right]);
            }
            right++;
        }
        
        return un;
    }

    void printVector(vector<int>& v) {
        for(int i = 0; i < v.size(); i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
        vector<int> a = {1, 2, 3, 4, 5};
        vector<int> b = {1, 2, 3, 6, 7};

        Solution s;
        vector<int> unBrute = s.findUnionBrute(a, b);
        s.printVector(unBrute);

        vector<int> unOpt = s.findUnionOpt(a, b); 
        s.printVector(unOpt);
    return 0;
}