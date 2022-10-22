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

//#define CUT_DOMN_TREE_METHOD // �ô���֦���ܵ������洢��TIME OUT
//#define CUT_DOMN_TREE_ENHANCE_METHOD // �ô��Ż���֦���ܵ������洢��TIME OUT
#define DYNAMIC_PROGRAMMING_METHOD // ��̬�滮��TIME 156ms, 27.00%, MEMORY 53.1MB and 57.00%


#ifdef CUT_DOMN_TREE_METHOD
 // ��һ������֦���ܵ������洢
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

	// ��ĳ���ڵ㿪ʼ�ݹ飬���ظýڵ�Ϊ���ڵ���������Ƿ������ӽڵ� crtIndex
	bool dfs(Node* root, std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit, int crtIndex) {
		bool childSuccess = false;
		for (int i = 0; i < root->children.size(); i++) {
			if (dfs(root->children[i], startTime, endTime, profit, crtIndex) == true) {
				childSuccess = true;
			}
		}

		// �ж��Ƿ��Ǹ��ڵ�
		if (root->idex == -1) {
			return childSuccess;
		}

		// �ýڵ������������ӽڵ� crtIndex��ֱ�ӷ���true
		if (childSuccess) {
			return childSuccess;
		}

		// �ýڵ��������������ӽڵ� crtIndex���Ըýڵ���г���
		if (endTime[root->idex] <= startTime[crtIndex]) {
			// �ýڵ������ӽڵ� crtIndex����¼���λ��
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

		// �� endTime ��������O(nlogn)
		int n = startTime.size();
		std::vector<int> order(n); // order Ϊ endTime ��С���������ֵ��˳��
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		std::sort(order.begin(), order.end(), [&](int a, int b) {return endTime[a] < endTime[b]; });

		// �Ե� i ���ڵ㣬�������У�����֦������Ҫ���ǣ�
		// 1.���룺�Ӹ��ڵ��������ĳһ���ӽڵ�������ɽڵ� i���򸸽ڵ����������ӽڵ� i�������е��ӽڵ���������ɽڵ� i���򸸽ڵ��ѡ�����ӽڵ� i
		// 2.��֦�������������ӽڵ� i �ĸ��ڵ��ж����������·���� value ֵ��ѡ������һ���������ӽڵ� i
		// 3.���ֵ��֦�����Ѵ��ڽڵ� max���� endTime[max] < endTime[i]��ͬʱ �ӽڵ� i ���Ӻ����󳤶� length[i] < length[max]������������ӽڵ� i
		Node *root = new Node(-1, 0);
		Node *first = new Node(order[0], profit[order[0]]);
		maxidex = order[0];
		maxLength = profit[order[0]];
		root->children.push_back(first);
		for (int i = 1; i < n; i++) {
			int index = order[i];
			if (dfs(root, startTime, endTime, profit, index)) {
				// tempFatherNode�ڵ������ӵ� i ���ڵ㣬�������ֵ��֦�ж�
				if (tempFatherNode->length + profit[index] <= maxLength && endTime[index] > endTime[maxidex]) {
					// ��֦�����������
				}
				else {
					// �����֦����ӽڵ㣬�޸���Ӧֵ
					Node* nextNode = new Node(index, tempFatherNode->length + profit[index]);
					tempFatherNode->children.push_back(nextNode);
					if (maxLength < nextNode->length) {
						maxidex = nextNode->idex;
						maxLength = nextNode->length;
					}
				}
			}
			else {
				// �ڸ��ڵ�����ӽڵ㣬�������ֵ��֦�ж�
				if (profit[index] <= maxLength && endTime[index] > endTime[maxidex]) {
					// ��֦�����������
				}
				else {
					// �����֦����ӽڵ㣬�޸���Ӧֵ
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
// ��һ������֦���ܵ������洢
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

	// ��ĳ���ڵ㿪ʼ�ݹ飬���ظýڵ�Ϊ���ڵ���������Ƿ������ӽڵ� crtIndex
	bool dfs(Node* root, std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit, int crtIndex) {
		bool childSuccess = false;
		for (int i = 0; i < root->children.size(); i++) {
			if (dfs(root->children[i], startTime, endTime, profit, crtIndex) == true) {
				childSuccess = true;
			}
		}

		// �ж��Ƿ��Ǹ��ڵ�
		if (root->idex == -1) {
			return childSuccess;
		}

		// �ýڵ������������ӽڵ� crtIndex��ֱ�ӷ���true
		if (childSuccess) {
			return childSuccess;
		}

		// �ýڵ��������������ӽڵ� crtIndex���Ըýڵ���г���
		if (endTime[root->idex] <= startTime[crtIndex]) {
			// �ýڵ������ӽڵ� crtIndex����¼���λ��
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

		// �� endTime ��������O(nlogn)
		int n = startTime.size();
		std::vector<int> order(n); // order Ϊ endTime ��С���������ֵ��˳��
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		std::sort(order.begin(), order.end(), [&](int a, int b) {return endTime[a] < endTime[b]; });

		// �Ե� i ���ڵ㣬�������У�����֦������Ҫ���ǣ�
		// 1.���룺�Ӹ��ڵ��������ĳһ���ӽڵ�������ɽڵ� i���򸸽ڵ����������ӽڵ� i�������е��ӽڵ���������ɽڵ� i���򸸽ڵ��ѡ�����ӽڵ� i
		// 2.��֦�������������ӽڵ� i �ĸ��ڵ��ж����������·���� value ֵ��ѡ������һ���������ӽڵ� i
		// 3.���ֵ��֦�����Ѵ��ڽڵ� max���� endTime[max] < endTime[i]��ͬʱ �ӽڵ� i ���Ӻ����󳤶� length[i] < length[max]������������ӽڵ� i
		Node *root = new Node(-1, 0);
		for (int i = 0; i < n; i++) {
			int index = order[i];

			dfs(root, startTime, endTime, profit, index);
			if (i < n - 1 && endTime[order[i]] == endTime[order[i + 1]]) {
				continue;
			}

			if (tempFatherNode != nullptr) {
				// tempFatherNode�ڵ������ӵ� i ���ڵ㣬�������ֵ��֦�ж�
				if (tempFatherNode->length + profit[tempidex] <= maxLength && endTime[index] > endTime[maxidex]) {
					// ��֦�����������
				}
				else {
					// �����֦����ӽڵ㣬�޸���Ӧֵ
					Node* nextNode = new Node(index, tempFatherNode->length + profit[tempidex]);
					tempFatherNode->children.push_back(nextNode);
					if (maxLength < nextNode->length) {
						maxidex = nextNode->idex;
						maxLength = nextNode->length;
					}
				}
			}
			else {
				// �ڸ��ڵ�����ӽڵ㣬�������ֵ��֦�ж�
				if (profit[index] <= maxLength && endTime[index] > endTime[maxidex]) {
					// ��֦�����������
				}
				else {
					// �����֦����ӽڵ㣬�޸���Ӧֵ
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

		// �� endTime ��������O(nlogn)
		int n = startTime.size();
		std::vector<std::vector<int>> jobs(n);
		for (int i = 0; i < n; i++) {
			jobs[i] = { startTime[i], endTime[i], profit[i] };
		}
		std::sort(jobs.begin(), jobs.end(), [](const std::vector<int> &job1, const std::vector<int> &job2) -> bool {
			return job1[1] < job2[1];
		});

		// �� dp[i] Ϊǰ i ����������󱨳꣬�� i > j ʱ����Ȼ�� dp[i] >= dp[j]
		// ����ѡ��� i ���������� dp[i] = dp[i-1]
		// ��ѡ��� i ������������Ҫ���� i ����������ǰ��һЩ�����󣬼��ҵ����е� dp[j]������ endTime[j] <= startTime[i]��
		//			�������е� dp[j]��Ѱ�� dp[j] ���ֵ���� j ���ֵ
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