class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        // vector<vector<int>> ans;
        int ans = 0;
        int prevEnd =  intervals[0][1];
        vector<int> interval = intervals[0];
        for(int i=1;i<intervals.size();i++){
        
            if(prevEnd<=intervals[i][0]){
                // ans.push_back(interval);
                prevEnd = intervals[i][1];
            }
            else{
                // interval[1] = max(intervals[i][1],interval[1]);
                ans++;
                prevEnd = min(prevEnd,intervals[i][1]);
            }
        }

        // ans.push_back(interval);
        return ans;
    }
};
