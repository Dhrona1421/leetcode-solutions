class Solution:
    def recoverTree(self, root):
        first = second = prev = None
        stack = []
        curr = root

        while stack or curr:
            while curr:
                stack.append(curr)
                curr = curr.left

            curr = stack.pop()

            if prev and prev.val > curr.val:
                if first is None:
                    first = prev
                second = curr

            prev = curr
            curr = curr.right

        first.val, second.val = second.val, first.val