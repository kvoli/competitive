#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:

        n = len(nums)
        seen = set(nums)
        candidates = set([i for i in range(1, n+1)])

        return list(candidates.difference(seen))
