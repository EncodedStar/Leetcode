/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return  -1;
        int i = 0, j = height.size() - 1, max_v = 0;
        while (i < j) {
            int h = min(height[i],height[j]);
            max_v = max(max_v, h * (j - i));
            height[i] < height[j] ? i++ : j--; 
        }
        return max_v;
    }
    
};
// @lc code=end

