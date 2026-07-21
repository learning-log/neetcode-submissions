class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        uint32_t tp = 1;
        int i = 0;
        while(i<32){
            ans = (ans)*2 + (tp&n);
            n = n/2;
            i++;
        }
        return ans;
    }
};
