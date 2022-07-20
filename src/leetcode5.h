#ifndef __leet_code_5__
#define __leet_code_5__

#include<iostream>
#include<queue>

//#define ITERATROR_METHOD // 用队列存储当前需要检测的子串
#define SLIDE_WINDOW_METHOD // 滑动窗口

#ifdef ITERATROR_METHOD
class Solution {
public:
	std::string longestPalindrome(std::string s) {
		int n = s.size();
		std::queue<std::string> temp;
		temp.push(s);

		while (true) {
			std::string crtString = temp.front();
			temp.pop();

			bool isRight = true;
			for (int i = 0; i < crtString.size() / 2; i++) {
				int begin = i;
				int end = crtString.size() - 1 - i;
				if (s[begin] != s[end]) {
					isRight = false;
					break;
				}
			}

			if (isRight) {
				return crtString;
			}
			else {
				std::string left = crtString.substr(0, crtString.size() - 1);
				std::string right = crtString.substr(1, crtString.size());
				temp.push(left);
				temp.push(right);
			}
		}
	}
};
#endif // ITERATROR_METHOD

#ifdef SLIDE_WINDOW_METHOD
class Solution {
public:
	std::string longestPalindrome(std::string s) {
		std::string result = "";
		std::string temp = "";
		for (int i = 0; i < s.size(); i++) {
			if (s.size() - i < result.size() || i < result.size()){
				continue;
			}

			temp = s[i];
			for (int j = 0; j < i; j++) {
				if (s[i - j - 1] != s[i + j + 1]) {
					break;
				}
				temp = s[i - j - 1] + temp + s[i + j + 1];
			}

			if (temp.size() > result.size()) {
				result = temp;
			}

			if (i > 0 && s[i - 1] == s[i]) {
				temp = s[i - 1] + s[i];
				for (int j = 0; j < i - 1; j++) {
					if (s[i - 1 - j - 2] != s[i + j + 1]) {
						break;
					}
					temp = s[i - 1 - j - 1] + temp + s[i + j + 1];
				}

				if (temp.size() > result.size()) {
					result = temp;
				}
			}
		}
		
		return result;
	}
};
#endif // SLIDE_WINDOW_METHOD



#endif // __leet_code_5__