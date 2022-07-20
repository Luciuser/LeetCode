#ifndef __leet_code_890__
#define __leet_code_890__

#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
	std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
		std::vector<int> patternInt;	// ģʽ���������0��ʼ��ӳ��
		std::map<char, int> patternCharInt; // pattern �а�����Щ�ַ����Լ���Щ�ַ������

		patternInt.push_back(0);
		patternCharInt[pattern[0]] = 0;
		int temp = 1;
		for (int i = 1; i < pattern.size(); i++) {
			if (patternCharInt.count(pattern[i]) == 0) {
				patternInt.push_back(temp);
				patternCharInt[pattern[i]] = temp;
				temp++;
			}
			else {
				patternInt.push_back(patternCharInt[pattern[i]]);
			}
		}
		patternCharInt.clear();
		
		std::vector<std::string> result = words;
		for (int i = 0; i < result.size(); i++) {
			std::string crtString = result[i];
			std::map<char, int> crtStringCharInt;

			bool isRight = true;
			crtStringCharInt[crtString[0]] = 0;
			int tempNum = 1;
			for (int j = 1; j < crtString.size(); j++) {
				if (crtStringCharInt.count(crtString[j]) == 0) {
					// û���ҵ�
					if (tempNum != patternInt[j]) {
						// ģʽ��ƥ��
						isRight = false;
						break;
					}
					crtStringCharInt[crtString[j]] = tempNum;
					tempNum++;
				}
				else {
					// �ҵ���
					if (crtStringCharInt[crtString[j]] != patternInt[j]) {
						// ģʽ��ƥ��
						isRight = false;
						break;
					}
				}
			}

			if (isRight == false) {
				result.erase(result.begin() + i);
				i--;
			}

		}

		return result;
	}
};

#endif // __leet_code_890__