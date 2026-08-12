from collections import deque
class Solution:
    def fill(self,i,j,inf,grid,v):
        if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j]!=inf:
            return False
        grid[i][j] = v
        return True
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        inf = 2147483647

        q = deque()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    q.append([i,j,0])
        

        while len(q)>0:
            node = q.popleft()
            i,j,v = node
            if self.fill(i+1,j,inf,grid,v+1):
                q.append([i+1,j,v+1])

            if self.fill(i-1,j,inf,grid,v+1):
                q.append([i-1,j,v+1])
            if self.fill(i,j-1,inf,grid,v+1):
                q.append([i,j-1,v+1])
            if self.fill(i,j+1,inf,grid,v+1):
                q.append([i,j+1,v+1])
        
            