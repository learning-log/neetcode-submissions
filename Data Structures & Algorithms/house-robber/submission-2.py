class Solution:
    def rob(self, nums: List[int]) -> int:

        def req(i,dp):
            if i>=len(nums):
                return 0
            if dp[i]!=-1:
                return dp[i]
            dp[i] = max(req(i+2,dp),req(i+3,dp)) + nums[i]
            return dp[i]
        dp = [-1]*len(nums)
        return max(req(0,dp),req(1,dp))
        