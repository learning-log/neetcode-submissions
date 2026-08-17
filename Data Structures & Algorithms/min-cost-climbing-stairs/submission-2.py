class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        
        def req(i,n,dp):

            if i>=n:
                return 0
            if dp[i]!=-1:
                return dp[i]
            dp[i] = min(req(i+1,n,dp),req(i+2,n,dp)) + cost[i]
            return dp[i]
        dp = [-1]*len(cost)
        return min(req(0,len(cost),dp),req(1,len(cost),dp))