class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='X' or grid[i][j]=='Z'){
            return;
        }

        // if(heights[i][j]<pVal){
        //     return;
        // }

        grid[i][j]='Z';
        // pVal = heights[i][j];

        dfs(grid,i+1,j);

        dfs(grid,i,j-1);

        dfs(grid,i,j+1);

        dfs(grid,i-1,j);

        return;

    }


    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            dfs(board,i,0);
        }
        for(int i=0;i<board[0].size();i++){
            dfs(board,board.size()-1,i);
        }

        for(int i=0;i<board.size();i++){
            dfs(board,i,board[0].size()-1);
        }

        for(int i=0;i<board[0].size();i++){
            dfs(board,0,i);
        }

        for (int i = 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j] ='X';
                }
                else if(board[i][j]=='Z'){
                    board[i][j]='O';
                }
            }
        }
        return;
        
    }
};
