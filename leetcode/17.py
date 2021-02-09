#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
       phone = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}
       if not digits:
           return []
       possible = phone[digits[0]]
       if len(digits) == 1:
           return possible
        

       old_ret = self.letterCombinations(digits[1:])
       ret = []

       for s in old_ret:
           for letter in possible:
                ret.append(letter + s)

       return ret

        


        

        
        
