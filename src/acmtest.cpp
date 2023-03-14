#include"acmtest.h"

#include<algorithm>
#include<iostream>
#include<vector>

ACMTest::ACMTest() {
}

ACMTest::~ACMTest() {
}

void ACMTest::cin_cout_test() {
    cin_cout_46_test();

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
