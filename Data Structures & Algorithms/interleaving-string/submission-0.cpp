class Solution {
public:
    bool req(string s1,string s2, string s3, int a, int b, int c){
        if((a!=s1.length() or b!=s2.length()) and c==s3.length()){
            return false;
        }
        if(a==s1.length() and b==s2.length() and c==s3.length()){
            return true;
        }

        if(a<s1.length() and b<s2.length()){
            if(s1[a]==s3[c] and s2[b]==s3[c])
                return req(s1,s2,s3,a+1,b,c+1) or req(s1,s2,s3,a,b+1,c+1);
            else if(s1[a]==s3[c]){
                return req(s1,s2,s3,a+1,b,c+1);
            }
            else if(s2[b]==s3[c]){
                return req(s1,s2,s3,a,b+1,c+1);
            }
            else{
                return false;
            }
        }
        
        if(a<s1.length()){
            if(s1[a]==s3[c]){
                return req(s1,s2,s3,a+1,b,c+1);
            }
            else{
                return false;
            }
        }
        if(b<s2.length()){
            if(s2[b]==s3[c]){
                return req(s1,s2,s3,a,b+1,c+1);
            }
            else{
                return false;
            }
        }

    }
    bool isInterleave(string s1, string s2, string s3) {
            return req(s1,s2,s3,0,0,0);
    }   
};
