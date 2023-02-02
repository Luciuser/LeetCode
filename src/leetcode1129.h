/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-02 15:35:54
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1129.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-02 16:19:35
 * @Editor: Bingyang Jin
 * @Description: create ITER_METHOD, TIME 20ms, 49.34%, MEMORY 17.7MB and 9.60%
 */

#ifndef __leet_code_1129_h__
#define __leet_code_1129_h__

#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<int> shortestAlternatingPaths(int n, std::vector<std::vector<int>>& redEdges, std::vector<std::vector<int>>& blueEdges) {
		
		std::vector<std::vector<int>> red_edges(n, std::vector<int>(n, -1)); // �þ���洢��ɫ����ߣ���߱����ٶ�
		std::vector<std::vector<int>> blue_edges(n, std::vector<int>(n, -1)); // �þ���洢��ɫ����ߣ���߱����ٶ�

		for (int i = 0; i < n; i++) {
			red_edges[i][i] = 0;
			blue_edges[i][i] = 0;
		}
		for (int i = 0; i < redEdges.size(); i++) {
			red_edges[redEdges[i][0]][redEdges[i][1]] = 1;
		}
		for (int i = 0; i < blueEdges.size(); i++) {
			blue_edges[blueEdges[i][0]][blueEdges[i][1]] = 1;
		}

		bool is_change = true; // red_from_zero �� blue_from_zero �����Ƿ����仯
		std::vector<int> is_red_change(n, 0); // red_from_zero �����Ƿ����仯
		std::vector<int> is_blue_change(n, 0); // blue_from_zero �����Ƿ����仯
		for (int i = 0; i < n; i++) {
			if (red_edges[0][i] == 1) {
				is_red_change[i] = 1;
			}
			if (blue_edges[0][i] == 1) {
				is_blue_change[i] = 1;
			}
		}
		while (is_change) {
			is_change = false;
			// �ȱ����������飬���Ը�����������
			for (int i = 0; i < n; i++) {
				if (red_edges[0][i] == -1 || is_red_change[i] == 0) {
					continue;
				}
				is_red_change[i] = 0;
				for (int j = 0; j < n; j++) {
					if (blue_edges[i][j] > 0) {
						if (blue_edges[0][j] == -1 || blue_edges[i][j] + red_edges[0][i] < blue_edges[0][j]) {
							blue_edges[0][j] = blue_edges[i][j] + red_edges[0][i];
							is_blue_change[j] = 1;
							is_change = true;
						}
					}
				}
			}
			// �ٱ����������飬���Ը��ĺ�������
			for (int i = 0; i < n; i++) {
				if (blue_edges[0][i] == -1 || is_blue_change[i] == 0) {
					continue;
				}
				is_blue_change[i] = 0;
				for (int j = 0; j < n; j++) {
					if (red_edges[i][j] > 0) {
						if (red_edges[0][j] == -1 || red_edges[i][j] + blue_edges[0][i] < red_edges[0][j]) {
							red_edges[0][j] = red_edges[i][j] + blue_edges[0][i];
							is_red_change[j] = 1;
							is_change = true;
						}
					}
				}
			}
		}

		// ���ɴ�0��ʼ�����飬�ó����ս��
		std::vector<int> result(n, -1);
		for (int i = 0; i < n; i++) {
			result[i] = red_edges[0][i];
			if (blue_edges[0][i] == -1) {
				continue;
			}
			else if(blue_edges[0][i] < red_edges[0][i] || red_edges[0][i] == -1){
				result[i] = blue_edges[0][i];
			}
		}
		result[0] = 0;
		return result;
	}
};

#endif // __leet_code_1129_h__