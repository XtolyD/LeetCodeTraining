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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 对数组进行排序，以便后续操作
        vector<vector<int>> answer; // 存储结果的二维向量
        
        for (int i = 0; i < n - 2; i++) { // 遍历数组，固定第一个元素
            // 避免重复的固定元素
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1; // 左指针指向固定元素的下一位
            int right = n - 1; // 右指针指向数组末尾
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right]; // 计算三个元素的和

                if (sum < 0) { // 如果和小于零，说明需要增大和，左指针右移一位
                    left++;
                }
                else if (sum > 0) { // 如果和大于零，说明需要减小和，右指针左移一位
                    right--;
                }
                else { // 和等于零，找到满足条件的三元组
                    answer.push_back({nums[i], nums[left], nums[right]}); // 将三元组添加到结果中
                    
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
        return answer;
    }
};