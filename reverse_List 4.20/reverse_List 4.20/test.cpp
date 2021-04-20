/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // Time 8ms, 99%
class Solution {
public:

	ListNode* reverseList(ListNode* head) {
		ListNode*p = NULL;
		for (p; head; swap(p, head))
		{
			swap(p, head->next);
		}
		return p;

	}
};