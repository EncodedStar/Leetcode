/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        for (int r = 0; r < nr; r++) {
            for (int c = 0; c < nc; c++) {
                if (r == 0 and c != 0) {
                    grid[r][c] += grid[r][c - 1];
                }
                else if (c == 0 and r != 0) {
                    grid[r][c] += grid[r - 1][c];
                }
                else if (c != 0 and r != 0) {
                    grid[r][c] += min(grid[r - 1][c],grid[r][c - 1]);
                }
            }
        }
        return grid[nr - 1][nc - 1];
    }
};
// @lc code=end

