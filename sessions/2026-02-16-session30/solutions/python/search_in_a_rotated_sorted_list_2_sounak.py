class Solution:
    def search(self, nums: list[int], target: int) -> bool:
        l = 0
        r = len(nums) - 1 

        # check for duplicates, we are incrementing l as its a right rotated list
        while l != r and nums[l] == nums[r]:
            l += 1

        while l <= r:
            mid = (l+r)//2

            if nums[mid] == target:
                return True
            # check if list [l,mid] is sorted
            elif nums[l] <= nums[mid]:
                # check if target lies in the list
                if nums[l] <= target and target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            # check if list [mid, r] is sorted
            elif nums[mid] <= nums[r]:
                # check if target lies in the list
                if nums[mid] < target and target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            
        
        return False