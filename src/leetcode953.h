#ifndef __leet_code_953__
#define __leet_code_953__

#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
	bool isAlienSorted(std::vector<std::string>& words, std::string order) {
		
		std::map<char, int> characterNum;
		for (int i = 0; i < order.size(); i++) {
			characterNum[order[i]] = i;
		}
		
		bool success = true;
		for (int i = 0; i < words.size() - 1; i++) {
			int j = i + 1;

			int length = words[i].size();
			if (length < words[j].size()) {
				length = words[j].size();
			}

			for (int k = 0; k < length; k++) {
				int iNum, jNum;
				if (words[i].size() <= k) {
					iNum = -1;
				}
				else {
					iNum = characterNum[words[i][k]];
				}
				
				if (words[j].size() <= k) {
					jNum = -1;
				}
				else {
					jNum = characterNum[words[j][k]];
				}

				if (iNum < jNum) {
					break;
				}
				else if (iNum == jNum) {
					continue;
				}
				else {
					success = false;
					break;
				}
			}

			if (success == false) {
				break;
			}
		}

		return success;
	}
};

#endif // !__leet_code_953__