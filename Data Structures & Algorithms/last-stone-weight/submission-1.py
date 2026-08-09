import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        q = []
        if len(stones)==0:
            return 0
        for i in stones:
            heapq.heappush(q,-i)
        
        while len(q)>1:
            x = -heapq.heappop(q)
            y  = -heapq.heappop(q)

            if x>y:
                heapq.heappush(q,-(x-y))
            elif y>x:
                heapq.heappush(q,(x-y))
        
        if len(q)==1:
            return -q[0]
        return 0
