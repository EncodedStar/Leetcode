/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
<<<<<<< HEAD
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j != 0) grid[i][j] += grid[i][j-1];
                else if(j == 0 && i != 0)    grid[i][j] += grid[i-1][j];
                else if(i != 0 && j != 0)    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]); 
            }
        }
        return grid[m-1][n-1];
    }
};

=======
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
>>>>>>> f1f1bf52168b56bde47af96645213027a4465fed
// @lc code=end

