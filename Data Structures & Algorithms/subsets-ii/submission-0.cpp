class Solution {
public:
    void req(vector<int> &nums, int pos, vector<int> curr,vector<vector<int>> &ans){

        if(pos==nums.size()){
            ans.push_back(curr);
            return;
        }
        
        
        curr.push_back(nums[pos]);
        req(nums,pos+1,curr,ans);
        curr.pop_back();
        pos = pos+1;
        while(pos<nums.size() and nums[pos]==nums[pos-1]){
            pos++;
        }
        req(nums,pos,curr,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        int pos = 0;
        req(nums,pos,curr,ans);
        return ans;
    }
};
