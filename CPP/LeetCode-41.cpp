// leetcode-42 接雨水

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int nums = height.size(); //  数组长度
        int left = 0, right = nums -1;
        int sum = 0;
        int left_max = 0, right_max = 0;
        while(left < right){
            // 从两边向中间维护
        }

        return sum;
    }
};
