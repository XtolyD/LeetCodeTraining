#include <iostream>
#include <vector>

using namespace std;

/*
    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
    请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

class Solution
{
public:
    void moveZeroes(vector<int> &nums){
        int countZore = 0;
        for (int i = 0; i < nums.size() - countZore; i++){
            if (nums[i] == 0 && i + countZore < nums.size() - 1){
                nums[i] = nums[i + 1];
                countZore++;
                i -= 1;
            }
        }
        for (int i = nums.size() - countZore; i < nums.size(); i++){
            nums[i] = 0;
    }
};

# TODO unsolved
