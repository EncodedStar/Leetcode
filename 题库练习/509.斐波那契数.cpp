/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
int fib(int N) {
    if (N == 0) return 0;
    if (N == 1 or N == 2) return 1;
    int first = 1;
    int second = 1;
    for (int i = 2; i < N; i++) {
        int tmp = second;
        second = first + second;
        first = tmp;
    }
    return second;
}
};
// @lc code=end

