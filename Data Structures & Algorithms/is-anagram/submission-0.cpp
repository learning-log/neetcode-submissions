class Solution {
public:
    bool isAnagram(string s, string t) {
        char a1[26]={0};
        char a2[26]={0};
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            a1[s[i]-'a']++;
            a2[t[i]-'a']++;
        }
        for (int i=0;i<26;i++){
            if(a1[i]!=a2[i])
                return false;
        }
        return true;

    }
};
