class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        queue<int> q;

        vector<vector<int>> grid(numCourses);
        vector<int> ind(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            grid[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ind[prerequisites[i][0]]++;
        }
        int completed = 0;
        for(int i = 0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
                completed++;
                
            }
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto t: grid[i]){
                ind[t]--;
                if(ind[t]==0){
                    q.push(t);
                    completed++;
                }
            }
        }
        return completed==numCourses;
    }
};
