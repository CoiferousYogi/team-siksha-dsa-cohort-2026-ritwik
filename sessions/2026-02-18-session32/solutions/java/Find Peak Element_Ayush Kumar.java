class Solution {
    public int findPeakElement(int[] nums) 
    {
        int low =1,high = nums.length-2,mid;
        mid = (high + low) /2;

        if(nums.length ==1)
        return mid;
        else if(nums[0] > nums[1])
        return 0;
        else if(nums[nums.length-1] > nums[nums.length-2])
        return nums.length-1;
        
        while(low<=high)
        {
            mid = (high + low) /2;
            if((nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]))
            return mid;

            if(nums[mid-1] < nums[mid])
            {
                low = mid +1;
            }
            else
            {
                high = mid -1;
            }
        } 
        return mid;
    }
}