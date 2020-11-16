class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int right = grid[0].size(); 
        int bottom = grid.size();
        vector<vector<int>> DP(bottom, vector<int>(right, 0));

        for (int i = 0; i < right; i++) {
            for (int j = 0; j < bottom; j++) {
                int left = 0; int top = 0;

                if (i > 0) {left = DP[i - 1][j]};
                if (j > 0) {top = DP[i][j - 1]};

                DP[i][j] = max(left, top);
            }
        }

        return DP[bottom - 1][right -1];
        
    }
};