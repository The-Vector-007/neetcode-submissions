# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def __init__(self):
        self.ans = True

    def dfs(self, root):

        if root is None:
            return 0

        
        L = self.dfs(root.left)
        R = self.dfs(root.right)
        if abs(L - R) > 1:
            self.ans = False

        return 1 + max(L, R)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        if root is None:
            return True

        self.ans = True

        self.dfs(root)

        return self.ans

        