class Solution:
    def check(self,tdictt, bdictt):
        for k,v in tdictt.items(): 
            vv = bdictt.get(k,0)
            if v>vv:
                return False
        return True       

    def minWindow(self, s: str, t: str) -> str:
        # def checkInclusion(self, s1: str, s2: str) -> bool:
        tdictt = {}
        start = 0
        end = 0
        ansLen = 10000
        ansstart = 0
        ansend = 0
        ansF = False

        while end<len(t):
            tdictt[t[end]] = tdictt.get(t[end],0)+1
            end+=1

        end=0
        bdictt = {}

        while end<len(s):
            curr = s[end]
            if curr in tdictt.keys():
                bdictt[curr] = bdictt.get(curr,0) +1
            else:
                if start==end:
                    start+=1
                else:
                    bdictt[curr] = bdictt.get(curr,0) +1
            while start < end and (s[start] not in tdictt.keys() or bdictt[s[start]]>tdictt[s[start]]):
                
                bdictt[s[start]]-=1
                start+=1
            if self.check(tdictt,bdictt):
                ansF = True
                if ansLen>(end - start +1 ):
                    ansstart = start
                    ansend = end
                    ansLen = end - start +1
            end +=1
        
        return s[ansstart:ansend+1] if ansF else ""
            
        

        