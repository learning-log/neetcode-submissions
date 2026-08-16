from collections import deque

class Solution:

    def foreignDictionary(self, words: List[str]) -> str:
        
        graph = [[] for i in range(26)]
        inD = [-1]*26
        def createG(a,b):
            i=0
            j=0
            while i<len(a):
                if inD[ord(a[i]) - ord("a")] ==-1:
                    inD[ord(a[i]) - ord("a")] = 0
                i+=1
            while j<len(b):
                if inD[ord(b[j]) - ord("a")] ==-1:
                    inD[ord(b[j]) - ord("a")] = 0
                j+=1
            i=0
            j=0
            while i<len(a) and j<len(b):
                if a[i]!=b[j]:
                    graph[ord(a[i]) - ord("a")].append((ord(b[j])-ord("a")))
                    inD[ord(b[j])- ord("a")] +=1
                    break
                i+=1
                j+=1

            if i<len(a) and j==len(b):
                if inD[ord(a[i]) - ord("a")] ==-1:
                    inD[ord(a[i]) - ord("a")] = 0
                inD[ord(a[i]) - ord("a")] +=1
            return
        if len(words)==1:
            return words[0]
        if len(words)==0:
            return ""
        for i in range(len(words)-1):
            j = i+1
            createG(words[i],words[j])
        q = deque()

        for i in range(26):
            if inD[i]==0:
                q.append(i)
        ans = ""
        print((q))
        print(graph)
        print(inD)
        while len(q)!=0:
            print(q)
            # if len(q)!=1:
            #     return ""
            idx = q.popleft()
            inD[idx]-=1
            ans = ans+chr(ord("a")+idx)
            for n in graph[idx]:
                inD[n]-=1
                print(n)
                if inD[n]==0:
                    q.append(n)

        for i in range(26):
            if inD[i] > -1:
                return ""
        return ans

                        

