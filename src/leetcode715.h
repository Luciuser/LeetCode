#ifndef __leet_code_715__
#define __leet_code_715__

#include<iostream>
#include<vector>
#include<set>

//#define SET_SUM_METHOD // 设置集合求和的方法
#define SEGMENT_TREE_METHOD // 线段树

#ifdef SET_SUM_METHOD
class RangeModule {
public:
	RangeModule() {
		numCount.clear();
	}

	void addRange(int left, int right) {
		for (int i = left; i < right; i++) {
			numCount.emplace(i);
		}
	}

	bool queryRange(int left, int right) {
		auto iter = numCount.find(left);
		if (iter == numCount.end()) {
			return false;
		}
		for (int i = 0; i < right - left; i++) {
			if (iter == numCount.end()) {
				return false;
			}
			iter++;
		}
		iter--;
		if ((*iter) > right) {
			return false;
		}
		return true;
	}

	void removeRange(int left, int right) {
		for (int i = left; i < right; i++) {
			auto iter = numCount.find(i);
			if (iter != numCount.end()) {
				numCount.erase(iter);
			}
		}
	}

private:
	std::set<int> numCount;
};
#endif // SET_SUM_METHOD

#ifdef SEGMENT_TREE_METHOD
class RangeModule {
public:
	RangeModule() {
		numCount.clear();
	}

	void addRange(int left, int right) {
		for (int i = left; i < right; i++) {
			numCount.emplace(i);
		}
	}

	bool queryRange(int left, int right) {
		auto iter = numCount.find(left);
		if (iter == numCount.end()) {
			return false;
		}
		for (int i = 0; i < right - left; i++) {
			if (iter == numCount.end()) {
				return false;
			}
			iter++;
		}
		iter--;
		if ((*iter) > right) {
			return false;
		}
		return true;
	}

	void removeRange(int left, int right) {
		for (int i = left; i < right; i++) {
			auto iter = numCount.find(i);
			if (iter != numCount.end()) {
				numCount.erase(iter);
			}
		}
	}

private:
	std::set<int> numCount;
};
#endif // SEGMENT_TREE_METHOD

#endif //__leet_code_715__