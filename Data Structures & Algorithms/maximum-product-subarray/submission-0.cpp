class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // vector<int> mim(nums.size(),1);
        // vector<int> mam(nums.size(),1);
        
        int mim = nums[0];
        int mam = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            int premam = mam;
            int premim = mim;
            if(nums[i]<0){
                mam = max(premim*nums[i],nums[i]);
                mim = min(premam*nums[i],nums[i]);
            }
            else{
                mam = max(premam*nums[i],nums[i]);
                mim = min(premim*nums[i],nums[i]);

            }
            ans = max(ans,mam);

        }
        return ans;
    }
};
