# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp; vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count( target - nums[i])){
                res.push_back(i) ;      //  加入当前index
                res.push_back(mp[target-nums[i]]); // 加入被找到数index
                break;
            }
            else{
                mp[nums[i]] = i ;
            }
        }
        return res;
    }
};

