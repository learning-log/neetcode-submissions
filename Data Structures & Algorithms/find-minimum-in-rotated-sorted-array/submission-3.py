class Solution:
    def findMin(self, nums: List[int]) -> int:
        ans = 10000

        start = 0
        end = len(nums)-1
        while start <= end:
            mid = int((start + end)/2)

            if nums[mid]>nums[-1]:
                start = mid+1
            else:
                end = mid-1
            ans = min(ans,nums[mid])

        return ans