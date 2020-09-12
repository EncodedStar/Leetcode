/*
637. 二叉树的层平均值
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

示例 1：

输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 

提示：
节点值的范围在32位有符号整数范围内。
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> re;
        queue<TreeNode*> t_queue;
        t_queue.push_back(root);
        
        while(!t_queue.empty()) {
            int len_queue = t_queue.size();
            int sum = 0;
            for (int i = 0; i < len_queue; i++){
                TreeNode* t_Node = t_queue.top();
                if (t_Node->left != NULL) t_queue.push_back(t_Node->left);
                if (t_Node->right != NULL) t_queue.push_back(t_Node->right);
                sum += t_Node->val;
                t_queue.pop();
            }
            double avg = (double)sum/(double)len_queue;
            re.push_back(avg);
        }
        return re;
    }
};



class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        auto counts = vector<int>();
        auto sums = vector<double>();
        dfs(root, 0, counts, sums);
        
        for (int i = 0; i < sums.size(); i++) {
            sums[i] /= counts[i];
        }
        return sums;
    }

    void dfs(TreeNode* root, int level, vector<int> &counts, vector<double> &sums) {
        if (root == NULL) return;

        if (level >= sums.size()) {
            sums.emplace_back(root->val);
            counts.emplace_back(1);
        } else {
            sums[level] += root->val;
            counts[level] += 1;
        }
        dfs(root->left, level + 1, counts, sums);
        dfs(root->right, level + 1, counts, sums);
    }
};
