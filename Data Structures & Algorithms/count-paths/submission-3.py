class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        def req(i,j,dp):
            if i<0 or j<0:
                return 0
            if i==0 and j==0:
                return 1
            if dp[i][j]!=-1:
                return dp[i][j]
            dp[i][j] =req(i-1,j,dp)+req(i,j-1,dp)
            return dp[i][j]
        dp = [[-1]*n for i in range(m)]
        return req(m-1,n-1,dp)
        