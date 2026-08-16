class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:

        dist = [10000]*(n+1)

        dist[k] = 0

        for i in range(n-1):
            for e in times:
                if dist[e[0]]!=10000 and dist[e[1]]>(dist[e[0]]+ e[2]):
                    dist[e[1]] =  dist[e[0]]+ e[2]
        
        ans = 0
        for i in range(1,n+1):
            ans = max(ans,dist[i])
        return -1 if ans==10000 else ans

        