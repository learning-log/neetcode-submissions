class Solution {
public:
    int req(string s1,string s2,int a, int b,vector<vector<int>> &dp){
        if(a==s1.length() or b == s2.length()){
            return 0;
        }

        if(dp[a][b]!=-1){
            return dp[a][b];
        }

        if(s1[a]==s2[b]){
            return dp[a][b]=req(s1,s2,a+1,b+1,dp)+1;
        }
        else
            return dp[a][b] = max(req(s1,s2,a,b+1,dp),req(s1,s2,a+1,b,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return req(text1,text2,0,0,dp);
    }
};
