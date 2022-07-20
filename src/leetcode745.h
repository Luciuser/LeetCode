/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-14 00:54:23
 * @FilePath: /EMeshGen/src/eTetrahedralize.h
 */
/*
 * @EditTime: 2022-07-14 00:56:44
 * @Editor: Bingyang Jin
 * @Description: create HASH_MAP_METHOD
 */

#ifndef __leet_code_745__
#define __leet_code_745__

#include<iostream>
#include<vector>
#include<unordered_map>
#include<assert.h>

#define VIOLENCE_METHOD // 暴力算法，会超时
#define HASH_MAP_METHOD // 通过哈希表映射

#ifdef VIOLENCE_METHOD
class WordFilter {
public:

	std::vector<std::pair<std::string, int>> sortWords;

	// 比较两个 string 的大小
	static bool cmpPairStringSmall(std::pair<std::string, int>a, std::pair<std::string, int>b) {
		int n = a.first.size() > b.first.size() ? b.first.size() : a.first.size();
		for (int i = 0; i < n; i++) {
			if (a.first[i] != b.first[i]) {
				return a.first[i] < b.first[i];
			}
		}

		return a.first.size() < b.first.size();
	}

	// 返回 0 说明包含
	// 返回 -1 说明 str 的前几个字母 比 fix 小了
	// 返回 1 说明 str 的前几个字母 比 fix 大了
	static int stringCompareInHead(std::string str, std::string fix) {
		int n = str.size() > fix.size() ? fix.size() : str.size();
		for (int i = 0; i < n; i++) {
			if (str[i] < fix[i]) {
				return -1;
			}
			else if (str[i] > fix[i]) {
				return 1;
			}
		}

		if (fix.size() > str.size()) {
			return -1;
		}

		return 0;
	}

	static int stringCompareInTail(std::string str, std::string fix) {
		int n = str.size() > fix.size() ? fix.size() : str.size();
		for (int i = n - 1; i >= 0; i--) {
			if (str[str.size() - 1 - i] < fix[fix.size() - 1 - i]) {
				return -1;
			}
			else if (str[str.size() - 1 - i] > fix[fix.size() - 1 - i]) {
				return 1;
			}
		}

		if (fix.size() > str.size()) {
			return -1;
		}

		return 0;
	}

	// O(logn)
	WordFilter(std::vector<std::string>& words) {
		for (int i = 0; i < words.size(); i++) {
			std::pair<std::string, int> crtPair(words[i], i);
			auto iter = std::lower_bound(sortWords.begin(), sortWords.end(), crtPair, cmpPairStringSmall);
			sortWords.insert(iter, crtPair);
		}
	}

	int f(std::string prefix, std::string suffix) {
		// O(logn)
		auto beginIter = std::lower_bound(sortWords.begin(), sortWords.end(), std::pair<std::string, int>(prefix, -1), cmpPairStringSmall);
		int result = -1;
		if (beginIter == sortWords.end()) {
			// 没找到
			return result;
		}

		// O(n)
		for (; beginIter < sortWords.end(); beginIter++) {
			// 找前缀是否吻合
			int headSuccess = stringCompareInHead((*beginIter).first, prefix);
			if (headSuccess == 1) {
				break;
			}
			else if (headSuccess == 0) {
				// 找后缀是否吻合
				int tailSuccess = stringCompareInTail((*beginIter).first, suffix);
				if (tailSuccess != 0) {
					continue;
				}

				if ((*beginIter).second > result) {
					result = (*beginIter).second;
				}
			}
			else {
				assert(false);
			}
		}

		return result;
	}
};
#endif // VIOLENCE_METHOD

#ifdef HASH_MAP_METHOD
class WordFilter {
public:

	std::unordered_map<std::string, int> preSufFix2id;

	// O(logn)
	WordFilter(std::vector<std::string>& words) {
		for (int i = 0; i < words.size(); i++) {
			int s = words[i].size();
			for (int j = 0; j < s; j++) {
				std::string pre = words[i].substr(0, j + 1);
				for (int k = 0; k < s; k++) {
					std::string suf = words[i].substr(s - k - 1, k + 1);
					std::string key = pre + "#" + suf;
					preSufFix2id[key] = i;
				}
			}
		}
	}

	int f(std::string prefix, std::string suffix) {
		std::string key = prefix + "#" + suffix;
		if (preSufFix2id.count(key)) {
			return preSufFix2id[key];
		}
		return -1;
	}
};
#endif // HASH_MAP_METHOD





/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */


#endif // __leet_code_745__