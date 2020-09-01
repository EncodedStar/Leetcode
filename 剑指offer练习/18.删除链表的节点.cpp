// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

// 返回删除后的链表的头节点。

// 注意：此题对比原题有改动

// 示例 1:

// 输入: head = [4,5,1,9], val = 5
// 输出: [4,1,9]
// 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
// 示例 2:

// 输入: head = [4,5,1,9], val = 1
// 输出: [4,5,9]
// 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == NULL) return head;
        if (head->val == val) return head->next;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p1->next != NULL) {
            if (p2->val == val) {
                p2 = p2->next;
                p1->next = p2;
                break;
            }
            p1 = p2;
            p2 = p2->next;
        }
        return head;
    }
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode new_head = ListNode(0);
        ListNode* curr = &new_head;
        while (head) {
            if (head->val != val) {
                curr->next = head;
                curr = curr->next;
            }
            head = head->next;
        }
        curr->next = NULL;
        return new_head.next;
    }
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == NULL)
            return head;
        if (head->val == val)
            return head->next;
        head->next = deleteNode(head->next, val);
        return head;
    }
};