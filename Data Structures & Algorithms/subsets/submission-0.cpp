class Solution {
public:
    void req(vector<int> &nums,int pos,vector<vector<int>>&ans,vector<int>curr){
        if(pos==nums.size()){
            ans.push_back(curr);
            return;
        }

        req(nums,pos+1,ans,curr);
        curr.push_back(nums[pos]);
        req(nums,pos+1,ans, curr);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        int pos = 0;
        req(nums,pos,ans,curr);
        return ans;
    }
};
