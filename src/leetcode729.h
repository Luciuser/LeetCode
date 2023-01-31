/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-31 10:21:10
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode729.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-31 10:28:54
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 136ms, 34.74%, MEMORY 36.6MB and 88.96%
 */

#ifndef __leet_code_729_h__
#define __leet_code_729_h__

#include<vector>

class MyCalendar {
public:
	MyCalendar() {

	}

	bool book(int start, int end) {

		for (int i = 0; i < calendar_.size(); i++) {
			if (start >= calendar_[i].second || end <= calendar_[i].first) {
				continue;
			}
			return false;
		}

		calendar_.push_back(std::pair<int, int>(start, end));
		return true;
	}

private:
	std::vector<std::pair<int, int>> calendar_;

};

#endif // __leet_code_729_h__