/*
You are given an array of integers arr[]. You have to reverse the given array.

Note: Modify the array in place.

Examples:

Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
Explanation: The elements of the array are [1, 4, 3, 2, 6, 5]. After reversing the array, the first element goes to the last position, the second element goes to the second last position and so on. Hence, the answer is [5, 6, 2, 3, 4, 1].
Input: arr = [4, 5, 2]
Output: [2, 5, 4]
Explanation: The elements of the array are [4, 5, 2]. The reversed array will be [2, 5, 4].
Input: arr = [1]
Output: [1]
Explanation: The array has only single element, hence the reversed array is same as the original.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  private:
    void printVector(vector<int>& arr) {
        for(int ele : arr) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

  public:
    void reverseArrayIterative(vector<int>& arr) {
        // code here
        int low = 0;
        int high = arr.size()-1;

        while(low < high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;

            low++;
            high--;
        }

        printVector(arr);
    }

    void reverseArrayRec(vector<int>& arr, int low, int high) {
        if(low == high) {
            printVector(arr);
        }

        // swap the low and high elements
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        return reverseArrayRec(arr, low+1, high-1);
    }
};

int main() {
    return 0;
}