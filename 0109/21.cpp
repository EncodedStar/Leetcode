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
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if(!l1 && !l2)
				return NULL;
			if(!l1 && l2)
				return l2;
			if(l1 && !l2)
				return l1;

			ListNode* head = new ListNode(-1);
			ListNode* p = head, *q;

			while(l1 && l2){
				if(l1->val < l2->val){
					q = new ListNode(l1->val);
					p->next = q;
					p = q;
					l1 = l1->next;
				}
				else{
					q = new ListNode(l2->val);
					p->next = q;
					p = q;
					l2 = l2->next;
				}
			}

			if(l1)
				l2 = l1;
			p->next = l2;

			return head->next;
		}
};

