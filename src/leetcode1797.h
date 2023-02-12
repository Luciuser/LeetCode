/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-12 16:58:14
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1797.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-12 19:09:40
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 64ms, 92.76%, MEMORY 31.6MB and 5.01%
 */

#ifndef __leet_code_1797_h__
#define __leet_code_1797_h__

#include<iostream>
#include<string>
#include<queue>
#include<set>
#include<unordered_map>

class AuthenticationManager {
public:
	AuthenticationManager(int timeToLive) {
		time_to_live_ = timeToLive;
		std::cout << "null" << std::endl;

	}

	void generate(std::string tokenId, int currentTime) {
		code_live_time_[tokenId] = currentTime + time_to_live_;
		code_time_set.emplace(std::pair<int, std::string>(currentTime + time_to_live_, tokenId));
		std::cout << "null" << std::endl;

	}

	void renew(std::string tokenId, int currentTime) {
		if (code_live_time_.count(tokenId) != 0 && code_live_time_[tokenId] > currentTime) {
			// ������֤��ʱ��
			code_time_set.erase(std::pair<int, std::string>(code_live_time_[tokenId], tokenId));
			code_live_time_[tokenId] = currentTime + time_to_live_;
			code_time_set.emplace(std::pair<int, std::string>(currentTime + time_to_live_, tokenId));
			
		}
		std::cout << "null" << std::endl;

	}

	int countUnexpiredTokens(int currentTime) {
		//for (auto iter = code_live_time_.begin(); iter != code_live_time_.end(); iter++) {
		//	if ((*iter).second < currentTime) {
		//		code_live_time_.erase(iter);
		//	}
		//}
		//return code_live_time_.size();
		
		// ɾ�����ڵ���֤��
		auto iter = code_time_set.begin();
		std::vector<std::string> delete_code;
		while (iter != code_time_set.end()) {
			if ((*iter).first > currentTime) {
				break;
			}
			delete_code.push_back((*iter).second);
			iter++;
		}
		for (int i = 0; i < delete_code.size(); i++) {
			std::string temp = delete_code[i];
			code_time_set.erase(std::pair<int, std::string>(code_live_time_[temp], temp));
		}
		return code_time_set.size();
	}

private:
	template<typename T1, typename T2>
	struct PairCompareFirst {
		bool operator()(const std::pair<T1, T2> &a, const std::pair<T1, T2> &b) const{
			return a.first < b.first;
		}
	};

	int time_to_live_ = 0;
	std::unordered_map<std::string, int> code_live_time_; // ����ÿ����֤������Ӧ��ʱ�䣬��֤ generate �� renew �����ܹ��ڽӽ� O(1) �����
	//std::queue<std::string> code_time_queue_; // ��ʱ��˳��洢��ÿ����֤�룬����ɾ���Ѿ����ڵ���֤��
	std::set<std::pair<int, std::string>, PairCompareFirst<int, std::string>> code_time_set; // ��ʱ��˳��洢��ÿ����֤�룬����ɾ���Ѿ����ڵ���֤��
};


#endif // __leet_code_1797_h__