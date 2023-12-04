#include <iostream>
#include <vector>
using namespace std;
/*
    几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。
    每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。
    你的点数就是你拿到手中的所有卡牌的点数之和。
    给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。
*/

// 滑动窗口
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];   // 取前k张牌
        }

        int maxSum = sum;
        for (int i = 0; i < k; i++) {
            // 从前往后取一张牌，从后往前去一张牌
            sum = sum - cardPoints[k - i - 1] + cardPoints[n - i - 1];
            maxSum = max(maxSum, sum);  // 更新最大值
        }
        return maxSum;
    }
};

int main()
{
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    Solution s;
    cout << s.maxScore(cardPoints, k) << endl;
}