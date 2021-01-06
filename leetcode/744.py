#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        index = bisect.bisect(letters, target)
        return letters[index % len(letters)]
