class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans ;
        int st = 0;
        int end = nums.size()-1;

        while(st<=end){
            int mid = (st+end)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[0]){
                if(nums[mid]>target and nums[0]<=target){
                    end = mid-1;
                }

                else{
                    st = mid+1;
                }
            }
            else{
                if(nums[mid]<target and target< nums[0]){
                    st = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};
