/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-03 13:37:02
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode622.h
 * @Description: create the file and direct method, TIME 4 ms, MEMORY 6.2 MB
 */

 /*
 * @EditTime: 2022-08-03 14:00:52
 * @Editor: Bingyang Jin
 * @Description: create MINIMUM_REPRESENTATION_METHOD, TIME 0 ms, MEMORY 6.2 MB
 */

#ifndef __leet_code_899__
#define __leet_code_899__

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//#define DIRECTION_METHOD // 当k=1时，直接遍历判断，O(n^2)时间复杂度
#define MINIMUM_REPRESENTATION_METHOD // 当k=1时，用最小表示法，O(nlogn)时间复杂度


class Solution {
public:
	std::string orderlyQueue(std::string s, int k) {
		
		// 根据复杂计算证明，当 k==1 时，有可能无法得到s所有排列组合中字典最小的字符串
		// 而当 k>= 2 时，每经过 s.length() 次移动，可以将 [1, k-1] 个字符放置到队列的任何位置，因此一定可以得到 s 排列组合中字典最小的字符串
		std::string result = s;
		if (k == 1) {
#ifdef DIRECTION_METHOD
			std::string temp = s;
			for (int i = 1; i < s.size(); i++) {
				char c = temp[0];
				temp.erase(temp.begin());
				temp += c;
				if (result > temp) {
					result = temp;
				}
			}
#endif // DIRECTION_METHOD

#ifdef MINIMUM_REPRESENTATION_METHOD
			int min = 0;
			for (int i = 1; i < s.size(); i++) {
				int index = i;
				for (int j = 0; j < s.size(); j++) {
					int minIndex = (min + j) % s.size();
					int tempIndex = (i + j) % s.size();
					if (s[minIndex] < s[tempIndex]) {
						i += j;
						break;
					}
					if (s[minIndex] > s[tempIndex]) {
						min = index;
						break;
					}
				}
			}
			result = s.substr(min, s.size() - min);
			result += s.substr(0, min);
#endif // MINIMUM_REPRESENTATION_METHOD
		}
		else {
			std::sort(result.begin(), result.end());
		}
		return result;
	}
};

#endif // __leet_code_899__