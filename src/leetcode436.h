#ifndef __leet_code_436__
#define __leet_code_436__

#include<iostream>
#include<algorithm>
#include<vector>

//#define VIOLENCE_METHOD // O(n^2) 的时间复杂度进行遍历
#define SORT_VIOLENCE_METHOD // 先排序，再进行遍历查找

#ifdef VIOLENCE_METHOD
class Solution {
public:
	std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
		std::vector<int> result;
		for (int i = 0; i < intervals.size(); i++) {
			int minj = -1;
			int min = std::numeric_limits<int>::max();
			for (int j = 0; j < intervals.size(); j++) {
				if (i == j) {
					continue;
				}
				if (intervals[j][0] >= intervals[i][1] && intervals[j][0] <= min) {
					min = intervals[j][0];
					minj = j;
				}
			}
			result.push_back(minj);
		}
		return result;
	}
};
#endif // VIOLENCE_METHOD

#ifdef SORT_VIOLENCE_METHOD
class Solution {
public:

	struct Temp {
		int left;
		int index;
	};

	std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
		std::vector<int> result;

		std::vector<Temp> tempVec;
		for (int i = 0; i < intervals.size(); i++) {
			Temp temp;
			temp.left = intervals[i][0];
			temp.index = i;
			tempVec.push_back(temp);

			result.push_back(-1);
		}
		// 排序
		std::sort(tempVec.begin(), tempVec.end(), [=](Temp a, Temp b) ->bool { return a.left < b.left; });

		// 暴力遍历查找
		for (int i = 0; i < tempVec.size(); i++) {
			for (int j = i; j < tempVec.size(); j++) {
				if (tempVec[j].left >= intervals[tempVec[i].index][1]) {
					result[tempVec[i].index] = tempVec[j].index;
					break;
				}
			}
		}

		return result;
	}
};
#endif // SORT_VIOLENCE_METHOD



#endif // __leet_code_436__