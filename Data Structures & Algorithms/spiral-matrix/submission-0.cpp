class Solution {
public:
    vector<int> spiralO(vector<vector<int>> matrix,int sti,int stj, int endi,int endj){
        if(sti>endi or stj>endj){
            return {};
        }

        vector<int> ans;
        for(int i = stj;i<=endj;i++){
            ans.push_back(matrix[sti][i]);
        }
        sti++;
        if(sti>endi or stj>endj){
            return ans;
        }

        for(int i = sti;i<=endi;i++){
            ans.push_back(matrix[i][endj]);
        }

        endj--;
        if(sti>endi or stj>endj){
            return ans;
        }

        for(int i = endj;i>=stj;i--){
            ans.push_back(matrix[endi][i]);
        }
        endi--;
        if(sti>endi or stj>endj){
            return ans;
        }

        for(int i = endi;i>=sti;i--){
            ans.push_back(matrix[i][stj]);
        }
        stj++;

        vector<int> next = spiralO(matrix,sti,stj,endi,endj);
        for(int i=0;i<next.size();i++){
            ans.push_back(next[i]);
        }
        return ans;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return spiralO(matrix,0,0,matrix.size()-1,matrix[0].size()-1);


    }
};
