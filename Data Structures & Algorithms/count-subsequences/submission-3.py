class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        def req(i,j,dp):
            if j==len(t):
                return 1

            if i==len(s):
                return 0
            
            if dp[i][j]!=-1:
                return dp[i][j]
            if s[i] == t[j]:
                dp[i][j] = req(i+1,j+1,dp)+req(i+1,j,dp) 
            else:
                dp[i][j] = req(i+1,j,dp)
            return dp[i][j]
        if len(s)<len(t):
            return 0
        dp = [[-1]*len(t) for i in range(len(s))]
        return req(0,0,dp)
            
        