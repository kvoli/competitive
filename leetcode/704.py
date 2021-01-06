#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def search(self, nums: List[int], target: int) -> int:

        n = len(nums)

        if n > 0:
            l = 0
            r = n - 1
            while l <= r:
                mid = l + (r - l) // 2
                
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    r = mid - 1
                else:
                    l = mid + 1

            return -1
