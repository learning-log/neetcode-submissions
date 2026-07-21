class Solution {
public:
    bool req(vector<vector<char>> board, string word,int pos,int i, int j){
        if (pos==word.size()){
            return true;
        }

        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[pos]){
            return false;
        }
        board[i][j] = '#';
        return req(board,word,pos+1,i,j+1) or req(board,word,pos+1,i-1,j) or req(board,word,pos+1,i+1,j) or req(board,word,pos+1,i,j-1);
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        bool ans;
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(req(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};
