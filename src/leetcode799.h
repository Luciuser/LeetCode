/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-20 13:37:01
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode799.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-20 14:18:00
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 12ms, 47.28%, MEMORY 21.9MB and 31.95%
 */

#ifndef __leet_code_799__
#define __leet_code_799__

#include<iostream>
#include<vector>

class Solution {
public:
	double dfs(int query_row, int query_glass) {
		double input = glasses_input[query_row][query_glass];
		if (input < -1) {
			// �ñ���δ����¼����ݹ����ñ�
			input = 0;
			// ÿ�е�һ���������һ��ֻ�ܵݹ鵽һ�����������ܵݹ鵽����
			if (query_glass != 0) {
				input += dfs(query_row - 1, query_glass - 1);
			}
			if (query_row != query_glass) {
				input += dfs(query_row - 1, query_glass);
			}
			glasses_input[query_row][query_glass] = input;
		}

		// �ñ��Ѿ��ݹ���������ֱ�Ӷ�ֵ
		if (input < 1) {
			// ����һ��
			return 0;
		}
		else {
			// ÿһ���������������
			return (input - 1) / 2;
		}
	}

	double champagneTower(int poured, int query_row, int query_glass) {

		if (poured == 0) {
			return 0;
		}

		for (int i = 0; i <= query_row; i++) {
			std::vector<double> temp;
			for (int j = 0; j <= i; j++) {
				temp.push_back(-2);
			}
			glasses_input.push_back(temp);
		}
		glasses_input[0][0] = poured;

		dfs(query_row, query_glass);

		double result = glasses_input[query_row][query_glass];

		if (result >= 1) {
			return 1;
		}

		return result;
	}

private:
	std::vector<std::vector<double>> glasses_input;
};

#endif // __leet_code_799__