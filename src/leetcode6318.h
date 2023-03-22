/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6318.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 336
 */

#ifndef __leet_code_6318_h__
#define __leet_code_6318_h__

#include<iostream>
#include<map>
#include<set>
#include<vector>

class Solution {
public:
	int findMinimumTime(std::vector<std::vector<int>>& tasks) {

		std::vector<int> del(tasks.size(), 0);
		std::map<int, std::vector<int>> m;

		for (int i = 0; i < tasks.size(); i++) {
			int start = tasks[i][0];
			int end = tasks[i][1];
			int duration = tasks[i][2];

			m[start].push_back(i);
			m[end].push_back(i);
			del[i] = end - start + 1 - duration;
		}

		int result = 0;
		// ��ʼ��
		auto iter = m.begin();
		int before_time = (*iter).first;
		std::set<int> current_task;
		for (int i = 0; i < (*iter).second.size(); i++) {
			current_task.emplace((*iter).second[i]);
		}
		iter++;

		while (iter != m.end()) {

			int time = (*iter).first;
			int max = time - before_time; // �� [before_time - time)֮�䣬���������� max ��ʱ���

			// �ж��Ƿ���� 0
			for (auto iter_task : current_task) {
				if (del[iter_task] < max) {
					max = del[iter_task];
				}
			}
			if (max != 0) {
				for (auto iter_task : current_task) {
					del[iter_task] -= max;
				}
			}
			result += time - before_time - max;

			// ���� current_task
			for (int i = 0; i < (*iter).second.size(); i++) {
				int next_task = (*iter).second[i];
				if (current_task.count(next_task) == 0) {
					current_task.emplace(next_task);
				}
				else {
					current_task.erase(next_task);
				}
			}
			before_time = time;
			iter++;
		}

		// �ж����һ�����ܷ�ɾ��
		iter--;
		// ���� current_task
		for (int i = 0; i < (*iter).second.size(); i++) {
			int next_task = (*iter).second[i];
			current_task.emplace(next_task);
		}
		bool can_be_del = true;
		for (auto iter_task : current_task) {
			if (del[iter_task] == 0) {
				can_be_del = false;
				break;
			}
		}
		if (!can_be_del) {
			result++;
		}

		return result;
	}
};

#endif // __leet_code_6318_h__