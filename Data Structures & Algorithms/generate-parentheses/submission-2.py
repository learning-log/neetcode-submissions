class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def req(i,j,st):

            if i==0 and j==0:
                ans.append(st)
                return
            
            if i==j:
                req(i-1,j,st+"(")
            
            else:
                if i>0:
                    req(i-1,j,st+"(")
                req(i,j-1,st+")")
        i = n
        j = n
        req(i,j,"")
        return ans

