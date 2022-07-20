#ifndef __sword_offer_II_114__
#define __sword_offer_II_114__

#include<iostream>
#include<vector>
#include<map>

class Solution {
public:

	std::string alienOrder(std::vector<std::string>& words) {

		// 判断第一个单词是否直接出错
		std::map<char, int> char2int;
		std::string temp = "";
		for (int i = 0; i < words[0].size(); i++) {
			if (i == 0) {
				char2int[words[0][i]] = 0;
				temp += words[0][i];
			}
			else {
				int beforeInt = char2int[words[0][i - 1]];
				if (char2int.count(words[0][i]) == 0) {
					// 第 i 个字母没出现过
					char2int[words[0][i]] = beforeInt + 1;
					temp += words[0][i];
				}
				else {
					// 第 i 个字母又出现了
					if (char2int[words[0][i]] < beforeInt) {
						// 第 i 个字母比前一个字母位序靠前，因此第一个单词出错，直接退出
						return "";
					}
					else {
						continue;
					}
				}
			}
		}

		std::vector<std::string> result;
		result.push_back(temp);

		for (int i = 1; i < words.size(); i++) {
			std::string beforeWord = words[i - 1];
			int beforeWordSize = beforeWord.size();

			for (int j = 0; j < words[i].size(); j++) {
				char crtChar = words[i][j];
				if (j == 0) {
					// 不需要和自身前一个字母比较
					if (char2int.count(crtChar) == 0) {
						// 该字母不存在，需要加入 result 中
						std::vector<std::string> tempResult;
						for (int k = 0; k < result.size(); k++) {
							int beforeWordInt = result[k].find_first_of(beforeWord[j]);
							for (int m = beforeWordInt; m < result[k].size() + 1; m++) {
								std::string insertBefore = result[k].substr(0, m);
								std::string insertAfter = result[k].substr(m, result[k].size());
								std::string temp = insertBefore + crtChar + insertAfter;
								tempResult.push_back(temp);
							}
							result.erase(result.begin() + k);
							k--;
						}
						for (int k = 0; k < tempResult.size(); k++) {
							result.push_back(tempResult[k]);
						}
					}
					else {
						// 该字母存在，进行比较
						bool isRight = false;
						for (int k = 0; k < result.size(); k++) {
							int beforeWordInt = result[k].find_first_of(beforeWord[j]);
							int crtInt = result[k].find_first_of(crtChar);
							if (beforeWordInt <= crtInt) {
								// 成功了
								continue;
							}
							else {
								// 失败了，需删除该可能的排序结果
								result.erase(result.begin() + k);
								k--;
							}
						}
					}
				}
				else {
					// TODO
				}
			}
		}

		return result[0];
	}
};

#endif //__sword_offer_II_114__