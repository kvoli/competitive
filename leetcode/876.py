#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def middleNode(self, head: ListNode) -> ListNode:
        l = head
        r = head

        n = 0
        while r:
            r = r.next
            n += 1

        n = n // 2
        while n > 0:
            l = l.next
            n -= 1 

        return l
            
        
