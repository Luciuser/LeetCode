/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-08
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6306.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 327
 */

#ifndef __leet_code_6306_h__
#define __leet_code_6306_h__

#include<iostream>
#include<queue>
#include<vector>

// 尝试解法，会超时
//class Solution {
//public:
//	int findCrossingTime(int n, int k, std::vector<std::vector<int>>& time) {
//		// 初始化
//		int all_time = 0;
//		for (int i = 0; i < k; i++) {
//			left_bridge.emplace(std::pair<int, int>(i, time[i][0] + time[i][2]));
//		}
//
//		while (true) {
//			if (n == 0 && right_warehouse.size() == 0 && right_bridge.size() == 0) {
//				break;
//			}
//
//			int temp_time = 0;
//			std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairWarehouseCmp> left_warehouse_temp;
//			std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairWarehouseCmp> right_warehouse_temp;
//
//			if (right_bridge.size() != 0) {
//				// 右边工人先过桥
//				auto top = right_bridge.top();
//				int person = top.first;
//				temp_time = time[person][2];
//				right_bridge.pop();
//				left_warehouse_temp.emplace(std::pair<int, int>(person, time[person][3]));
//			}
//			else if (left_bridge.size() != 0 && n > 0) {
//				// 左边工人过桥
//				auto top = left_bridge.top();
//				int person = top.first;
//				temp_time = time[person][0];
//				left_bridge.pop();
//				right_warehouse_temp.emplace(std::pair<int, int>(person, time[person][1]));
//				n--;
//			}
//			else {
//				// 左右仓库判断时间
//				int left_warehouse_top = left_warehouse.size() == 0 ? std::numeric_limits<int>::max() : left_warehouse.top().second;
//				int right_warehouse_top = right_warehouse.size() == 0 ? std::numeric_limits<int>::max() : right_warehouse.top().second;
//				if (left_warehouse_top <= right_warehouse_top) {
//					temp_time = left_warehouse_top;
//				}
//				else {
//					temp_time = right_warehouse_top;
//				}
//			}
//
//			// 整理两边仓库
//
//			while (left_warehouse.size() > 0) {
//				int person = left_warehouse.top().first;
//				int left_warehouse_time = left_warehouse.top().second;
//				if (left_warehouse_time <= temp_time) {
//					left_bridge.emplace(person, time[person][0] + time[person][2]);
//					left_warehouse.pop();
//				}
//				else {
//					left_warehouse_temp.emplace(person, left_warehouse_time - temp_time);
//					left_warehouse.pop();
//				}
//			}
//			left_warehouse = left_warehouse_temp;
//
//			while (right_warehouse.size() > 0) {
//				int person = right_warehouse.top().first;
//				int right_warehouse_time = right_warehouse.top().second;
//				if (right_warehouse_time <= temp_time) {
//					right_bridge.emplace(person, time[person][0] + time[person][2]);
//					right_warehouse.pop();
//				}
//				else {
//					right_warehouse_temp.emplace(person, right_warehouse_time - temp_time);
//					right_warehouse.pop();
//				}
//			}
//			right_warehouse = right_warehouse_temp;
//
//			all_time += temp_time;
//		}
//
//		return all_time;
//	}
//
//private:
//
//	struct PairBridgeCmp {
//		bool operator()(const std::pair<int, int>&a, const std::pair<int, int>&b) {
//			if (a.second != b.second) {
//				return a.second < b.second;
//			}
//			return a.first < b.first;
//		}
//	};
//
//	struct PairWarehouseCmp {
//		bool operator()(const std::pair<int, int>&a, const std::pair<int, int>&b) {
//			if (a.second != b.second) {
//				return a.second > b.second;
//			}
//			return a.first < b.first;
//		}
//	};
//
//	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairWarehouseCmp> left_warehouse;
//	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairWarehouseCmp> right_warehouse;
//	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairBridgeCmp> left_bridge;
//	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairBridgeCmp> right_bridge;
//
//};

// 进行加速，通过
class Solution {
public:
	int findCrossingTime(int n, int k, std::vector<std::vector<int>>& time) {
		// 初始化
		int all_time = 0;
		for (int i = 0; i < k; i++) {
			left_bridge.emplace(std::pair<int, int>(i, time[i][0] + time[i][2]));
		}

		while (true) {
			if (n == 0 && right_warehouse.size() == 0 && right_bridge.size() == 0) {
				break;
			}

			int temp_time = 0;
			bool left_cross_bridge = false;
			bool right_cross_bridge = false;
			std::pair<int, int> left_warehouse_add_pair;
			std::pair<int, int> right_warehouse_add_pair;

			if (right_bridge.size() != 0) {
				// 右边工人先过桥
				right_cross_bridge = true;
				auto top = right_bridge.top();
				int person = top.first;
				temp_time = time[person][2];
				right_bridge.pop();
				left_warehouse_add_pair = std::pair<int, int>(person, time[person][3] + all_time + temp_time);
			}
			else if (left_bridge.size() != 0 && n > 0) {
				// 左边工人过桥
				left_cross_bridge = true;
				auto top = left_bridge.top();
				int person = top.first;
				temp_time = time[person][0];
				left_bridge.pop();
				right_warehouse_add_pair = std::pair<int, int>(person, time[person][1] + all_time + temp_time);
				n--;
			}
			else {
				// 左右仓库判断时间
				int left_warehouse_top = left_warehouse.size() == 0 ? std::numeric_limits<int>::max() : left_warehouse.top().second;
				int right_warehouse_top = right_warehouse.size() == 0 ? std::numeric_limits<int>::max() : right_warehouse.top().second;
				if (left_warehouse_top <= right_warehouse_top) {
					temp_time = left_warehouse_top - all_time;
				}
				else {
					temp_time = right_warehouse_top - all_time;
				}
			}

			// 整理两边仓库
			all_time += temp_time;
			while (left_warehouse.size() > 0) {
				int person = left_warehouse.top().first;
				int left_warehouse_time = left_warehouse.top().second;
				if (left_warehouse_time <= all_time) {
					left_bridge.emplace(person, time[person][0] + time[person][2]);
					left_warehouse.pop();
					continue;
				}
				break;
			}

			while (right_warehouse.size() > 0) {
				int person = right_warehouse.top().first;
				int right_warehouse_time = right_warehouse.top().second;
				if (right_warehouse_time <= all_time) {
					right_bridge.emplace(person, time[person][0] + time[person][2]);
					right_warehouse.pop();
					continue;
				}
				break;
			}
			if (right_cross_bridge) {
				left_warehouse.emplace(left_warehouse_add_pair);
			}
			if (left_cross_bridge) {
				right_warehouse.emplace(right_warehouse_add_pair);
			}

		}

		return all_time;
	}

private:

	struct PairBridgeCmp {
		bool operator()(const std::pair<int, int>&a, const std::pair<int, int>&b) {
			if (a.second != b.second) {
				return a.second < b.second;
			}
			return a.first < b.first;
		}
	};

	struct PairWarehouseCmp {
		bool operator()(const std::pair<int, int>&a, const std::pair<int, int>&b) {
			if (a.second != b.second) {
				return a.second > b.second;
			}
			return a.first < b.first;
		}
	};

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairWarehouseCmp> left_warehouse;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairWarehouseCmp> right_warehouse;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairBridgeCmp> left_bridge;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PairBridgeCmp> right_bridge;

};
#endif // __leet_code_6306_h__