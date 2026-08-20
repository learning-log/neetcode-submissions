class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        
        vis = [[0]*len(matrix[0]) for i in range(len(matrix))]
        def req(i,j,dp):
            if i<0 or j<0 or i>=len(matrix) or j>=len(matrix[0]):
                return 0
            
            ans = 1
            if dp[i][j]!=-1:
                return dp[i][j]
            vis[i][j] = 1

            if i+1>=0 and i+1<len(matrix) and vis[i+1][j]==0 and matrix[i+1][j]>matrix[i][j]:
                ans = max(req(i+1,j,dp)+1,ans)

            if i-1>=0 and i-1<len(matrix) and vis[i-1][j]==0 and matrix[i-1][j]>matrix[i][j]:
                ans = max(req(i-1,j,dp)+1,ans)
            
            if j+1>=0 and j+1<len(matrix[0]) and vis[i][j+1]==0 and matrix[i][j+1]>matrix[i][j]:
                ans = max(req(i,j+1,dp)+1,ans)
            
            if j-1>=0 and j-1<len(matrix[0]) and vis[i][j-1]==0 and matrix[i][j-1]>matrix[i][j]:
                ans = max(req(i,j-1,dp)+1,ans)
            vis[i][j] = 0
            dp[i][j] = ans
            return ans 

        mans = 0
        dp = [[-1]*len(matrix[0]) for i in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                mans = max(mans,req(i,j,dp))

        return mans            
