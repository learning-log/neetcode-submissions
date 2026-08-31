class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        prev = -1
        pe = 0
        ans = 0
        intervals = sorted(intervals)
        print(intervals)
        for i in intervals:
            if prev==-1:
                pe = i[1]
                prev =0
            else:
                if pe>i[0]:
                    pe = min(pe,i[1])
                    ans +=1
                else:
                    pe = i[1]
        return ans