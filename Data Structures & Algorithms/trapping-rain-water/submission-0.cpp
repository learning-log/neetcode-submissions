class Solution {
public:
    int trap(vector<int>& height) {
        int leftarr[height.size()];
        int rightarr[height.size()];
        leftarr[0] = 0;
        rightarr[height.size()-1] = 0;
        for(int i=0;i<height.size()-1;i++){
            leftarr[i+1] = max(leftarr[i],height[i]);
        }
        for(int i=height.size()-1;i>0;i--){
            rightarr[i-1] = max(rightarr[i],height[i]);
        }

        int ans = 0;
        for(int i=1;i<height.size()-1;i++){
            ans += max(0,min(leftarr[i],rightarr[i])-height[i]);
        }
        return ans;
    }
};
