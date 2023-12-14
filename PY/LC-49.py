# 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
# 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

from typing import List

class Solution:

    ch_dict = { 
        # key: ch, value: ch_value
        "a": 2, "b": 3, "c": 5, "d": 7, "e": 11, "f": 13, "g": 17, 
        "h":19, "i": 23, "j": 29, "k": 31, "l": 37, "m": 41, "n": 43, 
        "o": 47, "p": 53, "q": 59, "r": 61, "s": 67, "t": 71, 
        "u": 73, "v": 79, "w": 83, "x": 89, "y": 97, "z": 101
    }

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res_dict = {} # key: str_value, value: str_item
        for str_item in strs:
            str_value = 1
            for ch in str_item:
                str_value *= self.ch_dict[ch]  # Fixed the issue by referencing self.ch_dict
            if str_value in res_dict:
                res_dict[str_value].append(str_item)
            else:
                res_dict[str_value] = [str_item]
        return list(res_dict.values())

if __name__ == '__main__':
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    solution = Solution()
    print(solution.groupAnagrams(strs))  # [["bat"],["nat","tan"],["ate","eat","tea"]]