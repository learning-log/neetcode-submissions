class DLNode:
    def __init__(self,val=None,key=None,next=None,prev=None):
        self.val = val
        self.key = key
        self.next = next
        self.prev = prev
class DL:
    def __init__(self,head=None,tail=None):
        self.head = None
        self.tail = self.head
        self.size = 0
    def delete(self,node:DLNode):
        if self.size == 1:
            self.head = None
            self.tail = None
        elif node == self.head:
            self.head = self.head.next
            self.head.prev = None
        elif node == self.tail:
            self.tail = self.tail.prev
            self.tail.next = None
        else:
            node.prev.next = node.next
            node.next.prev = node.prev
        self.size -=1
        return node
        # del node
    def insert(self, node):
        if self.head != None:
            node.next = self.head
            self.head.prev = node
            self.head = node
            self.head.prev = None
        else:
            self.head = node
            self.head.prev = None
            self.head.next = None
            self.tail = self.head
        self.size+=1
    def getHeadNode(self):
        return self.head
    def getTailNode(self):
        return self.tail
    def get_size(self):
        return self.size


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.dl = DL()
        self.mp = {}
        

    def get(self, key: int) -> int:
        if key not in self.mp:
            return -1
        value = self.mp[key].val
        self.put(key,value)
        return value

    def put(self, key: int, value: int) -> None:
        print("keys",key)
        if key not in self.mp:
            print(self.capacity,self.dl.get_size())
            if self.capacity>self.dl.get_size():
                node = DLNode(value,key)
                self.mp[key] = node
                self.dl.insert(node)

            else:
                print(key)
                dl_node = self.dl.delete(self.dl.getTailNode())
                node = DLNode(value,key)
                del self.mp[dl_node.key]
                self.mp[key] = node
                self.dl.insert(node)
        else:
            node = self.mp[key]
            node.val = value
            self.dl.delete(node)
            self.dl.insert(node)

        

        
