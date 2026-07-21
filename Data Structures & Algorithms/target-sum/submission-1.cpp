class Solution {
public:
    int req(int amount, int pos,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0 and pos == coins.size()){
            return 1;
        }

        if(pos==coins.size()){
            return 0;
        }
        if(dp[amount+20000][pos]!=-1){
            return dp[amount+20000][pos];
        }
        return dp[amount+20000][pos]=req(amount-coins[pos],pos+1,coins,dp)+req(amount+coins[pos],pos+1,coins,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(40000,vector<int>(nums.size(),-1));
        // dp[0][0] = 0;
        return req(target,0,nums,dp);
    }
};
