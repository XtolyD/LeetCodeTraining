


class Solution(object):
    
    def __init__(self) -> None:
        self.ch_map = {
            1000: 'M',
            900: 'CM',
            500: 'D',
            400: 'CD',
            100: 'C',
            90: 'XC',
            50: 'L',
            40: 'XL',
            10: 'X',
            9: 'IX',
            5: 'V',
            4: 'IV',
            1: 'I'
        }
    
    def intToRoman(self, num: int) -> str:
        res = ''
        for k, v in self.ch_map.items():
            while num >= k:
                res += v
                num -= k
        return res

if __name__ == "__main__":
    s = Solution()
    print(s.intToRoman(3)) # "III"
    print(s.intToRoman(4)) # "IV"
    print(s.intToRoman(9)) # "IX"
    print(s.intToRoman(58)) # "LVIII"
    print(s.intToRoman(1994)) # "MCMXCIV
        