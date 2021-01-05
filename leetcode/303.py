#!/usr/bin/env python
# -*- coding: utf-8 -*-

class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.prefix_sum = nums
        for i in range(1, self.n):
            self.prefix_sum[i] = self.prefix_sum[i-1] + nums[i]


    def sumRange(self, i: int, j: int) -> int:
        # edge case i == 0
        if i == 0:
            return self.prefix_sum[j]
        return self.prefix_sum[j] - self.prefix_sum[i-1]
        

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
