class Solution {
public:
    int jump(vector<int>& nums) {
        int maxIdx = 0;
        int curr_reach = 0;
        int ans=0;
        for(int i =0;i<nums.size();i++){
            if(curr_reach<i){
                curr_reach = maxIdx;
                ans++;
            }
            maxIdx = max(maxIdx,i+nums[i]);
        }

        return ans;
        
    }
};
