class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // int arr[26]={0};
        unordered_map<char,int>arr;
        int st =0;
        int curr = 0;
        int ans = 0;
        while(curr<s.length()){
            while(curr<s.length() and (arr.find(s[curr])==arr.end() or arr[s[curr]]==0)){
                arr[s[curr]] = 1;
                curr++;
            }
            ans = max(ans,curr-st);

            while(curr<s.length() and st<curr and arr[s[curr]]!=0){
                arr[s[st]] = 0;
                st++;
            }
        }

        return ans;
    }
};
