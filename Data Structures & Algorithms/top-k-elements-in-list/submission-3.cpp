class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> arr(nums.size()+1);
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]]=1;
            }
            vector<int> a;
            arr[i] = a;
        }

        vector<int> a;
        arr[nums.size()-1] = a;
        for(auto t:mp){
            arr[t.second].push_back(t.first);
        }

        vector<int> ans;

        int number=nums.size();
        while(k!=0){
            if(arr[number].size()!=0){

                for(int i=0;i<arr[number].size();i++){
                    ans.push_back(arr[number][i]);
                    k--;
                }

                // while(k!=0 and arr[number].size()!=0){
                //     k--;
                //     ans.push_back(arr[number]);
                // }
            }
            number--;
        }
        return ans;

    }
};
