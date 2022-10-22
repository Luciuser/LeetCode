/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-22 10:05:27
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1235.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-22 12:02:00
 * @Editor: Bingyang Jin
 * @Description: create CUT_DOMN_TREE_METHOD, TIME OUT
 */

 /*
 * @EditTime: 2022-10-22 12:17:49
 * @Editor: Bingyang Jin
 * @Description: create CUT_DOMN_TREE_ENHANCE_METHOD, TIME OUT
 */

 /*
 * @EditTime: 2022-10-22 17:10:21
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 156ms, 27.00%, MEMORY 53.1MB and 57.00%
 */

#ifndef __leet_code_1235__
#define __leet_code_1235__

#include<iostream>
#include<vector>
#include<algorithm>

//#define CUT_DOMN_TREE_METHOD // 用带剪枝功能的树来存储，TIME OUT
//#define CUT_DOMN_TREE_ENHANCE_METHOD // 用带优化剪枝功能的树来存储，TIME OUT
#define DYNAMIC_PROGRAMMING_METHOD // 动态规划，TIME 156ms, 27.00%, MEMORY 53.1MB and 57.00%


#ifdef CUT_DOMN_TREE_METHOD
 // 用一个带剪枝功能的树来存储
class Node {
public:
	Node(int i) { idex = i; }
	Node(int i, int l) { idex = i; length = l; }

	int idex;
	int length;
	std::vector<Node*> children;
};

class Solution {
public:

	// 从某个节点开始递归，返回该节点为根节点的子树中是否可以添加节点 crtIndex
	bool dfs(Node* root, std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit, int crtIndex) {
		bool childSuccess = false;
		for (int i = 0; i < root->children.size(); i++) {
			if (dfs(root->children[i], startTime, endTime, profit, crtIndex) == true) {
				childSuccess = true;
			}
		}

		// 判断是否是根节点
		if (root->idex == -1) {
			return childSuccess;
		}

		// 该节点的子树可以添加节点 crtIndex，直接返回true
		if (childSuccess) {
			return childSuccess;
		}

		// 该节点的子树不可以添加节点 crtIndex，对该节点进行尝试
		if (endTime[root->idex] <= startTime[crtIndex]) {
			// 该节点可添加子节点 crtIndex，记录添加位置
			if (tempFatherNode == nullptr) {
				tempFatherNode = root;
			}
			else if (root->length > tempFatherNode->length) {
				tempFatherNode = root;
			}
			return true;
		}

		return false;
	}

	int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {

		// 对 endTime 进行排序，O(nlogn)
		int n = startTime.size();
		std::vector<int> order(n); // order 为 endTime 从小到大的索引值的顺序
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		std::sort(order.begin(), order.end(), [&](int a, int b) {return endTime[a] < endTime[b]; });

		// 对第 i 个节点，加入树中，并剪枝，核心要素是：
		// 1.加入：从根节点出发，若某一个子节点可以容纳节点 i，则父节点无需增加子节点 i；若所有的子节点均不能容纳节点 i，则父节点可选增加子节点 i
		// 2.剪枝：若可以增加子节点 i 的父节点有多个，则计算该路径的 value 值，选择最大的一个，增加子节点 i
		// 3.最大值剪枝：若已存在节点 max，且 endTime[max] < endTime[i]，同时 子节点 i 增加后的最大长度 length[i] < length[max]，则无需加入子节点 i
		Node *root = new Node(-1, 0);
		Node *first = new Node(order[0], profit[order[0]]);
		maxidex = order[0];
		maxLength = profit[order[0]];
		root->children.push_back(first);
		for (int i = 1; i < n; i++) {
			int index = order[i];
			if (dfs(root, startTime, endTime, profit, index)) {
				// tempFatherNode节点可以添加第 i 个节点，进行最大值剪枝判断
				if (tempFatherNode->length + profit[index] <= maxLength && endTime[index] > endTime[maxidex]) {
					// 剪枝，不进行添加
				}
				else {
					// 无需剪枝，添加节点，修改相应值
					Node* nextNode = new Node(index, tempFatherNode->length + profit[index]);
					tempFatherNode->children.push_back(nextNode);
					if (maxLength < nextNode->length) {
						maxidex = nextNode->idex;
						maxLength = nextNode->length;
					}
				}
			}
			else {
				// 在根节点添加子节点，进行最大值剪枝判断
				if (profit[index] <= maxLength && endTime[index] > endTime[maxidex]) {
					// 剪枝，不进行添加
				}
				else {
					// 无需剪枝，添加节点，修改相应值
					Node* nextNode = new Node(index, profit[index]);
					root->children.push_back(nextNode);
					if (maxLength < nextNode->length) {
						maxidex = nextNode->idex;
						maxLength = nextNode->length;
					}
				}
			}
			tempFatherNode = nullptr;
		}

		return maxLength;
	}

private:
	int maxidex = -1;
	int maxLength = 0;

	Node *tempFatherNode = nullptr;
};
#endif // CUT_DOMN_TREE_METHOD

#ifdef CUT_DOMN_TREE_ENHANCE_METHOD
// 用一个带剪枝功能的树来存储
class Node {
public:
	Node(int i) { idex = i; }
	Node(int i, int l) { idex = i; length = l; }

