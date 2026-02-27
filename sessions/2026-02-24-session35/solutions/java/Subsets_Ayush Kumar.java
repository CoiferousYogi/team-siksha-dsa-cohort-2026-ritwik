class Solution {
    public List<List<Integer>> subsets(int[] nums) 
    {
        List<List<Integer>> result = new ArrayList<>();
        //int n = nums.length;
        //result.add(new ArrayList());
        sets(nums, 0, new ArrayList(), result);

        return result;
    }

    static void sets(int[] nums, int index,List<Integer> subsets ,List<List<Integer>> result)
    {
        //List<Integer> subsets = new ArrayList<>();
        if(index>=nums.length)
        {
            result.add(new ArrayList<>(subsets));
            return;
        }

        subsets.add(nums[index]);
        sets(nums, index+1 ,subsets, result);
        
        subsets.remove((Integer)nums[index]);
        //subsets.remove(Integer.valueOf(nums[index]));
        sets(nums, index+1 ,subsets ,result);
    }
}