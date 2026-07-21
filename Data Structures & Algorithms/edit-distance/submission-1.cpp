class Solution {
public:

    int diffSub(string s,string t, int a, int b){
        if(b==t.length()){
            return s.length()-a;
        }
        if(a==s.length()){
            return t.length()-b;
        }
        
        if(s[a]!=t[b]){
            return min(min(diffSub(s,t,a,b+1), diffSub(s,t,a+1,b)),diffSub(s,t,a+1,b+1))+1;
        }
        else{
            return diffSub(s,t,a+1,b+1);
        }
        // return max(diffSub(),diffSub)
    }

    int minDistance(string word1, string word2) {
        
        return diffSub(word1,word2,0,0);
    }
};
