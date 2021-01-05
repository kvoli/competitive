#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        diff = 0
        left = prices[0]

        for i in range(1, len(prices)):
            cur = prices[i]
            if cur < left:
                left = cur
            diff = max(diff, cur - left)

        return diff
                





        
