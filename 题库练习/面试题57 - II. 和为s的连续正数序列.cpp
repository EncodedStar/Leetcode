class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 1, sum = 0; 
        vector<vector<int>> result;
        while (left < target / 2 + 1) {
            if (sum < target) {
                sum += right++;
            } 
            else if (sum > target) {
                sum -= left++;
            } 
            else {
                vector<int> array;
                for (int t = left; t < right; t++) array.push_back(t);
                res.push_back(array);
                sum -= left++;
            }
        }
        return result;
    }
};