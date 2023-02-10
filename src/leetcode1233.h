/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-08 00:24:24
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1233.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-08 00:51:46
 * @Editor: Bingyang Jin
 * @Description: create NODE_TREE_METHOD, TIME 268ms, 25.00%, MEMORY 91MB and 20.31%
 */

#ifndef __leet_code_1233_h__
#define __leet_code_1233_h__

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

class Solution {
private:
	class Node {
	public:
		Node(std::string value) {
			value_ = value;
			index_ = -1;
		}
		Node(std::string value, int index) {
			value_ = value;
			index_ = index;
		}

		void addNewPath(std::string path, int destination_index) {
			if (index_ != -1) {
				// ��ǰ�ļ����Ѿ����ڣ���������ӣ�ֱ���˳�
				return;
			}

			auto index = path.find_first_of('/');
			if (index == std::string::npos) {
				// ���һ��
				if (children_.count(path) == 0) {
					// û�и�Ҷ�ӽڵ㣬���½�һ��Ҷ�ӽڵ�
					Node* child = new Node(path, destination_index);
					children_[path] = child;
				}
				else {
					// ���ļ���·������
					children_[path]->index_ = destination_index;
					//children_[path]->children_.clear();
				}
				
			}
			else{
				// �������һ��
				std::string key = path.substr(0, index);
				std::string child_path = path.substr(index + 1, path.size() - index - 1);
				if (children_.count(key) == 0) {
					// û�и�Ҷ�ӽڵ㣬���½�һ��Ҷ�ӽڵ�
					Node* child = new Node(key);
					children_[key] = child;
				}
				children_[key]->addNewPath(child_path, destination_index);
			}
		}

		void findLeafNode(std::vector<std::string>&folder, std::vector<std::string> &result) {
			if (index_ != -1) {
				result.emplace_back(folder[index_]);
				return;
			}
			for (auto iter = children_.begin(); iter != children_.end(); iter++) {
				(*iter).second->findLeafNode(folder, result);
			}
		}

		std::string value_ = "";
		std::unordered_map<std::string, Node*> children_;
		int index_ = -1; // ���ļ����Ƿ����
	};
public:
	std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
		Node *root = new Node("root");
		for (int i = 0; i < folder.size(); i++) {
			root->addNewPath(folder[i].substr(1, folder[i].size() - 1), i);
		}
		std::vector<std::string> result;
		root->findLeafNode(folder, result);

		return result;
	}
};

#endif // __leet_code_1233_h__