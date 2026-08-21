class Solution:
    def maxCoins(self, nums: List[int]) -> int:

        dictt = {}
        for i in range(len(nums)):
            dictt[i] = [nums[i],i]

        

        def req(start,end,dp):
            if start>end:
                return 0
            
            ans = 0
            if dp[start][end]!=-1:
                return dp[start][end]
            for i in range(start,end+1):
                if start-1>=0:
                    l = nums[start-1]
                else:
                    l = 1
                r = 1 if end+1>=len(nums) else nums[end+1]
                ans = max(req(start,i-1,dp)+req(i+1,end,dp)+l*r*nums[i],ans)
            dp[start][end] = ans
            return ans

        dp = [[-1]*len(nums) for i in range(len(nums))]
        
        return req(0,len(nums)-1,dp)
        