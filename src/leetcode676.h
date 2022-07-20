#ifndef __leet_code_676__
#define __leet_code_676__

#include<vector>
#include<iostream>
#include<map>

//#define HASH_MAP_METHOD // 哈希表存储某长度的单词
#define DICTIONARY_TREE_METHOD // 字典树

#ifdef HASH_MAP_METHOD
class MagicDictionary {
public:
	MagicDictionary() {

	}

	void buildDict(std::vector<std::string> dictionary) {
		length2words.clear();
		for (int i = 0; i < dictionary.size(); i++) {
			length2words[dictionary[i].size()].push_back(dictionary[i]);
		}
	}

	bool search(std::string searchWord) {
		if (length2words.count(searchWord.size()) == false) {
			return false;
		}
		auto words = length2words[searchWord.size()];
		int wrongCount = 0;
		bool success = false;
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < searchWord.size(); j++) {
				if (words[i][j] != searchWord[j]) {
					wrongCount++;
					if (wrongCount > 1) {
						break;
					}
				}
			}
			if (wrongCount == 1) {
				return true;
			}
			wrongCount = 0;
		}
		return false;
	}
private:
	std::map<int, std::vector<std::string>> length2words;	// 对应长度的单词列表
};
#endif // HASH_MAP_METHOD

#ifdef DICTIONARY_TREE_METHOD
class Node{
public:
	Node() {}
	Node(char character) { c = character; }

	int add(int index, std::string word) {
		if (index < word.size()) {
			char pattern = word[index];
			if (children.count(pattern) == 0) {
				Node *newNode = new Node(pattern);
				children[pattern] = newNode;
			}
			children[pattern]->add(index + 1, word);
			return 0;
		}
		isLeaf = true;
		return 0;
	}

	bool find(int index, std::string word, int wrongCount) {
		if (wrongCount >= 2) {
			return false;
		}
		if (index >= word.size()) {
			if (wrongCount == 1 && isLeaf) {
				return true;
			}
			else {
				return false;
			}
		}
		char pattern = word[index];
		
		for (auto iter = children.begin(); iter != children.end(); iter++) {
			bool success;
			if ((*iter).first == pattern) {
				success = (*iter).second->find(index + 1, word, wrongCount);
			}
			else {
				success = (*iter).second->find(index + 1, word, wrongCount + 1);
			}
			if (success) {
				return true;
			}
		}

		return false;
	}

	char c;
	bool isLeaf = false;
	std::map<char, Node *> children;
};

class MagicDictionary {
public:
	MagicDictionary() {

	}

	void buildDict(std::vector<std::string> dictionary) {
		root = new Node();
		for (int i = 0; i < dictionary.size(); i++) {
			root->add(0, dictionary[i]);
		}
	}

	bool search(std::string searchWord) {
		return root->find(0, searchWord, 0);
	}
private:
	Node *root = nullptr;
};
#endif // DICTIONARY_TREE_METHOD

#endif // __leet_code_676__