class Solution:
    def rowWiseCheck(self, board) -> bool:
        rowWise = True
        for i in range(len(board)):
            dictt = {}
            for j in range(len(board[0])):
                num = board[i][j]
                if num !="." and num in dictt.keys():
                    rowWise = False
                    return rowWise
                dictt[num] = 1
        return rowWise
    def columnWiseCheck(self, board) -> bool:
        columnWise = True
        for i in range(len(board[0])):
            dictt = {}
            for j in range(len(board)):
                num = board[j][i]
                if num !="." and num in dictt.keys():
                    columnWise = False
                    return columnWise
                dictt[num] = 1
        return columnWise

    def blockWiseCheck(self, board) -> bool:
        bloack = True
        # bnum = 0
        for bnum in range(9):
            basei = int(bnum/3)
            basej = int(bnum%3)
            dictt = {}
            for i in range(3):
                for j in range(3):
                    aci = basei*3 + i
                    acj = basej*3 + j
                    num = board[aci][acj]
                    if num !="." and num in dictt.keys():
                        bloack = False
                        return bloack
                    dictt[num] = 1
            # bnum+=1
        return bloack



    def isValidSudoku(self, board: List[List[str]]) -> bool:
        blockWise = self.blockWiseCheck(board)
        rowWise = self.rowWiseCheck(board)
        columnWise = self.columnWiseCheck(board)

        return blockWise and rowWise and columnWise
    
    

        