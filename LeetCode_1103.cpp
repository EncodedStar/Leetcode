/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int candy = 1, num = 0;
        while (candies > 0) {
            result[num++ % num_people] += candy++;
            if (candies <= candy) 
                result[num % num_people] += (candies - 1);
            candies -= candy;
        }
        return result;
    }
};

// @lc code=end
