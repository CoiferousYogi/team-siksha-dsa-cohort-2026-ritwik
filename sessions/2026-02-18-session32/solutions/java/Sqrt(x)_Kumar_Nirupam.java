class Solution {
    public int mySqrt(int x) {

         if (x < 2) return x;

        int low = 0 ; 
        int high = x;

        int res =0;
        while(low<=high){
            int mid = low + ((high -low)/2);

            if( mid <= x / mid){  // integer overflow - (mid * mid) <= x 
                res = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return res;
    }
}