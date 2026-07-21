class KthLargest {
public:
    priority_queue<int>pq;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        kk  = k;
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k){
                pq.push(-(nums[i]));
            }
            else{
                if(-pq.top()<nums[i]){
                    pq.pop();
                    pq.push(-nums[i]);
                }
            }

        }

    }
    
    int add(int val) {
        if(pq.size()<kk){
            pq.push(-val);
        }
        else{
            if(-pq.top()<val){
                    pq.pop();
                    pq.push(-val);
            }
        }
        return -pq.top();
    }
};
