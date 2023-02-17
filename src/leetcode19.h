/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-16 18:50:52
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode19.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-16 19:06:14
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 75.34%, MEMORY 10.3MB and 91.97%
 */

 /*
 * @EditTime: 2023-02-16 19:23:04
 * @Editor: Bingyang Jin
 * @Description: create STACK_METHOD, TIME 0ms, 100.00%, MEMORY 10.6MB and 5.24%
 */

#ifndef __leet_code_19_h__ 
#define __leet_code_19_h__

#include<iostream>
#include<stack>

//#define GET_LENGTH_METHOD // 第一遍遍历获取链表的长度，第二次遍历删除节点，TIME 4ms, 75.34%, MEMORY 10.3MB and 91.97%
#define STACK_METHOD // 栈法，只需一次遍历

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#ifdef GET_LENGTH_METHOD
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		int deep = getDeep(head);

		if (deep == n) {
			return head->next;
		}
		else {
			deleteNode(head, deep, n);
		}

		return head;
	}

private:
	// 获得节点的深度
	int getDeep(ListNode* root) {
		if (root->next == nullptr) {
			return 1;
		}

		return getDeep(root->next) + 1;
	}

	ListNode* deleteNode(ListNode* root, int node_deep, int delete_deep) {
		if (node_deep == delete_deep) {
			return root->next;
		}

		root->next = deleteNode(root->next, node_deep - 1, delete_deep);
		return root;
	}

};
#endif // GET_LENGTH_METHOD

#ifdef STACK_METHOD
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		
		std::stack<ListNode*> node_stack;
		while (head != nullptr) {
			node_stack.emplace(head);
			head = head->next;
		}
		
		ListNode *next = nullptr;
		while (node_stack.size()>0)	{
			if (n == 1) {
				node_stack.pop();
				if (node_stack.size() == 0) {
					return next;
				}
				node_stack.top()->next = next;
			}
			n--;
			next = node_stack.top();
			node_stack.pop();
		}

		return next;
	}

};
#endif // STACK_METHOD


#endif // __leet_code_19_h__