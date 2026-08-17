class Solution:
    def climbStairs(self, n: int) -> int:
        def req(n,dp):
            if n==0:
                return 1
            if dp[n]!=-1:
                return dp[n]
            if n>1:
                dp[n] = req(n-1,dp)+req(n-2,dp)
                return dp[n]
            else:
                dp[n] = req(n-1,dp)
                return dp[n]
        dp = [-1]*(n+1)

        return req(n,dp)
    