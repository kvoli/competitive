#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:

        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val > l2.val:
            l2.next = mergeTwoLists(l1, l2.next)
            return l2
        else:
            l1.next = mergeTwoLists(l1.next, l2)
            return l1
        
