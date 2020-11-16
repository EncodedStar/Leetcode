struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(NULL), right(NULL) {};
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (root == NULL) return {};
    vector<vector<int>> re;
    queue<Node*> m_queue;
    m_queue.push(root);

    while (!m_queue.empty()) {
        vector<int> t_re;
        int queue_size = m_queue.size();
        for (int i = 0; i < queue_size; i++) {
            Node *top = m_queue.front();
            m_queue.pop();
            t_re.push_back(top->data);
            if (!m_queue->left) m_queue.push(top->left);
            if (!m_queue->right) m_queue.push(top->right);
        }
        re.emplace_back(t_re);
    }
    cout << "层：" << re.size() << endl;
    return re;
}