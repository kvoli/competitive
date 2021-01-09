#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:

        def solve(root):

            if not root:
                return 0, 0

            ldep, lbest = solve(root.left)
            rdep, rbest = solve(root.right)

            return max(ldep, rdep) + 1, max(lbest, rbest, ldep + rdep)

        return solve(root)[1]




