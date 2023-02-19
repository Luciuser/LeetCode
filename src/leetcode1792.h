/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-19 09:50:25
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1792.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-19 10:23:21
 * @Editor: Bingyang Jin
 * @Description: create PRIORITY_QUEUE_METHOD, TIME 688ms, 92.38%, MEMORY 91.3MB and 29.52%
 */

#ifndef __leet_code_1792_h__ 
#define __leet_code_1792_h__

#include<iostream>
#include<vector>
#include<queue>

class PairCompare {
public:
	bool operator()(const std::pair<double, int> &a, const std::pair<double, int> &b) {
		return a.first < b.first;
	}
};

class Solution {
public:
	double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
		
		std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, PairCompare> sort_queue;
		double sum = 0;
		for (int i = 0; i < classes.size(); i++) {
			double pass_rate = 1.0 * classes[i][0] / classes[i][1];
			sum += pass_rate;
			double add_pass_rate = 1.0 * (classes[i][1] - classes[i][0]) / classes[i][1] / (classes[i][1] + 1);
			sort_queue.emplace(std::pair<double, int>(add_pass_rate, i));
		}

		for (int i = 0; i < extraStudents; i++) {
			auto top = sort_queue.top();
			sort_queue.pop();
			sum += top.first;
			
			classes[top.second][0]++;
			classes[top.second][1]++;
			double add_pass_rate = 1.0 * (classes[top.second][1] - classes[top.second][0]) / classes[top.second][1] / (classes[top.second][1] + 1);
			sort_queue.emplace(std::pair<double, int>(add_pass_rate, top.second));
		}

		return sum / classes.size();
	}
};

#endif //__leet_code_1792_h__