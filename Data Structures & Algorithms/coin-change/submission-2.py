class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        inf = 100000
        def req(i,target,dp):
            
            if i==len(coins):
                return inf
            
            if target <0:
                return inf
            
            if target==0:
                # print(i)
                return 0
            if dp[i][target]!=-1:
                return dp[i][target]
            if coins[i]<=target:
                dp[i][target] = min(req(i,target-coins[i],dp)+1,req(i+1,target,dp))
                return dp[i][target]
            else:
                dp[i][target] =  req(i+1,target,dp)
                return dp[i][target]

        dp = [[-1]*(amount+1) for i in range(len(coins))]

        ans =  req(0,amount,dp)
        
        return ans if ans!=inf else -1
