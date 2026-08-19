class Solution:
    def numDecodings(self, s: str) -> int:
        ans = []
        def req(s,i):
            if i == len(s):
                # ans.append(curr)
                return 1
            if s[i] == "0":
                return 0
            if dp[i]!=-1:
                return dp[i]
            lans = 0
            for j in range(i,len(s)):
                number = int(s[i:j+1])

                if number<=26:
                    # ch = chr(ord("A")+number-1)
                    lans += req(s,j+1)
                else:
                    break
            dp[i] = lans
            return lans
        dp = [-1]*len(s)

        return req(s,0)


            