/*
Given two sorted arrays a[] and b[], where each array contains distinct elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 3, 4, 5], b[] = [1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1], b[] = [2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  <=  a.size(), b.size()  <=  105
-109  <=  a[i] , b[i]  <=  109
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <set>

using namespace std;

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnionBrute(vector<int> &a, vector<int> &b) {
        // Your code here
        // brute force: use an ordered set and push all the elements in that
        // we use a set because even though each array has unique elements, an element can be common across the arrays
        set<int> st;
        
        for(int i = 0; i < a.size(); i++) {
            st.insert(a[i]);
        }
        
        for(int i = 0; i < b.size(); i++) {
            st.insert(b[i]);
        }
        
        // convert the set to a vector
        vector<int> res(st.begin(), st.end());
        
        return res;
        
        // return vector with correct order of elements

        /*
            TC: O(2*(m + n)) : (m + n) for iterating during set insertion and another (m + n) while converting set to vector
            SC: O(2*(m+n)): Both sets take up m and n space respectively and the result vector takes up (m + n) space
        */
    }

    // a,b : the arrays
    // Function to return a vector containing the union of the two arrays.
    vector<int> findUnionOpt(vector<int> &a, vector<int> &b) {
        // Your code here
        // optimal approach: using 2 pointers
        int left = 0;
        int right = 0;
        
        vector<int> un;
        
        while((left < a.size()) && (right < b.size())) {
            if(a[left] <= b[right]) {
                if(un.empty() || un.back() != a[left]) {
                    un.push_back(a[left]);
                } 
                left++;
            }
            else {
                // a[left] > b[right]
                if(un.empty() || un.back() != b[right]) {
                    un.push_back(b[right]);
                }
                right++;
            }
        }
        
        // check for remaining elemets
        while(left < a.size()) {
            if(un.empty() || un.back() != a[left]) {
                un.push_back(a[left]);
            }
            left++;
        }
        
        while(right < b.size()) {
            if(un.empty() || un.back() != b[right]) {
                un.push_back(b[right]);
            }
            right++;
        }
        
        return un;

        /*
            TC: O(m + n): iterating two arrays with m and n elements respectively
            SC: O(m + n): extra space for the union vector
        */
    }

    void printVector(vector<int> v) {
        for(int i = 0; i < v.size(); i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

};

int main() {
        vector<int> a = {1,2,3,4,5};
        vector<int> b = {1,2,3,5,7,9};

        Solution s;
        vector<int> ansBrute = s.findUnionBrute(a, b);
        vector<int> ansOpt = s.findUnionOpt(a, b);

        s.printVector(ansBrute);
        s.printVector(ansOpt);
    return 0;
}