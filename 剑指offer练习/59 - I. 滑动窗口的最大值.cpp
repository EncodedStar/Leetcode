/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:


输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

*/

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 0) return {};
		vector<int>res;
		deque<size_t> window;
		/*Init K integers in the list*/
		for (size_t i = 0; i < k; i++) {
			while (!window.empty() && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);
		}
		res.push_back(nums[window.front()]);
		/*End of initialization*/
		for (size_t i = k; i < nums.size(); i++) {
			if (!window.empty() && window.front() <= i - k) {
				window.pop_front();
			}
			while (!window.empty() && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);
			res.push_back(nums[window.front()]);
		}
		return res;
	}
};