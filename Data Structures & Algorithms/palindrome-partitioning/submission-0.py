class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPal(st,end,a):
            while end>=st:
                if a[st]!=a[end]:
                    return False
                end-=1
                st+=1
            return True
        ans = []
        curr = []
        st = 0
        end = 0
        def req(st,end,s,curr):
            if end==len(s):
                if st==end:
                    ans.append(curr.copy())
                return 
            if isPal(st,end,s):
                req(st,end+1,s,curr)
                curr.append(s[st:end+1])
                req(end+1,end+1,s,curr)
                curr.pop()
            else:
                req(st,end+1,s,curr)
        req(0,0,s,curr)
        return ans

            
            