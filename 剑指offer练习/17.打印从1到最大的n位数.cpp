// 剑指 Offer 17. 打印从1到最大的n位数
// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = 1;
        vector<int> res;
        while (n--) max *= 10;
        for (int i = 1; i < max; ++i) {
            res.emplace_back(i);
        }
        return res; 
    }
};