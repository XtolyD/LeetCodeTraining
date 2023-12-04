#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

/*
    给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
    字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
*/

class Solution
{
public:
    unordered_map<char, int> chr_mp = {
        {'a', 2}, {'b', 3}, {'c', 5}, {'d', 7}, {'e', 11}, {'f', 13}, {'g', 17}, {'h', 19}, {'i', 23}, {'j', 29}, {'k', 31}, {'l', 37}, {'m', 41}, {'n', 43}, {'o', 47}, {'p', 53}, {'q', 59}, {'r', 61}, {'s', 67}, {'t', 71}, {'u', 73}, {'v', 79}, {'w', 83}, {'x', 89}, {'y', 97}, {'z', 101}};

    long int get_Key(string s)
    {
        long int Key = 1;
        for (int i = 0; i < s.size(); i++)
        {
            Key *= chr_mp[s[i]]; // 乘法防止重复
            Key %= 1000000007;   // 防止溢出

            // Key %= (int)(1e9 + 7);   // 防止溢出
        }
        return Key;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<long int, int> mp_idx; // 存储Key值和对应的下标, (Key, idx)
        for (int i = 0; i < strs.size(); i++)
        {
            // 遍历每个字符串，计算其Key值
            long int Key = get_Key(strs[i]);
            // 如果Key值不存在，就新建一个vector
            if (mp_idx.count(Key) == 0)
            {
                // 存储Key值和对应的下标
                mp_idx[Key] = res.size();   // 该Key值对应的下标为res的长度
                res.push_back(vector<string>{strs[i]});  // 将该字符串添加到res中
            }
            // 如果Key值存在，就直接添加
            else
                res[mp_idx[Key]].push_back(strs[i]);
        }
        return res;
    }
};

int main()
{
    return 0;
}