class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        dictt = {}
        for n in nums:
            dictt[n] = 1
        ans = 0
        for n in nums:
            if (n-1) not in dictt.keys():
                tans = 1
                newn = n+1
                while newn in dictt.keys():
                    tans+=1
                    newn+=1
                ans = max(ans,tans)
        return ans