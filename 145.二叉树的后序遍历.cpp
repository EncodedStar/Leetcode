/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// C++ 典型后序遍历模板
class Solution {
private:
    vector<int> TraversalVal;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return TraversalVal; 
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        TraversalVal.push_back(root->val);
        return TraversalVal;
    }
};
// @lc code=end

