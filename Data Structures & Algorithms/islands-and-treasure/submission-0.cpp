class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    grid[i][j] = 2147483647;
                    q.push(make_pair(i,j));
                }
            }
        }
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0;k<sz;k++){
                pair<int,int> p = q.front();
                int i = p.first, j= p.second;
                q.pop();
                if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==-1 or (grid[i][j]!=2147483647)){
                    continue;
                }
                // if(grid[i][j]==0){
                //     grid[i][j] = -2;
                // }
                // else{
                
                // }
                grid[i][j] = level;
                
                q.push(make_pair(i,j+1));

                q.push(make_pair(i+1,j));

                q.push(make_pair(i-1,j));

                q.push(make_pair(i,j-1));

            }
            level++;

        }

        return;

    }
};
