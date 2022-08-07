/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-07 13:07:28
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode636.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-07 15:06:16
 * @Editor: Bingyang Jin
 * @Description: create STACK_METHOD, TIME 12 ms and 95.05%, MEMORY 13.6 MB and 33.21%
 */

#ifndef __leet_code_636__
#define __leet_code_636__

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<assert.h>

class Function {
public:
	Function() {};
	Function(int _id, int _begin) { this->id = _id; this->begin = _begin; this->isBegin = true; }
	Function(int _id, int _begin, bool _isBegin) { this->id = _id; this->begin = _begin; this->isBegin = _isBegin; }
	Function(std::string log) {
		int temp = 0;
		int i;
		for (i = 0; i < log.size(); i++) {
			if (log[i] == ':') {
				this->id = temp;
				if (log[i + 1] == 's') {
					this->isBegin = true;
				}
				else {
					this->isBegin = false;
				}
				i++;
				break;
			}
			temp = temp * 10 + log[i] - '0';
		}
		for (; i < log.size(); i++) {
			if (log[i] == ':') {
				break;
			}
		}
		i++;
		temp = 0;
		for (; i < log.size(); i++) {
			temp = temp * 10 + log[i] - '0';
		}
		this->begin = temp;
	}

	bool isSameFunction(Function *f) {
		assert(this->isBegin);
		if (this->id == f->id) {
			if (this->isBegin == true && f->isBegin == false) {
				return true;
			}
		}
		assert(f->isBegin);
		return false;
	}

	int id;
	int begin;
	int time = 0;
	bool isBegin;	// 判断是否是开始戳
};

class Solution {
public:
	std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {
		std::vector<int> result(n, 0);	// 输出的结果
		std::stack<Function *> functions;	// 函数调用栈

		int tempTime = 0;
		for (int i = 0; i < logs.size(); i++) {
			Function *crtFunction = new Function(logs[i]);
			if (functions.size() == 0) {
				functions.push(crtFunction);
			}
			else {
				Function *topFunction = functions.top();
				if (topFunction->isSameFunction(crtFunction)) {
					int id = topFunction->id;
					result[id] += crtFunction->begin - topFunction->begin + 1;
					result[id] += topFunction->time;
					functions.pop();

					if (functions.size() != 0) {
						Function *fatherFunction = functions.top();
						fatherFunction->begin = crtFunction->begin + 1;
					}
				}
				else {
					topFunction->time += crtFunction->begin - topFunction->begin;
					topFunction->begin = crtFunction->begin;
					//tempTime = crtFunction->begin;
					functions.push(crtFunction);
				}
			}
		}

		return result;
	}
};

#endif // __leet_code_636__