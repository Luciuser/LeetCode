/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-11 10:42:02
 * @Editor: Bingyang Jin
 * @FilePath: /src/audition1705.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-28 16:46:09
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_METHOD, TIME 128ms, 42.06%, MEMORY 95.9MB and 9.34%
 */

#ifndef __leet_code_audition_17_05__
#define __leet_code_audition_17_05__

#include<iostream>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<vector>

class Solution {
public:
	std::vector<std::string> findLongestSubarray(std::vector<std::string>& array) {
		// ����ĸΪ 1 ������Ϊ -1���������ת��Ϊ��ȡһ��������飬���Ϊ 0
		// ���Բ���ǰ׺�����飬����� prefix������������� prefix[j] - prefix[i] == 0 ʱ��j - i �����ֵ
		// ��һ������ͨ�� vector �� unordered_map ��¼ÿһλ�Լ������Ӧ�ģ�ֵ��ͬ��������������ֵ

		if (array.size() <= 1) {
			return std::vector<std::string>();
		}

		std::vector<int> prefix(array.size() + 1, 0);
		for (int i = 1; i < prefix.size(); i++) {
			int temp = 0;
			for (int j = 0; j < array[i - 1].size(); j++) {
				if ('0' <= array[i-1][j] && array[i-1][j] <= '9') {
					temp++;
					break;
				}
				else if('A' <= array[i-1][j] && array[i-1][j] <= 'Z') {
					temp--;
					break;
				}
				else if ('a' <= array[i-1][j] && array[i-1][j] <= 'z') {
					temp--;
					break;
				}
			}
			prefix[i] = prefix[i - 1] + temp;
		}

		std::unordered_map<int, int> value_index;
		for (int i = 0; i < prefix.size(); i++) {
			value_index[prefix[i]] = i - 1;
		}

		int left = 0;
		int max = -1;
		std::vector<int> record(prefix.size(), -1);
		for (int i = 0; i < prefix.size(); i++) {
			record[i] = value_index[prefix[i]];
			if (record[i] != i && record[i] - i>max) {
				max = record[i] - i;
				left = i;
			}
		}

		std::vector<std::string> result;
		for (int i = left; i <= max + left; i++) {
			result.push_back(array[i]);
		}
		return result;
	}

};

#endif // __leet_code_audition_17_09__