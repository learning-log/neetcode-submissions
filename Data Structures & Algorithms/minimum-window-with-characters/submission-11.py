class Solution:
    def getCount(self,st):
        n_dict = {}
        for k in st:
            prev_count = n_dict.get(k,0)
            n_dict[k] = prev_count+1
        return n_dict 
    def minWindow(self, s: str, t: str) -> str:
        ans =""
        if len(t)==0 or len(s)==0:
            return ans
        t_dict  = self.getCount(t)
        s_dict = {}
        done = 0
        t_done = len(t)
        start = 0
        end = 0
        ans_s = 0
        ans_en = -1
        ans_l = len(s)
        while end<len(s):
            k = s[end]
            if start == end and k not in t_dict:
                start +=1
            elif k in t_dict:
                prev_count = s_dict.get(k,0)
                if prev_count < t_dict[k]:
                    s_dict[k] = prev_count + 1
                    done += 1
                elif prev_count >= t_dict[k]:
                    if k == s[start]:
                        start += 1
                        while start < end and (s[start] not in t_dict or (s_dict[s[start]] > t_dict[s[start]])):
                            if s[start] in t_dict:
                                s_dict[s[start]]-=1
                            start += 1
                    else:
                        s_dict[k] = prev_count+1
            if done == t_done:
                print(ans_l,(end - start+1))
                if ans_l >= (end - start+1):
                    ans_s = start
                    ans_en = end
                    ans_l = (end - start+1)
            end +=1
        return s[ans_s:ans_en+1]







