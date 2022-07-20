#ifndef __leet_code_732__
#define __leet_code_732__

#include<iostream>
#include<vector>
#include<map>

//#define DIFFERENCE_METHODS	// 差分数组法
#define SEGMENT_TREE_METHODS // 线段树方法

#ifdef DIFFERENCE_METHODS
class MyCalendarThree {
public:

	std::map<int, int> results;

	MyCalendarThree() {

	}

	int book(int start, int end) {

		int max = 0;
		int temp = 0;

		if (results.count(start) == 0) {
			results[start] = 1;
		}
		else {
			results[start] ++;
		}

		if (results.count(end) == 0) {
			results[end] = -1;
		}
		else {
			results[end] --;
		}

		for (auto &m : results) { // 这种方法读取到的map是基于key值从小到大
			//std::cout << m.first << " " << m.second << std::endl;
			temp += m.second;
			if (temp > max) {
				max = temp;
			}
		}

		return max;
	}
};
#endif // DIFFERENCE_METHODS

#ifdef SEGMENT_TREE_METHODS

class SegmentTree {

public:
	SegmentTree() {

	}
	~SegmentTree() {
		clear();
	}

	std::vector<int> data;

	// 建树
	void build(std::vector<int> _data) {
		clear();
		data = std::vector<int>(_data.size() * 4, 0);
		build(_data, 0, _data.size() - 1, 1);
	}

	// 查询某个范围数据的和
	int findDataIndex(int begin, int end) {
		return findDataIndex(begin, end, 0, data.size() / 4 - 1, 1);
	}

	// 更新线段树
	void update(int index, int _data) {
		update(index, _data, 0, data.size() / 4 - 1, 1);
	}

	// 清理线段树
	void clear() {
		data.clear();
	}


private:
	// 递归建树
	void build(std::vector<int> _data, int _start, int _end, int node_index) {
		if (_start == _end) {
			data[node_index] = _data[_start];
		}
		else {
			int node_left = node_index * 2;
			int node_right = node_index * 2 + 1;
			int mid = (_start + _end) / 2;

			build(_data, _start, mid, node_left);
			build(_data, mid + 1, _end, node_right);

			data[node_index] = data[node_left] + data[node_right];

		}
	}

	// 递归查询数据
	int findDataIndex(int begin, int end, int left, int right, int node_index) {
		std::cout << "此时的区间为 " << left << " " << right << std::endl;
		if (end < left || right < begin) {
			return 0;
		}
		else if (begin <= left && right <= end) {
			// 递归终止条件：当前的查询区间在目标区间内
			return data[node_index];
		}
		else {
			// 递归查询
			int mid = (left + right) / 2;
			int node_left = node_index * 2;
			int node_right = node_index * 2 + 1;

			int sum = 0;

			sum += findDataIndex(begin, end, left, mid, node_left);
			sum += findDataIndex(begin, end, mid + 1, right, node_right);

			return sum;
		}
	}

	// 递归更新线段树
	void update(int index, int _data, int _start, int _end, int node_index) {
		if (_end < index || index < _start) {
			return ;
		}
		else if (_start == index && _end == index) {
			data[node_index] = _data;
		}
		else {
			int node_left = node_index * 2;
			int node_right = node_index * 2 + 1;
			int mid = (_start + _end) / 2;

			update(index, _data, _start, mid, node_left);
			update(index, _data, mid + 1, _end, node_right);

			data[node_index] = data[node_left] + data[node_right];

		}
	}

};

class MyCalendarThree {
public:

	MyCalendarThree() {

	}

	int book(int start, int end) {

	}
};
#endif // SEGMENT_TREE_METHODS



/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

#endif // __leet_code_732__