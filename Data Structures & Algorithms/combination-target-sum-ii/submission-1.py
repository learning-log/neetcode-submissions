class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:

        ans = []
        curr = []

        def req(i, target):
            if target == 0:
                ans.append(curr.copy())
                return

            if target < 0 or i == len(nums):
                return

            # Don't take nums[i]
            curr.append(nums[i])
            req(i+1, target - nums[i])
            curr.pop()
            while i+1<len(nums) and nums[i+1]==nums[i]:
                i = i+1
            req(i + 1, target)

            # Take nums[i]
            
        nums.sort()
        req(0, target)

        return ans
        
        