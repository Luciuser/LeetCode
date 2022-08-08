/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-08 13:35:42
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode761.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-08 15:03:03
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME WRONG(0ms, 100.00%), MEMORY 6.2 MB and 53.03%
 */

 /*
 * @EditTime: 2022-08-08 15:58:45
 * @Editor: Bingyang Jin
 * @Description: create DIVIDE_METHOD, TIME WRONG(0ms, 100.00%), MEMORY 6.4 MB and 10.60%
 */

#ifndef __leet_code_761__
#define __leet_code_761__

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

//#define VIOLENCE_METHOD	// �����ⷨ��ֱ�ӱ����Ƚϣ���ѭ������
#define DIVIDE_METHOD		// ���η�

#ifdef VIOLENCE_METHOD
class Solution {
public:
	std::string makeLargestSpecial(std::string s) {

		bool isChange = true;
		std::string result = s;
		while (isChange) {
			isChange = false;
			for (int i = 0; i < result.size(); i++) {
				if (result[i] == '0') {
					continue;
				}
				int num1 = 1;	// 1 ������
				int num0 = 0;	// 0 ������
				int end = -1;
				for (int j = i + 1; j < result.size(); j++) {
					result[j] == '1' ? num1++ : num0++;
					if (num1 == num0) {
						end = j;
						break;
					}
				}
				if (end == -1 || end >= result.size() - 1) {
					// û�ҵ���i��ʼ�������Ӵ������߸������Ӵ��ﵽ�ַ���ĩβ
					continue;
				}

				if (result[end + 1] == '0') {
					// û�����ڵ��Ӵ�
					continue;
				}
				num1 = 1;
				num0 = 0;
				int end2 = -1;
				for (int j = end + 2; j < result.size(); j++) {
					result[j] == '1' ? num1++ : num0++;
					if (num1 == num0) {
						end2 = j;
						break;
					}
				}
				if (end2 == -1) {
					// û�ҵ��� end+1 ��ʼ�������Ӵ�
					continue;
				}


				bool change = false;
				for (int j = 0; j < end2 - end; j++) {
					if (result[i + j] == '1' && result[end + 1 + j] == '0') {
						break;
					}
					if (result[i + j] == '0' && result[end + 1 + j] == '1') {
						change = true;
						break;
					}
				}
				if (change == false) {
					continue;
				}

				// �����滻
				std::string str1 = result.substr(0, i);
				std::string str2 = result.substr(i, end - i + 1);
				std::string str3 = result.substr(end + 1, end2 - end);
				std::string str4 = result.substr(end2 + 1, result.size() - end2 - 1);

				result = str1 + str3 + str2 + str4;
				isChange = true;
			}
		}

		return result;
	}
};
#endif // VIOLENCE_METHOD

#ifdef DIVIDE_METHOD
class Solution {
public:
	// ��֤����� s һ����һ����������
	std::string makeLargestSpecial(std::string s) {

		// �� s=="" �� s=="10"
		if (s.size() <= 2) {
			return s;
		}

		std::string result = "";

		// �֣���s�з�Ϊ����Ӵ���ÿ���Ӵ�ɾ����һ���ַ�1�����һ���ַ�0
		std::vector<std::string> subStrings;
		int temp = 0;
		int begin = 0;
		for (int i = 0; i < s.size(); i++) {
			s[i] == '1' ? temp++ : temp--;
			if (temp == 0) {
				std::string str = s.substr(begin + 1, i - begin - 1);
				begin = i + 1;
				// �ݹ鴦��ÿһ���Ӵ�
				str = makeLargestSpecial(str);
				subStrings.push_back("1" + str + "0");
			}
		}

		// �ϣ��Զ���Ӵ���������ͬʱ��ÿ���Ӵ�ǰ����1���Ӵ�������0
		std::sort(subStrings.begin(), subStrings.end(), [=](std::string a, std::string b) {
			std::string ab = a + b;
			std::string ba = b + a;
			return ab > ba;
		});
		for (int i = 0; i < subStrings.size(); i++) {
			result += subStrings[i];
		}

		return result;
	}
};
#endif // DIVIDE_METHOD




#endif // __leet_code_761__