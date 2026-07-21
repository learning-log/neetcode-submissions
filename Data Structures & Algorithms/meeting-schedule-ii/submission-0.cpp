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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start;
        vector<int> end;
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());

        sort(end.begin(),end.end());

        int s = 0,e = 0;
        int ans =0;
        int temp = 0;
        while(s<intervals.size()){
            if(start[s]<end[e]){
                temp++;
                s++;
            }
            else{
                e++;
                temp--;

            }
            ans = max(ans,temp);
        }
        return ans;
    }
};
