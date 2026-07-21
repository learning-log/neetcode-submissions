/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
bool comp(Interval a, Interval b){
    if(a.start<b.start){
        return true;
    }
    return false;
}
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        sort(intervals.begin(),intervals.end(),comp);
        if(intervals.size()==0)
        return true;
        int prevEnd = intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<prevEnd){
                return false;
            }
            else{
                prevEnd = intervals[i].end;
            }
        }
        return true;
        
    }
};
