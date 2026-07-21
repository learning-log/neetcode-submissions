class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans =-99999;
        int temp = 0;
        for(int i=0;i<nums.size();i++){
            temp = temp+nums[i];
            ans = max(ans,temp);
            if(temp<0){
                temp = 0;
            }
        }
        return ans;

    }
};
