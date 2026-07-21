class Solution {
public:
    bool dfs(vector<vector<int>> &graph,int s,vector<int> &vis,int pr){
        if(vis[s]){
            return false;
        }
        vis[s]=1;
        for(auto t:graph[s]){
            if(pr!=t and vis[t]==1){
                return true;
            }
            else if(dfs(graph,t,vis,s)){
                    return true;
                }
            
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);

            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n,0);
        int iland = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                iland++;
                if(dfs(graph,i,vis,-1)){
                    return false;

                }
            }
        }
        if (iland>1){
            return false;
        }
        return true;
    }
};
