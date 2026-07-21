class Solution {
public:
    vector<int> partitionLabels(string s) {
        int count[26] = {0};
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']=i;
        }
        int reach = 0;
        int str = 0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            reach = max(reach,count[s[i]-'a']);
            if(reach == i){
                ans.push_back(reach-str+1);
                str = i+1;
            }
        }
        return ans;
    }
};
