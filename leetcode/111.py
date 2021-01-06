#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:

        def solve(root, depth):
            
            if not root:
                return 0

            if not root.left and not root.right:
                return depth
            
            if not root.left:
                return solve(root.right, depth + 1)
            
            if not root.right:
                return solve(root.left, depth + 1)

            return min(solve(root.left, depth + 1), solve(root.right, depth + 1))

        
        return solve(root, 1)
