class Solution:
    def dfs(self,graph,vis,s):
        if vis[s]==1:
            return
        vis[s] = 1
        for n in graph[s]:
            self.dfs(graph,vis,n)
        return

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges)>(n-1):
            return False
        connections = 0
        graph = [[] for i in range(n) ]
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
        vis = [0]*n
        for i in range(n):
            if vis[i]==0:
                self.dfs(graph,vis,i)
                connections+=1
        return True if connections==1 else False