#ifndef __sword_offer_II_114__
#define __sword_offer_II_114__

#include<iostream>
#include<vector>
#include<map>

class Solution {
public:

	std::string alienOrder(std::vector<std::string>& words) {

		// �жϵ�һ�������Ƿ�ֱ�ӳ���
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
					// �� i ����ĸû���ֹ�
					char2int[words[0][i]] = beforeInt + 1;
					temp += words[0][i];
				}
				else {
					// �� i ����ĸ�ֳ�����
					if (char2int[words[0][i]] < beforeInt) {
						// �� i ����ĸ��ǰһ����ĸλ��ǰ����˵�һ�����ʳ���ֱ���˳�
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
					// ����Ҫ������ǰһ����ĸ�Ƚ�
					if (char2int.count(crtChar) == 0) {
						// ����ĸ�����ڣ���Ҫ���� result ��
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
						// ����ĸ���ڣ����бȽ�
						bool isRight = false;
						for (int k = 0; k < result.size(); k++) {
							int beforeWordInt = result[k].find_first_of(beforeWord[j]);
							int crtInt = result[k].find_first_of(crtChar);
							if (beforeWordInt <= crtInt) {
								// �ɹ���
								continue;
							}
							else {
								// ʧ���ˣ���ɾ���ÿ��ܵ�������
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