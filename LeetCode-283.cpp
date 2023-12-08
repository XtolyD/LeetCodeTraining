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
            if (nums[i] == 0){  // 当找到0时候
                countZore++;    // 0计数器加1
                // 删除当前位置的0
                nums.erase(nums.begin() + i);
                // 因为删除了一个元素，所以i要减1
                i--;
                // 在数组末尾添加0
                nums.push_back(0);
            }
        }
    }
};

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution solution;
    solution.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}