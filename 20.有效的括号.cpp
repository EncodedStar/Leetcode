/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack <char> mystack;
        for (auto t: s) {
            if (t == '(' || t == '[' || t == '{') {
                mystack.push(t);
            }
            else if (mystack.size() == 0) {
                return false;
            }
            else if (t == ')' and mystack.top() == '(') {
                mystack.pop();
            }
            else if (t == ']' and mystack.top() == '[') {
                mystack.pop();
            }
            else if (t == '}' and mystack.top() == '{') {
                mystack.pop();
            }
            else {
                return false;
            }
        }
        if (mystack.size() != 0)
            return false;
        return true;
    }
};
// @lc code=end

