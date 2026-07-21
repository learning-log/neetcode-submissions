class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int no_zero = 0;
        int lproduct[nums.size()];
        int rproduct[nums.size()];
        lproduct[0] = nums[0];
        rproduct[nums.size()-1] = nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            lproduct[i] = lproduct[i-1]*nums[i];
        }
        for(int i=nums.size()-2;i>=0;i--){
            rproduct[i] = rproduct[i+1]*nums[i];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                // if(no_zero==1)
                ans.push_back(rproduct[i+1]);
                // else
            }
            else if(i==nums.size()-1){
                ans.push_back(lproduct[i-1]);

            }
            else{
                ans.push_back(rproduct[i+1]*lproduct[i-1]);
            }
        }
        return ans;

    }
};
