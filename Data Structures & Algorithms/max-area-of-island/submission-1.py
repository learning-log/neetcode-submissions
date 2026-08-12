class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        ans = 0

        def req(grid,i,j):
            if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j]==0:
                return 0

            grid[i][j]=0
            summ = 1

            summ = summ+req(grid,i+1,j) + req(grid,i-1,j) + req(grid,i,j+1) + req(grid,i,j-1)
            return summ
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                ans = max(ans,req(grid,i,j))
        
        return ans
            

        