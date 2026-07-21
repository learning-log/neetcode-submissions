class Solution {
public:
    int convInt(string s,int st){
          if(s[st]=='0'){
            return 0;
        }

        int ans = 0;
        ans = (s[st]-'0')*10 + (s[st+1]-'0');

        return ans; 
    }
    int convInt1(string s,int st){
        if(s[st]=='0'){
            return 0;
        }
        return s[st]-'0';
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,0);
        dp[0] = 1;
        if(s[0]=='0'){
            dp[1] =0;
            return 0;
        }
        else
            dp[1] = 1;
        for(int i=2;i<=s.size();i++){
            int with2  = convInt(s,i-2);
            if(with2>0 and with2<=26){
                dp[i] += dp[i-2];
            }
            int with1 = convInt1(s,i-1);
            if(with1>0){
                dp[i]+=dp[i-1];
            }
            if(dp[i]==0){
                return 0;
            }
        }

        return dp[s.length()];
    }
};
