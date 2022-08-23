/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-23 14:40:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode782.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-23 14:48:04
 * @Editor: Bingyang Jin
 * @Description: create ARRAY_METHOD, TIME 10ms, 72.34%, MEMORY 81.7MB and 37.79%
 */

#ifndef __leet_code_1656__
#define __leet_code_1656__

#include<iostream>
#include<vector>
#include<string>

#define ARRAY_METHOD // Êý×é±éÀú

class OrderedStream {
public:
	OrderedStream(int n) {
		ptr = 1;
		streams = std::vector<std::string>(n+1, "");
	}

	std::vector<std::string> insert(int idKey, std::string value) {
		streams[idKey] = value;
		std::vector<std::string> result;
		if (idKey == ptr) {
			for (int i = ptr ; i < streams.size(); i++) {
				if (streams[i] == "") {
					ptr = i;
					break;
				}
				else {
					result.push_back(streams[i]);
				}
			}
		}
		return result;
	}
private:
	int ptr;
	std::vector<std::string> streams;
};

#endif // __leet_code_1656__