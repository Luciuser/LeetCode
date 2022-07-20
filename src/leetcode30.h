#ifndef __leet_code_30__
#define __leet_code_30__

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>

class Solution {
public:
	std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {

		// s.size() = m; words.size() = n; words[0].size() = p;
		// 整理给出的words，进行去重 O(n)
		std::map<std::string, int> wordID;	// 由string到id的映射
		std::vector<int> IDCount;	// 由ID到数量的映射
		for (int i = 0; i < words.size(); i++) {
			if (wordID.count(words[i]) == 0) {
				wordID[words[i]] = i;
				IDCount[wordID[words[i]]] = 1;
			}
			else {
				IDCount[wordID[words[i]]]++;
			}
		}

		std::vector<int> numsVec; // nums 为正，其值为i，表示此处开始能够组成第i个单词；为-1表示此处无法组成单词

		int wordsNum = words.size();
		int wordLength = words[0].size();

		// 判断单词的组成情况 O(m) * O(n) * O(p)
		for (int i = 0; i < s.size(); i++) {
			if (s.size() - i < wordLength) {
				// 不够组成一个单词，全部为-1
				numsVec.push_back(-1);
				continue;
			}

			for (auto iter = wordID.begin(); iter != wordID.end(); iter++) {
				if (isSubString(s, i, (*iter).first)) {
					numsVec.push_back((*iter).second);
					break;
				}
			}
			if (numsVec.size() == i) {
				numsVec.push_back(-1);
			}
		}

		// 进行遍历，判断能够产生的连续子串的头部索引
		std::vector<int>result;
		int length = wordsNum * wordLength - 1;

		for (int i = 0; i < wordLength; i++) {
			int j = i;
			std::vector<int> numTemp;


			for (; j + length < numsVec.size(); j = j + wordLength) {
				// 找到第一组不存在-1的可能性
				int k = 0;
				for (; k < wordsNum; k++) {
					int index = j + k * wordLength;
					if (numsVec[index] == -1) {
						break;
					}
					numTemp.push_back(j + k * wordLength);
				}

				if (numTemp.size() == wordsNum) {
					break;
				}
				else {
					numTemp.clear();
					j = j + wordLength * k;
				}
			}

			if (numTemp.size() != wordsNum) {
				continue;
			}

			std::queue<int> numTempQueue;
			for (int m = 0; m < numTemp.size(); m++) {
				numTempQueue.push(numTemp[m]);
			}

			if (isRightSubString(numTempQueue, IDCount)) {
				result.push_back(j);
			}
			j += wordLength;
			for (; j + length < numsVec.size(); j = j + wordLength) {
				int index = j + wordLength * (wordsNum - 1);
				if (numsVec[index] == -1) {
					j = index;
					continue;
				}
				if (isRightSubString(numTempQueue, IDCount)) {
					result.push_back(j);
				}
			}
		
		
		
		}

		//for (int i = 0; i + length < numsVec.size(); i++) {
		//	std::vector<int> numberArray;
		//	for (int j = 0; j < wordsNum; j++) {
		//		numberArray
		//	}
		//}

		return result;
	}

private:
	// 判断s字符串在index位置是否存在ptr子字符串 O(p)
	bool isSubString(std::string s, int index, std::string ptr) {
		for (int i = 0; i < ptr.size(); i++) {
			if (s[index + i] != ptr[i]) {
				return false;
			}
		}
		return true;
	}

	bool isRightSubString(std::queue<int> nums, std::vector<int> numCount) {
		for (int i = 0; i < nums.size(); i++) {
			//if (nums[i] == -1) {
			//	return false;
			//}
			int index = nums.front();
			nums.pop();
			numCount[index]--;
			if (numCount[index] < 0) {
				return false;
			}
		}
		return true;
	}
};

#endif // __leet_code_30__