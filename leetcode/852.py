#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        ret = 0
        for i in range(len(arr)):
            if arr[ret] > arr[i]:
                return ret
            ret = i

