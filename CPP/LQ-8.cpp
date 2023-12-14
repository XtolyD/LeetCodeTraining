#include <bits/stdc++.h>
using namespace std;

// 判断一个数字是否是回文数
bool isPalindrome(int num) {
    string str_num = to_string(num);
    int left = 0, right = str_num.length() - 1;
    while (left < right) {
        if (str_num[left] != str_num[right]) {
            return false;
        }
        left++; right--;
    }
    return true;
}

// 找到第 K 小的回文数
long long findKthPalindrome(int K) {
    int count = 0;
    long long num = 1;
    while (count < K) {
        if (isPalindrome(num)) {
            count++;
        }
        num++;
    }
    return num - 1;
}

int main() {
    int K;
    std::cin >> K;
    std::cout << findKthPalindrome(K + 1);

    return 0;
}