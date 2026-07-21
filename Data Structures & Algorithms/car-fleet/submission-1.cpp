class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,float>> imp;

        for(int i=0;i<position.size();i++){
            float time = (float)(target-position[i])/speed[i];
            cout<<time<<endl;
            imp.push_back(make_pair(position[i],time));
        }
        sort(imp.begin(),imp.end());

        stack<float> fleets;
        int ans = 0;
        for(int i = position.size()-1;i>=0;i--){

            cout<<imp[i].second<<endl;
            if(fleets.empty()){
                fleets.push(imp[i].second);
            }
            else if(fleets.top()<imp[i].second){
                fleets.pop();
                ans++;
                fleets.push(imp[i].second);
            }
        }

        ans++;
        return ans;


    }
};
