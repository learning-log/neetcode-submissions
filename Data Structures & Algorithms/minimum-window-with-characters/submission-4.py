class Solution:    
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
        lent = len(tdictt)
        lenb = 0

        while end<len(s):
            curr = s[end]
            if curr in tdictt.keys():
                bdictt[curr] = bdictt.get(curr,0) +1
                if bdictt[curr]==tdictt[curr]:
                    lenb += 1
            else:
                if start==end:
                    start+=1
            while start < end and (s[start] not in tdictt.keys() or bdictt[s[start]]>tdictt[s[start]]):
                if s[start] not in tdictt.keys():
                    start +=1
                else:
                    bdictt[s[start]]-=1 
                    start+=1
            if lenb==lent:
                ansF = True
                if ansLen>(end - start +1 ):
                    ansstart = start
                    ansend = end
                    ansLen = end - start +1
            end +=1
        
        return s[ansstart:ansend+1] if ansF else ""
            
        

        