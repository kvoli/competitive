#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def solve(s, l, r):
            if len(s) == 2 * n:
                ans.append(s)
                return
            if l < n:
                solve(s+"(", l+1, r)
            if r < l:
                solve(s+")", l, r+1)

        solve("", 0, 0)
        return ans
