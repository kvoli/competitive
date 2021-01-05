#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:

        
        def solve(head):
            if head:
                ret = solve(head.next)
                ret.append(head.val)
                return ret
            else:
                return []


        ret = solve(head)
        n = len(ret)
        
        for i in range(n):
            if ret[i] != ret[n-i-1]:
                return False
        return True
