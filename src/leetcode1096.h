/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-07 11:01:13
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1096.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-05 12:29:20
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGTAMMING_METHOD, TIME 68ms, 80.39%, MEMORY 21.5MB and 81.37%
 */

#ifndef __leet_code_1096_h__ 
#define __leet_code_1096_h__

#include<iostream>
#include<stack>
#include<string>
#include<unordered_set>
#include<vector>

class DictionaryNode {
public:
	DictionaryNode() {
		children = std::vector<DictionaryNode*>(26, nullptr);
	}

	void braceExpansionII(std::string &expression, int index) {
		std::vector<std::string> temp_result;
		while (index < expression.size()) {
			if (expression[index] == '{') {
				index++;
				dfs(expression);
				for (auto iter : next_string) {
					result.emplace(temp + iter);
				}
			}
			else if (expression[index] == '}') {
				// 一层花括号结束，直接退出
				index++;
				break;
			}
			else if (expression[index] == ',') {
				result.emplace(temp);
				temp = "";
				index++;
			}
			else {
				temp += expression[index];
				index++;
			}
		}

		return ;
	}
	}

	char value = 'A';
	bool is_leaf = false;
	std::vector<DictionaryNode *> children;
};

class DictionaryTree {
public:
	DictionaryTree() {
		root = new DictionaryNode();
	}

	void braceExpansionII(std::string expression) {
		root->braceExpansionII(expression);
	}

	DictionaryNode *root;
};

class Solution {
public:
	std::vector<std::string> braceExpansionII(std::string expression) {

		//DictionaryTree *tree = new DictionaryTree();

		

		std::stack<std::string> brackets;
		std::unordered_set<std::string> set_result;
		
		expression = "{" + expression + "}";
		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == '{') {

			}
			else if (expression[i] == '}') {
				// 一层花括号结束，进行分解即可
			}
			else {

			}
		}

		std::vector<std::string> result(set_result.size());
		int i = 0;
		for (auto iter : set_result) {
			result[i] = iter;
			i++;
		}
		return result;
	}

private:
	std::unordered_set<std::string> dfs(std::string &expression) {
		std::unordered_set<std::string> result;

		std::vector<std::string> temp_result;
		while (index < expression.size()) {
			if (expression[index] == '{') {
				index++;
				std::unordered_set<std::string> next_string = dfs(expression);
				for (auto iter : next_string) {
					result.emplace(temp + iter);
				}
			}
			else if (expression[index] == '}') {
				// 一层花括号结束，直接退出
				index++;
				break;
			}
			else if(expression[index] == ','){
				result.emplace(temp);
				temp = "";
				index++;
			}
			else {
				temp += expression[index];
				index++;
			}
		}

		return result;
	}

	int index;
};

#endif // __leet_code_982_h__