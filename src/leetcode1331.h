/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-28 00:24:24
 * @FilePath: /src/leetcode1331.h
  * @Description: create the file and hash method, TIME 153 ms, MEMORY 51.3 MB
 */

#ifndef __leet_code_1331__
#define __leet_code_1331__

#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
	std::vector<int> arrayRankTransform(std::vector<int>& arr) {
		std::map<int, std::vector<int>> num2count;
		for (int i = 0; i < arr.size(); i++) {
			num2count[arr[i]].push_back(i);
		}

		int temp = 1;
		std::vector<int> result(arr.size(), -1);
		for (auto iter = num2count.begin(); iter != num2count.end(); iter++) {
			auto vec = (*iter).second;
			for (int i = 0; i < vec.size(); i++) {
				result[vec[i]] = temp;
			}
			temp++;
		}

		return result;
	}
};

#endif // __leet_code_1331__