class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int ma = prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            ans = max(ans,ma-prices[i]);
            ma = max(ma,prices[i]);
        }
        return ans;
    }
};
