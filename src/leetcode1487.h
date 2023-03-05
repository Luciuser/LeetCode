/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-03 16:19:48
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1487.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-03 16:31:24
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 180ms, 39.34%, MEMORY 57.1MB and 96.72%
 */

#ifndef __leet_code_1487_h__ 
#define __leet_code_1487_h__

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

class Solution {
public:
	std::vector<std::string> getFolderNames(std::vector<std::string>& names) {
		std::unordered_map<std::string, int> exist_name;
		
		for (int i = 0; i < names.size(); i++) {
			std::string name = names[i];
			if (exist_name.count(name) == 0) {
				exist_name[name] = 1;
			}
			else {
				int k = exist_name[name];
				while (true) {
					std::string new_name = name + "(" + std::to_string(k) + ")";
					if (exist_name.count(new_name) == 0) {
						exist_name[name] = k + 1;
						exist_name[new_name] = 1;
						names[i] = new_name;
						break;
					}
					k++;
				}
			}
		}
		
		return names;
	}
};
#endif // __leet_code_1487_h__