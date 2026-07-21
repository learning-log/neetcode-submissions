from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

        start = 0
        end =  0
        dq = deque()
        while end<k and end<len(nums):
            while len(dq)!=0 and nums[dq[len(dq)-1]]< nums[end]:
                dq.pop()
            dq.append(end)
            print(dq)
            end +=1
        print(dq)
        ans = [nums[dq[0]]]
        start+=1
        while end< len(nums):
            if start > dq[0]:
                dq.popleft()
            while len(dq)!=0 and nums[dq[len(dq)-1]]< nums[end]:
                dq.pop()
            dq.append(end)
            end+=1
            start += 1
            ans.append(nums[dq[0]])

        return ans