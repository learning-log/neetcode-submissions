class Solution {
public:
    bool check(unordered_map<char,int>a,unordered_map<char,int> b){
        for(auto t:a){
            if(b[t.first]<t.second){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        int st=0,end=0;
        if(s.length()<t.length()){
            return "";
        }
        for(;end<t.length();end++){
            mp1[t[end]]++;
            mp2[s[end]]++;
        }
        if(check(mp1,mp2)){
            return s.substr(st,end-st);
        }
        int strlen = 10000;
        int ansst=-1;
        int ansend = -1;
        while(end<s.length()){
            mp2[s[end]]++;
            while(check(mp1,mp2)){
                if(strlen>end-st+1){
                    ansst = st;
                    ansend = end;
                    strlen = end-st+1;
                }
                mp2[s[st]]--;
                st++;  
            }
            end++;
        }
        cout<<ansend<<endl;
        cout<<ansst<<endl;
        cout<<strlen<<endl;
        if(ansst==-1){
            return "";
        }
        
        else{
            return s.substr(ansst,strlen);
        }
    }
};
