class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        vis = [0] * n
        graph = [[] for i in range(n)]

        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
        
        

        def dfs(graph,s):
            if vis[s]:
                return
            vis[s] = 1

            for n in graph[s]:
                dfs(graph,n)

            return
        ans = 0
        for i in range(n):
            if vis[i]==0:
                ans+=1
                dfs(graph,i)
        return ans
        