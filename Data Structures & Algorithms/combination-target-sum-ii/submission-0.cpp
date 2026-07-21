class Solution {
public:
    void req(vector<int> &nums, int target, int pos, vector<int> curr,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0 or pos==nums.size()){
            return;
        }
        
        
        curr.push_back(nums[pos]);
        req(nums,target-nums[pos],pos+1,curr,ans);
        curr.pop_back();
        pos = pos+1;
        while(pos<nums.size() and nums[pos]==nums[pos-1]){
            pos++;
        }
        req(nums,target,pos,curr,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        int pos = 0;
        req(candidates,target,pos,curr,ans);
        return ans;
    }
};
