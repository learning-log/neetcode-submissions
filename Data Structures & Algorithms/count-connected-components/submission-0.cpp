class Solution {
public:
    void dfs(vector<vector<int>> &graph,int s,vector<int> &vis){
        if(vis[s]){
            return;
        }
        vis[s]=1;
        for(auto t:graph[s]){
            
            dfs(graph,t,vis);
            
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> graph(n);

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);

            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(graph,i,vis);
            }
        }
        return ans;
    }
};
