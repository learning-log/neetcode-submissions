class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st = []
        ans = [0]*len(temperatures)
        i=len(temperatures)-1
        while i>=0:
            while len(st)!=0 and temperatures[i]>=temperatures[st[-1]]:
                st.pop()
            if len(st)==0:
                ans[i] = 0
            else:
                ans[i] = (st[-1]-i)
            
            st.append(i)
            i-=1

        return ans

            