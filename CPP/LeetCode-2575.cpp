#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int nums = word.length();
        long long cur = 0;
        vector<int> res;
        for(int i = 0; i < nums; i++){
            cur = (cur * 10 + (word[i] - '0')) % m;
            res.push_back(cur % m ==0);
        }
        return res;
    }
};