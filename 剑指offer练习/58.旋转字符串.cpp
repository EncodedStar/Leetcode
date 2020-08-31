// 剑指 Offer 58 - II. 左旋转字符串

// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。
// 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int size = s.length();
        n %= size;
        if(n == 0)
            return s;
        string tmp = s.substr(0, n);
        s += tmp;
        s = s.substr(n, size);
        return s;
    }
};
