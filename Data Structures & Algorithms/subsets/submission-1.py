class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        def req(nums,i,curr):
            nonlocal ans
            if len(nums) == i:
                ans.append(curr.copy())
                return
            req(nums,i+1,curr)
            curr.append(nums[i])
            req(nums,i+1,curr)
            curr.pop()
            return

        ans = []
        curr = []
        req(nums,0,curr)
        return ans

        