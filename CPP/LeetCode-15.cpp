#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // 暴力循环（超时）
        /*
        int mid = 1, len = nums.size();
        while(mid != len - 2){
            for(int i = mid - 1; i >= 0; i--){
                for(int j = mid + 1; j <= len - 1; j++){
                    if(!(nums[mid] + nums[i] + nums[j])){
                        vector<int> temp = {i, mid, j};
                        res.push_back(temp);
                    }
                }
            }
        }
        */

        sort(nums.begin(),nums.end());
        int n = nums.size(), left, right, sum;

        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums [i - 1]){
                // 如果i与上一个数字相同，则跳过
                continue;
            }

            // 初始化左右指针
            left = i + 1;
            right = n - 1;
            
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];

                if(sum < 0) // 和小了，要调大
                    left++;
                else if(sum > 0) // 和大了，要调小
                    right--;
                else{   // 和等于0，加入结果
                    res.push_back((vector<int>){nums[left],nums[i],nums[right]});
                    
                    // 避免重复的左指针元素
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // 避免重复的右指针元素
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    left++; // 左指针右移一位
                    right--; // 右指针左移一位
                }
            }
        }
        return res;
    }
};

int main(){
    return 0;
}