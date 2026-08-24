class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        out = []

        i = 0
        preEnd = -1
        preId = -1
        pre = [-1,-1]
        intervals = sorted(intervals)
        # print(intervals)
        while i<len(intervals):
            if preId == -1:
                pre = intervals[i]
                preId = i

            if intervals[i][0]>pre[1]:
                out.append(pre)
                pre = intervals[i]
                preId = i
            else:
                pre[0] = min(pre[0],intervals[i][0])
                pre[1] = max(pre[1],intervals[i][1])
            i+=1
        # print(pre)
        out.append(pre)
        # print(out)
        return out                
