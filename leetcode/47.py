#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0

        local_max = nums[0]
        global_max = nums[0]

        # either take:
        #  a) nums[i]
        #  b) nums[i] + larray
        #  c) larry
        #  d) nothing

        for i in range(1, len(nums)):
            local_max = max(local_max + nums[i], nums[i])
            global_max = max(local_max, global_max)

        return global_max
