class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int ans = -1;
       for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                if(nums[nums[i]]<0){
                    return nums[i];
                }
                nums[nums[i]] = -(nums[nums[i]]);
            }
            else{
                int pos = -nums[i];
                if(nums[pos]<0){
                    return pos;
                }
                nums[pos] = -(nums[pos]);
            }
       }  

       return 0;
    }
};
