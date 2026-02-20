class Solution {
    public int mySqrt(int x) 
    {
        long low = 1,high = x/2,mid;
        mid = (low+high) / 2;
        if(x==0 || x==1)
        return x;
        while(low<=high)
        {
            mid = (low + high) / 2;
            
            if(mid*mid == x)
            return (int)mid;

            if(( (mid-1)*(mid-1) < x) && ( (mid+1)*(mid+1) >x ) && mid*mid < x)
            return (int)mid;

            if(mid*mid > x)
            {
                high = mid-1;
            }
            else
            low = mid+1;
        }
        return (int)Math.floor(mid);
    }
}