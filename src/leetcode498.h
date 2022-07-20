#ifndef __leet_code_498__
#define __leet_code_498__

#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
		std::vector<int> results;

		int m = mat.size();
		int n = mat[0].size();

		for (int i = 0; i <= m + n - 2; i++) {
			for (int j = 0; j <= i; j++) {
				if (i % 2 == 0 && i - j < m && j < n) {
					results.push_back(mat[i-j][j]);
				}
				else if(i % 2 == 1 && j < m && i - j < n){
					results.push_back(mat[j][i - j]);
				}
			}
		}

		return results;
	}
};

#endif // __leet_code_498__