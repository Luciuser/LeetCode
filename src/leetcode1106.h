/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-05 10:40:33
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1106.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-05 11:02:27
 * @Editor: Bingyang Jin
 * @Description: create RECURSION_METHOD, TIME 12ms, 41.62%, MEMORY 5.9MB and 31.89%
 */

 /*
 * @EditTime: 2022-11-05 11:23:19
 * @Editor: Bingyang Jin
 * @Description: create STACK_METHOD, TIME 4ms, 89.86%, MEMORY 6.9MB and 80.40%
 */

#ifndef __leet_code_1106__
#define __leet_code_1106__

#include<string>
#include<vector>
#include<stack>
#include<assert.h>

//#define RECURSION_METHOD // 递归法，TIME 12ms, 41.62%, MEMORY 5.9MB and 31.89%
#define STACK_METHOD // 栈法，TIME 4ms, 89.86%, MEMORY 6.9MB and 80.40%

#ifdef RECURSION_METHOD
class Solution {
public:
	bool parseBoolExpr(std::string expression) {
		int n = expression.size();
		switch (expression[0])
		{
		case 't':return true;
		case 'f':return false;
		case '!': {
			std::string substring = expression.substr(2, n - 3);
			return !parseBoolExpr(substring);
		}
		case '&': {
			// 构建子字符串数组
			std::vector<std::string> substrings;
			int i = 2;
			int before = 2;
			int left = 0;
			while (true) {
				if (i >= n - 1) {
					break;
				}
				if (expression[i] == '(') {
					left++;
				}
				if (expression[i] == ')') {
					left--;
				}
				if (expression[i] == ',' && left == 0) {
					std::string str = expression.substr(before, i - before);
					substrings.push_back(str);
					before = i + 1;
				}
				i++;
			}
			std::string str = expression.substr(before, n - 1 - before);
			substrings.push_back(str);

			// 判断
			for (int i = 0; i < substrings.size(); i++) {
				if (parseBoolExpr(substrings[i]) == false) {
					return false;
				}
			}
			return true;
		}
		case '|': {
			// 构建子字符串数组
			std::vector<std::string> substrings;
			int i = 2;
			int before = 2;
			int left = 0;
			while (true) {
				if (i >= n - 1) {
					break;
				}
				if (expression[i] == '(') {
					left++;
				}
				if (expression[i] == ')') {
					left--;
				}
				if (expression[i] == ',' && left == 0) {
					std::string str = expression.substr(before, i - before);
					substrings.push_back(str);
					before = i + 1;
				}
				i++;
			}
			std::string str = expression.substr(before, n - 1 - before);
			substrings.push_back(str);

			// 判断
			for (int i = 0; i < substrings.size(); i++) {
				if (parseBoolExpr(substrings[i]) == true) {
					return true;
				}
			}
			return false;
		}
		default:
			assert(false);
			break;
		}

		return true;
	}
};
#endif // RECURSION_METHOD

#ifdef STACK_METHOD
class Solution {
public:
	bool parseBoolExpr(std::string expression) {

		std::stack<char> str;

		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == ',') {
				continue;
			}
			if (expression[i] == ')') {
				// 进行出栈操作，计算表达式
				int t = 0;
				int f = 0;
				while (true) {
					char c = str.top();
					if (c == 't') {
						t++;
					}
					else if (c == 'f') {
						f++;
					}
					else if (c == '(') {
						str.pop();
						c = str.top();
						str.pop();

						if (c == '!') {
							if (t + f == 1) {
								if (t == 1) {
									str.push('f');
								}
								else {
									str.push('t');
								}
							}
							else {
								assert(false);
							}
						}
						else if (c == '&') {
							if (f > 0) {
								str.push('f');
							}
							else {
								str.push('t');
							}
						}
						else if (c == '|') {
							if (t > 0) {
								str.push('t');
							}
							else {
								str.push('f');
							}
						}

						break;
					}
					str.pop();
				}

				continue;
			}

			str.push(expression[i]);
		}

		bool result = str.top() == 't' ? true : false;

		return result;
	}
};
#endif // STACK_METHOD


#endif //__leet_code_1106__