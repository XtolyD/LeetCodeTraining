#include <iostream>
#include <vector>

using namespace std;

/*
    给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
    请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

// 内存换时间
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int maxLen = 0;            // 初始化结果
        int curLen = 0;            // 当前长度
        int* arr = new int[2000000007];
        for (int i = 0; i < 2000000007; i++)
            arr[i] = 0;
        int len = nums.size();     // 数组长度
        for (int i = 0; i < len; i++)
            arr[nums[i] + 1000000000]++; // 防止负数
        for (int i = 0; i < 2000000007; i++)
        {
            if (arr[i] != 0)
                curLen++;
            else
            {
                maxLen = maxLen > curLen ? maxLen : curLen;
                curLen = 0;
            }
        }
        return maxLen;
    }
};

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution s;
    cout << s.longestConsecutive(nums) << endl;
}

