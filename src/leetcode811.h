/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-08 13:16:26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode811.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-07 13:44:45
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 16ms, 42.10%, MEMORY 11.4MB and 22.56%
 */

#ifndef __leet_code_811__
#define __leet_code_811__

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

class Solution {
public:
	std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains) {
		std::unordered_map<std::string, int> name;

		for (int i = 0; i < cpdomains.size(); i++) {
			std::string domain = cpdomains[i];
			int j = 0;
			int number = 0;
			while (true) {
				if (domain[j] == ' ') {
					j++;
					break;
				}
				number = number * 10 + domain[j] - '0';
				j++;
			}
			
			std::string sub = domain.substr(j);
			name[sub] += number;

			int pointi = sub.find_first_of(".");
			while (pointi != std::string::npos) {
				sub = sub.substr(pointi + 1);
				name[sub] += number;	
				pointi = sub.find_first_of(".");
			}

		}

		std::vector<std::string> result;
		for (auto iter = name.begin(); iter != name.end(); iter++) {
			std::string temp = std::to_string((*iter).second) + " " + (*iter).first;
			result.push_back(temp);
		}

		return result;
	}
};

#endif // __leet_code_811__