/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-24 15:12:15
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1825.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-24 16:34:02
 * @Editor: Bingyang Jin
 * @Description: create ONE_MAP_METHOD, WRONG
 */

 /*
 * @EditTime: 2023-01-28 11:52:04
 * @Editor: Bingyang Jin
 * @Description: create THREE_MAP_METHOD, WRONG
 */

 /*
 * @EditTime: 2023-01-24 16:34:02
 * @Editor: Bingyang Jin
 * @Description: create THREE_MULTISET_METHOD, TIME 892ms, 9%, MEMORY 143.5MB and 62%
 */

#ifndef __leet_code_1825_h__
#define __leet_code_1825_h__

#include<iostream>
#include<queue>
#include<map>
#include<set>

//#define ONE_MAP_METHOD // 使用一个 map 来存储所有数据，出错了没查出来
//#define THREE_MAP_METHOD // 使用三个 map 来存储所有数据，出错了没查出来
#define THREE_MULTISET_METHOD // 使用三个 multiset 来存储所有数据，题解答案，TIME 892ms, 9%, MEMORY 143.5MB and 62%

#ifdef THREE_MULTISET_METHOD
class MKAverage {
private:
	int m, k;
	std::queue<int> q;
	std::multiset<int> s1, s2, s3;
	long long sum2;
public:
	MKAverage(int m, int k) : m(m), k(k) {
		sum2 = 0;
	}

	void addElement(int num) {
		q.push(num);
		if (q.size() <= m) {
			s2.insert(num);
			sum2 += num;
			if (q.size() == m) {
				while (s1.size() < k) {
					s1.insert(*s2.begin());
					sum2 -= *s2.begin();
					s2.erase(s2.begin());
				}
				while (s3.size() < k) {
					s3.insert(*s2.rbegin());
					sum2 -= *s2.rbegin();
					s2.erase(prev(s2.end()));
				}
			}
			return;
		}

		if (num < *s1.rbegin()) {
			s1.insert(num);
			s2.insert(*s1.rbegin());
			sum2 += *s1.rbegin();
			s1.erase(prev(s1.end()));
		}
		else if (num > *s3.begin()) {
			s3.insert(num);
			s2.insert(*s3.begin());
			sum2 += *s3.begin();
			s3.erase(s3.begin());
		}
		else {
			s2.insert(num);
			sum2 += num;
		}

		int x = q.front();
		q.pop();
		if (s1.count(x) > 0) {
			s1.erase(s1.find(x));
			s1.insert(*s2.begin());
			sum2 -= *s2.begin();
			s2.erase(s2.begin());
		}
		else if (s3.count(x) > 0) {
			s3.erase(s3.find(x));
			s3.insert(*s2.rbegin());
			sum2 -= *s2.rbegin();
			s2.erase(prev(s2.end()));
		}
		else {
			s2.erase(s2.find(x));
			sum2 -= x;
		}
	}

	int calculateMKAverage() {
		if (q.size() < m) {
			return -1;
		}
		return sum2 / (m - 2 * k);
	}
};
#endif // THREE_MULTISET_METHOD

#ifdef THREE_MAP_METHOD
class MKAverage {
public:
	MKAverage(int m, int k) {
		m_ = m;
		k_ = k;
		length_ = m_ - 2 * k_;
		sum_ = 0;
	}

	void addElement(int num) {

		if (current_data_.size() < m_) {
			// 还不够 m 个，直接增加
			current_data_.emplace(num);
			middle_[num]++;

			if (current_data_.size() == m_) {
				// 第一次计算平均值，并设置相应迭代器的位置
				int temp = 0; // 个数
				auto iter = middle_.begin();
				while (iter != middle_.end()) {
					int frequence = (*iter).second;
					temp += frequence;
					if (temp >= k_) {
						int left_num = (k_ - (temp - frequence));
						left_[(*iter).first] = left_num;
						temp = temp - k_;
						middle_[(*iter).first] = temp;
						if (temp == 0) {
							middle_.erase((*iter).first);
						}
						break;
					}
					left_[(*iter).first] = (*iter).second;
					auto iter_temp = iter;
					iter++;
					middle_.erase(iter_temp);
				}
				temp = 0;
				iter = middle_.end();
				iter--;
				while (true) {
					int frequence = (*iter).second;
					temp += frequence;
					if (temp >= k_) {
						int right_num = (k_ - (temp - frequence));
						right_[(*iter).first] = right_num;
						temp = temp - k_;
						middle_[(*iter).first] = temp;
						if (temp == 0) {
							middle_.erase((*iter).first);
						}
						break;
					}
					right_[(*iter).first] = (*iter).second;
					auto iter_temp = iter;
					iter--;
					middle_.erase(iter_temp);
				}
				for (iter = middle_.begin(); iter != middle_.end(); iter++) {
					sum_ += (*iter).first*(*iter).second;
				}


			}
		}
		else {
			// 入队列出队列
			int delete_number = current_data_.front();
			current_data_.pop();
			current_data_.emplace(num);

			// 增加数，维护 sum_ 和保证左右两边共计删除 k 个数的 left、right 迭代器
			if (num < (*middle_.begin()).first) {
				left_[num]++;
				auto iter = left_.end();
				iter--;
				middle_[(*iter).first]++;
				sum_ += (*iter).first;
				(*iter).second--;
				if ((*iter).second == 0) {
					left_.erase(iter);
				}
			}
			else if (num >= (*right_.begin()).first) {
				right_[num]++;
				auto iter = right_.begin();
				middle_[(*iter).first]++;
				sum_ += (*iter).first;
				(*iter).second--;
				if ((*iter).second == 0) {
					left_.erase(iter);
				}
			}
			else {
				middle_[num]++;
				sum_ += num;
			}

			// 删除数，维护 sum_ 和保证左右两边共计删除 k 个数的 left、right 迭代器
			if (delete_number < (*middle_.begin()).first) {
				left_[delete_number]--;
				if (left_[delete_number] == 0) {
					left_.erase(delete_number);
				}

				auto iter = middle_.begin();
				left_[(*iter).first]++;
				sum_ -= (*iter).first;
				(*iter).second--;
				if ((*iter).second == 0) {
					middle_.erase(iter);
				}
			}
			else if (delete_number >= (*right_.begin()).first) {
				right_[delete_number]--;
				if (right_[delete_number] == 0) {
					right_.erase(delete_number);
				}

				auto iter = middle_.end();
				iter--;
				right_[(*iter).first]++;
				sum_ -= (*iter).first;
				(*iter).second--;
				if ((*iter).second == 0) {
					middle_.erase(iter);
				}
			}
			else {
				middle_[delete_number]--;
				if (middle_[delete_number] == 0) {
					middle_.erase(delete_number);
				}
				sum_ -= delete_number;
			}

		}

	}

