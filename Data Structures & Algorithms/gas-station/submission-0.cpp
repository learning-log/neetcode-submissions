class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int range =0;
        int ans = 0;
        for(int i=0;i<gas.size();i++){
            range += gas[i];
            if(range<cost[i]){
                range = 0;
                ans = i+1;
                cout<<ans<<endl;
            }
            else{
                range-=cost[i];
            }
        }

        for(int i=0;i<ans;i++){
            range += gas[i];
            if(range<cost[i]){
                return -1;
            } 
            range -= cost[i];
        }


        return ans;
    }
};
