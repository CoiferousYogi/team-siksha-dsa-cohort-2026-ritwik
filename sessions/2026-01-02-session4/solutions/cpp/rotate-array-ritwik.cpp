/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;


/*
For rotating an array, the main thing that needs to be taken care of is the no. of rotations required
For example, consider nums = {1,2,3,4,5} where n = 5
If k = 10, nums will become => nums = {1,2,3,4,5} which is similar to what happens if k = 0
If k = 7, nums will become => nums = {4,5,1,2,3} which is similar to what happens if k = 2


{1 2 3 4 5} => {3 4 5 1 2} k = 3

{1 2 3 4 5}

{5 4 3 2 1}
{4 5 3 2 1}
{4 5 1 2 3}

In short, no. of rotations =  n % k

Secondly, we must find the pivot index. The pivot index is the index in the rotatated array at which the sorted order breaks.
For nums = {4,5,1,2,3}, the sorted order breaks at index 2. Hence pivotIndex = 2
*/

/*
Brute force approach:
For brute force we will use an extra array to make the rotated array
We will take the k = k % n elements from the back and append it to the start of the new array
After that we will append the remaining n - k elements from the original array to the new array
*/
void rotateBrute(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        if(k == 0) {
            return;
        }
        
        vector<int> arr;

        for(int i = n - k; i < nums.size(); i++) {
            arr.push_back(nums[i]);
        }

        for(int i = 0; i <= n-k-1; i++) {
            arr.push_back(nums[i]);
        }

        for(int i = 0; i < arr.size(); i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    return;
}

/*
For the optimal approach we can
1. Reverse the entire array
2. Reverse the sub-array from 0 to k-1 and the sub-array from n-k-1 till n-1 separately

*/
void rotateOpt(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    if(k == 0) {
        return;
    }

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());

    for(int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}


int main() {
        vector<int> nums = {1,2,3,4,5};
        int k = 23;

        rotateBrute(nums, k);
        cout<<endl;
        cout<<nums.size() % k<<endl;

        rotateOpt(nums, k);
        cout<<endl;
        
        
    return 0;
}