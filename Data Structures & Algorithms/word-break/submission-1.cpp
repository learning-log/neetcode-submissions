class Solution {
public:
    bool req(string s,unordered_map<string,int>&mp,int pos,vector<int>&dp){
        if(pos == (s.length())){
            return true;
        }
        if(dp[pos]!=-1){
            return dp[pos];
        }
        string st = "";
        for(int i = pos;i<s.size();i++){
            st+=s[i];
            if(mp.find(st)!=mp.end() and req(s,mp,i+1,dp)){
                return dp[pos] = true;
            }
        }
        return dp[pos] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        vector<int> dp(s.size(),-1);
        for(auto t:wordDict){
            mp[t] = 1;
        }
        return req(s,mp,0,dp);
    }
};
