/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
public:
    int dfs(TreeNode* root, int num) {
        if (root->left == NULL and root->right == NULL)
            return num;
        else if (root->left == NULL)
            return dfs(root->right, num + 1);
        else if (root->right == NULL)
            return dfs(root->left, num + 1);
        else
            return max(dfs(root->right, num + 1), dfs(root->left,num + 1));
    }
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        int result = dfs(root,1);

        return result;
    }
};
// @lc code=end

