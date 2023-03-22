#include"acmtest.h"

#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<unordered_set>

ACMTest::ACMTest() {
}

ACMTest::~ACMTest() {
}

void ACMTest::cin_cout_test() {
    //scanf_test();
    //cin_cout_46_test();
    //cin_cout_743_test();

    return;
}

void ACMTest::cin_cout_46_test() {

    std::cout << "Leetcode 46" << std::endl;

    int n;
    std::cin >> n;
    std::vector<int> nums;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }

    int sum = 1;
    while (n >= 1) {
        sum *= n;
        n--;
    }
    n = nums.size();

    std::sort(nums.begin(), nums.end(), [=](int a, int b) {
        return a < b;
    });

    std::vector<std::vector<int>> result;
    result.emplace_back(nums);
    // 针对每一个排列，去寻找下一个排列
    while (true) {
        if (result.size() == sum) {
            break;
        }
        int before = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > before) {
                before = nums[i];
            }
            else {
                int j = i + 1;
                while (j < n) {
                    if (nums[j] <= nums[i]) {
                        j--;
                        break;
                    }
                    j++;
                }
                if (j >= n) {
                    j--;
                }
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;

                j = i + 1;
                int k = n - 1;
                while (j < k) {
                    int temp = nums[j];
                    nums[j] = nums[k];
                    nums[k] = temp;
                    k--;
                    j++;
                }
                result.emplace_back(nums);
                break;
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return;
}

void ACMTest::cin_cout_743_test() {
    struct MyPair {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            return a.second > b.second;
        }
    };

    int time_num;
    std::cin >> time_num;

    std::unordered_map<int, std::vector<std::pair<int, int>>> edge; // 每个与每个点相连接的其他点及其边的value，pair 为 [终点，value]
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, MyPair> q; // 存储当前最短边的节点，pair 为 [终点，value]

    // 装载链表
    for (int i = 0; i < time_num; i++) {
        int begin;
        int end;
        int value;
        std::cin >> begin >> end >> value;
        edge[begin].push_back(std::pair<int, int>(end, value));
    }
    int n, k;
    std::cin >> n >> k;

    // 从源节点开始，进行初始化
    std::unordered_set<int> nodes_receive; // 收到信号的节点
    nodes_receive.emplace(k);
    for (int i = 0; i < edge[k].size(); i++) {
        q.emplace(edge[k][i]);
    }

    // 每次装载最近的一个节点
    int sum = 0;
    while (true) {
        if (q.size() == 0) {
            break;
        }

        auto pair_temp = q.top();
        q.pop();
        int end = pair_temp.first;

        if (nodes_receive.count(end) == 0) {
            nodes_receive.emplace(end);
            int value = pair_temp.second;
            if (nodes_receive.size() == n) {
                std::cout << "the answer is: " << value << std::endl;
                return;
            }

            for (int i = 0; i < edge[end].size(); i++) {
                q.emplace(std::pair<int, int>(edge[end][i].first, edge[end][i].second + value));
            }
        }
    }

    std::cout << "the answer is: -1" << std::endl;
    return;

}

void ACMTest::scanf_test() {
    int a, c;
    double b;
    scanf_s("%d%lf%d", &a, &b, &c);

    printf("a = %d, b = %f, c = %d\n", a, b, c);
}
