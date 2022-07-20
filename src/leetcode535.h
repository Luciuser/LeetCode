#ifndef __leet_code_535__
#define __leet_code_535__

#include<iostream>
#include<string>

class Solution {
public:

	// Encodes a URL to a shortened URL.
	std::string encode(std::string longUrl) {
		std::string result;
		for (int i = 0; i < longUrl.size(); i++) {
			result += (longUrl[i] - '0');
		}
		return result;
	}

	// Decodes a shortened URL to its original URL.
	std::string decode(std::string shortUrl) {
		std::string result;
		for (int i = 0; i < shortUrl.size(); i++) {
			result += (shortUrl[i] + '0');
		}
		return result;
	}
};

#endif // __leet_code_535__