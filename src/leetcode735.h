#ifndef __leet_code_735__
#define __leet_code_735__

#include<iostream>
#include<vector>

//#define VIOLENCE_METHOD // 暴力遍历法
#define STACK_METHOD // 栈方法

#ifdef VIOLENCE_METHOD
class Solution {
public:
	std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
		std::vector<int> result = asteroids;
		while (true) {
			bool isDelete = false;

			int n = result.size() - 1;
			for (int i = 0; i < n; i++) {
					if (result[i] > 0 && result[i + 1] < 0) {
						isDelete = true;
						if (result[i] + result[i + 1] > 0) {
							result.erase(result.begin() + i + 1);
						}
						else if (result[i] + result[i + 1] < 0) {
							result.erase(result.begin() + i);
						}
						else {
							result.erase(result.begin() + i);
							result.erase(result.begin() + i);
							n--;
						}
						n--;
					}
			}

			if (isDelete == false) {
				break;
			}
		}
		return result;
	}
};
#endif // VIOLENCE_METHOD

#ifdef STACK_METHOD
class Solution {
public:
	std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
		std::vector<int> result;
		
		result.push_back(asteroids[0]);
		for (int i = 1; i < asteroids.size(); i++) {
			if (result.size() > 0) {
				int left = result[result.size() - 1];
				int right = asteroids[i];

				if (left > 0 && right < 0) {

					while (true) {
						if (left < 0) {
							break;
						}
						if (left + right > 0) {
							break;
						}
						else if (left + right< 0) {
							result.erase(result.end() - 1);
							if (result.size() > 0) {
								left = result[result.size() - 1];
							}
							else {
								result.push_back(asteroids[i]);
								break;
							}
						}
						else {
							result.erase(result.end() - 1);
							break;
						}
					}

				}
				else{
					result.push_back(asteroids[i]);
				}
			}
			else {
				result.push_back(asteroids[i]);
			}
		}

		return result;
	}
};
#endif // STACK_METHOD




#endif // __leet_code_735__