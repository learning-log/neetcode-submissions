from collections import deque
import heapq
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand)%groupSize != 0:
            return False
        
        dictt = {}
        q = []
        for n in hand:
            v = dictt.get(n,0)
            dictt[n] = v+1
        for k in dictt.keys():
            heapq.heappush(q,k)
        ans = []
        curr = 0
        qu = deque()
        prev = -1
        while len(q)!=0: 
            v = heapq.heappop(q)
            dictt[v] -=1
            
            if dictt[v]>0:
                qu.append([v,curr])
            if curr%groupSize==0:
                prev = v
                ans.append(v)
            else:
                if v - prev==1:
                    prev = v
                    ans.append(v)
                else:
                    print(ans)
                    return False
            curr +=1
            while len(qu)>0 and curr%groupSize==0:
                l = qu.popleft()
                heapq.heappush(q,l[0])

        return True if len(ans)==len(hand) else False

        



        
