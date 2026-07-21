class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<int>>& grid,int i,int j, int pVal){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==1){
            return;
        }

        if(heights[i][j]<pVal){
            return;
        }

        grid[i][j]=1;
        pVal = heights[i][j];

        dfs(heights,grid,i+1,j,pVal);

        dfs(heights,grid,i,j-1,pVal);

        dfs(heights,grid,i,j+1,pVal);

        dfs(heights,grid,i-1,j,pVal);

        return;

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> grid1(heights.size(),vector<int>(heights[0].size(),0));
        // queue<int> q;
        for(int i = 0;i<heights.size();i++){
            if(grid1[i][0]==0)
                dfs(heights,grid1,i,0,0);
        }
        for(int i = 0;i<heights[0].size();i++){
            if(grid1[0][i]==0)
                dfs(heights,grid1,0,i,0);
        }


        vector<vector<int>> grid2(heights.size(),vector<int>(heights[0].size(),0));
        // queue<int> q;
        int row = heights.size(),col = heights[0].size();
        cout<<row<<col<<endl;
        for(int i = 0;i<row;i++){
            if(grid2[i][col-1]==0){
                cout<<i<<" "<<col-1<<endl;
                dfs(heights,grid2,i,col-1,0);
                cout<<grid2[i][col-1]<<endl;
            }
        }
        for(int i = 0;i<col;i++){
            if(grid2[row-1][i]==0)
                dfs(heights,grid2,row-1,i,0);
        }

        vector<vector<int>> ans;
        cout<<grid2[0][4]<<endl;

        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                cout<<grid2[i][j]<<" ";
                if(grid1[i][j]==1 and grid2[i][j]==1){
                    ans.push_back({i,j});
                }
            }
            cout<<endl;
        }
        return ans;


    }
};
