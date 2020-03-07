/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';

        if (r - 1 >  0 and grid[r - 1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr and grid[r + 1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >  0 and grid[r][c - 1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc and grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        int numIsland = 0;

        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == '1') {
                    numIsland++;
                    dfs(grid, i, j);
                } 
            }
        }
        return numIsland;
    }
};
// @lc code=end

