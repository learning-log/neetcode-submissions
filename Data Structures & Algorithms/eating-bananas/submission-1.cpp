class Solution {
public:
    bool isItpossible(vector<int>piles,int k,int h){
        bool ans;
        int requiredH = 0;
        for(int i=0;i<piles.size();i++){
            int tempH;
            if(piles[i]%k==0){
                tempH  = piles[i]/k;
            }
            else{
                tempH =  (piles[i]/k)+1;
            }
            requiredH += tempH; 
        }
        cout<<requiredH<<" "<<k<<endl;
        return h>=requiredH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int high = 0;
        for(int i = 0;i<piles.size();i++){
            high = max(high,piles[i]);
        }
        int l = 1;
        int ans = -1;
        // cout<<high<<endl;
        while(l<=high){
            int mid = (high+l)/2;
            if(isItpossible(piles,mid,h)){
                if(ans==-1)
                    ans = mid;
                else
                    ans = min(ans,mid);
                high = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
