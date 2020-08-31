/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return result;
        }
        vector<int> row;
        for(int i = 0; i < numRows; i++){
            row.push_back(1);
            for(int j = i - 1; j > 0; j--){
                row[j] = row[j - 1] + row[j];
            }
            result.push_back(row);
        }
        return result;
    }
};
// @lc code=end

