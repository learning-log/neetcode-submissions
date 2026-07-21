class Solution {
public:
    bool checkValidString(string s) {
        int lmin =0;
        int lmax = 0;
        int st =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                lmin++;
                lmax++;
            }
            else if(s[i]==')'){
                lmin--;
                lmax--;
            }
            else{
                lmin--;
                lmax++;
            }
            if(lmax<0){
                return false;
            }
            if(lmin<0){
                lmin=0;
            }
            
        }
        if (lmin==0){
            return true;
        }
           


    }
};
