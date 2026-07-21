class Solution:
    def getmax(self, dictt):
        char = ""
        maxx = -1
        
        for k, v in dictt.items():
            if v>maxx:
                maxx = v
                char = k
        return char
    def characterReplacement(self, s: str, k: int) -> int:
        dictt = {}
        start = 0
        end = 1
        dictt[s[0]] = 1
        windowLen = 1
        kused = 0
        ans = 1
        while end<len(s):
            maxc = self.getmax(dictt)
            kused = windowLen - dictt[maxc]
            
            print(maxc, windowLen,dictt[maxc])
            while kused>k:
                rec = s[start]
                dictt[rec]-=1
                start+=1
                windowLen -=1
                newM = self.getmax(dictt)
                kused = windowLen - dictt[newM]
                # if rec==maxc:
            ans = max(windowLen,ans)
            dictt[s[end]] = dictt.get(s[end],0)+1
            end+=1
            windowLen+=1

        maxc = self.getmax(dictt)
        kused = windowLen - dictt[maxc]
        while kused>k:
            rec = s[start]
            dictt[rec]-=1
            start+=1
            windowLen -=1
            newM = self.getmax(dictt)
            kused = windowLen - dictt[newM]
        ans = max(windowLen,ans)
        return ans
        

                    
                




        