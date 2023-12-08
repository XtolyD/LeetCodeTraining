#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1. 暴力法
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};

        // 2. 哈希表
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            if(hash.count(target - nums[i])){
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum(nums, target);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}