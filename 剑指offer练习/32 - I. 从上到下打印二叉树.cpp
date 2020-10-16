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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> re;
        queue<TreeNode*> m_queue;
        if (root == NULL) return re;
        m_queue.push(root);
        while (m_queue.empty()) {
            TreeNode *t = m_queue.front();
            m_queue.pop();
            re.emplace_back(t->val);
            if (t->left != NULL) m_queue.push(t->left);
            if (t->right != NULL) m_queue.push(t->right);
        }
        return re;
    }
};