#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

/*
    You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.
*/

class Solution {
  public:
    // brute force: using linear search
    bool isPossible(vector<int>& stalls, int dist, int cows) {
        int count = 1;
        int lastPos = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i];
            }
            
            if(count >= cows) {
                return true;
            }
        }
        return false;
    }
    
    int aggressiveCowsBrute(vector<int> &stalls, int cows) {
        // code here
        // using linear search on the answer
        // the search space ranges from 1 till max-min of array
        int minEle = INT_MAX;
        for(int i = 0; i < stalls.size(); i++) {
            if(stalls[i] < minEle) {
                minEle = stalls[i];
            }
        }
        
        int maxEle = INT_MIN;
        for(int i = 0; i < stalls.size(); i++) {
            if(stalls[i] > maxEle) {
                maxEle = stalls[i];
            }
        }
        
        int maxRange = maxEle - minEle;
        
        // we need to sort the array first to apply the linear search
        sort(stalls.begin(), stalls.end());
        
        int maxDist = 1;
        
        for(int dist = 1; dist <= maxRange; dist++) {
            if(isPossible(stalls, dist, cows)) {
                maxDist = max(maxDist, dist);
                continue;
            }
            else {
                return dist-1;
            }
        }
        
        return maxDist;

        // TC: O(maxRange*n) : maxRange is the maximum possible value of distance between 2 cows
        // n is the number of elements in the array
        // SC: O(1) 
    }

    // optimal solution: binary search
    int aggressiveCowsOpt(vector<int>& stalls, int cows) {
            // optimal approach: binary search
            // the search space between 1 till max-min is sorted => we can apply binary search

            int minEle = INT_MAX;
            int maxEle = INT_MIN;

            for(auto e : stalls) {
                if(e < minEle) {
                    minEle = e;
                }
            }

            for(auto e : stalls) {
                if(e > maxEle) {
                    maxEle = e;
                }
            }

            int maxRange = maxEle - minEle;

            int low = 1;
            int high = maxRange;
            int maxDist = 1;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(isPossible(stalls, mid, cows)) {
                    // mid is a possible answer
                    maxDist = max(maxDist, mid);
                    // search on the right for more possible answers
                    low = mid + 1;
                }
                else {
                    // if mid is not the answer => mid + 1, mid + 2,... also will not be the answers
                    // discard right half
                    high = mid - 1;
                }
            }
        return maxDist;

        // TC: (log(maxRange) * n)
        // SC: 1
    }
};

int main() {
        vector<int> stalls = {10, 1, 2, 7, 5};
        int cows = 3; // expected ans = 4

        Solution s;
        int ansBrute = s.aggressiveCowsBrute(stalls, cows);
        int ansOpt = s.aggressiveCowsOpt(stalls, cows);
        
        cout<<ansBrute<<endl<<ansOpt<<endl;

    return 0;
}