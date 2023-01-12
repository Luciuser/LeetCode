/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-12 10:12:44
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1807.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-12 10:19:51
 * @Editor: Bingyang Jin
 * @Description: create HASH_MAP_METHOD, TIME 356ms, 40.13%, MEMORY 114.4MB and 53.29%
 */

 /*
 * @EditTime: 2023-01-12 11:26:51
 * @Editor: Bingyang Jin
 * @Description: create DICTIONARY_TREE_METHOD, out of TIME
 */

#ifndef __leet_code_1807_h__
#define __leet_code_1807_h__

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

//#define HASH_MAP_METHOD // 哈希表法，TIME 356ms, 40.13%, MEMORY 114.4MB and 53.29%
#define DICTIONARY_TREE_METHOD // 字典树法，超时，理论速度是够的，猜测是一直在删除并且重建字典树

#ifdef HASH_MAP_METHOD
class Solution {
public:
	std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) {
		std::unordered_map<std::string, std::string> key_to_value;
		for (int i = 0; i < knowledge.size(); i++) {
			key_to_value[knowledge[i][0]] = knowledge[i][1];
		}

		std::string result = "";
		bool is_in_brackets = false;
		std::string temp = "";
		for (int i = 0; i < s.size(); i++) {
			if (is_in_brackets) {
				if (s[i] == ')') {
					if (key_to_value.count(temp) == 0) {
						result += "?";
					}
					else {
						result += key_to_value[temp];
					}
					temp = "";
					is_in_brackets = false;
				}
				else {
					temp += s[i];
				}
			}
			else {
				if (s[i] == '(') {
					is_in_brackets = true;
				}
				else {
					result += s[i];
				}
			}
		}

		return result;
	}
};
#endif // HASH_MAP_METHOD

#ifdef DICTIONARY_TREE_METHOD
class Solution {
private:
	class Node {
	public:
		Node(char key) {
			key_ = key;
			value_ = "";
			for (int i = 0; i < 26; i++) {
				children.push_back(nullptr);
			}
		}
		Node(char key, std::string value) {
			key_ = key;
			value_ = value;
			for (int i = 0; i < 26; i++) {
				children.push_back(nullptr);
			}
		}
		~Node() {
			for (int i = 0; i < children.size(); i++) {
				delete children[i];
				children[i] = nullptr;
			}
			children.clear();
		}

		void add(std::string &str, int index, std::string &value) {
			if (index >= str.size()) {
				value_ = value;
				return;
			}
			int child_index = str[index] - 'a';
			if (children[child_index] == nullptr) {
				children[child_index] = new Node('a' + child_index);
			}
			children[child_index]->add(str, index+1, value);
		}

		std::string find(std::string &key, int index) {
			if (index >= key.size()) {
				return value_;
			}

			int child_index = key[index] - 'a';
			if (children[child_index] == nullptr) {
				return "";
			}

			return children[child_index]->find(key, index + 1);
		}

		char key_;
		std::string value_;
		std::vector<Node *> children;
	};

public:
	std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) {

		Node *root = new Node(' ');

		for (int i = 0; i < knowledge.size(); i++) {
			root->add(knowledge[i][0], 0, knowledge[i][1]);
		}

		std::string result = "";
		bool is_in_brackets = false;
		std::string temp = "";
		for (int i = 0; i < s.size(); i++) {
			if (is_in_brackets) {
				if (s[i] == ')') {
					std::string find_string = root->find(temp, 0);
					if (find_string == "") {
						result += "?";
					}
					else {
						result += find_string;
					}
					temp = "";
					is_in_brackets = false;
				}
				else {
					temp += s[i];
				}
			}
			else {
				if (s[i] == '(') {
					is_in_brackets = true;
				}
				else {
					result += s[i];
				}
			}
		}

		return result;
	}
};
#endif // DICTIONARY_TREE_METHOD



#endif // __leet_code_1807_h__