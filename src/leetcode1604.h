/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-07 00:31:51
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1604.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-07 00:47:45
 * @Editor: Bingyang Jin
 * @Description: create MAP_SET_METHOD, TIME 308ms, 34.72%, MEMORY 116.1MB and 13.89%
 */

#ifndef __leet_code_1604_h__
#define __leet_code_1604_h__

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>

class Solution {
public:
	std::vector<std::string> alertNames(std::vector<std::string>& keyName, std::vector<std::string>& keyTime) {
		std::map<std::string, std::set<std::string>> name_record;
		for (int i = 0; i < keyName.size(); i++) {
			name_record[keyName[i]].emplace(keyTime[i]);
		}

		std::vector<std::string> result;
		for (auto iter = name_record.begin(); iter != name_record.end(); iter++) {
			if ((*iter).second.size() < 2) {
				continue;
			}
			std::string name = (*iter).first;
			auto begin = (*iter).second.begin();
			auto end = (*iter).second.begin();
			end++;
			end++;
			while (end != (*iter).second.end()){
				std::string begin_time = *begin;
				std::string end_time = *end;
				int hour_time = (end_time[0] - '0') * 10 + (end_time[1] - '0') - (begin_time[0] - '0') * 10 - (begin_time[1] - '0');
				int minute_time = (end_time[3] - '0') * 10 + (end_time[4] - '0') - (begin_time[3] - '0') * 10 - (begin_time[4] - '0');
				if (hour_time * 60 + minute_time <= 60) {
					result.emplace_back(name);
					break;
				}
				begin++;
				end++;
			} 
		}

		return result;
	}
};

#endif // __leet_code_1604_h__