class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = {0,1};
        if (n==0)
            return {0};
        if(n==1){
            return {0,1};
        }
        int check = 2;
        for(int i =2;i<=n;i++){
            if(i==2*check){
                check = i;
            }
            ans.push_back(ans[i-check]+1);
        }
        return ans;
    }
};
