class Solution:
    def countSubstrings(self, s: str) -> int:
        
        def req(s,i,j):
            if i>j:
                return True
            # if i==len(s) or j==len(r):
            #     return True
            if dp[i][j] != -1:
                return dp[i][j]
            if s[i] == s[j]:
                dp[i][j] = req(s,i+1,j-1)
                return dp[i][j]
            else:
                dp[i][j] = False
                return dp[i][j]

        dp = [[-1]*len(s) for i in range(len(s))]
        ansLen = 0 
        for i in range(len(s)):
            for j in range(i,len(s)):
                dp[i][j] = req(s,i,j)
        # print(dp)
        ans = 0
        for i in range(len(s)):
            for j in range(i,len(s)):
                if dp[i][j]:
                    ans = ans+1
                    # ansLen = (j-i+1)
        return ans
