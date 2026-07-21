from collections import deque
class MinStack:

    def __init__(self):
        self.mS = deque()
        self.S = deque()

    def push(self, val: int) -> None:
        if len(self.mS)==0 or self.mS[-1]>=val:
            self.mS.append(val)
        self.S.append(val)

        

    def pop(self) -> None:
        if self.mS[-1]==self.S[-1]:
            self.mS.pop()
        self.S.pop()
        

    def top(self) -> int:
        return self.S[-1]

    def getMin(self) -> int:
        return self.mS[-1]
        
