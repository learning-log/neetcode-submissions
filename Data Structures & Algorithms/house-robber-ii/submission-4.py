class Solution:
    def rob(self, nums: List[int]) -> int:
        
        def req(i,dp,n):
            if i>=n:
                return 0
            if dp[i]!=-1:
                return dp[i]
            
            dp[i] = max((req(i+2,dp,n) + nums[i]),req(i+1,dp,n)) 
            return dp[i]
        dp1 = [-1]*len(nums)
        dp2 = [-1]*len(nums)
        if len(nums)==1:
            return nums[0]
        a = req(0,dp1,len(nums)-1)
        b = req(1,dp2,len(nums))
        # print(a,b)
        return max(a,b)