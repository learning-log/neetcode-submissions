class Solution {
public:
    void construct(int n,int l,int r, string curr,vector<string> &ans){
        
        if(r==n and l==n){
            ans.push_back(curr);
            return;
        }
        else if(l>r){
            if(l==n){
                construct(n,l,r+1,curr+')',ans);
            }
            else{
                construct(n,l,r+1,curr+')',ans);
                construct(n,l+1,r,curr+'(',ans);
            }
        }
        else if(l==r){
            construct(n,l+1,r,curr+'(',ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        int l = 0,r =0;
        // stack<char> left,right;
        // for(int i=0;i<n;i++){
        //     left.push('(');
        //     right.push(')');
        // }

        vector<string> ans;
        string curr="";
        construct(n,l,r,curr,ans);
        return ans;

    }
};
