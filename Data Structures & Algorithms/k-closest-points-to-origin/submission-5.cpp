class Solution {
public:
    float distance(int a, int b){
        float d = sqrt((float)(a*a+b*b));
        return d;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<float,int>>pq;
        for(int i=0;i<points.size();i++){
            float d = distance(points[i][0],points[i][1]);
            cout<<d<<endl;

            if(pq.size()<k){
                pq.push(make_pair(d,i));
            }
            else{
                cout<<d<<" "<<pq.top().first<<endl;
                if(pq.top().first>d){
                    cout<<"hellp"<<endl;
                    pq.pop();
                    pq.push(make_pair(d,i));
                }
            }
        }

        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;


    }
};
