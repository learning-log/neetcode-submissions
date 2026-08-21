class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        ans = nums[0]
        currs = 0
        for n in nums:
            currs = currs+n
            ans = max(ans,currs)
            if currs<0:
                currs = 0
        return ans


        