	int idex;
	int length;
	std::vector<Node*> children;
};

class Solution {
public:

	// 从某个节点开始递归，返回该节点为根节点的子树中是否可以添加节点 crtIndex
	bool dfs(Node* root, std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit, int crtIndex) {
		bool childSuccess = false;
		for (int i = 0; i < root->children.size(); i++) {
			if (dfs(root->children[i], startTime, endTime, profit, crtIndex) == true) {
				childSuccess = true;
			}
		}

		// 判断是否是根节点
		if (root->idex == -1) {
			return childSuccess;
		}

		// 该节点的子树可以添加节点 crtIndex，直接返回true
		if (childSuccess) {
			return childSuccess;
		}

		// 该节点的子树不可以添加节点 crtIndex，对该节点进行尝试
		if (endTime[root->idex] <= startTime[crtIndex]) {
			// 该节点可添加子节点 crtIndex，记录添加位置
			if (tempFatherNode == nullptr) {
				tempFatherNode = root;
				tempidex = crtIndex;
			}
			else if (root->length + profit[crtIndex] > tempFatherNode->length + profit[tempidex]) {
				tempFatherNode = root;
				tempidex = crtIndex;
			}
			return true;
		}

		return false;
	}

	int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {

		// 对 endTime 进行排序，O(nlogn)
		int n = startTime.size();
		std::vector<int> order(n); // order 为 endTime 从小到大的索引值的顺序
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		std::sort(order.begin(), order.end(), [&](int a, int b) {return endTime[a] < endTime[b]; });

		// 对第 i 个节点，加入树中，并剪枝，核心要素是：
		// 1.加入：从根节点出发，若某一个子节点可以容纳节点 i，则父节点无需增加子节点 i；若所有的子节点均不能容纳节点 i，则父节点可选增加子节点 i
		// 2.剪枝：若可以增加子节点 i 的父节点有多个，则计算该路径的 value 值，选择最大的一个，增加子节点 i
		// 3.最大值剪枝：若已存在节点 max，且 endTime[max] < endTime[i]，同时 子节点 i 增加后的最大长度 length[i] < length[max]，则无需加入子节点 i
		Node *root = new Node(-1, 0);
		for (int i = 0; i < n; i++) {
			int index = order[i];

			dfs(root, startTime, endTime, profit, index);
			if (i < n - 1 && endTime[order[i]] == endTime[order[i + 1]]) {
				continue;
			}

			if (tempFatherNode != nullptr) {
				// tempFatherNode节点可以添加第 i 个节点，进行最大值剪枝判断
				if (tempFatherNode->length + profit[tempidex] <= maxLength && endTime[index] > endTime[maxidex]) {
					// 剪枝，不进行添加
				}
				else {
					// 无需剪枝，添加节点，修改相应值
					Node* nextNode = new Node(index, tempFatherNode->length + profit[tempidex]);
					tempFatherNode->children.push_back(nextNode);
					if (maxLength < nextNode->length) {
						maxidex = nextNode->idex;
						maxLength = nextNode->length;
					}
				}
			}
			else {
				// 在根节点添加子节点，进行最大值剪枝判断
				if (profit[index] <= maxLength && endTime[index] > endTime[maxidex]) {
					// 剪枝，不进行添加
				}
				else {
					// 无需剪枝，添加节点，修改相应值
					Node* nextNode = new Node(index, profit[index]);
					root->children.push_back(nextNode);
					if (maxLength < nextNode->length) {
						maxidex = nextNode->idex;
						maxLength = nextNode->length;
					}
				}
			}
			tempFatherNode = nullptr;
			tempidex = -1;
		}

		return maxLength;
	}

private:
	int maxidex = -1;
	int maxLength = 0;

	Node *tempFatherNode = nullptr;
	int tempidex = -1;
};
#endif // CUT_DOMN_TREE_ENHANCE_METHOD

#ifdef DYNAMIC_PROGRAMMING_METHOD
class Solution {
public:

	int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {

		// 对 endTime 进行排序，O(nlogn)
		int n = startTime.size();
		std::vector<std::vector<int>> jobs(n);
		for (int i = 0; i < n; i++) {
			jobs[i] = { startTime[i], endTime[i], profit[i] };
		}
		std::sort(jobs.begin(), jobs.end(), [](const std::vector<int> &job1, const std::vector<int> &job2) -> bool {
			return job1[1] < job2[1];
		});

		// 设 dp[i] 为前 i 个工作的最大报酬，则当 i > j 时，显然有 dp[i] >= dp[j]
		// 若不选择第 i 个工作，则 dp[i] = dp[i-1]
		// 若选择第 i 个工作，则需要将第 i 个工作接在前面一些工作后，即找到所有的 dp[j]，满足 endTime[j] <= startTime[i]；
		//			对于所有的 dp[j]，寻找 dp[j] 最大值，即 j 最大值
		std::vector<int> dp(n + 1);
		for (int i = 1; i <= n; i++) {
			int k = std::upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const std::vector<int> &job) -> bool {
				return st < job[1];
			}) - jobs.begin();
			dp[i] = std::max(dp[i - 1], dp[k] + jobs[i - 1][2]);
		}
		return dp[n];
	}

};
#endif // DYNAMIC_PROGRAMMING_METHOD

 
#endif // __leet_code_1235__