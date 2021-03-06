/*
216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    void dfs(int k, int n, int s) {
        if (n == 0 && t_result.size() == k) {
            result.emplace_back(t_result);
            return;
        }
        for (int i = s; i < 10; ++i) {
            if (n > 0 && t_result.size() < k) {
              t_result.emplace_back(i);
              dfs(k, n - i, i + 1);
              t_result.pop_back();
            } 
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return result;
    }
    vector<vector<int>> result;
    vector<int> t_result;
};