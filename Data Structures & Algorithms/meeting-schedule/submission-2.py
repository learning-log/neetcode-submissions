"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""
def compare(a:Interval, b:Interval):
    if a.start>b.end:
        True
    else:
        False
class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        intervals = sorted(intervals,key= lambda x:x.start)
        ans = True
        p = -1
        for i in intervals:
            if p==-1:
                p = i.end
            else:
                if p>i.start:
                    ans = False
                else:
                    p = i.end
        return ans


        