/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-01 10:04:52
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2325.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-01 10:24:44
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 71.94%, MEMORY 6.8MB and 48.22%
 */

#ifndef __leet_code_2325_h__
#define __leet_code_2325_h__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	std::string decodeMessage(std::string key, std::string message) {
		
		std::vector<char> encode(26, ' ');
		char current = 'a';
		for (int i = 0; i < key.size(); i++) {
			if (key[i] != ' ' && encode[key[i] - 'a'] == ' ') {
				encode[key[i] - 'a'] = current;
				current++;
			}
		}

		for (int i = 0; i < message.size(); i++) {
			if (message[i] != ' ') {
				message[i] = encode[message[i] - 'a'];
			}
		}

		return message;
	}
};

#endif // __leet_code_2325_h__