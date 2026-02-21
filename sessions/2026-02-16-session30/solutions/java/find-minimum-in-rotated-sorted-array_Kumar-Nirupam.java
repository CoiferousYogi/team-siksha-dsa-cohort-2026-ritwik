/*
 This solution uses Binary Search to find the minimum element 
 in a rotated sorted array.

 Key Idea:
 - In a rotated sorted array, at least one half (left or right)
   is always sorted.
 - The minimum element always lies in the unsorted half.
 - At each step, we:
     1. Calculate mid.
     2. Update the minimum value if nums[mid] is smaller.
     3. Check whether the right half is sorted.
        - If right half is sorted, move to the left half.
        - Otherwise, move to the right half.
 - Continue this process until the search space is exhausted.

 Time Complexity: O(log n)
 Space Complexity: O(1)
*/

class Solution {
    public int findMin(int[] nums) {
        int low = 0 ;
        int high = nums.length-1;
        int min = Integer.MAX_VALUE;

        while(low<=high){
            int mid = low+((high-low)/2);

            if(nums[mid]<= min){
                min = nums[mid];
            }

            // right part sorted check - move to unsorted
            if(nums[mid]<=nums[high]){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return min;
    }
}