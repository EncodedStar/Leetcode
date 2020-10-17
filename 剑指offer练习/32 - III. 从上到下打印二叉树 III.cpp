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
        deque<TreeNode*> m_queue;
        if (root == NULL) return re;
        m_queue.push_back(root);

        while (!m_queue.empty()) {
            vector<int> re_t;
            int size = m_queue.size();

            for (int i = 0; i < size; ++i) {
                TreeNode *t = m_queue.front();
                m_queue.pop_front();
                re_t.emplace_back(t->val);
                if (t->left != NULL) m_queue.push_back(t->left);
                if (t->right != NULL) m_queue.push_back(t->right);
            }
            re.emplace_back(re_t);
            if (m_queue.empty()) break;
            re_t.clear();

            size = m_queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *t = m_queue.back();
                m_queue.pop_back();
                re_t.emplace_back(t->val);
                if (t->right != NULL) m_queue.push_front(t->right);
                if (t->left != NULL) m_queue.push_front(t->left);
            }
            re.emplace_back(re_t);
        }
        return re;
    }
};