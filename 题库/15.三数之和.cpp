/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
/* 暴力
class Solution {
public:
    bool find_re(vector<vector<int>> v1, vector<int> v2) {
        for (auto i: v1)
        {
            if (i[0] == v2[0] and i[1] == v2[1] and i[2] == v2[2])
                return false;
        }
        return true;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        vector<vector<int>>  v_2;
        for (int i = 0; i < length - 2; i++) {
            for (int j = i + 1; j < length - 1; j++) {
                for (int k = j + 1; k < length; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0 and find_re(v_2,{nums[i], nums[j], nums[k]})) {
                        v_2.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return v_2;
    }
};
*/
class Solution {
public:
    bool find_re(vector<vector<int>> v1, vector<int> v2) {
        for (auto i: v1)
        {
            if (i[0] == v2[0] and i[1] == v2[1] and i[2] == v2[2])
                return false;
        }
        return true;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        vector<vector<int>>  v_2;
        map<int,int> my_map;
        for (int i = 0; i < length; i++) {
            my_map[nums[i]] = i;
        }
        for (int i = 0; i < length - 2; i++) {
            for (int j = i + 1; j < length - 1; j++) {
                if ( my_map.count(0 - (nums[i] + nums[j])) and find_re(v_2,{nums[i], nums[j], 0 - (nums[i] + nums[j]})) ){
                    v_2.push_back({nums[i], nums[j], 0 - (nums[i] + nums[j]) });
                }
            }
        }
        return v_2;
    }
};
// @lc code=end

