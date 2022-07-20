#ifndef __leet_code_1089__
#define __leet_code_1089__

#include<iostream>
#include<vector>
#include<queue>

//#define QUEUE_METHOD // 队列存储方法
#define DOUBLE_PTR_METHOD // 双指针

#ifdef QUEUE_METHOD
class Solution {
public:
	void duplicateZeros(std::vector<int>& arr) {
		std::queue<int> temp;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 0) {
				temp.push(0);
			}
			temp.push(arr[i]);
			int crt = temp.front();
			temp.pop();
			arr[i] = crt;
		}
		return;
	}
};
#endif // QUEUE_METHOD

#ifdef DOUBLE_PTR_METHOD
class Solution {
public:
	void duplicateZeros(std::vector<int>& arr) {
		int i = 0, j = 0;
		while (j<arr.size())
		{
			if (arr[i] == 0) {
				j++;
			}
			i++;
			j++;
		}
		i--;
		j--;

		while (i >= 0) {
			if (arr[i] == 0) {
				if (j >= arr.size()) {
					j--;
				}
				else {
					arr[j] = 0;
					j--;
				}
			}
			arr[j] = arr[i];
			i--;
			j--;
		}

		return;
	}
};
#endif // DOUBLE_PTR_METHOD



#endif // __leet_code_1089__