class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        queue<int> q;

        vector<vector<int>> grid(numCourses);
        vector<int> ind(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            grid[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ind[prerequisites[i][0]]++;
        }
        vector<int>ans;
        for(int i = 0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto t: grid[i]){
                ind[t]--;
                if(ind[t]==0){
                    q.push(t);
                    ans.push_back(t);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        vector<int> a;
        return a;

    }
};
