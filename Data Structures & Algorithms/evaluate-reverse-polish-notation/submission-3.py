class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        ans = 0
        for k in tokens:
            if k=="+":
                a = st.pop()
                b= st.pop()

                ans = a+b
                st.append(ans)
                # st.append(ans)
            elif k=="-":
                a = st.pop()
                b= st.pop()

                ans = b-a
                st.append(ans)
            elif k=="*":
                a = st.pop()
                b= st.pop()

                ans = a*b
                st.append(ans)

            elif k=="/":
                a = st.pop()
                b= st.pop()

                ans = int(b/a)
                st.append(ans)
            else:
                print(int(k))
                st.append(int(k))
            print(st)
        return st[0]

        
        