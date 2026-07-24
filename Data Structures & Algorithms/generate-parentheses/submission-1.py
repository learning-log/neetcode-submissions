class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        def req(l,r,curr):

            if l==0 and r==0:
                ans.append(curr)
                return
            if l<0 or r<0:
                return
            if l==r:
                # curr = curr+"("
                req(l-1,r,curr+"(")
            
            else:
                req(l-1,r,curr+"(")
                req(l,r-1,curr+")")


        ans = []
        curr = ""
        l = n
        r = n
        req(l,r,curr)
        return ans
