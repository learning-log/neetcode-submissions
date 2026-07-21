class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int no_zero = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(no_zero==0){
                    product = 1*product;
                    no_zero++;
                }
                else{
                    product = 0;
                    break;
                }
            }
            else{
                product = product * nums[i];
            }
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(no_zero==1)
                    ans.push_back(0);
                else
                    ans.push_back(product/nums[i]);
            }
            else{
                ans.push_back(product);
            }
        }
        return ans;

    }
};
