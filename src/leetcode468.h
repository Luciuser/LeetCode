#ifndef __leet_code_468__
#define __leet_code_468__

#include<iostream>
#include<vector>

class Solution {
public:
	std::string validIPAddress(std::string queryIP) {
		std::string temp = queryIP;

		bool isIPV4 = true;
		std::string pattern = ".";
		int position = temp.find_first_of(".");
		if (position == -1) {
			isIPV4 = false;
			pattern = ":";
		}

		std::vector<std::string> numbers;
		while (true) {
			int position = temp.find_first_of(pattern);
			if (position == -1) {
				break;
			}
			//std::cout << position << std::endl;
			std::string subString = temp.substr(0, position);
			numbers.push_back(subString);
			temp = temp.substr(position);
			temp.erase(temp.begin());
			//std::cout << subString.c_str() << std::endl;
			//std::cout << temp.c_str() << std::endl;
		}
		numbers.push_back(temp);

		if (numbers.size() != 4 && numbers.size() != 8) {
			return "Neither";
		}

		if (isIPV4 == true && numbers.size() == 4) {
			for (int i = 0; i < numbers.size(); i++) {
				int sum = 0;
				if (numbers[i].size() == 0) {
					return "Neither";
				}
				for (int j = 0; j < numbers[i].size(); j++) {
					if (numbers[i][j] < '0' || numbers[i][j] > '9') {
						return "Neither";
					}
					sum = sum * 10 + (numbers[i][j] - '0');
				}
				if (sum < 0 || sum>255) {
					return "Neither";
				}
				if (sum == 0 && numbers[i].size() != 1) {
					return "Neither";
				}
				if (sum > 0 && numbers[i][0] == '0') {
					return "Neither";
				}
			}
			return "IPv4";
		}

		if (isIPV4 == false && numbers.size() == 8) {
			for (int i = 0; i < numbers.size(); i++) {
				int sum = 0;
				if (numbers[i].size() > 4 || numbers[i].size() < 1) {
					return "Neither";
				}
				for (int j = 0; j < numbers[i].size(); j++) {
					if ((numbers[i][j] >= '0' &&numbers[i][j] <= '9') ||
						(numbers[i][j] >= 'a' &&numbers[i][j] <= 'f') ||
						(numbers[i][j] >= 'A' &&numbers[i][j] <= 'F')) {

					}
					else {
						return "Neither";
					}
				}
			}
			return "IPv6";
		}

		return "Neither";
	}
};

#endif // __leet_code_468__