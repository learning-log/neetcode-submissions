class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint32_t tp = 1;
        while(n){
            ans+=(tp & n);
            n = n/2;
        }
        return ans;
    }
};
