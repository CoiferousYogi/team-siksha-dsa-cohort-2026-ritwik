class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) 
    {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        subsets(0,nums,new ArrayList(),res);
        return res;
    }
    static void subsets(int index,int[] nums, List<Integer> subset, List<List<Integer>> res)
    {
        if(index >= nums.length)
        {
            //if(!res.contains(subset))
            res.add(new ArrayList(subset));
            return;
        }

        subset.add(nums[index]);
        subsets(index+1 , nums, subset, res);
        subset.remove((Integer)nums[index]);
        while(index<nums.length-1 && nums[index]==nums[index + 1])
        {
            index++;
        }
        subsets(index+1, nums, subset, res);
    }
}