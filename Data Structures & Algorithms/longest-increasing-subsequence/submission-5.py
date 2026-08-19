class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:

        def req(i,tf,dp):
            if i==len(nums):
                return 0
            ans = 0
            if dp[tf][i] != -1:
                return dp[tf][i]
            if tf==0:
                ans = max(req(i,1,dp)+1,req(i+1,tf,dp))
            else:
                for j in range(i+1,len(nums)):
                    if nums[j]>nums[i]:
                        ans = max(req(j,tf,dp)+1,ans)
            dp[tf][i] = ans
            return ans
        
        dp = [[-1]*len(nums) for i in range(2)]
        
        return req(0,0,dp)
        