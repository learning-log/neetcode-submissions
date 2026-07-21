class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<int> q;
        vector<int> dist(n+1,9999);
        dist[k] = 0;
        for(int i=1;i<=n;i++){

            for(int j=0;j<times.size();j++){
                int a = times[j][0], b= times[j][1], c= times[j][2];

                if(dist[b]>dist[a]+c){
                    dist[b] = dist[a] + c;
                }
            }

        }
        
        int ans = 0;
        for(int i=1;i<n+1;i++){
            ans = max(ans,dist[i]);
        }

        return ans==9999?-1:ans;
    }
};
