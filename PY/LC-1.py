# -*- coding:utf-8 -*-

from typing import List

# 给定一个整数数组 nums 和一个整数目标值 target，
# 请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

# 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

# 你可以按任意顺序返回答案。

# 1. Two Sum
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        val_dict = {}  # key: num_value, value: num_index
        for num_index, num_value in enumerate(nums):
            if target - num_value in val_dict:
                return [val_dict[target - num_value], num_index]
            val_dict[num_value] = num_index
        return []


if __name__ == '__main__':
    nums = [3,3]
    target = 6
    solution = Solution()
    print(solution.twoSum(nums, target))  # [0, 1]