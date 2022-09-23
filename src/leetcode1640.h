/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-22 10:08:25
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1640.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-22 10:20:24
 * @Editor: Bingyang Jin
 * @Description: create HASH_MAP_METHOD, TIME 4ms, 82.16%, MEMORY 9.9MB and 50.19%
 */

#ifndef __leet_code_1640__
#define __leet_code_1640__

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
	bool canFormArray(std::vector<int>& arr, std::vector<std::vector<int>>& pieces) {

		std::unordered_map<int, int> pieceMap;
		for (int i = 0; i < pieces.size(); i++) {
			pieceMap[pieces[i][0]] = i;
		}

		int arri = 0;
		while (arri < arr.size()) {
			int key = arr[arri];
			if (pieceMap.count(key) == 0) {
				return false;
			}

			int index = pieceMap[key];
			for (int i = 0; i < pieces[index].size(); i++) {
				if (arr[arri] != pieces[index][i]) {
					return false;
				}
				arri++;
			}
		}

		return true;
	}
};

#endif // __leet_code_1640__