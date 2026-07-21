class Solution {
public:
    int profit(vector<int>&prices,int pos, int s){
        if(pos>=prices.size()){
            return 0;
        }
        
        int cold = profit(prices,pos+1,s);

        if(s){
            return max(cold,profit(prices,pos+1,false)-prices[pos]);
        }
        else{
            return max(cold,profit(prices,pos+2,true)+prices[pos]);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        // int s = -2;
        // int b = -3;
        bool s = true;
        return profit(prices,0,s);
    }
};
