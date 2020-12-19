#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 找两链表的第一个公共结点----快慢指针法
//  Definition for singly-linked list.
//  struct ListNode {
//     int val;
//      struct ListNode *next;
//  };
// 
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//
//	struct ListNode*curA, *curB;
//	curA = headA;
//	curB = headB;
//	int lenA = 0;
//	int lenB = 0;
//	while (curA)
//	{
//		++lenA;
//		curA = curA->next;
//	}
//	while (curB)
//	{
//		++lenB;
//		curB = curB->next;
//	}
//	curA = headA;
//	curB = headB;
//	int k = abs(lenA - lenB);
//
//	if (lenA > lenB)
//	{
//		while (k--)
//		{
//			curA = curA->next;
//		}
//
//	}
//	else
//	{
//		while (k--)
//		{
//			curB = curB->next;
//		}
//	}
//
//	while (curA&&curB)
//	{
//		if (curA == curB)
//			return curA;
//		curA = curA->next;
//		curB = curB->next;
//	}
//	return NULL;
//}