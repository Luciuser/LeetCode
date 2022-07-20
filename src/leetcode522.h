#ifndef __leet_code_522__
#define __leet_code_522__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:

	// 判断 child 是否是 father 的子串或相同，如果相同，返回0，如果是子串，返回1，如果不是子串，返回-1
	int isSubOrSame(std::string father, std::string child) {
		int fi = 0, ci = 0;
		while (true)
		{
			if (fi >= father.size() || ci >= child.size()) {
				break;
			}
			if (child[ci] == father[fi]) {
				fi++;
				ci++;
			}
			else {
				fi++;
			}
		}

		if (father.size() == child.size() && fi == ci) {
			return 0;
		}
		if (ci >= child.size()) {
			return 1;
		}
		return -1;
	}

	int findLUSlength(std::vector<std::string>& strs) {
		std::sort(strs.begin(), strs.end(), [=](std::string str1, std::string str2) -> bool {return str1.size() > str2.size(); });

		for (int i = 0; i < strs.size(); i++) {
			std::string crtString = strs[i];
			bool isDelete = false;
			for (int j = i + 1; j < strs.size(); j++) {
				if (isSubOrSame(crtString, strs[j]) == 0) {
					strs.erase(strs.begin() + j);
					j--;
					isDelete = true;
				}
				else if (isSubOrSame(crtString, strs[j]) == 1) {
					strs.erase(strs.begin() + j);
					j--;
				}
			}
			if (isDelete) {
				strs.erase(strs.begin() + i);
				i--;
			}
		}

		if (strs.size() == 0) {
			return -1;
		}

		return strs[0].size();
	}
};

#endif // __leet_code_522__