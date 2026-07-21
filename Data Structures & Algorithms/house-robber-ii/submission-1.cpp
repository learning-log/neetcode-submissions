class Solution {
public:
    int roby(vector<int>& nums, int st,int end) {
        
        int n = nums.size()-1;
        vector<int> dp(nums.size(),0);
        dp[st] = nums[st];
        if(n==1){
            return dp[st];
        }
        dp[st+1] = max(nums[st],nums[st+1]);
        for(int i=st+2;i<=end;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }

        return dp[end];
    }
    int rob(vector<int>& nums) {
        
        // roby(nums,1)
        if(nums.size()==1){
            return nums[0];
        }
        return max(roby(nums,0,nums.size()-2),roby(nums,1,nums.size()-1));
    }
};
