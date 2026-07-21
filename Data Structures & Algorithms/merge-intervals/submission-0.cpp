class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        vector<int> interval = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(interval[1]<intervals[i][0]){
                ans.push_back(interval);
                interval = intervals[i];
            }
            else{
                interval[1] = max(intervals[i][1],interval[1]);
            }
        }

        ans.push_back(interval);
        return ans;
    }
};
