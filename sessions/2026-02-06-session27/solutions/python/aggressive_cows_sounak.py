class Solution:
    def isFess(self ,mid, stalls, k):
        cow_pos = 0
        i = 1
        cow_cnt = 1
        
        # to check if k cows can be placed in the list we use greedy approach
        while i < len(stalls):
            xAI = stalls[i] - stalls[cow_pos]
            if xAI >= mid:
                cow_cnt += 1
                cow_pos = i
            i += 1
            
        
        if cow_cnt >= k:
            return True
        
        return False
        
        
        
    def aggressiveCows(self, stalls, k):
        # code here
        lenn = len(stalls)
        res = -1
        
        # we sort since the minimum distance between 2 cows will always be consecutive in a sorted array
        stalls.sort()
        
        # The range for the search 1 to (max(stalls) - min(stalls))
        l = 1
        r = stalls[lenn - 1] - stalls[0]
        
        while l <= r:
            mid = (l + r)//2
            
            if self.isFess(mid, stalls, k):
                res = mid
                l = mid + 1
            else:
                r = mid - 1
        
        return res
            
            
        