class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        def req(nums,target,i,curr):
            if target==0:
                ans.append(curr.copy())
                return
            if target<0 or i==len(nums):
                return
            req(nums,target,i+1,curr)
            curr.append(nums[i])
            req(nums,target-nums[i],i,curr)
            curr.pop()
        ans = []
        curr = []
        i = 0
        req(nums,target,i,curr)
        return ans