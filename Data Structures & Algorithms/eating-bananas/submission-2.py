from math import ceil

class Solution:
    def satisfied(self, tgt, piles,h):
        used_hours = 0
        for p in piles:
            used_hours += ceil(p/tgt)
        
        return used_hours<=h
            

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        mi = 1
        ma = 0
        for p in piles:
            ma = max(ma,p)
        
        ans = ma
        while mi<=ma:
            mid = int((mi+ma)/2)
            print(mid)
            if self.satisfied(mid,piles,h):
                ans = min(mid,ans)
                ma = mid-1
                print("y")
            else:
                mi = mid+1

        return int(ans)
