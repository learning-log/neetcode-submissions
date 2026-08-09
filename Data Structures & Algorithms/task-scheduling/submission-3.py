import heapq
from collections import deque
class Solution:
    # def increase_cooldown(self,cooldown,q,dictt):
    #     pop_l = []
    #     for k,v in cooldown.items():
    #         if v <=1:
    #             heapq.heappush(q,(-dictt[k],k))
    #             pop_l.append(k)
    #         else:
    #             cooldown[k] = v-1
    #     for k in pop_l:
    #         cooldown.pop(k)
            
    def leastInterval(self, tasks: List[str], n: int) -> int:
        q = []
        cycle=0
        dictt = {}
        for t in tasks:
            fr = dictt.get(t,0)
            fr = fr+1
            dictt[t] = fr
        
        for k,v in dictt.items():
            heapq.heappush(q,(-v,k))
        
        done = len(dictt)
        ans = 0
        # cooldown={}
        coolqueue = deque()
        while len(q)>0 or len(coolqueue)>0:

            while len(coolqueue)!=0 and (coolqueue[0][2]<cycle):
                heapq.heappush(q,(-coolqueue[0][0],coolqueue[0][1]))
                coolqueue.popleft()
            
            if len(q)!=0:
                top = heapq.heappop(q)
                if (-top[0])>1:
                    coolqueue.append([(-top[0]-1),top[1],cycle+n])
                # else:

            cycle+=1
  
        return cycle
                    





        