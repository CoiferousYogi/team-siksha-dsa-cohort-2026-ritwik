class Solution:
    def createBq(self,day: int, bd: list[int], m: int, k: int) -> bool:
        cnt = 0
        bq = 0

        for i in range(len(bd)):
            if bd[i] > day:
                cnt = 0
                continue

            if bd[i] <= day:
                cnt += 1

            if cnt == k:
                bq += 1
                cnt = 0
        
        return bq



    def minDays(self, bloomDay: list[int], m: int, k: int) -> int:
        l = min(bloomDay)
        r = max(bloomDay)
        res = -1

        while l <= r:
            mid = (l+r)//2
            possible_bq = self.createBq(mid, bloomDay, m, k)

            if possible_bq >= m:
                res = mid
                r = mid - 1
            else:
                l = mid + 1
        
        return res

            