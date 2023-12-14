#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

/*
    给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
    请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/


class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        int maxLen = 0;            // 初始化结果
        int curLen = 0;            // 当前长度
        /*  方法一 内存换时间
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
        */


        // 用哈希表存储每个端点值对应连续区间的长度
        // 若数已在哈希表中：跳过不做处理
        // 若是新数加入：
        // 取出其左右相邻数已有的连续区间长度 left 和 right
        // 计算当前数的区间长度为：cur_length = left + right + 1
        // 根据 cur_length 更新最大长度 max_length 的值
        unordered_map<int, int> mp;
        for (int num : nums)
        {
            // 如果num已经存在，就跳过
            if (mp.count(num)) continue;
            
            // 如果num不存在，就计算其左右相邻数已有的连续区间长度 left 和 right
            int left = 0;
            if(mp.count(num - 1))   // 如果num-1存在，就取出其连续区间长度
                left = mp[num - 1];
            
            int right = 0;
            if(mp.count(num + 1))   // 如果num+1存在，就取出其连续区间长度
                right = mp[num + 1];

            // 计算当前数的区间长度为：cur_length = left + right + 1
            curLen = left + right + 1;
            
            // 根据 cur_length 更新最大长度 max_length 的值
            maxLen = maxLen > curLen ? maxLen : curLen;
            
            // 更新num的左右端点的长度
            mp[num - left] = curLen;    // num-left是左端点
            mp[num + right] = curLen;   // num+right是右端点
            mp[num] = curLen;           // 当前数也要更新，防止重复计算
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

