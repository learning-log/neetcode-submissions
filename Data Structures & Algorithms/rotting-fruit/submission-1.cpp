class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {


        queue<pair<int,int>>q;
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    grid[i][j] = 1;
                    q.push(make_pair(i,j));
                    count++;
                }
                else if (grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count==0){
            return 0;
        }
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0;k<sz;k++){
                pair<int,int> p = q.front();
                int i = p.first, j= p.second;
                q.pop();
                if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0 or (grid[i][j]==2)){
                    continue;
                }
                // if(grid[i][j]==0){
                //     grid[i][j] = -2;
                // }
                // else{
                
                // }
                count--;
                grid[i][j] = 2;
                
                q.push(make_pair(i,j+1));

                q.push(make_pair(i+1,j));

                q.push(make_pair(i-1,j));

                q.push(make_pair(i,j-1));

            }
            level++;

        }

        if(count==0)
        return level-2;

        return -1;
        
    }
};
