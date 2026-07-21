class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size()-1;
        int ans = -1;
        while(start<end){
            int temp = min(heights[start],heights[end])*(end-start);
            ans = max(ans,temp);
            if(heights[start]>heights[end]){
                end--;
            }
            else{
                start++;
            }

        }
        return ans;
    }
};
