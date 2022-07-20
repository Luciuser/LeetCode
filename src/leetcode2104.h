#ifndef __leet_code_2104__
#define __leet_code_2104__

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

struct SonArray {
	long long max;
	long long min;
};

class Solution {
public:

	long long subArrayRanges(vector<int>& nums) {

		long long sum = 0;
		
		vector<SonArray> sonArrayVec;
		for (int i = 1; i < nums.size(); i++) {
			long long temp = 0;
			SonArray crtArray;
			crtArray.max = nums[i - 1];
			crtArray.min = nums[i - 1];
			sonArrayVec.push_back(crtArray);

			for (int j = 0; j < sonArrayVec.size(); j++) {
				if (nums[i] > sonArrayVec[j].max) {
					sonArrayVec[j].max = nums[i];
				}
				if (nums[i] < sonArrayVec[j].min) {
					sonArrayVec[j].min = nums[i];
				}
				temp += sonArrayVec[j].max - sonArrayVec[j].min;
			}
			sum += temp;
		}

		return sum;
	}
};

#endif // !__leet_code_2104__