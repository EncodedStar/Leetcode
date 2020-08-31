/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
 
限制：
0 <= 节点个数 <= 5000
*/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root, int start, int end){// 中序的start和end
        if(start > end) return NULL;
        TreeNode *tree = new TreeNode(preorder[root]);
        int i = start;
        while(i < end && preorder[root] != inorder[i]) i++;//i加到根的地方
        tree->left = build(preorder, inorder, root + 1, start, i - 1);// root+1 左根 
        //start -> i -> end 区间分割成2块（start->i-1）(i+1->end)
        tree->right = build(preorder, inorder, root + 1 + i - start, i + 1, end);
        return tree;
    }
};