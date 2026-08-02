class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        ans = -1
        i = 0
        for i in range(len(nums)):
            if nums[i]>=0:
                if nums[nums[i]]<0:
                    return nums[i]
                else:
                    nums[nums[i]] = -nums[nums[i]]
            else:
                pos = -nums[i]
                if nums[pos]<0:
                    return pos
                else:
                    nums[pos] = -nums[pos]
        