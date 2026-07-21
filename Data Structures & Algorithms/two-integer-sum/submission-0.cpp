class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // int start=0,end=num.size();
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            int to_look = target - nums[i];
            if(mp.find(to_look)!=mp.end()){
                return {mp[to_look],i};
            }
            mp[nums[i]] = i;
        }
    }
};
