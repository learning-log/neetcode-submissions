class Solution {
public:
    bool isIt(int arr[],int brr[]){
        for(int i=0;i<26;i++){
            if(arr[i]!=brr[i])
            return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int arr[26]={0};
        int arr1[26]={0};
        int st =0;
        for(;st<s1.length();st++){
            arr[s1[st]-'a']++;
            arr1[s2[st]-'a']++;
        }
        int matches =0;
        for(int i=0;i<26;i++){
            if(arr[i]==arr1[i]){
                matches++;
            }
        }
        int l = 0;
        while(st<s2.length()){
            if(matches==26){
                return true;
            }
            
            if(arr[s2[l]-'a']==arr1[s2[l]-'a']){
                matches--;
            }
            arr1[s2[l]-'a']--;
            if(arr[s2[l]-'a']==arr1[s2[l]-'a']){
                matches++;
            }
            l++;

            if(arr[s2[st]-'a']==arr1[s2[st]-'a']){
                matches--;
            }
            arr1[s2[st]-'a']++;
            if(arr[s2[st]-'a']==arr1[s2[st]-'a']){
                matches++;
            }
            st++;
        }
        if(matches==26){
            return true;
        }
        return false;

    }
};
