#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // 思路暴力枚举
        int maxArea = 0;

        /* 超时
        for(int len = 1; len <= height.size(); len++){
            curHigh = 0; // 初始化当前底长下的高
            for(int i = 0; i + len < height.size(); i++){
                curHigh = max(curHigh, min(height[i], height[i + len]));
            }
            maxArea = max(maxArea, len*curHigh);
        } */

        // 思路2
        // 两边向内移动
        // 永远短板向内靠近1
        int i = 0, j = height.size() - 1;
        while(i != j)
        {
            int curArea = min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, curArea);
            if (height[i] > height[j])
                // 左板大于右板
                j--;
            else
                // 左板小于右板
                i++;
        }

        return maxArea;
    }
};