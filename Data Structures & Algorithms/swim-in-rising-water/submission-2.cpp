class Solution {
public:

    int swimInWater(vector<vector<int>>& grid) {

        // int t = 0;

        int ans = 99999;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));

        // dfs(grid,0,0,t,ans,vis);
        // return ans;  
        priority_queue<pair<int,pair<int,int>>> pq;

        pq.push(make_pair(-max(grid[0][0],0),make_pair(0,0)));

        while(!pq.empty()){
            pair<int,pair<int,int>>p= pq.top();
            int i = p.second.first,j = p.second.second;
            int t = -p.first;
            pq.pop();

            if(i==grid.size()-1 and j==grid[0].size()-1){
                ans = min(ans,max(t,-grid[i][j]));
                // return;
            }
            if(vis[i][j]==1){
                continue;
            }
            vis[i][j]=1;
            if(i+1>=0 and j>=0 and i+1<grid.size() and j<grid[0].size()){
                pq.push(make_pair(-max(t,grid[i+1][j]),make_pair(i+1,j)));
            }

            if(i-1>=0 and j>=0 and i-1<grid.size() and j<grid[0].size()){
                pq.push(make_pair(-max(t,grid[i-1][j]),make_pair(i-1,j)));
            }

            if(i>=0 and j+1>=0 and i<grid.size() and j+1<grid[0].size()){
                pq.push(make_pair(-max(t,grid[i][j+1]),make_pair(i,j+1)));
            }

            if(i>=0 and j-1>=0 and i<grid.size() and j-1<grid[0].size()){
                pq.push(make_pair(-max(t,grid[i][j-1]),make_pair(i,j-1)));
            }
        }    
        return ans;     
    }
};
