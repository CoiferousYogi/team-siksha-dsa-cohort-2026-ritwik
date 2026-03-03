#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

/*
Problem Description
You have an array ribbons where each element ribbons[i] represents the length of a ribbon. You also have an integer k representing the number of ribbon pieces you need.

You can cut any ribbon into smaller pieces of positive integer lengths, or leave it uncut. For example, a ribbon of length 4 can be:

Kept as length 4
Cut into pieces of lengths 3 and 1
Cut into two pieces of length 2
Cut into pieces of lengths 2, 1, and 1
Cut into four pieces of length 1
Your goal is to find the maximum possible length x such that you can obtain at least k ribbon pieces, where each piece has the same length x. Any leftover ribbon material after cutting can be discarded.

If it's impossible to get k ribbons of the same length, return 0.

For example:

If ribbons = [9, 7, 5] and k = 3, you could cut each ribbon to get pieces of length 5: from the ribbon of length 9 you get one piece (with 4 discarded), from length 7 you get one piece (with 2 discarded), and from length 5 you get one piece. This gives you exactly 3 pieces of length 5, so the answer is 5.
If ribbons = [7, 5, 9] and k = 4, you could cut ribbons to get pieces of length 4: from length 7 you get one piece, from length 5 you get one piece, and from length 9 you get two pieces. This gives you 4 pieces of length 4, so the answer is 4.

The search space is between 1 and max(array). So we can solve this problem by using binary search as well as linear search
*/

class Solution {
    public:
    bool isCutPossible(vector<int>& ribbons, int k, int len) {
        int pieceCount = 0;

        for(int i = 0; i < ribbons.size(); i++) {
            pieceCount += (ribbons[i] / len);

            if(pieceCount >= k) {
                return true;
            }
        }

        return false;

    }

    int findRibbonsBrute(vector<int>& ribbons, int k) {
        // brute force: linear search
        // the search space is from 1 till max of the array

        int maxEle = INT_MIN;

        for(auto e : ribbons) {
            if(e > maxEle) {
                maxEle = e;
            }
        }

        int maxLen = 1;

        for(int len = 1; len <= maxEle; len++) {
            if(isCutPossible(ribbons, k, len)) {
                maxLen = max(maxLen, len);
                continue;
            }
            else {
                return len - 1;
            }
        }

        return maxLen;
    }

    int findRibbonsOpt(vector<int>& ribbons, int k) {
       int maxEle = INT_MIN;

        for(auto e : ribbons) {
            if(e > maxEle) {
                maxEle = e;
            }
        }

        int maxLen = 1;
        
        int low = 1;
        int high = maxLen;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isCutPossible(ribbons, k, mid)) {
                maxLen = max(maxLen, mid);

                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return maxLen;
    }
};




int main() {
    return 0;
}
