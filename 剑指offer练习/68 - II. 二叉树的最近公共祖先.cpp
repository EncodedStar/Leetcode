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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;
        if (p->val < root->val and q->val < root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }else if (p->val > root->val and q->val > root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }else {
            return root;
        }
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;        
        if(root == p||root == q)return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right)return root;
        return left ? left : right; // 只有一个非空则返回该指针，两个都为空则返回空指针
    }
};

