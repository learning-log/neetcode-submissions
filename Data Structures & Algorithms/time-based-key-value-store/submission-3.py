class TimeMap:

    def __init__(self):
        self.storage = {}

        
    def getMin(sefl,arr,target_t):
        start = 0
        end = len(arr)-1
        ans = -1
        while start<=end:
            mid = (start+end)//2
            # print(mid)
            if arr[mid][0] <= target_t:
                print(mid)
                start = mid+1
                ans = mid
                # return arr[mid][1]
            elif arr[mid][0]>target_t:
                end = mid-1
            # else:

        print("*************",arr[ans][1])      
        
        if ans == -1:
            return ""
        else:
            return arr[ans][1]

    def set(self, key: str, value: str, timestamp: int) -> None:
        prev_values = self.storage.get(key,[])
        prev_values.append([timestamp,value])
        self.storage[key] = prev_values

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.storage:
            return ""
        else:
            return self.getMin(self.storage[key],timestamp)
        
        
