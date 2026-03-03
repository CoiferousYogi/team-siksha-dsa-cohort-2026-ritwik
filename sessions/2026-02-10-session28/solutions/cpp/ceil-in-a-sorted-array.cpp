#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:

    // brute fore approach
    int findCeilBrute(vector<int>& arr, int x) {
        // code here
        // brute force: using linear search
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= x) {
                return i;
            }
        }
        
        return -1;
        
        // TC: O(n)
        // SC: O(1)
    }

    // optimal approach
    int findCeilOpt(vector<int>& arr, int x) {
        // code here
        // optimal : using binary search
        
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] >= x) {
                // mid is a probable answer
                ans = mid;
                //discard right half to find any other element >= x
                high = mid - 1;
            }
            else if(arr[mid] < x) {
                // discard left half
                low = mid + 1;
            }
        }
        
        return ans;

        // TC: O(log n)
        // SC: O(1)
    }
};

int main() {
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int x = 5;

    Solution s;
    int ans1 = s.findCeilBrute(arr, x);
    int ans2 = s.findCeilOpt(arr, x);

    return 0;
}