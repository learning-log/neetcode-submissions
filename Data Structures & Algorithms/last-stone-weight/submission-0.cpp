class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(!pq.empty() and pq.size()!=1){
            int h1 = pq.top();
            pq.pop();
            int h2 = pq.top();
            pq.pop();
            if(h1!=h2){
                pq.push(abs(h1-h2));
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};
