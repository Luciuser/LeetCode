#ifndef __leet_code_436__
#define __leet_code_436__

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>

//#define NORMOL_METHOND // �����������ᳬʱ
//#define MAP_VECTOR_METHOND // ���� vector �� map �����ٱ���ʱ��
#define MAP_SET_METHOND // ���� set �� map �����ٱ���ʱ��

#ifdef NORMOL_METHOND
class DinnerPlates {
public:
	DinnerPlates(int capacity) {
		_capacity = capacity;
	}

	void push(int val) {
		for (int i = 0; i < cupStacks.size(); i++) {
			if (cupStacks[i].size() < _capacity) {
				cupStacks[i].push(val);
				return;
			}
		}

		std::stack<int> tempStack;
		tempStack.push(val);
		cupStacks.push_back(tempStack);
		return;
	}

	int pop() {
		int result = -1;
		for (int i = cupStacks.size() - 1; i >= 0; i--) {
			if (cupStacks[i].size() == 0) {
				continue;
			}
			result = cupStacks[i].top();
			cupStacks[i].pop();
			return result;
		}
		return result;
	}

	int popAtStack(int index) {
		if (cupStacks.size() < index + 1) {
			return -1;
		}
		if (cupStacks[index].size() == 0) {
			return -1;
		}
		int result = cupStacks[index].top();
		cupStacks[index].pop();
		return result;
	}

private:
	int _capacity;
	std::vector<std::stack<int>> cupStacks;
};
#endif // NORMOL_METHOND

#ifdef MAP_VECTOR_METHOND
class DinnerPlates {
public:
	DinnerPlates(int capacity) {
		_capacity = capacity;
	}

	void push(int val) {
		
		if (unfullStack.size() == 0) {
			std::stack<int> tempStack;
			tempStack.push(val);
			cupStacks.push_back(tempStack);
			// ά�� fullStack �� unfullStack
			if (_capacity == 1) {
				fullStack.push_back(cupStacks.size() - 1);
			}
			else {
				unfullStack.push_back(cupStacks.size() - 1);
			}
			return;
		}
		else {
			cupStacks[unfullStack[0]].push(val);
			if (cupStacks[unfullStack[0]].size() == _capacity) {
				insertValueToVector(fullStack, unfullStack[0]);
				unfullStack.erase(unfullStack.begin() + 0);
			}
			return;
		}
	}

	int pop() {
		int result;

		if (fullStack.size() == 0 && unfullStack.size() == 0) {
			return -1;
		}

		bool inFull = true;
		int num = -1;
		if (fullStack.size() != 0) {
			num = fullStack[fullStack.size() - 1];
		}
		for (int i = unfullStack.size() - 1; i >= 0; i--) {
			if (unfullStack[i] < num) {
				break;
			}
			if (cupStacks[unfullStack[i]].size() == 0) {
				continue;
			}
			if (unfullStack[i] > num) {
				num = unfullStack[i];
				inFull = false;
				break;
			}
		}

		if (num == -1) {
			return -1;
		}

		if (inFull == true) {
			result = cupStacks[num].top();
			cupStacks[num].pop();
			fullStack.erase(fullStack.end() - 1);
			insertValueToVector(unfullStack, num);
		}
		else {
			result = cupStacks[num].top();
			cupStacks[num].pop();
		}

		if (cupStacks[cupStacks.size() - 1].size() == 0) {
			cupStacks.erase(cupStacks.end() - 1);
			unfullStack.erase(unfullStack.end() - 1);
		}

		return result;
	}

	int popAtStack(int index) {
		if (cupStacks.size() < index + 1) {
			return -1;
		}
		if (cupStacks[index].size() == 0) {
			return -1;
		}
		
		bool inFull = false;
		if (cupStacks[index].size() == _capacity) {
			inFull = true;
		}
		int result = cupStacks[index].top();
		cupStacks[index].pop();

		if (inFull == true) {
			deleteValueOfVector(fullStack, index);
			insertValueToVector(unfullStack, index);
		}

		if (index == cupStacks.size() - 1 && cupStacks[index].size() == 0) {
			cupStacks.erase(cupStacks.end() - 1);
			unfullStack.erase(unfullStack.end() - 1);
		}

		return result;
	}

private:
	int _capacity;
	std::vector<std::stack<int>> cupStacks; // װ����������
	std::vector<int> fullStack; // װ����stack��������С����
	std::vector<int> unfullStack; // δװ�����߿��ŵ�stack��������С����

	// ������� vec �в���ֵval�����ز����λ��
	int insertValueToVector(std::vector<int> &vec, int val) {
		if (vec.size() == 0) {
			vec.push_back(val);
			return 0;
		}

		// ���ַ�������Ҫ����ֵ��λ��
		auto it = std::lower_bound(vec.begin(), vec.end(), val);
		if (it == vec.end()) {
			vec.push_back(val);
		}
		else {
			vec.insert(it, val);
		}
		return 1;
	}

	// ɾ������� vec �е�ֵ val������ɾ����λ��
	int deleteValueOfVector(std::vector<int> &vec, int val) {
		if (vec.size() == 0) {
			return -1;
		}

		// ���ַ�������Ҫɾ��ֵ��λ��
		int result;
		auto itPair = std::equal_range(vec.begin(), vec.end(), val);
		if (itPair.first == vec.end()) {
			return -1;
		}
		else {
			result = itPair.first - vec.begin();
			vec.erase(itPair.first);
		}
		return result;
	}

};
#endif // MAP_VECTOR_METHOND

#ifdef MAP_SET_METHOND

using namespace std;

class DinnerPlates {
private:
	vector<stack<int>> plates;
	set<int> remain, nonempty; // remain ��ʾδ���ģ�nonempty ��ʾ�ǿ�
	int capacity;
public:
	DinnerPlates(int capacity) : capacity(capacity) {}

	void push(int val) {
		if (this->remain.empty()) {
			this->plates.push_back(stack<int>({ val }));
			if (this->capacity > 1)
				this->remain.insert(this->plates.size() - 1);
			this->nonempty.insert(this->plates.size() - 1);
		}
		else {
			auto minRemain = this->remain.begin();
			stack<int>& s = this->plates[*minRemain];
			s.push(val);

			if (s.size() == 1) {
				this->nonempty.insert(*minRemain);
			}

			if (s.size() == this->capacity) {
				this->remain.erase(minRemain);
			}
		}
	}

	int pop() {
		if (this->nonempty.empty())
			return -1;
		auto maxNonempty = --this->nonempty.end();
		stack<int>& s = this->plates[*maxNonempty];

		int res = s.top(); s.pop();

		if (s.size() == this->capacity - 1) {
			this->remain.insert(*maxNonempty);
		}

		if (s.empty()) {
			this->nonempty.erase(maxNonempty);
		}
		return res;
	}

	int popAtStack(int index) {
		if (index >= this->plates.size() || this->plates[index].empty())
			return -1;

		stack<int>& s = this->plates[index];
		int res = s.top(); s.pop();

		if (s.size() == this->capacity - 1)
			this->remain.insert(index);

		if (s.empty()) {
			this->nonempty.erase(this->nonempty.find(index));
		}
		return res;
	}
};
#endif // MAP_SET_METHOND

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

#endif