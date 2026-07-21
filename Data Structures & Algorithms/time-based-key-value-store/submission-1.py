class TimeMap:

    def __init__(self):
        self.dictt = {}

    def getIndex(self, ts,key):
        start = 0
        end = len(self.dictt[key])-1
        ans = -1
        keysarr = list(self.dictt[key].keys())
        while start <=end:
            mid = (start+end)//2
            if keysarr[mid]<=ts:
                ans = max(ans,keysarr[mid])
                start = mid+1
            else:
                end = mid - 1
        return ans

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.dictt.keys():
            self.dictt[key][timestamp] = value
        else:
            self.dictt[key] = {}
            self.dictt[key][timestamp] = value

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.dictt.keys():
            return ""
        else: 
            indx = self.getIndex(timestamp,key)
            if indx == -1:
                return ""
            else:
                return self.dictt[key][indx]

        
