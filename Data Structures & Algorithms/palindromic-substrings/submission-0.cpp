class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int start = 0;
        int endt = 0;
        for(int i=0;i<s.length();i++){
            int l1 = 1;
            ans+=1;
            int st = i-1, end = i+1;
            while(st>=0 and end<s.length()){
                if(s[st]==s[end]){
                    l1+=2;
                    ans++;
                }
                else{
                    break;
                }
                st--;
                end++;
            }
            // if(l1>ans){
            //     ans = l1;
            //     start = st+1;
            //     endt = end-1;
            // }
            int l2 = 0;
            st = i;
            end = i+1;

             while(st>=0 and end<s.length()){
                if(s[st]==s[end]){
                    l2+=2;
                    ans++;
                }
                else{
                    break;
                }
                st--;
                end++;
            }
            // if(l2>ans){
            //     ans = l2;
            //     start = st+1;
            //     endt = end-1;
            // }
        }
            return ans;
    }
};
