class Solution {
public:
    // int justGreater(vector<int>)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int justG = matrix.size();
        int st = 0;
        int end = matrix.size()-1;

        while(st<=end){
            int mid = (st+end)/2;
            if(matrix[mid][0]==target){
                return true;
            }
            else if(matrix[mid][0]>target){
                end = mid-1;
                justG = mid;
            }
            else{
                st = mid+1;
            }
        }

        st = 0;
        end = matrix[0].size()-1;
        cout<<justG<<endl;
        if(justG==0){
            return false;
        }

        while(st<=end){
            int mid = (st+end)/2;
            if(matrix[justG-1][mid]==target){
                return true;
            }
            else if(matrix[justG-1][mid]>target){
                end = mid-1;
                // justG = mid;
            }
            else{
                st = mid+1;
            }
        }

        return false;

    }
};
