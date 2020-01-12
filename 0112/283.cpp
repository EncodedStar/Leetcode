class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			int fast = 0;
			int slow = 0;
			if (nums.size() == 1)
				return;
			for (int fast = 0 ; fast < nums.size() ; fast++) {
				if (nums[fast] != 0 ) {
					if (fast == slow){
						slow++;
					}else{
						nums[slow] = nums[fast];
						slow++;
						nums[fast] = 0;
					}

				}
			}
		}
};
