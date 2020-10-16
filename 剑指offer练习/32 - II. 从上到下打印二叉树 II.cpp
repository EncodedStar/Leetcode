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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > re;
        queue<TreeNode*> m_queue;
        if (root == NULL) return re;
        m_queue.push(root);
        while (!m_queue.empty()) {
            int size = m_queue.size();
            vector<int> re_t;
            for (int i = 0; i < size; ++i) {
                TreeNode *t = m_queue.front();
                m_queue.pop();
                re_t.emplace_back(t->val);
                if (t->left != NULL) m_queue.push(t->left);
                if (t->right != NULL) m_queue.push(t->right);
            }
            re.emplace_back(re_t);
        }
        return re;
    }
};