class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s)<=1:
            return len(s)
        st = 0
        en = 1
        ans = 1
        mp = {s[st]:1}
        while en<len(s):
            dv = mp.get(s[en],0)
            if dv!=1:
                ans = max(ans,en-st+1)
                mp[s[en]] = 1
            else:
                while st<en and mp[s[en]]==1:
                    cr = s[st]
                    mp[cr] = 0
                    st+=1
                mp[s[en]] = 1
            en+=1
        return ans


        