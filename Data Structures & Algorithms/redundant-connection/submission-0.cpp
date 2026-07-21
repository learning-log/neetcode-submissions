class Solution {
public:
    void union_(vector<int>&arr,int a,int b){
        int ap = find(arr,a);
        int bp = find(arr,b);
        arr[bp] = ap;
        return;
    }
    int find(vector<int> arr,int a){
        if(arr[a]==a){
            return a;
        }
        return find(arr,arr[a]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> arr(edges.size()+1,0);

        for(int i=0;i<arr.size();i++){
            arr[i] = i;
        }

        vector<int>ans;

        for(int i=0;i<edges.size();i++){
            if(find(arr,edges[i][1])==find(arr,edges[i][0])){
                ans = edges[i];
            }
            else{
                union_(arr,edges[i][0],edges[i][1]);
            }
        }

        return ans;






    }
};
