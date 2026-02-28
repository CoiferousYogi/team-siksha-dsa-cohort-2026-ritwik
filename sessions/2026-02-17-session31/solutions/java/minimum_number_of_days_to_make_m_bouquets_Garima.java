/*
Problem Link : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 */

class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int low = Integer.MAX_VALUE, high = Integer.MIN_VALUE, res = -1, mid = 0;

        // N iterations to find min and max day in array
        for(int day : bloomDay) {
            low = Math.min(low, day);
            high = Math.max(high, day);
        }

        while(low <= high) {
            mid = (low + high) / 2;
            if(isPossible(mid, bloomDay, m, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }

    private boolean isPossible(int day, int[] bloomDay, int m, int k) {
        int count = 0, bouquets = 0, i = 0;
        while(i < bloomDay.length) {
            if(bloomDay[i] <= day) {
                count++;
                if(count == k) {
                    count = 0;
                    bouquets++;
                }
            } else {
                count = 0;
            }
            i++;
        }
        if(bouquets >= m)
            return true;
        return false;
    }
}

/*
Time Complexity : N*log(max - min)
Space Complexity : constant
 */