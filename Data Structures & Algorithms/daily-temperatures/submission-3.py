from collections import deque
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        S = deque()
        ans = [0]*len(temperatures)
        for  i in range(len(temperatures)-1,-1,-1):
            while len(S)!=0 and temperatures[S[-1]]<=temperatures[i]:
                S.pop()
            ans[i]=(0 if len(S)==0 else (S[-1] - i))
            S.append(i)

        

        return ans