class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        for(auto t:mp){
            pq.push(make_pair(t.second,t.second));
        }
        // int turn = 0;
        queue<pair<pair<int,char>,int>>q;
        int cycle = 0;
        while(!pq.empty() or !q.empty()){

            while(!q.empty() and q.front().second<cycle){
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()){
                pair<int,char> p = pq.top();
                pq.pop();
                if(p.first!=1){
                    p.first--;
                    q.push(make_pair(p,cycle+n));
                    // cycle+ = ()
                }
            }
            
            cycle++;
        }
        return cycle;

    }
};
