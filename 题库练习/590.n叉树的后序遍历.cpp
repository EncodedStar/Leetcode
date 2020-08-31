/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return vector<int> {};
        vector<Node*> stack { root };
        vector<int> res;
        // 遍历栈
        while (stack.size()) {
            // 打印栈内容
            Node *node = stack.back();
            stack.pop_back();
            res.push_back(node->val);
            // 将子集压入栈里
            for (Node *c: node->children) 
                stack.push_back(c);
        }
        reverse(begin(res), end(res));
        return res;
    }
};
// @lc code=end

