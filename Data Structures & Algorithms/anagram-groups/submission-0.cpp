class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for (int i=0;i<strs.size();i++){
            string st = strs[i];
            vector<int> v(26,0);
            for (int j=0;j<st.length();j++){
                v[st[j]-'a']++;
            }
            string key=to_string(v[0]);
            
            for(int j=1;j<v.size();j++){
                key+= (','+ to_string(v[j]));
            }

            if(mp.find(key)!=mp.end()){
                mp[key].push_back(st);
            }
            else{
                vector<string>s;
                s.push_back(st);
                mp[key]= s;
            }

        }

        vector<vector<string>> ans;

        for (auto t:mp){
            ans.push_back(t.second);
        }
        return ans;
    }
};
