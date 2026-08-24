class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals)
        ans = 0
        pre = [-1,-1]
        preId = -1
        for i in intervals:
            if preId == -1:
                pre = i
                preId = 0
            elif pre[1]<=i[0]:
                pre = i

            else:
                pre[1] = min(pre[1],i[1])
                ans+=1
        return ans


        
       
