#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        d = set(wordDict)
        nd = set()

        def solve(st):
            if st in nd:
                return False
            if st in d:
                return True

            for word in d:
                if st.startswith(word):
                    if self.solve(st[:len(word)]):
                        return True
                    else:
                        nd.add(st[:len(word)])
            return False

        return solve(s)
