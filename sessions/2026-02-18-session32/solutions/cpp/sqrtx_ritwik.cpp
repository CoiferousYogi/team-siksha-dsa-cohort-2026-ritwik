#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;


class Solution {
public:
    // brute force solution using linear search
    int mySqrtBrute(int x) {
        // for this question, the search space is the set Z+
        // brute force approach: using linear search
        // we will start from 2 and search till the integer x/2
        // for all x >= 4, sqrt(x) <= x/2
        // as per the problem description, we need to return the floor

        // edge case
        if(x == 0 || x == 1) {
            return x;
        }
        
        int start = 1;
        int end = (x / 2) + 1;
        double res = 1;
        
        for(int i = 1; i < end; i++) {
            if(res * res <= x) {
                res++;
            }
        }

        return (int)res-1;

        // TC: O(n): since linear search checks each element sequentially, a search space having n elements will take n computations
        // WILL GIVE TLE for large input size
        // SC: O(1): no extra space used.
    }

    // optimized solution using binary search
    int mySqrtOpt(int x) {
        /*
            The search space is Z+ 
            It is sorted => binary search is possible
        */
        
        // edge cases
        if(x == 0 || x == 1) {
            return x;
        }

        int ans;
        int low = 1;
        int high = (x / 2) + 1; 

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            // long long prevents int overflow

            if(mid * mid < x) {
                // mid < sqrt(x)
                // mid might be a probable ans
                ans = mid;
                low = mid + 1;
            }
            else if(mid * mid > x) {
                // mid > sqrt(x)
                high = mid -1;
            }
            else {
                // mid * mid == x
                return mid;
            }
        }

        return ans;

        /*
            TC: O(log2 (n)): Binary search halves the search space in every iteration 
            SC: O(1): No extra space used 
        */
    }
};

int main() {
        Solution s;
        int ans1 = s.mySqrtBrute(2147483647); // expected 46340
        int ans2 = s.mySqrtOpt(2147483647);

        cout<<ans1<<endl;
        cout<<ans2<<endl;
    return 0;
}