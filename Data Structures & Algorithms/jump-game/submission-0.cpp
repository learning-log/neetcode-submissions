class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx =0;
        for(int i=0;i<nums.size();i++){
            if(maxIdx>=i){
                maxIdx = max(maxIdx,i+nums[i]);
            }
        }
        cout << maxIdx;
        return maxIdx>=(nums.size()-1);
    }
};
