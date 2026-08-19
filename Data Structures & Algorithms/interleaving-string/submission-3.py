class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1)+len(s2)!=len(s3):
            return False
        def req(i,j,dp):
            if i==len(s1) and j==len(s2):
                return True
            pos = i+j
            if dp[i][j]!=-1:
                return dp[i][j]
            if i<len(s1) and j<len(s2):
                if s1[i]==s3[pos] and s2[j]==s3[pos]:
                    dp[i][j] = req(i+1,j,dp) or req(i,j+1,dp)
                    return dp[i][j]
                elif s1[i]==s3[pos]:
                    dp[i][j] = req(i+1,j,dp)
                    return dp[i][j]
                elif s2[j] == s3[pos]:
                    dp[i][j] = req(i,j+1,dp)
                    return dp[i][j]
                else:
                    dp[i][j] = False
                    return dp[i][j]
            
            elif i<len(s1):
                if s1[i]==s3[pos]:
                    dp[i][j] = req(i+1,j,dp)
                    return dp[i][j]
                else:
                    dp[i][j] = False
                    return dp[i][j]
            else:
                if s2[j]==s3[pos]:
                    dp[i][j] = req(i,j+1,dp)
                    return dp[i][j]
                else:
                    dp[i][j] = False
                    return dp[i][j]
        dp = [[-1]*(len(s2)+1) for i in range(len(s1)+1)]
        return req(0,0,dp)


