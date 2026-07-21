class Solution {
public:
    void swap(int &a, int &b){
        int c = a;
        a = b;
        b = c;
        return;
    }
    void req(vector<int> &nums,int pos, vector<vector<int>> &ans){
        if(pos == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = pos;i<nums.size();i++){
            swap(nums[i],nums[pos]);
            req(nums,pos+1,ans);
            swap(nums[i],nums[pos]);
        }

        return;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int pos = 0;
        vector<vector<int>> ans;
        req(nums,pos, ans);
        return ans;
    }
};
