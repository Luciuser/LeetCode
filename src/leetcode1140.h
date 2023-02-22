/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-22 10:14:12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1140.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-22 11:14:45
 * @Editor: Bingyang Jin
 * @Description: create MEMORY_SEARCH_DFS_METHOD, TIME 48ms, 22.62%, MEMORY 14.9MB and 5.36%
 */

 /*
 * @EditTime: 2023-02-22 13:17:37
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_METHOD, TIME 12ms, 85.12%, MEMORY 9.7MB and 73.22%
 */

#ifndef __leet_code_1140_h__ 
#define __leet_code_1140_h__

#include<iostream>
#include<vector>

//#define MEMORY_SEARCH_DFS_METHOD // ���仯����+DFS��TIME 48ms, 22.62%, MEMORY 14.9MB and 5.36%
#define DYNAMIC_METHOD // ��̬�滮��TIME 12ms, 85.12%, MEMORY 9.7MB and 73.22%

#ifdef DYNAMIC_METHOD
class Solution {
public:
	int stoneGameII(std::vector<int>& piles) {
		// ��̬�滮���� dp[i][m] ��ʾȡ�� i-1 ��ʯͷ��ʣ�� [i, n] ��ʯͷ���ҵ�ǰ M = m ʱ����ȡʯͷ�����ܻ�õ����ʯ����
		// ��ô��� i+2*m >= piles.size()������ȡ���˿���ȫ�����ߣ���ʱ�У�
		//				dp[i][m] = accumulate(piles.begin()+i, piles.end(), 0);
		// ���򣬿������ȫ�����ܵ�һ�� M��ö�ٲ�Ѱ�����Ŀ���ȡֵ

		int n = piles.size();
		std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, 0));

		int sum_last = 0;
		for (int i = n - 1; i >= 0; i--) {
			sum_last += piles[i];
			for (int m = 1; m <= n; m++) {
				if (i + 2 * m >= n) {
					dp[i][m] = sum_last;
				}
				else {
					int temp = std::numeric_limits<int>::max();
					for (int x = 1; x <= 2 * m; x++) {
						if (dp[i + x][x < m ? m : x] < temp) {
							temp = dp[i + x][x < m ? m : x];
						}
					}
					dp[i][m] = sum_last - temp;
				}
			}
		}

		return dp[0][1];
	}

};
#endif // DYNAMIC_METHOD

#ifdef MEMORY_SEARCH_DFS_METHOD
class Solution {
public:
	int stoneGameII(std::vector<int>& piles) {
		int alice = 0;
		int bob = 0;
		int m = 1;
		bool is_alice_first = true;
		record_alice = std::vector<std::vector<std::vector<int>>>(piles.size(), std::vector<std::vector<int>>(2, std::vector<int>(50, -1))); // record[i][j][m] ��ʾ�ֵ��� index ʱ���� j ����ȡ����ǰ m ʱ��alice �õ���ʯ����
		record_bob = std::vector<std::vector<std::vector<int>>>(piles.size(), std::vector<std::vector<int>>(2, std::vector<int>(50, -1))); // record[i][j][m] ��ʾ�ֵ��� index ʱ���� j ����ȡ����ǰ m ʱ��bob �õ���ʯ����

		dfs(piles, m, 0, is_alice_first, &alice, &bob);

		return alice;
	}

private:

	void dfs(const std::vector<int>&piles, const int m, const int index, const bool is_alice_first, int *alice, int *bob) {

		if (index + m * 2 >= piles.size()) {
			int sum = 0;
			for (int i = 1; i <= 2 * m && i + index - 1 < piles.size(); i++) {
				sum += piles[i + index - 1];
			}
			if (is_alice_first) {
				*alice = sum;
				*bob = 0;
			}
			else {
				*alice = 0;
				*bob = sum;
			}
			return;
		}
		int add_this = 0;
		int alice_max = 0;
		int bob_max = 0;
		for (int i = 1; i <= 2 * m; i++) {
			add_this += piles[i + index - 1];
			int alice_next = 0;
			int bob_next = 0;
			int m_next = i < m ? m : i;
			if (m_next > 50) {
				m_next = 50;
			}

			if (index + i > piles.size()) {
				continue;
			}
			if (record_alice[index + i][is_alice_first ? 0 : 1][m_next - 1] == -1) {
				dfs(piles, m_next, index + i, !is_alice_first, &alice_next, &bob_next);
				record_alice[index + i][is_alice_first ? 0 : 1][m_next - 1] = alice_next;
				record_bob[index + i][is_alice_first ? 0 : 1][m_next - 1] = bob_next;
			}
			else {
				alice_next = record_alice[index + i][is_alice_first ? 0 : 1][m_next - 1];
				bob_next = record_bob[index + i][is_alice_first ? 0 : 1][m_next - 1];
			}

			if (is_alice_first) {
				int add_temp = add_this + alice_next;
				if (add_temp > alice_max) {
					alice_max = add_temp;
					bob_max = bob_next;
				}
			}
			else {
				int add_temp = add_this + bob_next;
				if (add_temp > bob_max) {
					bob_max = add_temp;
					alice_max = alice_next;
				}
			}
		}

		*alice = alice_max;
		*bob = bob_max;
	}

	std::vector<std::vector<std::vector<int>>> record_alice;
	std::vector<std::vector<std::vector<int>>> record_bob;
};
#endif // MEMORY_SEARCH_DFS_METHOD

#endif // __leet_code_1140_h__