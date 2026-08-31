"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        dictt = {}

        # intervals = sorted(intervals,key=lambda x:x.start)
        listt = []
        for i in intervals:
            val = dictt.get(i.start,0)
            dictt[i.start] = val+1
            
            val = dictt.get(i.end,0)
            dictt[i.end] = val-1
        ans = 0
        for k,v in dictt.items():
            listt.append([k,v])
        listt = sorted(listt)
        
        tempp = 0
        for l in listt:
            tempp += l[1]
            ans = max(ans,tempp)
        
        return ans

            

             

