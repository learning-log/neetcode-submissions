class Solution {
public:
    int distance(vector<int> a, vector<int> b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }

    int find(vector<int>&arr,int a){
        if(arr[a]==a){
            return a;
        }
        arr[a] = find(arr,arr[a]);
        return arr[a];
    }

    void union_(vector<int> &arr,int i, int j){
        int i_p = find(arr,i);
        int j_p = find(arr,j);
        arr[i_p] = j_p;
        return;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<vector<int>> edges;

        priority_queue<pair<int,pair<int,int>>> q;

        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int d = distance(points[i],points[j]);
                // priority_queue<pair<int,pair<int,int>> q;
                q.push(make_pair(-d,make_pair(i,j)));
            }

        }

        vector<int> arr(points.size());
        for(int i=0;i<arr.size();i++){
            arr[i] = i;
        }
        int ans = 0;
    
        while(!q.empty()){
            pair<int,pair<int,int>> p = q.top();
            q.pop();
            int d = p.first;
            if(find(arr,p.second.first)!=find(arr,p.second.second)){
                ans-=d;
                union_(arr,p.second.first,p.second.second);
            }
        }

        return ans;

        
    }
};
