 /*
     Note: This is a brute-force approach
    
     We try to find the minimum day required to make m bouquets.

     Process:
     1. First, find the smallest and largest bloom day in the array.(Range of the min and max for making a bouquet)
     2. Then, start checking from the smallest possible day.
     3. For each day:
        - Count how many flowers have bloomed on or before that day.
        - Check how many bouquets we can form using k consecutive bloomed flowers.
     4. If we can make at least m bouquets, return that day.
     5. Otherwise, increase the day and try again.
     6. If no day works, return -1.

    */


class Solution {
    public int minDays(int[] bloomDay, int m, int k) {

        int day = Integer.MAX_VALUE;
        int maxDay = Integer.MIN_VALUE;
        
        for(int i =0 ; i< bloomDay.length ; i++){

            day = Math.min(day,bloomDay[i]);
            maxDay = Math.max(maxDay,bloomDay[i]);

        }

        while(day<=maxDay){

        int count = 0 ;
        int TotalBouque = 0 ;
        for(int i = 0 ; i< bloomDay.length ; i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else {
                TotalBouque += count / k;
                count=0;
            }
        }
        // at the last count if not 0
        TotalBouque += count / k;
        if(TotalBouque >= m) return day ;
         day++;
        }
        return -1;
    }
}
