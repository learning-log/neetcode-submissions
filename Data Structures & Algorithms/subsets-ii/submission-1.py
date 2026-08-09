class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        


        ans = []
        curr = []

        def req(i):
 
            

            if i == len(nums):
                ans.append(curr.copy())
                return
                return

            # Don't take nums[i]
            curr.append(nums[i])
            req(i+1)
            curr.pop()
            while i+1<len(nums) and nums[i+1]==nums[i]:
                i = i+1
            req(i + 1)
        nums.sort()
        i=0
        req(i)
        return ans
        