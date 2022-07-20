#ifndef __leet_code_1786__
#define __leet_code_1786__

#include<iostream>
#include<vector>
#include<assert.h>

#define VIOLENCE_METHOD // ��������

#ifdef VIOLENCE_METHOD

#endif // VIOLENCE_METHOD

class Solution {
public:

	int min(int a, int b) { return a < b ? a : b; }

	// ���ַ�����
	int insertInQu(std::vector<std::pair<int, int>> &qu, std::pair<int, int> &pa) {
		auto pos = std::lower_bound(qu.begin(), qu.end(), pa, [=](std::pair<int, int>a, std::pair<int, int>b) {
			return a.second < b.second;
		});
		qu.insert(pos, pa);
		return 0;
	}

	// ���ַ�ɾ��
	int deleteInQu(std::vector<std::pair<int, int>> &qu, std::pair<int, int> &pa) {
		auto pos = std::lower_bound(qu.begin(), qu.end(), pa, [=](std::pair<int, int>a, std::pair<int, int>b) {
			return a.second < b.second;
		});

		qu.erase(pos);
		return 0;
	}

	int countRestrictedPaths(int n, std::vector<std::vector<int>>& edges) {

		// ����ͼ O(n)
		std::vector<std::vector<int>> graph(n, std::vector<int>(n, -1)); // ͼ
		std::vector<int> distanceToLastNode(n, -1);	// ����n�������̾���

		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0] - 1;
			int v = edges[i][1] - 1;
			int weight = edges[i][2];
			graph[u][v] = weight;
			graph[v][u] = weight;
		}

		// ����ÿ����� distanceToLastNode
		std::vector<std::pair<int, int>> qu; // �������Ľڵ�Ͷ�Ӧ����̾���
		qu.push_back(std::pair<int, int>(n - 1, 0));
		distanceToLastNode[n - 1] = 0;
		
		// O(n^2 * logn)
		while (qu.size() != 0) {
			auto node = qu[0];
			int crtNode = node.first;
			int crtDis = node.second;
			for (int i = 0; i < graph[crtNode].size(); i++) {
				if (graph[crtNode][i] != -1) {
					if (distanceToLastNode[i] == -1) {
						// ������û�е�i���ڵ㣬��������ýڵ�
						distanceToLastNode[i] = graph[crtNode][i] + distanceToLastNode[crtNode];
						insertInQu(qu, std::pair<int, int>(i, distanceToLastNode[i]));// �����ڵ�
					}
					else {
						// �������Ѿ����ڵ�i���ڵ㣬��˱Ƚϸýڵ�洢ֵ����·����ֵ�Ĵ�С
						if (graph[crtNode][i] + distanceToLastNode[crtNode] < distanceToLastNode[i]) {
							deleteInQu(qu, std::pair<int, int>(i, distanceToLastNode[i]));
							distanceToLastNode[i] = graph[crtNode][i] + distanceToLastNode[crtNode];
							insertInQu(qu, std::pair<int, int>(i, distanceToLastNode[i]));
						}
					}
				}
			}
			qu.erase(qu.begin());
		}

		// ���б�����Ѱ�ҿ��ܵ�·�����
		std::vector<int> isUsed(n, -1); // �ж�ĳ���ڵ��Ƿ��Ѿ���������
		std::vector<long long> result(n, 0);  // ���ս��
		qu.push_back(std::pair<int, int>(n - 1, 0));
		result[n - 1] = 1;
		while (qu.size() != 0) {
			auto node = qu[0];
			int crtNode = node.first;
			int crtDis = node.second;
			for (int i = 0; i < graph[crtNode].size(); i++) {
				if (graph[crtNode][i] != -1) {
					// ��·���Ƿ���ͨ��
					if (distanceToLastNode[crtNode] < distanceToLastNode[i]) {
						// �ܹ�ͨ��
						if (isUsed[i] == -1) {
							insertInQu(qu, std::pair<int, int>(i, distanceToLastNode[i]));
							isUsed[i] = 1;
						}
						result[i] += result[crtNode];
						if (result[i] >= (1000000007)) {
							result[i] = result[i] % (1000000007);
						}
					}
				}
			}
			qu.erase(qu.begin());
		}


		return result[0];
	}
};

#endif // __leet_code_1786__