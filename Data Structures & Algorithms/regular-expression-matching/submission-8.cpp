class Solution {
public:
    int diffSub(string s, string t, int a, int b){
        if(b==t.length() and s.length()==a){
            return true;
        }
        if(b==t.length() or s.length()==a){
            return false;
        }
        bool star = false;
        

        if((b+1<t.length() and t[b+1]!='*') or (b+1>=t.length()) and t[a]=='.'){
            return diffSub(s,t,a+1,b+1);
        }

        if(b+1<t.length() and t[b+1]=='*' and t[b]=='.'){
            star = star or diffSub(s,t,a,b+2);
            int st = a;
            while((st<s.length())){
                star = star or diffSub(s,t,st+1,b+2);
                st++;
            }

            return star;
        }

        

        if(b+1<t.length() and t[b+1]=='*'){
            star = star or diffSub(s,t,a,b+2);
            int st = a;
            while((st<s.length() and s[st]==t[b])){
                star = star or diffSub(s,t,st+1,b+2);
                st++;
            }

            return star;
        }
        if(s[a]==t[b]){
            star =  diffSub(s,t,a+1,b+1);
            return star;
        }
        // if(t[b]=='*'){
        //     star = star or diffSub(s,t,a,b+1);
        //     int st = a;
        //     while(st<s.length() and s[st]==s[a]){
        //         star = star or diffSub(s,t,st+1,b+1);
        //         st++;
        //     }

        //     return star;
        // }

        // if(t[b]=='*'){

        //     bool star = diffSub(s,t,a,b+1) or diffSub(s,t,a+1,b+1);
        //     int st = a+1;
        //     while(st<s.length() and s[st]==s[a]){
        //         star = star or diffSub(s,t,st+1,b+1);
        //         st++;
        //     }
        //     return star;
        // }
        // else{
            return false;
        // }
        
        // return max(diffSub(),diffSub)
    }
    bool isMatch(string s, string p) {
        return diffSub(s,p,0,0);
    }
};
