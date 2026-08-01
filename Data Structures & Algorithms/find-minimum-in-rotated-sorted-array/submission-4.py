class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        start = 0
        end = len(nums)-1
        ans = 0
        
        while start<=end:
            mid = (end+start)//2
            if nums[0]>nums[mid]:
                end = mid-1
                ans = mid
            else:
                if nums[0]>nums[end]:
                    start = mid+1
                else:
                    end = mid-1

            print(start,end)
            
        return nums[ans]
