#ifndef __leet_code_1108__
#define __leet_code_1108__

#include<iostream>
#include<string>

class Solution {
public:
	std::string defangIPaddr(std::string address) {
		std::string result;
		for (int i = 0; i < address.size(); i++) {
			if (address[i] == '.') {
				result += "[.]";
			}
			else {
				result += address[i];
			}
		}
		return result;
	}
};

#endif // __leet_code_1108__