#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        
        q, res = deque([(root, 0)]), []

        while q:
            node, level = q.popleft()
            if node:
                if len(res) < level + 1:
                    res.insert(0, [])
                res[-(level+1)].append(node.val)
                q.append((node.left, level+1))
                q.append((node.right, level+1))
        return list(map(lambda x: sum(x) / len(x), res))[::-1]
