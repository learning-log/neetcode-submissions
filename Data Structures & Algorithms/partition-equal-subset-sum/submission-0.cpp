class Solution {
public:
    bool req(vector<int>& nums, int pos, int sum){
        if(sum==0){
            return true;
        }
        if(pos==nums.size()){
            return false;
        }

        if(sum-nums[pos]<0){
            return req(nums,pos+1,sum);
        }
        else{
            return req(nums,pos+1,sum) or req(nums,pos+1,sum-nums[pos]);
        }
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }

        return req(nums,0,sum/2);

    }
};
