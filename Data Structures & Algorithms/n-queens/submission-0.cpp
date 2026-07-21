class Solution {
public:
    
    vector<string> ansCreation(vector<int> curr){
        vector<string> ans;

        for(int i=0;i<curr.size();i++){
            string row_st = "";
            for(int j=0;j<curr.size();j++){
                if(j!=curr[i]){
                    row_st+=".";
                }
                else{
                    row_st+="Q";
                }
            }
            ans.push_back(row_st);
        }
        return ans;

    }

    bool isColSafe(vector<vector<int>> brd, int row, int col){
        for(int i=0;i<row;i++){
            if(brd[i][col]==1){
                return false;
            }
        }
        return true;
    }

    bool isDiagSafe(vector<vector<int>> brd, int row, int col){
        int r = row-1;
        int c = col-1;
        while(r>=0 and c>=0){
            if(brd[r][c]==1){
                return false;
            }
            r--;
            c--;
        }
        r = row-1;
        c = col+1;

        while(r>=0 and c<brd.size()){
            if(brd[r][c]==1){
                return false;
            }
            r--;
            c++;
        }
        return true;
    }

    bool isSafe(vector<vector<int>> brd, int row, int col){
        return isColSafe(brd,row,col) and isDiagSafe(brd,row,col);
    }

    void req(vector<vector<int>> brd,int row, vector<int>curr,vector<vector<string>> &ans){
        if(row==brd.size()){

            ans.push_back(ansCreation(curr));
            return;
        }

        for(int i=0;i<brd.size();i++){
            if(isSafe(brd, row,i)){
                brd[row][i]=1;
                curr.push_back(i);
                req(brd,row+1,curr,ans);
                curr.pop_back();
                brd[row][i] = 0;
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> brd(n,vector<int>(n,0));
        vector<int> curr;
        vector<vector<string>> ans;
        int row = 0;
        req(brd,row,curr,ans);
        return ans;



    }
};
