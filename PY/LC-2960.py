from typing import List

class Solution:
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        global_count  = 0 # 用于记录测试次数
        for item in batteryPercentages:
            if item - global_count > 0:
                global_count += 1
        return global_count

if __name__ == '__main__':
    batteryPercentages = [5, 10, 15, 20, 25]
    solution = Solution()
    print(solution.countTestedDevices(batteryPercentages)) # 5