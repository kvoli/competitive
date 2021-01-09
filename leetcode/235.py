#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

            
        if not root:
            return None

        pval = p.val
        qval = q.val
        tval = root.val

        if pval > tval and qval > tval:
            return self.lowestCommonAncestor(root.right, p, q)
        if pval < tval and qval < tval:
            return self.lowestCommonAncestor(root.left, p, q)
        return root

