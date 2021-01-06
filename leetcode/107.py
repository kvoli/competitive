#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import defaultdict

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        
        ret = defaultdict(list)
        
        def solve(root, depth):
            
            if root:
                ret[depth].append(root.val)
                return max(solve(root.left, depth + 1), solve(root.right, depth + 1)) + 1
            return 0
        
        dep = solve(root, 0)
        
        res = []
        
        for i in range(dep):
            res.append(ret[i])
            
        return res[::-1]
