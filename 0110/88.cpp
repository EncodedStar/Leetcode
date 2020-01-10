class Solution {
	public:
	    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
			multiset<int> nums;
			for(auto i = 0; i < m ; i++) {
				nums.insert(nums1.at(i));
			}

			for(auto i = 0; i < n; i++) {
				nums.insert(nums2.at(i));
			}

			int i = 0;
			for (auto k : nums) {
				nums1[i++] = k;
			}
		}
};
