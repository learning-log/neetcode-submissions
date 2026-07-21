class Solution:
    def check(self,dictt):
        for k, v in dictt.items():
            if v!=0:
                return False
        return True
    def checkInclusion(self, s1: str, s2: str) -> bool:
        dictt = {}
        start = 0
        end = 0

        while end<len(s1):
            dictt[s1[end]] = dictt.get(s1[end],0)+1
            end+=1
        end = 0

        while end<len(s2):
            
            if (s2[end] not in dictt.keys()):
                # if start == end:
                while start<end:
                    dictt[s2[start]] += 1
                    start += 1
                end += 1
                start = end
                continue
            elif dictt[s2[end]]==0:
                while dictt[s2[end]]==0:
                    dictt[s2[start]] += 1
                    start += 1
        
            if dictt[s2[end]]!=1:
                dictt[s2[end]]-=1

            else:
                dictt[s2[end]]-=1
                if self.check(dictt):
                    return True
            end+=1
            print(dictt)
        return False

        