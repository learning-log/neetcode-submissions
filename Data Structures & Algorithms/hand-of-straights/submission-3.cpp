class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int> q;
        unordered_map<int,int> mp;
        if(hand.size()%groupSize){
            return false;
        }
        for(int i=0;i<hand.size();i++){
            if(mp.find(hand[i])==mp.end())
                q.push(-hand[i]);
            mp[hand[i]]++;
        }

        int groupmade = 0;
        int target = hand.size()/groupSize;

        while(!q.empty()){
            int top = -q.top();
            int seq = top;
            for(int i = 0;i<groupSize;i++){
                if(mp.find(seq)==mp.end() or mp[seq]<=0){
                    //do some thing;
                    return false;
                }
                else{
                    mp[seq]--;
                }
                seq++;
            }
            while(!q.empty()){
                int top = -q.top();
                if(mp[top]<=0){
                    q.pop();
                    cout<<top<<endl;
                }
                else{
                    break;
                }
            }
            groupmade++;
            if(groupmade==target){
                return true;
            }
        }
    }
};