	int calculateMKAverage() {
		if (current_data_.size() < m_) {
			return -1;
		}
		else {
			return sum_ / length_;
		}
	}

private:
	int m_ = 0;
	int k_ = 0;
	int length_ = 0; // 剩余元素的长度
	long long sum_ = 0; // 剩余元素的总和

	std::queue<int> current_data_;
	std::map<int, int> left_;
	std::map<int, int> middle_;
	std::map<int, int> right_;
};
#endif // THREE_MAP_METHOD

#ifdef ONE_MAP_METHOD
class MKAverage {
public:
	MKAverage(int m, int k) {
		m_ = m;
		k_ = k;
		length_ = m_ - 2 * k_;
		sum_ = 0;
		sort_data_.clear();
	}

	void addElement(int num) {
		if (current_data_.size() < m_) {
			// 还不够 m 个，直接增加
			current_data_.emplace(num);

			// 维护 map 和平均值
			sort_data_[num]++;
			if (current_data_.size() == m_) {
				// 第一次计算平均值，并设置相应迭代器的位置
				int temp = 0; // 个数
				auto iter = sort_data_.begin();
				while (iter != sort_data_.end()) {
					int frequence = (*iter).second;
					temp += frequence;
					if (temp > k_) {
						left_ = iter;
						left_delete_num_ = (k_ - (temp - frequence));
						temp = temp - k_;
						sum_ += (*iter).first * temp;
						break;
					}
					iter++;
				}
				if (temp >= length_) {
					right_ = iter;
					right_delete_num_ = temp - length_;
					return;
				}
				while (iter != sort_data_.end()) {
					int frequence = (*iter).second;
					temp += frequence;
					if (temp >= length_) {
						right_ = iter;
						right_delete_num_ = temp - length_;
						sum_ += (*iter).first * ((*iter).second - right_delete_num_);
						break;
					}
					sum_ += (*iter).first * (*iter).second;
					iter++;
				}

			}
		}
		else {
			// 入队列出队列
			int delete_number = current_data_.front();
			current_data_.pop();
			current_data_.emplace(num);

			// 增加数，维护 map
			sort_data_[num]++;
			// 增加数，维护 sum_ 和保证左右两边共计删除 k 个数的 left、right 迭代器
			if (num < (*left_).first) {
				if (left_delete_num_ == 0) {
					left_--;
					left_delete_num_ = (*left_).second;
				}
				sum_ += (*left_).first;
				left_delete_num_--;
			}
			else if (num > (*right_).first) {
				if (right_delete_num_ == 0) {
					right_++;
					right_delete_num_ = (*right_).second;
				}
				sum_ += (*right_).first;
				right_delete_num_--;
			}
			else {
				sum_ += num;
			}

			// 维护 map 和平均值
			// 删除数，维护 sum_ 和保证左右两边共计删除 k 个数的 left、right 迭代器
			if (delete_number < (*left_).first) {
				sum_ -= (*left_).first;
				left_delete_num_++;
				if ((*left_).second == left_delete_num_) {
					left_++;
					left_delete_num_ = 0;
				}
			}
			else if (delete_number > (*right_).first) {
				sum_ -= (*right_).first;
				right_delete_num_++;
				if ((*right_).second == right_delete_num_) {
					right_--;
					right_delete_num_ = 0;
				}
			}
			else {
				sum_ -= delete_number;
			}
			// 删除数，维护 map 和保证左右两边共计删除 k 个数的 left、right 迭代器
			sort_data_[delete_number]--;
			if ((*left_).second == 0) {
				left_++;
				left_delete_num_ = 0;
			}
			if ((*right_).second == 0) {
				right_--;
				right_delete_num_ = 0;
			}
			if (sort_data_[delete_number] == 0) {
				sort_data_.erase(delete_number);
			}

		}

		std::cout << "null" << std::endl;
	}

	int calculateMKAverage() {
		if (current_data_.size() < m_) {
			return -1;
		}
		else {
			return sum_ / length_;
		}
	}

private:
	int m_ = 0;
	int k_ = 0;
	int length_ = 0; // 剩余元素的长度
	long long sum_ = 0; // 剩余元素的总和

	std::queue<int> current_data_;
	std::map<int, int> sort_data_;

	std::map<int, int>::iterator left_;
	int left_delete_num_ = 0; // left 迭代器对应 map 中需要减掉的数值
	std::map<int, int>::iterator right_;
	int right_delete_num_ = 0; // right 迭代器对应 map 中需要减掉的数值
};
#endif // ONE_MAP_METHOD

#endif // __leet_code_1825_h__