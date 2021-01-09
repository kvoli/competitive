#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:

        def get(string)
            ret = ""
            for letter in string:
                if letter == "#":
                    ret = ret[:-1]
                else:
                    ret += letter 
            return ret

        
        return get(S) == get(T)
