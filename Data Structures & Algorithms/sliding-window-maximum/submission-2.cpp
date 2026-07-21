class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> series;
        for (int i=0;i<k;i++){
            if(series.empty()){
                series.push_back(make_pair(nums[i],i));
            }
            else{
                while(!series.empty() and series.back().first<nums[i]){
                    series.pop_back();
                }
                series.push_back(make_pair(nums[i],i));
            }
        }
        vector<int> ans;
        ans.push_back(series.front().first);
        int indx = k;
        while(indx<nums.size()){
            int removeIdx = indx-k;
            // cout
            if(series.front().second<=removeIdx){
                series.pop_front();
            }
            while(!series.empty() and (series.back().first<nums[indx])){
                    series.pop_back();
                }
            series.push_back(make_pair(nums[indx],indx));
            ans.push_back(series.front().first);
            indx++;
        }
        return ans;

    }
};
