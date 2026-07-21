class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.replace(" ","")
        newstr = ""
        for c in s:
            if c.isalnum():
                newstr += c.lower()
        print(newstr)
        return newstr == newstr[::-1] 
        