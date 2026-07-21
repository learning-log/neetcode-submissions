class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int,int> unomap;

        for(auto t:nums){
            if(unomap.find(t)!=unomap.end()){
                return true;
            }
            unomap[t] = 1;
        }
        return false;

    }
};
