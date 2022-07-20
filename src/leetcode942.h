#ifndef __leet_code_942__
#define __leet_code_942__

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> diStringMatch(string s) {

		vector<int> results;

		int begin = 0;
		int end = s.size();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'I') {
				results.push_back(begin);
				begin++;
			}
			else if (s[i] == 'D') {
				results.push_back(end);
				end--;
			}
			else {
				std::cout << "error: wrong string input" << std::endl;
				exit(0);
			}
		}
		results.push_back(begin);

		return results;
	}
};

#endif // !__leet_code_942__