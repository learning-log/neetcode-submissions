class Solution {
public:
    int maxPath(vector<vector<int>>& matrix,int a,int b,int prev,vector<vector<int>> vis){
        if(a<0 or b<0 or a>=matrix.size() or b>=matrix[0].size()){
            return 0;
        }
        vis[a][b]=1;
        if(matrix[a][b]<=prev){
            return 0;
        }

        int pl= max(maxPath(matrix,a+1,b,matrix[a][b],vis),maxPath(matrix,a,b+1,matrix[a][b],vis))+1;
        int ml = max(maxPath(matrix,a-1,b,matrix[a][b],vis),maxPath(matrix,a,b-1,matrix[a][b],vis))+1;
        return max(pl,ml);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> vis(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans = max(maxPath(matrix,i,j,-1,vis),ans);
            }
        }
        return ans;
    }
};
