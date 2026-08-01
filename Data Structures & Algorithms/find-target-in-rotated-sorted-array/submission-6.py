class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start  = 0
        end = len(nums)-1

        while start<=end:
            mid = (end+start)//2
            print(mid)
            if target==nums[mid]:
                return mid

            elif nums[mid]>=nums[0]:
                if nums[mid]>target and nums[0]<=target:
                    end = mid-1
                else:
                    start = mid+1
            else:
                if nums[mid]<target and nums[0]>target:
                    start= mid+1
                else:
                    end = mid-1
        return -1

