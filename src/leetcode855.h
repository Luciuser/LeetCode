/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-30 08:58:04
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode855.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-30 14:49:19
 * @Editor: Bingyang Jin
 * @Description: create PRIORITY_QUEUE_METHOD, TIME 44ms, 97.40%, MEMORY 21.9MB and 14.93%
 */

#ifndef __leet_code_855__
#define __leet_code_855__

#include<iostream>
#include<unordered_map>
#include<queue>

class ExamRoom {
public:
	ExamRoom(int n) {
		seat_num = n;
	}

	int seat() {
		if (target.size() == 0) {
			valid.clear();
			left.clear();
			right.clear();

			target.emplace(std::pair<int, int>(-seat_num, seat_num)); // 取 -2 为左侧极限点
			valid[-seat_num] = 0;
			valid[0] = -1;
			right[-seat_num] = seat_num; // 取 seat_num 为右侧极限点
		}
		auto currentPair = target.top();
		target.pop();
		// 跳过已经删除掉的几个插点位置
		while (true){
			// 当前 current 已经被删去
			if (currentPair.first + currentPair.second != valid[currentPair.first]) {
				currentPair = target.top();
				target.pop();
				continue;
			}
			else if(currentPair.first + currentPair.second==0 && valid[0] != -1){
				currentPair = target.top();
				target.pop();
				continue;
			}
			break;
		}

		// 找到该段的左侧和右侧顶点，并得到目标顶点
		int leftPoint = currentPair.first;
		int rightPoint = right[leftPoint];
		int currentTarget = currentPair.first + currentPair.second;

		// 计算下一次以 leftPoint 和 currentTarget 为左侧位置，即 [leftPoint, currentTarget] 和 [currentTarget, rightPoint] 这两个区间的插点位置
		int point1 = getMidPoint(leftPoint, currentTarget);
		int point2 = getMidPoint(currentTarget, rightPoint);

		// 更新优先队列和相应 map
		if (leftPoint < 0 && rightPoint == seat_num) {
			target.emplace(std::pair<int, int>(currentTarget, seat_num - 1));
			point2 = seat_num - 1;
		}
		else {
			if (leftPoint >= 0) {
				target.emplace(std::pair<int, int>(leftPoint, point1 - leftPoint));
			}
			if (rightPoint < seat_num) {
				target.emplace(std::pair<int, int>(currentTarget, point2 - currentTarget));
			}
		}
		valid[leftPoint] = point1;
		valid[currentTarget] = point2;
		right[leftPoint] = currentTarget;
		left[currentTarget] = leftPoint;
		right[currentTarget] = rightPoint;
		left[rightPoint] = currentTarget;

		return currentTarget;
	}

	void leave(int p) {

		// 找到点 n 的左侧顶点和右侧顶点
		int leftPoint = left[p];
		int rightPoint = right[p];

		// 更改点 p 的有效性
		valid[p] = -1;

		// 计算新的插入点
		int mid = getMidPoint(leftPoint, rightPoint);
		if (leftPoint < 0) {
			mid = 0;
			leftPoint = mid - rightPoint;
		}
		else if (rightPoint == seat_num) {
			mid = seat_num - 1;
		}
		target.emplace(std::pair<int, int>(leftPoint, mid - leftPoint));
		valid[leftPoint] = mid;

		// 更改 left 和 right 的 map
		left[rightPoint] = leftPoint;
		right[leftPoint] = rightPoint;

	}

private:

	int getMidPoint(int left, int right){
		return (left + right) / 2;
	}

	struct pair_cmp {
		bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
			if (a.second != b.second) {
				return a.second < b.second;
			}
			else {
				return a.first > b.first;
			}
		}
	};

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, pair_cmp> target; // 每个左侧位置，及所对应的目标插入位置距左侧目标位置的长度
	std::unordered_map<int, int> valid; // 每个左侧点所对应的目标插入位置，用于判断 target 当前最优结果是否有效
	std::unordered_map<int, int>left;	// 每个点所对应的左侧点
	std::unordered_map<int, int>right; // 每个点所对应的右侧点
	int seat_num;
};

#endif // 