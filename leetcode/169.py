#!/usr/bin/env python
# -*- coding: utf-8 -*-

from collections import Counter

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        

        counter = Counter(nums)


        return counter.most_common()

