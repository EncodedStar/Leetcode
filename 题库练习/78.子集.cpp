/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> mynums;
public:
    void dfs(vector<vector<int>> &result, vector<int> &nums, vector<int> &mynums, int index) {
        if (nums.size() <= index) {
            result.push_back(mynums);
            return ;
        }
        dfs(result, nums, mynums, index + 1);
        mynums.push_back(nums[index]);
        dfs(result, nums, mynums, index + 1);
        mynums.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {   
        if (nums.empty()) {
            return result;
        }
        dfs(result, nums, mynums, 0);
        return result;
    }
};
// @lc code=end

