#
# @lc app=leetcode.cn id=146 lang=python3
#
# [146] LRU 缓存
#

# @lc code=start
class LinkedNode:
    def __init__(self, key=0, value=0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = dict()
        self.head = LinkedNode()
        self.tail = LinkedNode()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.capacity = capacity
        self.size = 0

    def moveToHead(self, node: LinkedNode):
        prevNode = node.prev
        nextNode = node.next
        prevNode.next = nextNode
        nextNode.prev = prevNode

        headNext = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next = headNext
        headNext.prev = node

    def addToHead(self, node: LinkedNode):
        headNext = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next = headNext
        headNext.prev = node

    def removeTail(self):
        tailPrev = self.tail.prev
        tailPrevPrev = self.tail.prev.prev
        tailPrevPrev.next = self.tail
        self.tail.prev = tailPrevPrev
        return tailPrev

    def get(self, key: int) -> int:
        if key in self.cache:
            curNode = self.cache[key]
            self.moveToHead(curNode)
            return curNode.value
        return -1

    def put(self, key: int, value: int) -> None:
        if self.get(key) != -1:
            self.cache[key].value = value
        else:
            newNode = LinkedNode(key, value)
            self.cache[key] = newNode
            self.addToHead(newNode)
            if self.size + 1 > self.capacity:
                removed = self.removeTail()
                self.cache.pop(removed.key)
            else:
                self.size += 1

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

