from typing import List

# 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res_list, s_len, p_len = [], len(s), len(p) # 获取两个字符串长度
        
        if s_len < p_len: 
            return res_list # 如果s的长度小于p的长度，直接返回空列表
        
        p_count, s_count = [0] * 26, [0] * 26 # 初始化两个长度为26的列表

        for i in range(p_len): # 遍历p字符串
            # ord() 函数是 chr() 函数（对于8位的ASCII字符串）的配对函数，它以一个字符串（Unicode 字符）作为参数，
            # 返回对应的 ASCII 数值，或者 Unicode 数值。
            p_count[ord(p[i]) - ord('a')] += 1   # 统计p字符串中每个字符出现的次数
            s_count[ord(s[i]) - ord('a')] += 1   # 统计s字符串中每个字符出现的次数
        
        if p_count == s_count: # 如果p字符串和s字符串的前p_len个字符的统计结果相同
            res_list.append(0)
        
        for i in range(1, s_len - p_len + 1):
            s_count[ord(s[i - 1]) - ord('a')] -= 1
            s_count[ord(s[i + p_len - 1]) - ord('a')] += 1
            if p_count == s_count:
                res_list.append(i)

        return res_list

    

if __name__ == '__main__':
    s = "cbaebabacd"
    p = "abc"
    solution = Solution()
    print(solution.findAnagrams(s, p)) # [0, 6]
    
    s = "abab"
    p = "ab"
    print(solution.findAnagrams(s, p)) # [0, 1, 2]