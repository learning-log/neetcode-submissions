class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        curr = []

        def req(i, target):
            if target == 0:
                ans.append(curr.copy())
                return

            if target < 0 or i == len(nums):
                return

            # Don't take nums[i]
            req(i + 1, target)

            # Take nums[i]
            curr.append(nums[i])
            req(i, target - nums[i])
            curr.pop()

        req(0, target)
        return ans