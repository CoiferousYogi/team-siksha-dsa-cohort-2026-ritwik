#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    int findFloorBrute(vector<int>& arr, int x) {
        // code here
        // brute force: linear search
        
        for(int i = arr.size()-1; i >= 0; i--) {
            if(arr[i] <= x) {
                return i;        
            }
        }
        
        return -1;
        
        // TC: O(n)
        // SC: O(1)
    }

    int findFloorOpt(vector<int>& arr, int x) {
        // code here
        // optimal approach: using binary search
        
        int fl = -1;
        
        int low = 0;
        int high = arr.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] <= x) {
                // mid might be an answer
                fl = mid;
                // discard left half to find j > i st arr[j] <= x
                low = mid + 1;
            }
            else if(arr[mid] > x) {
                // discard right half
                high = mid - 1;
            }
            
        }
        
        return fl;

        /*
            TC: O(log n)
            SC: O(1)
        */
    }


};

int main() {
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 19;

    Solution s;

    int ans1 = s.findFloorBrute(arr, x);
    int ans2 = s.findFloorOpt(arr, x);
    
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}