class Solution:
    def bs(self, l: int, r: int, target: int, nums: List[int]):

        while l <= r:
            mid = (l+r)//2

            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        
        return -1

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lenn = len(nums) - 1
        res = [-1,-1]

        firstF = self.bs(0, lenn, target, nums)

        if firstF == -1:
            return res

        leftP = self.bs(0, firstF-1, target, nums)
        while leftP >= 1 and nums[leftP-1] == nums[leftP]:
            leftP -= 1
        
        rightP = self.bs(firstF+1, lenn ,target, nums)
        while rightP < lenn and nums[rightP+1] == nums[rightP]:
            rightP += 1
        
        res[0] = firstF if leftP == -1 else leftP
        res[1] = firstF if rightP == -1 else rightP

        return res
