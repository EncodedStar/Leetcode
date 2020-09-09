/*
剑指 Offer 16. 数值的整数次方
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || n == 0) return 1;
        double re = 1;
        long num = n;
        
        if (num < 0) {
            num = -num;
            x = 1 / x;
        }

        while(num) {
            if (num & 1) re *= x;
            x *= x;
            num >>= 1;
        }

        return re;
    }
};

