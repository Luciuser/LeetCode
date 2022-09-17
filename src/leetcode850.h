/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-16 15:52:26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode850.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-17 14:20:29
 * @Editor: Bingyang Jin
 * @Description: create DISCRETE_SCANLINE, TIME 24ms, 11%, MEMORY 14.5MB and 10%
 */

#ifndef __leet_code_850__
#define __leet_code_850__

#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
	int rectangleArea(std::vector<std::vector<int>>& rectangles) {

		// 按 y 轴，建立相应map，O(n)
		std::map<int, std::vector<int>> yBoundary; // y 方向的边界
		for (int i = 0; i < rectangles.size(); i++) {
			yBoundary[rectangles[i][1]].push_back(i);
			yBoundary[rectangles[i][3]].push_back(i);
		}
		
		// 扫描线进行扫描
		auto iter = yBoundary.begin();
		std::map<int, int> parts; // 当前扫描到的长方形的序号
		// 读入 y 最小值情况下扫描到的长方形，O(n)
		int before = (*iter).first; // 前一根扫描线的 y 值
		for (int i = 0; i < (*iter).second.size(); i++) {
			parts[(*iter).second[i]] = 1;
		}
		iter++;
		long long result = 0;
		for (; iter != yBoundary.end(); iter++) {
			long long yLength = (*iter).first - before;
			before = (*iter).first;
			// 计算当前扫描线 x 方向的长度
			std::map<int, int>xBoundary; // 当前扫描线扫到 x 的边界
			for (auto partIter = parts.begin(); partIter != parts.end(); partIter++) {
				if ((*partIter).second != 0) {
					int xLeft = rectangles[(*partIter).first][0];
					int xRight = rectangles[(*partIter).first][2];
					if (xBoundary.count(xLeft) == 0) {
						xBoundary[xLeft] = 1;
					}
					else {
						xBoundary[xLeft]++;
					}
					if (xBoundary.count(xRight) == 0) {
						xBoundary[xRight] = -1;
					}
					else {
						xBoundary[xRight]--;
					}
				}
			}

			long long xLength = 0;
			int xBefore = -1;
			int temp = 0;
			for (auto xIter = xBoundary.begin(); xIter != xBoundary.end(); xIter++) {
				if (xBefore == -1) {
					if ((*xIter).second > 0) {
						xBefore = (*xIter).first;
						temp = (*xIter).second;
					}
					else {
						std::cout << "WRONG 1" << std::endl;
						return -1;
					}
				}
				else {
					temp += (*xIter).second;
					if (temp < 0) {
						std::cout << "WRONG 2" << std::endl;
						return -2;
					}
					else if(temp == 0) {
						xLength += (*xIter).first - xBefore;
						xBefore = -1;
					}
				}
			}

			result += xLength * yLength;
			if (result > 1e9 + 7) {
				result = result % ((int)1e9 + 7);
			}

			// 更新 parts
			for (int i = 0; i < (*iter).second.size(); i++) {
				if (parts.count((*iter).second[i]) == 0) {
					parts[(*iter).second[i]] = 1;
				}
				else {
					parts[(*iter).second[i]] = 0;
				}
			}
		}

		return result;
	}
};

#endif // __leet_code_850__