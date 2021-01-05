#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:

    def __init__(self):
        
        self.seen = set()

    def hasCycle(self, head: ListNode) -> bool:
        if not head:
            return False
        if head in self.seen:
            return True
        self.seen.add(head)
        return self.hasCycle(head.next)
