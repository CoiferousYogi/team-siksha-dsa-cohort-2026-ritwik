/*
You are given an integer array arr[]. The task is to find the sum of it.

Examples:

Input: arr[] = [1, 2, 3, 4]
Output: 10
Explanation: 1 + 2 + 3 + 4 = 10.
Input: arr[] = [1, 3, 3]
Output: 7
Explanation: 1 + 3 + 3 = 7.
Constraints:
1 <= arr.size <= 105
1 <= arr[i] <= 104
*/

#include <iostream>
#include <vector>

using namespace std;

// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
        int sum = 0; // initializing as 0 as 0 is the additive identity under R

        for(const int &e : arr) {
            sum += e;
        }

        /*
            for(int i = 0; i < arr.size(); i++) {
                sum += arr[i];
            }

                        OR

            int i = 0;
            while(i < arr.size()) {
                sum += arr[i];
                i++;
            }
        */

        return sum;

        // TC: O(n)
        // SC: O(1)
    }
};

int main() {
        vector<int> arr = {1, 2, 3, 4};

        Solution s;

        cout<<s.arraySum(arr)<<endl;
    return 0;
}