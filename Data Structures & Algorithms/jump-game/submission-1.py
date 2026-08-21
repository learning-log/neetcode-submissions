class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        rangee = 0
        for i in range(len(nums)):
            n = nums[i]
            rangee = max(rangee,n)
            if rangee ==0 and i<(len(nums)-1):
                return False
            rangee-=1
        return True