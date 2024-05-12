from typing import List

# # 全排列方法将超出内存限制
# class Solution:
#     def findSubstring(self, s: str, words: List[str]) -> List[int]:
#         from itertools import permutations
#         words = list(set(permutations(words)))   # 生成器转换为列表
#         # 用于存放结果
#         res = []
#         # 遍历全排列
#         for word in words:
#             # 记录单词组在s中的位置
#             word = "".join(word)
#             idx = s.find(word)
#             # 如果找到了，记录位置
#             while idx != -1:
#                 res.append(idx)
#                 idx = s.find(word, idx + 1)
#         return res


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []  # s或者words为空，返回空列表

        s_len, word_num, word_len = len(s), len(words), len(words[0])  # s的长度，word的长度

        from collections import Counter

        words = Counter(words)  # 统计words中每个单词出现的次数，用于后续比较
        res = []  # 用于存放结果

        for start_idx in range(word_len):  # 起始位置 为 0 ~ word_len - 1

            # 从start_idx开始，每次跳word_len个位置
            for left in range(start_idx, s_len, word_len):
                right = left + word_num * word_len  # right为left的右边界

                if right > s_len:  # 如果right超出s的长度，结束循环
                    break

                cur_str = s[left:right]  # 当前字符串

                cur_words, cur_idx = Counter(), 0  # 当前单词组，单词的索引

                while cur_idx < word_num:  # 遍历单词
                    word = cur_str[cur_idx * word_len : (cur_idx + 1) * word_len]
                    cur_idx += 1  # 索引加1

                    # 如果单词不在words字典中，结束循环
                    if word not in words:
                        break

                    cur_words[word] += 1  # 记录单词出现的次数

                    # 如果单词出现的次数超过words中的次数，结束循环
                    if cur_words[word] > words[word]:
                        break

                    # 如果所有单词都出现了，记录位置
                    if cur_idx == word_num:
                        res.append(left)

        return res


if __name__ == "__main__":
    s = "barfoothefoobarman"
    words = ["foo", "bar"]
    solution = Solution()
    print(solution.findSubstring(s, words))
