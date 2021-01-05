#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:

        def getNext(head, val):
            if not head:
                return None
            if head.val == val:
                return getNext(head.next, val)
            return head

        if not head:
            return None
        elif head.val == val:
            return self.removeElements(head.next, val)
        else:
            head.next = getNext(head.next, val)
            self.removeElements(head.next, val)
            return head
        
