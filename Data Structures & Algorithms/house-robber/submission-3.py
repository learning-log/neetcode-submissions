class Solution:
    def rob(self, nums: List[int]) -> int:

        def req(i,dp):
            if i>=len(nums):
                return 0
            if dp[i]!=-1:
                return dp[i]
            dp[i] = max(req(i+2,dp)+ nums[i],req(i+1,dp)) 
            return dp[i]
        dp = [-1]*len(nums)
        return req(0,dp)
        