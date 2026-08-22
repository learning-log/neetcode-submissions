class Solution:
    def checkValidString(self, s: str) -> bool:
        st = []
        st2 = []
        lmin = 0
        lmax = 0
        rmin = 0
        rmax = 0
        for v in s:
            if v == "(":
                lmin += 1 
                lmax += 1 
            elif v == "*":
                lmax = lmax+1
                lmin = lmin-1
            else:
                # if lmin==0:
                #     if lmax!=0:
                #         lmax -= 1
                #         rmax -= 1
                #     else:
                #          return False
                # else:
                lmin-=1
                lmax-=1
            if lmax<0:
                return False
            if lmin<0:
                lmin = 0

        # while lmin>0:
        #     if rmax<=0:
        #         return False
        #     lmin-=1
        #     rmax -=1

        return True if lmin == 0 else False