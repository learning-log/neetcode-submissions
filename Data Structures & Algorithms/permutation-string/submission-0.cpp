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
        if(isIt(arr,arr1))
        return true;
        int l = 0;
        while(st<s2.length()){
            arr1[s2[l]-'a']--;
            l++;
            arr1[s2[st]-'a']++;
            if(isIt(arr,arr1)){
                return true;
            }
            st++;
        }
        return false;



    }
};
