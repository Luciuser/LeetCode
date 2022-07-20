#ifndef __leet_code_1200__
#define __leet_code_1200__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
		std::sort(arr.begin(), arr.end());
		
		std::vector<std::vector<int>> result;
		int min = arr[1] - arr[0];
		for (int i = 0; i < arr.size() - 1; i++) {
			if (min > arr[i + 1] - arr[i]) {
				min = arr[i + 1] - arr[i];
			}
		}
		for (int i = 0; i < arr.size() - 1; i++) {
			if (min == arr[i + 1] - arr[i]) {
				std::vector<int> temp;
				temp.push_back(arr[i]);
				temp.push_back(arr[i + 1]);
				result.push_back(temp);
			}
		}
		
		return result;
	}
};

#endif // __leet_code_1200__