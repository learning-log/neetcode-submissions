class Solution {
public:
    int diffSub(string s,string t, int a, int b){
        if(b==t.length()){
            return 1;
        }
        if(a==s.length()){
            return 0;
        }
        if(s[a]==t[b]){
            return diffSub(s,t,a+1,b+1)+ diffSub(s,t,a+1,b);
        }
        else{
            return diffSub(s,t,a+1,b);
        }
        // return max(diffSub(),diffSub)
    }
    int numDistinct(string s, string t) {
        return diffSub(s,t,0,0);
    }
};
