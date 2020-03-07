/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
class Solution {
private:
    vector<string> result;
public:
    void dfs(TreeNode* root, string s) {
        if (root->left == NULL and root->right == NULL )
            result.push_back(s);

        if (root->left) 
            dfs(root->left, s + "->" + std::to_string(root->left->val) );

        if (root->right) 
            dfs(root->right, s + "->" + std::to_string(root->right->val) );
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return result;
        dfs(root, std::to_string(root->val));
        return result;
    }
};
// @lc code=end

