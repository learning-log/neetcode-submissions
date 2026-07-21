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
        
        req(nums,target,pos+1,curr,ans);
        curr.push_back(nums[pos]);
        req(nums,target-nums[pos],pos,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int pos = 0;
        req(nums,target,pos,curr,ans);
        return ans;
    }
};
