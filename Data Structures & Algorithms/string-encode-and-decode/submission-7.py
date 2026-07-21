class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs)==0:
            return "empty"
        return "556655".join(strs)

    def decode(self, s: str) -> List[str]:
        print(s)
        if s=="empty":
            return []
        ans = s.split("556655")
        
        # if len(ans)==1 and len(ans[0])==0:
        #     return []
        return ans
