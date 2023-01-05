/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-05 09:53:30
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1803.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-05 11:45:45
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, out of TIME
 */

 /*
 * @EditTime: 2023-01-05 12:07:32
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOW_METHOD, out of TIME
 */

 /*
 * @EditTime: 2023-01-05 14:02:33
 * @Editor: Bingyang Jin
 * @Description: create DICTIONARY_TREE_METHOD, TIME 884ms, 6.35%, MEMORY 184.1MB and 6.35%
 */

#ifndef __leet_code_1803__
#define __leet_code_1803__

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

//#define VIOLENCE_METHOD // 暴力法，两两异或求解 O(n^2)，out of Time
//#define SLIDE_WINDOW_METHOD // 滑动窗口法，out of Time
#define DICTIONARY_TREE_METHOD // 字典树法，TIME 884ms, 6.35%, MEMORY 184.1MB and 6.35%

#ifdef VIOLENCE_METHOD
class Solution {
public:
	int countPairs(std::vector<int>& nums, int low, int high) {

		int result = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				int answer = nums[i] ^ nums[j];
				if (low <= answer && answer <= high) {
					result++;
				}
			}
		}

		return result;
	}
};
#endif // VIOLENCE_METHOD

#ifdef SLIDE_WINDOW_METHOD
class Solution {
public:
	int countPairs(std::vector<int>& nums, int low, int high) {
		
		// 进行排序，O(logn)
		std::sort(nums.begin(), nums.end(), [&](int a, int b) {
			return a < b;
		});

		int result = 0;
		std::unordered_map<int, std::pair<int, int>> window; // 针对每个数，构造其左侧和右侧的窗口
		int left = 0; int right = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] + nums[i - 1] < low) {
				continue;
			}
			while (right < i && nums[i] - nums[right] ) {
			}
		}


		//int left = 0, right = 1;
		//int result = 0;
		//while (right < nums.size()) {
		//	while (left < right && nums[right] - nums[left] > high) {
		//		left++;
		//	}
		//	for (int i = left; i < right; i++) {
		//		int temp = nums[i] ^ nums[right];
		//		if (low <= temp && temp <= high) {
		//			result++;
		//		}
		//	}
		//	//if (left >= right || nums[left] + nums[right] < low) {

		//	//}
		//	//else {
		//	//	for (int i = left; i < right; i++) {
		//	//		int temp = nums[i] ^ nums[right];
		//	//		if (low <= temp && temp <= high) {
		//	//			result++;
		//	//		}
		//	//	}
		//	//}
		//	right++;
		//}

		return result;
	}
};
#endif // SLIDE_WINDOW_METHOD

#ifdef DICTIONARY_TREE_METHOD
class DictionaryTreeNode {
public:
	DictionaryTreeNode() { sum = 0; }
	DictionaryTreeNode(int _sum) { sum = _sum; }
	~DictionaryTreeNode() {
		for (int i = 0; i < child.size(); i++) {
			if (child[i] != nullptr) {
				delete child[i];
				child[i] = nullptr;
			}
		}
	}

	void add(std::vector<int> &number, int index) {
		//if (index > number.size()) {
		//	return;
		//}
		sum++;
		if (index == number.size()) {
			return;
		}
		if (child[number[index]] == nullptr) {
			child[number[index]] = new DictionaryTreeNode();
		}
		child[number[index]]->add(number, index+1);
	}

	int getSum(std::vector<int> &x, std::vector<int> &a, int index) {
		if (index == x.size()) {
			return sum;
		}
		int destination;
		if (x[index] == 0) {
			destination = a[index];
			if (child[destination] == nullptr) {
				return 0;
			}
			return child[destination]->getSum(x, a, index + 1);
		}
		else {
			destination = a[index] ^ 1;
			int sum = 0;
			if (child[a[index]] != nullptr) {
				sum = child[a[index]]->sum;
			}
			if (child[destination] == nullptr) {
				return sum;
			}
			
			return sum + child[destination]->getSum(x, a, index + 1);
		}
	}

	int sum; // 表示以当前节点之前为前缀的数字总共有多少个
	std::vector<DictionaryTreeNode *> child = { nullptr , nullptr};
};

class DictionaryTree {
public:
	DictionaryTree() {
		root = new DictionaryTreeNode();
	}
	~DictionaryTree() {
		delete root;
		root = nullptr;
	}

	// 在字典树中增加一个数
	void add(std::vector<int> number) {
		root->add(number, 0);
	}

	// 查询
	int getSum(std::vector<int> &x, std::vector<int> &a) {
		return root->getSum(x, a, 0);
	}

	DictionaryTreeNode *root;
};

class Solution {
public:
	int countPairs(std::vector<int>& nums, int low, int high) {

		int n = nums.size();
		std::vector<std::vector<int>> number(n + 2, std::vector<int>(15, 0));
		nums.push_back(low - 1);
		nums.push_back(high);
		for (int i = 0; i < nums.size(); i++) {
			int index = 14;
			while (nums[i] > 1) {
				number[i][index] = nums[i] % 2;
				index--;
				nums[i] /= 2;
			}
			number[i][index] = nums[i];
		}

		int lowIndex = n;
		int highIndex = n + 1;

		DictionaryTree tree;
		tree.add(number[0]);
		int sum = 0;
		for (int i = 1; i < n; i++) {

			int lowSum = tree.getSum(number[lowIndex], number[i]);
			int highSum = tree.getSum(number[highIndex], number[i]);
			sum = sum + highSum - lowSum;

			tree.add(number[i]);
		}

		return sum;
	}

};
#endif // SLIDE_WINDOW_METHOD

#endif // __leet_code_1803__