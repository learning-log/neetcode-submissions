class Solution {
public:
    int req(int amount, int pos,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }

        if(pos==coins.size() or amount<0){
            return 0;
        }
        if(dp[amount][pos]!=-1){
            return dp[amount][pos];
        }
        return dp[amount][pos]=req(amount-coins[pos],pos,coins,dp)+req(amount,pos+1,coins,dp);
    }
    int change(int amount, vector<int>& coins) {
        // dp[amount+1][coins.size()] ={0};
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        // dp[0][0] = 0;
        return req(amount,0,coins,dp);
    }
};
