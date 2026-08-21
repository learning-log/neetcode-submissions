class Solution:
    def jump(self, nums: List[int]) -> int:

        rangee = 0
        dr = 0
        ans = 0
        for i in range(len(nums)):
            n = nums[i]
            rangee = max(rangee,n)
            if dr == 0 and i<(len(nums)-1):
                dr = rangee
                ans +=1
            rangee-=1
            dr -= 1
        return ans