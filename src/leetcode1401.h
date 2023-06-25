/*
 * @Author: Bingyang Jin
 * @Date: 2023-06-25 08:18:46
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1401.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-06-23 09:28:51
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 7.6MB and 33.05%
 */

#ifndef __leet_code_1401_h__
#define __leet_code_1401_h__

#include<iostream>

class Solution {
public:
	long long distance(int ux, int uy, int vx, int vy) {
		return (long long)pow(ux - vx, 2) + (long long)pow(uy - vy, 2);
	}

	bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
		/* 圆心在矩形内部 */
		if (x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2) {
			return true;
		}
		/* 圆心在矩形上部*/
		if (x1 <= xCenter && xCenter <= x2 && y2 <= yCenter && yCenter <= y2 + radius) {
			return true;
		}
		/* 圆心在矩形下部*/
		if (x1 <= xCenter && xCenter <= x2 && y1 - radius <= yCenter && yCenter <= y1) {
			return true;
		}
		/* 圆心在矩形左部*/
		if (x1 - radius <= xCenter && xCenter <= x1 && y1 <= yCenter && yCenter <= y2) {
			return true;
		}
		/* 圆心在矩形右部*/
		if (x2 <= xCenter && xCenter <= x2 + radius && y1 <= yCenter && yCenter <= y2) {
			return true;
		}
		/* 矩形左上角 */
		if (distance(xCenter, yCenter, x1, y2) <= radius * radius) {
			return true;
		}
		/* 矩形左下角 */
		if (distance(xCenter, yCenter, x1, y1) <= radius * radius) {
			return true;
		}
		/* 矩形右上角 */
		if (distance(xCenter, yCenter, x2, y2) <= radius * radius) {
			return true;
		}
		/* 矩形右下角 */
		if (distance(xCenter, yCenter, x1, y2) <= radius * radius) {
			return true;
		}
		/* 无交点 */
		return false;
	}
};

#endif // __leet_code_1401_h__