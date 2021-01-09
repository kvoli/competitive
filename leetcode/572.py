#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:

        def equals(l, r):
            if not l and not r:
                return True
            if not l or not r:
                return False
            return s.val == t.val and equals(l.left, r.left) and equals(l.right, r.right)
            

        return s and (equals(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t))



