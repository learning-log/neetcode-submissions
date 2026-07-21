class Solution {
public:


    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size());
        vector<int> right(heights.size());

        stack<int>st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }
            st.push(i);
        }
        stack<int> st1;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st1.empty() and heights[st1.top()]>=heights[i]){
                st1.pop();
            }

            if(st1.empty()){
                right[i] = heights.size();
            }
            else{
                right[i] = st1.top();
            }
            st1.push(i);
        }

        int ans = -1;

        for(int i = 0;i<heights.size();i++){
            int temp = ((i-1) - left[i])*heights[i] + (right[i] - (i+1))*heights[i] + heights[i];
            ans = max(temp,ans);
        }

        return ans;


    }
};
