/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-19 09:49:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1700.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-19 10:01:20
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 50.00%, MEMORY 8.6MB and 10.00%
 */

#ifndef __leet_code_1700__
#define __leet_code_1700__

#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
	int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
		
		int num0 = 0, num1 = 0;
		std::queue<int> stud;
		for (int i = 0; i < students.size(); i++) {
			stud.emplace(students[i]);
			students[i] == 0 ? num0++ : num1++;
		}

		int i = 0;
		while (i < sandwiches.size()) {
			if ((num0 == 0 && sandwiches[i] == 0) || (num1 == 0 && sandwiches[i] == 1)) {
				break;
			}
			int person = stud.front();
			stud.pop();
			if (person == sandwiches[i]) {
				i++;
				person == 0 ? num0-- : num1--;
			}
			else {
				stud.emplace(person);
			}
		}

		return num0 + num1;
	}
};

#endif // __leet_code_1700__