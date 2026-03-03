/*
    A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

/*
    About the search space. We have to find out the correct capacity of the ship
    The range is from the max of the array till the sum of the array
*/

class Solution {
public:
int canShip(vector<int>& weights, int days, int capacity) {
    int daysRequired = 1;
    int sum = 0;

    for(int i = 0; i < weights.size(); i++) {
        if(sum + weights[i] <= capacity) {
            sum += weights[i];
        }
        else {
            daysRequired += 1;
            sum = weights[i];
        }
    }
    return daysRequired;
}

int shipWithinDaysBrute(vector<int>& weights, int days) {
    int maxEle = INT_MIN;
    for(auto e : weights) {
        if(e > maxEle) {
            maxEle = e;
        }
    }

    int weightSum = 0;
    for(auto e : weights) {
        weightSum += e;
    }

    // trying each weight from maxEle till weight sum
    for(int i = maxEle; i <= weightSum; i++) {
        if(canShip(weights, days, i) <= days) {
            return i;
        }
        continue;
    }

    return -1;
}

int shipWithinDaysOptimal(vector<int>& weights, int days) {
        // since the seaech space (range between max of the element and sum of all elements) is sorted we can apply binary search

        int maxEle = INT_MIN;
        int weightSum = 0;

        for(auto e : weights) {
            weightSum += e;
            if(e > maxEle) {
                maxEle = e;
            }
        }

        // applying binary search for the weight capacity
        int low = maxEle;
        int high = weightSum;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canShip(weights, days, mid) <= days) {
                // mid can be a potential answer
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    return ans;
}

};


int main() {
        vector<int> weights = {3,2,2,4,1,4};
        int days = 3;

        Solution s;
        int ansBrute1 = s.shipWithinDaysBrute(weights, days);
        int ansOpt1 = s.shipWithinDaysOptimal(weights, days); 
        cout<<ansBrute1<<endl<<ansOpt1<<endl;
    return 0;
}