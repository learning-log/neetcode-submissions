class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();){
            int start = i+1;
            int end = nums.size()-1;
            int target = 0-nums[i];
            // vector<int>ans;
            while(start<end){
                int sum = nums[start]+nums[end];
                if(sum<target){
                    start++;
                }
                else if(sum>target){
                    end--;
                }
                else{
                    
                    // ans.push_back(start+1);
                    // ans.push_back(end+1);
                    vector<int> temp = {nums[i],nums[start],nums[end]};
                    ans.push_back(temp);
                    start++;
                    end--;
                    while(start<end and nums[start]==nums[start-1]){
                        start++;
                    }

                    while(end>start and nums[end]==nums[end+1]){
                        end--;
                    }

                }

            }


            i++;
            // cout<<i<<endl;
            while(i<nums.size() and nums[i]==nums[i-1]){
                i++;
            }
        }
        return ans;
    }
};
