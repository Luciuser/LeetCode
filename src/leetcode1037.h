#ifndef __leet_code_1037__
#define __leet_code_1037__

#include<iostream>
#include<vector>

class Solution {
public:
	bool isBoomerang(std::vector<std::vector<int>>& points) {

		double abx = points[1][0] - points[0][0];
		double aby = points[1][1] - points[0][1];

		double acx = points[2][0] - points[0][0];
		double acy = points[2][1] - points[0][1];

		// 有两个点相同
		if ((abx == 0 && aby == 0) ||
			(acx == 0 && acy == 0) ||
			(abx == acx && aby == acy)
			) {
			return false;
		}

		// 判断是否平行
		if (acx == 0 && abx == 0) {
			return false;
		}
		else {
			double k = abx / acx;
			if (aby == k * acy) {
				return false;
			}
			else{
				return true;
			}
		}

	}
};

#endif // __leet_code_1037__