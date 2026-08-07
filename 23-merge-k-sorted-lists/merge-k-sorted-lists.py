import heapq

class Solution:
    def mergeKLists(self, lists):
        h = []
        for i, node in enumerate(lists):
            if node:
                heapq.heappush(h, (node.val, i, node))

        dummy = ListNode(0)
        cur = dummy

        while h:
            _, i, node = heapq.heappop(h)
            cur.next = node
            cur = node
            if node.next:
                heapq.heappush(h, (node.next.val, i, node.next))

        return dummy.next