#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        seen = dict()


        for i in range(n):
            if nums[i] in seen:
                return [i, seen[nums[i]]]
            seen[target - nums[i]] = i
