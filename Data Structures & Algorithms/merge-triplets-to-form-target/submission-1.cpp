

class Solution {
public:
    
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // sort(triplets.begin(),triplets.end(),comp);
        // int st = 0;
        // int end = triplets.size()-1;
        vector<int> curr(3,-1);

        // while(st<triplets.size()){
        //     curr[0] = max(triplets[st][0],curr[0]);
        //     curr[1] = max(triplets[st][1],curr[1]);
        //     curr[2] = max(triplets[st][2],curr[2]);
        //     st++;
        //     if(curr[0]==target[0]){  
        //         break;
        //     }
        // }
        // if(curr[0]!=target[0]){  
        //         return false;;
        //     }
        // if(curr[1]!=target[1]){
        //     sort(triplets.begin()+st,triplets.end(),comp1);
        //     while(st<triplets.size()){
        //         curr[0] = max(triplets[st][0],curr[0]);
        //         curr[1] = max(triplets[st][1],curr[1]);
        //         curr[2] = max(triplets[st][2],curr[2]);
        //         st++;
        //         if(curr[1]==target[1]){
                
        //             break;
        //         }
        //     }
        // }
        // if(curr[1]!=target[1]){  
        //         return false;
        // }
        // if(curr[2]!=target[2]){
        //     sort(triplets.begin()+st,triplets.end(),comp3);
        //     while(st<triplets.size()){
        //         curr[0] = max(triplets[st][0],curr[0]);
        //         curr[1] = max(triplets[st][1],curr[1]);
        //         curr[2] = max(triplets[st][2],curr[2]);
        //         st++;
        //         if(curr[2]==target[2]){
                
        //             break;
        //         }
        //     }
        // }
        //  if(curr[2]!=target[2]){  
        //         return false;
        // }
        // return true;

        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]<=target[0] and triplets[i][2]<=target[2] and triplets[i][1]<=target[1]){
                curr[0] = max(triplets[i][0],curr[0]);
                curr[1] = max(triplets[i][1],curr[1]);
                curr[2] = max(triplets[i][2],curr[2]);
            }
        }
        cout<<curr[0]<<" "<<curr[1]<<" "<<curr[2];
        if(curr[2]==target[2] and curr[1]==target[1] and curr[0]==target[0]){  
                return true;
        }
        return false;
    }
};
