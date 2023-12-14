#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            //循环条件：lookup中找得到下一元素s[i]
            //.find在找不到下一元素的情况下返回.end()
            while (lookup.find(s[i]) != lookup.end()){
                //删除左元素，左指针右移1
                lookup.erase(s[left]);
                left ++;
                //直至lookup中找不到下一元素
                //即lookup.find(s[i]) == lookup.end()
                //终止循环
            }
            //更新最长字串大小
            maxStr = max(maxStr,i-left+1);
            //插入下一个元素
            lookup.insert(s[i]);
        }
        return maxStr;
    }
};
