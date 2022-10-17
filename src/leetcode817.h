/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-12 09:35:16
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode817.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-11 09:48:43
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 36ms, 45.42%, MEMORY 21MB and 31.30%
 */

#ifndef __leet_code_817__
#define __leet_code_817__

#include<iostream>
#include<vector>
#include<unordered_set>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	int numComponents(ListNode* head, std::vector<int>& nums) {

		std::unordered_set<int> number;
		for (int i = 0; i < nums.size(); i++) {
			number.emplace(nums[i]);
		}

		int result = 0;
		bool isConnect = true;
		while (head != nullptr)
		{
			if (number.count(head->val) == 0) {
				isConnect = true;
			}
			else {
				if (isConnect) {
					result++;
					isConnect = false;
				}
			}
			head = head->next;
		}

		return result;
	}
};

#endif // __leet_code_817__