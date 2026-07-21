class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans;

        int st = 0;
        int end = nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        while(st<=end){
            int mid = (st+end)/2;

            if(mid==0){
                if(nums[nums.size()-1]>nums[0]){
                    return nums[0];
                }
                else if(nums[mid]>=nums[end]){
                    st = mid+1;
                }
                else if(nums[mid]<nums[end]){
                    end = mid-1;
                }
            }
            else{
                if(nums[mid-1]>nums[mid]){
                    return nums[mid];
                }
                else if(nums[mid]>=nums[end]){
                    st = mid+1;
                }
                else if(nums[mid]<nums[end]){
                    end = mid-1;
                }
            }
        }
    }
};
