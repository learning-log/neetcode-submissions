class Solution {
public:
    int countup(unordered_map<int,int>&mp,int a){
        int ans=0;
        while(mp.find(a)!=mp.end() and mp[a]==1){
            mp[a] =2;
            ans++;
            a++;
        }
        return ans;
    }

    int countdown(unordered_map<int,int>&mp,int a){
        int ans=0;
        while(mp.find(a)!=mp.end() and mp[a]==1){
            mp[a] =2;
            ans++;
            a--;
        }
        return ans;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        for(int j=0; j<nums.size();j++){
            int count = countup(mp,nums[j]);
            count += countdown(mp,nums[j]-1);
            ans = max(ans,count);
        }
        return ans;
    }
};
