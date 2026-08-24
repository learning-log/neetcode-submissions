class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        out = []
        idx = -1
        i=0

        while i <len(intervals):
            if intervals[i][1]<newInterval[0]:
                out.append(intervals[i])
                
            else:
                idx = i
                break
            i+=1
            
        while i<len(intervals) and newInterval[1]>=intervals[i][0]:
            newInterval[0] = min(newInterval[0],intervals[i][0])
            newInterval[1] = max(newInterval[1],intervals[i][1])
            i+=1
        out.append(newInterval)

        while i<len(intervals):
            out.append(intervals[i])
            i+=1

        return out




        


        

