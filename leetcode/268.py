#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        e_sum = (n * (n + 1)) // 2
        a_sum = sum(nums)

        return e_sum - a_sum



