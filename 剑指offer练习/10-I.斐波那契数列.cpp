/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5
*/

class Solution {
public:
    int fib(int n) {
        int first = 0;
        int second = 1;
        if (n == 0) return 0;
        if (n == 1) return 1;
        int re = first + second;
        while (n > 2) {
            first = second%1000000007;
            second = re%1000000007;
            re = first + second;
            n--;
        }
        return re;
    }
};
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int N = 0, NMinusOne = 1, NMinusTwo = 0;
        while(n >= 2)
        {
            // 采取从下往上的方法，把计算过的中间项保存起来，避免重复计算导致递归调用栈溢出
            N = (NMinusOne + NMinusTwo) % 1000000007;
            NMinusTwo = NMinusOne;
            NMinusOne = N;
            n--;
        }
        return N;
    }
};

class Solution {
public:
    int fib(int n) {
        vector<int>f(101,0);
        f[0] = 0; f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = (f[i - 1] + f[i - 2])% 1000000007;
        }
        return f[n];
    }
};