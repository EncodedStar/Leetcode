/*
40. 组合总和 II
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*/

class Solution {
public:
    void dfs(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.emplace_back(result_temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if(candidates[i] <= target){
                //检测到重复的元素就跳过
                if (i > start && candidates[i] == candidates[i - 1])
                    continue;
                result_temp.emplace_back(candidates[start]);
                // 元素不可重复利用，使用下一个即i+1
                dfs(candidates, target - candidates[start], start + 1);
                result_temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return result;
    }

    vector<vector<int>> result;
    vector<int> result_temp;
};