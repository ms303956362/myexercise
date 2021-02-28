class ListNode:
    def __init__(self, v, succ=None, prev=None):
        self.v = v
        self.succ = succ
        self.prev = prev

class List:
    def __init__(self):
        self.dummy = ListNode(-1)
        self.tail = self.dummy

    def append(self, v):
        self.tail.succ = ListNode(v, None, self.tail)
        self.tail = self.tail.succ
    
    def pophead(self):
        return self.remove(self.dummy.succ)
    
    def remove(self, p):
        p.prev.succ = p.succ
        p.succ.prev = p.prev
        return p.v

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.l = List()
        self.d = {}

    def get(self, key: int) -> int:
        if key in self.d:
            _, value = self.l.remove(self.d[key])
            self.l.append((key, value))
            return value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.d:
            self.l.remove(self.d[key])
        else:
            if len(self.d) >= self.cap:
                k, v = self.l.pophead()
                self.d.pop(k)
        self.l.append((key, value))
        self.d[key] = self.l.tail


# Your LRUCache object will be instantiated and called as such:
obj = LRUCache(1)
obj.put(2, 1)
param_1 = obj.get(2)
