/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：
输入：head = [1,3,2]
输出：[2,3,1]
 
限制：
0 <= 链表长度 <= 10000
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if (head == NULL) return {};
        ListNode *p = head;
        vector<int> re;
        vector<int> temp_re;
        while(p) {
            temp_re.push_back(p->val);
            p = p->next;
        }
        for(auto start = temp_re.begin(); start != temp_re.end(); start++) {
            re.push_back(*start);
        }
        return re;
    }
};