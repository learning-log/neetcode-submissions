class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,99999);

        dp[0] = 0;

        for(int i = 1;i<=amount;i++){
            for(auto t: coins){
                if(i>=t)
                    dp[i] = min(dp[i],dp[i-t]+1);
            }
        }
        return dp[amount]==99999?-1:dp[amount];
    }
};
