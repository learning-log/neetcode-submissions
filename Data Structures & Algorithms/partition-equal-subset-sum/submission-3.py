class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum = 0
        for n in nums:
            sum+=n
        
        if sum%2==1:
            return False
        dp = [[-1]*(sum//2+1) for i in range(len(nums))]
        def req(i,target,dp):
            if target ==0:
                return True
            if target<0:
                return False
            if i==len(nums):
                return False
            if dp[i][target]!=-1:
                return dp[i][target]
            dp[i][target] = req(i+1,target,dp) or req(i+1,target-nums[i],dp)
            return dp[i][target]
        
        return req(0,sum//2,dp)