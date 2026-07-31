from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        start = 0
        end = 0
        dq = deque()
        while end<k:
            while len(dq)>0 and dq[-1]<nums[end]:
                dq.pop()
            dq.append(nums[end])
            end+=1
        ans.append(dq[0])

        while end<len(nums):
            if nums[start] == dq[0]:
                dq.popleft()
            while len(dq)>0 and dq[-1]<nums[end]:
                dq.pop()
            dq.append(nums[end])
            ans.append(dq[0])
            end+=1
            start+=1

        return ans
