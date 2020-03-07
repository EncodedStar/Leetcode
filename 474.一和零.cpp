/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zore_num = 0;
        int one_num = 0;
        int number = 0;
        for (auto t1: strs) {
            for (auto t2: t1) {
                if (t2 == '0') {
                    zore_num++;
                }
                if (t2 == '1') {
                    one_num++;
                }
            }
            if (zore_num <= m && one_num <= n) {
                number++;
            }
            zore_num = 0;
            one_num = 0;
        }
    }
};
// @lc code=end

