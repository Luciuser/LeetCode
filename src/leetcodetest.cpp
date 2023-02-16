#include  "leetcodetest.h"

int leetcodetest2()
{
#ifdef LEETCODE_2
	ListNode *l13 = new ListNode(3);
	ListNode *l12 = new ListNode(4, l13);
	ListNode *l11 = new ListNode(2, l12);
	ListNode *l23 = new ListNode(4);
	ListNode *l22 = new ListNode(6, l23);
	ListNode *l21 = new ListNode(5, l22);

	Solution solution;
	std::cout << solution.addTwoNumbers(l11, l21) << std::endl;
#endif // LEETCODE_2

	return 0;
}

int leetcodetest4()
{
#ifdef LEETCODE_4
	//std::vector<int> nums1 = { 1,2 };
	//std::vector<int> nums2 = { 3,4 };
	std::vector<int> nums1 = { 1};
	std::vector<int> nums2 = { 2,3,4,5,6 };
	//std::vector<int> nums1 = { 1,3 };
	//std::vector<int> nums2 = { 2 };


	Solution solution;
	std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;

#endif // LEETCODE_4
	return 0;
}

int leetcodetest5()
{
#ifdef LEETCODE_5
	Solution solution;
	std::cout << solution.longestPalindrome("cbbd").c_str() << std::endl;
#endif // LEETCODE_5

	return 0;
}

int leetcodetest10()
{
#ifdef LEETCODE_10

	//std::string s = "aa";
	//std::string p = "a*";
	std::string s = "a";
	std::string p = "ab*";
	//std::string s = "mississippi";
	//std::string p = "mis*is*ip*.";

	Solution solution;
	solution.isMatch(s, p);

#endif // LEETCODE_10
	return 0;
}

int leetcodetest11()
{
#ifdef LEETCODE_11
	//std::vector<int> temp = { 1,1 };
	std::vector<int> temp = { 1,8,6,2,5,4,8,3,7 };

	Solution solution;
	std::cout << solution.maxArea(temp) << std::endl;

#endif // LEETCODE_11
	return 0;
}

int leetcodetest13()
{
#ifdef LEETCODE_13
	std::string temp = "MCMXCIV";
	Solution solution;
	std::cout << solution.romanToInt(temp) << std::endl;;

#endif // LEETCODE_13
	return 0;
}

int leetcodetest14()
{
#ifdef LEETCODE_14
#endif // LEETCODE_14
	return 0;
}

int leetcodetest15()
{
#ifdef LEETCODE_15

	std::vector<int> nums = { -1,0,1,2,-1,-4 };

	Solution solution;
	solution.threeSum(nums);

#endif // LEETCODE_15
	return 0;
}

int leetcodetest20()
{
#ifdef LEETCODE_20
#endif // LEETCODE_20
	return 0;
}

int leetcodetest21()
{
#ifdef LEETCODE_21
#endif // LEETCODE_21
	return 0;
}

int leetcodetest30()
{
#ifdef LEETCODE_30
#endif // LEETCODE_30
	return 0;
}

int leetcodetest49()
{
#ifdef LEETCODE_49
#endif // LEETCODE_49
	
	return 0;
}

int leetcodetest94()
{
#ifdef LEETCODE_94
#endif

	return 0;
}

int leetcodetest171()
{
#ifdef LEETCODE_171
#endif // LEETCODE_171

	return 0;
}

int leetcodetest174()
{
#ifdef LEETCODE_174

	std::vector<std::vector<int>> temp = { {-2, -3, 3},{-5, -10, 1},{10,30,-5} };

	Solution solution;
	std::cout << solution.calculateMinimumHP(temp) << std::endl;
#endif // LEETCODE_174

	return 0;
}

int leetcodetest215()
{
#ifdef LEETCODE_215

	std::vector<int> temp = { 2,1};

	Solution solution;
	std::cout << solution.findKthLargest(temp, 1) << std::endl;
#endif // LEETCODE_215

	return 0;
}

int leetcodetest287()
{
#ifdef LEETCODE_287
#endif // LEETCODE_287

	return 0;
}

int leetcodetest324()
{
#ifdef LEETCODE_324

	std::vector<int> temp = {1,1,2,1,2,2};
	Solution solution;
	solution.wiggleSort(temp);

	for (int i = 0; i < temp.size(); i++) {
		std::cout << temp[i] << std::endl;
	}
#endif // LEETCODE_324

	return 0;
}

int leetcodetest326()
{
#ifdef LEETCODE_326

	Solution solution;
	solution.isPowerOfThree(243);
#endif // LEETCODE_326

	return 0;
}

int leetcodetest427()
{
#ifdef LEETCODE_427

	std::vector<int> a;
	std::vector<int> b;
	a.push_back(0);
	a.push_back(1);
	b.push_back(1);
	b.push_back(0);

	std::vector<std::vector<int>> test;
	test.push_back(a);
	test.push_back(b);

	Solution solution;
	Node *root = solution.construct(test);
#endif

	return 0;
}

int leetcodetest434()
{
#ifdef LEETCODE_434
#endif // LEETCODE_434

	return 0;
}

int leetcodetest436()
{
#ifdef LEETCODE_436
	std::vector<std::vector<int>> temp = { {1,1},{3,4} };

	Solution solution;
	std::vector<int> result = solution.findRightInterval(temp);

	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}
#endif // LEETCODE_436

	return 0;
}

int leetcodetest450()
{
#ifdef LEETCODE_450
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node3 = new TreeNode(3, node2, node4);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node6 = new TreeNode(6, nullptr, node7);

	TreeNode *root = new TreeNode(5, node3, node6);

	Solution solution;

	solution.deleteNode(root, 3);
#endif // LEETCODE_450

	return 0;
}

int leetcodetest462()
{
#ifdef LEETCODE_462
#endif // LEETCODE_462
	return 0;
}

int leetcodetest464()
{
#ifdef LEETCODE_464
#endif // LEETCODE_464
	return 0;
}

int leetcodetest467()
{
#ifdef LEETCODE_467
	Solution solution;
	std::cout << solution.findSubstringInWraproundString("zaba") << std::endl;
#endif // LEETCODE_467
	return 0;
}

int leetcodetest468()
{
#ifdef LEETCODE_468
	Solution solution;
	std::cout << solution.validIPAddress("1.00.1.1").c_str();
#endif // LEETCODE_468

	return 0;
}

int leetcodetest473()
{
#ifdef LEETCODE_473
	Solution solution;
	std::vector<int> temp = {6961655, 6721573, 5852338, 4455955, 7980746, 4533546, 1148969, 101844, 9721301, 4048728, 4397033, 2520627, 2522511, 6094454, 1023140};
	// 6, 7, 8, 8, 6, 7, 8]
	// 13 11 9 8 8 1
	// 13 11 1
	// 9 8 8
	// 8 8 8

	if (solution.makesquare(temp)) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
#endif // LEETCODE_473

	return 0;
}

int leetcodetest481()
{
#ifdef LEETCODE_481
#endif // LEETCODE_481
	return 0;
}

int leetcodetest497()
{
#ifdef LEETCODE_497
#endif // LEETCODE_497
	return 0;
}

int leetcodetest498()
{
#ifdef LEETCODE_498
#endif // LEETCODE_498
	return 0;
}

int leetcodetest513()
{
#ifdef LEETCODE_513
#endif // LEETCODE_513
	return 0;
}

int leetcodetest522()
{
#ifdef LEETCODE_522
	std::vector<std::string> temp = { "aaa","aaa","aa" };
	Solution solution;
	std::cout << solution.findLUSlength(temp) << std::endl;
#endif // LEETCODE_522

	return 0;
}

int leetcodetest532()
{
#ifdef LEETCODE_532
	std::vector<int> temp = { 1,3,1,5,4 };
	Solution solution;
	std::cout << solution.findPairs(temp, 0) << std::endl;
#endif // LEETCODE_532

	return 0;
}

int leetcodetest535()
{
#ifdef LEETCODE_535
#endif // LEETCODE_535
	return 0;
}

int leetcodetest556()
{
#ifdef LEETCODE_556

	Solution solution;
	std::cout << solution.nextGreaterElement(230241) << std::endl;

#endif // LEETCODE_556
	return 0;
}

int leetcodetest558()
{
#ifdef LEETCODE_558
#endif // LEETCODE_558
	return 0;
}

int leetcodetest565()
{
#ifdef LEETCODE_565
#endif // LEETCODE_565
	return 0;
}

int leetcodetest592()
{
#ifdef LEETCODE_592
	Solution solution;
	std::cout << solution.fractionAddition("-1/2+1/2") << std::endl;

#endif // LEETCODE_592
	return 0;
}

int leetcodetest622()
{
#ifdef LEETCODE_622
	MyCircularQueue *solution = new MyCircularQueue(6);
	std::cout << solution->enQueue(6) << std::endl;
	std::cout << solution->Rear() << std::endl;
	std::cout << solution->deQueue() << std::endl;
	std::cout << solution->enQueue(5) << std::endl;
	std::cout << solution->Rear() << std::endl;
	std::cout << solution->deQueue() << std::endl;
	std::cout << solution->Front() << std::endl;
	std::cout << solution->deQueue() << std::endl;
	std::cout << solution->deQueue() << std::endl;
	std::cout << solution->deQueue() << std::endl;
#endif // LEETCODE_622

	return 0;
}

int leetcodetest623()
{
#ifdef LEETCODE_623
#endif // LEETCODE_623
	return 0;
}

int leetcodetest636()
{
#ifdef LEETCODE_636
	Solution *solution = new Solution();
	std::vector<std::string> temp = { "0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7" };

	solution->exclusiveTime(1, temp);
#endif // LEETCODE_636

	return 0;
}

int leetcodetest640()
{
#ifdef LEETCODE_640
	Solution *solution = new Solution();

	solution->solveEquation("x+5-3+x=6+x-2");

#endif // LEETCODE_640
	return 0;
}

int leetcodetest641()
{
#ifdef LEETCODE_641
#endif // LEETCODE_641
	return 0;
}

int leetcodetest646()
{
#ifdef LEETCODE_646
	Solution solution;
	std::vector<std::vector<int>> temp = { {1,2},{2,3},{3,4} };
	solution.findLongestChain(temp);
#endif // LEETCODE_646
	return 0;
}

int leetcodetest652()
{
#ifdef LEETCODE_652

	TreeNode *left = new TreeNode(1);
	TreeNode *right = new TreeNode(1);

	TreeNode *root = new TreeNode(2, left, right);

	Solution solution;
	solution.findDuplicateSubtrees(root);

#endif // LEETCODE_652
	return 0;
}

int leetcodetest654()
{
#ifdef LEETCODE_654
	Solution solution;
	std::vector<int> temp = { 3, 6, 7, 5, 1, 2, 8, 9 };
	solution.constructMaximumBinaryTree(temp);

#endif // LEETCODE_654
	return 0;
}

int leetcodetest655()
{
#ifdef LEETCODE_655
	Solution solution;
#endif // LEETCODE_655
	return 0;
}

int leetcodetest658()
{
#ifdef LEETCODE_658
#endif // LEETCODE_658
	return 0;
}

int leetcodetest662()
{
#ifdef LEETCODE_662

	TreeNode node6(6);
	TreeNode node5(5, &node6, nullptr);
	TreeNode node3(3, &node5, nullptr);
	TreeNode root(1, &node3, nullptr);

	Solution solution;
	solution.widthOfBinaryTree(&root);

#endif // LEETCODE_662
	return 0;
}

int leetcodetest667()
{
#ifdef LEETCODE_667
#endif // LEETCODE_667
	return 0;
}

int leetcodetest668()
{
#ifdef LEETCODE_668
	Solution solution;
	std::cout << solution.findKthNumber(3, 3, 5) << std::endl;
#endif // LEETCODE_668
	return 0;
}

int leetcodetest669()
{
#ifdef LEETCODE_669
#endif // LEETCODE_669
	return 0;
}

int leetcodetest672()
{
#ifdef LEETCODE_672
#endif // LEETCODE_672
	return 0;
}

int leetcodetest675()
{
#ifdef LEETCODE_675
	std::vector<std::vector<int>> temp = { {4,2,3},{0,0,1},{7,6,5} };

	Solution solution;
	std::cout << solution.cutOffTree(temp) << std::endl;
	return 0;
#endif // LEETCODE_675

	return 0;
}

int leetcodetest676()
{
#ifdef LEETCODE_676
	std::vector<std::string>temp = { "hello","leetcode" };

	MagicDictionary *md = new MagicDictionary();
	md->buildDict(temp);
	std::cout << md->search("hello") << std::endl;
	std::cout << md->search("hhllo") << std::endl;
	std::cout << md->search("hell") << std::endl;
	std::cout << md->search("leetcoded") << std::endl;

#endif // LEETCODE_676
	return 0;
}

int leetcodetest687()
{
#ifdef LEETCODE_687

#endif // LEETCODE_687
	return 0;
}

int leetcodetest698()
{
#ifdef LEETCODE_698

	std::vector<int> temp = { 4,3,2,3,5,2,1 };
	Solution solution;

	solution.canPartitionKSubsets(temp, 4);

#endif // LEETCODE_698
	return 0;
}

int leetcodetest699() {
#ifdef LEETCODE_699
	std::vector<std::vector<int>> temp = { {1,2},{2,3},{6,1} };

	Solution solution;
	std::vector<int> result = solution.fallingSquares(temp);

	for (int i = 0; i < result.size(); i++) {
		std::cout << result{i] << std::endl;
	}
#endif // LEETCODE_699
	return 0;
}

int leetcodetest707()
{
#ifdef LEETCODE_707

	//["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
	//[[], [1], [3], [1, 2], [1], [0], [0]]

	//["MyLinkedList", "addAtHead", "addAtIndex", "get"]
	//[[], [2], [0, 1], [1]]

	MyLinkedList linkedList;
	linkedList.addAtHead(2);
	//linkedList.addAtTail(3);
	linkedList.addAtIndex(0, 1);   //�����Ϊ1-> 2-> 3
	linkedList.get(1);            //����2
	//linkedList.deleteAtIndex(0);  //����������1-> 3
	//linkedList.get(0);            //����3

#endif // LEETCODE_707
	return 0;
}

int leetcodetest715()
{
#ifdef LEETCODE_715
	RangeModule *rm = new RangeModule();
	//rm->addRange(10, 20);
	//rm->removeRange(14, 16);
	//std::cout << rm->queryRange(10, 14) << std::endl;
	//std::cout << rm->queryRange(13, 15) << std::endl;
	//std::cout << rm->queryRange(16, 17) << std::endl;

	rm->addRange(5, 8);
	std::cout << rm->queryRange(3, 4) << std::endl;
	rm->removeRange(5, 6);
	rm->removeRange(3, 6);
	rm->addRange(1, 3);
	std::cout << rm->queryRange(2, 3) << std::endl;
	rm->addRange(4, 8);
	std::cout << rm->queryRange(2, 3) << std::endl;
	rm->removeRange(4, 9);

#endif // LEETCODE_715
	return 0;
}

int leetcodetest719()
{
#ifdef LEETCODE_719
	Solution solution;

	std::vector<int> temp = { 1,6,1 };

	std::cout << solution.smallestDistancePair(temp, 5000) << std::endl;

#endif // LEETCODE_719
	return 0;
}

int leetcodetest729()
{
#ifdef LEETCODE_729
#endif // LEETCODE_729
	return 0;
}

int leetcodetest730()
{
#ifdef LEETCODE_730
#endif // LEETCODE_730
	return 0;
}

int leetcodetest731()
{
#ifdef LEETCODE_731
#endif // LEETCODE_731
	return 0;
}

int leetcodetest732()
{
#ifdef LEETCODE_732
	std::vector<int> temp = { 93, 90, 50, 50, 40, 2};

	SegmentTree *segmentTree = new SegmentTree();
	segmentTree->build(temp);
	for (int i = 0; i < segmentTree->data.size(); i++) {
		std::cout << segmentTree->data[i] << std::endl;
	}
	std::cout << std::endl;
	//std::cout << segmentTree->findDataIndex(0, 3) << std::endl;

	segmentTree->update(3, 1);
	for (int i = 0; i < segmentTree->data.size(); i++) {
		std::cout << segmentTree->data[i] << std::endl;
	}

	//MyCalendarThree *solution = new MyCalendarThree();
	//std::cout << solution->book(10, 20) << std::endl;
	//std::cout << solution->book(50, 60) << std::endl;
	//std::cout << solution->book(10, 40) << std::endl;
	//std::cout << solution->book(5, 15) << std::endl;
	//std::cout << solution->book(5, 10) << std::endl;
	//std::cout << solution->book(25, 55) << std::endl;

#endif // LEETCODE_732
	return 0;
}

int leetcodetest735()
{
#ifdef LEETCODE_735
	std::vector<int> temp = { -2,-2,1,-2 };

	Solution *solution = new Solution();
	std::vector<int> result = solution->asteroidCollision(temp);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}

#endif // LEETCODE_735
	return 0;
}

int leetcodetest741()
{
#ifdef LEETCODE_741

	std::vector<std::vector<int>> temp = { {1, 1, -1},{1, -1, 1},{-1, 1, 1} };

	Solution solution;
	std::cout << solution.cherryPickup(temp) << std::endl;
#endif // LEETCODE_7451
	return 0;
}

int leetcodetest745()
{
#ifdef LEETCODE_745

	std::vector<std::string> temp = { "apple", "bsize", "hello", "abcd", "ab", "hellp", "hellp", "a", "basize" };
	WordFilter *wordFilter = new WordFilter(temp);
	wordFilter->f("a", "e");

#endif // LEETCODE_745
	return 0;
}

int leetcodetest747()
{
#ifdef LEETCODE_747
	Solution solution;
	std::vector<int> test = { 1,0 };
	std::cout << solution.dominantIndex(test) << std::endl;
#endif // LEETCODE_747
	return 0;
}

int leetcodetest749()
{
#ifdef LEETCODE_749
	//std::vector<std::vector<int>> temp = { {0,1,0,0,0,0,0,1},{0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0} };
	std::vector<std::vector<int>> temp = { {1, 1, 1, 0, 0, 0, 0, 0, 0},{1, 0, 1, 0, 1, 1, 1, 1, 1},{1, 1, 1, 0, 0, 0, 0, 0, 0} };


	Solution solution;
	std::cout << solution.containVirus(temp);

#endif // LEETCODE_749
	return 0;
}

int leetcodetest753()
{
#ifdef LEETCODE_753
	Solution solution;
	std::cout << solution.crackSafe(2, 2) << std::endl;

#endif // LEETCODE_753
	return 0;
}

int leetcodetest754()
{
#ifdef LEETCODE_754
#endif // LEETCODE_754
	return 0;
}

int leetcodetest761()
{
#ifdef LEETCODE_761
	Solution *solution = new Solution();

	std::cout << solution->makeLargestSpecial("11011000");


#endif // LEETCODE_761
	return 0;
}

int leetcodetest762()
{
#ifdef LEETCODE_762
#endif // LEETCODE_762
	return 0;
}

int leetcodetest764()
{
#ifdef LEETCODE_764
	Solution solution;

	//std::vector<std::vector<int>> temp = { {0, 0}, {0, 2}, {0, 5}, {0, 7}, {0, 8}, {0, 9}, {0, 10}, {0, 12}, {0, 19}, {1, 1}, {1, 2}, {1, 7}, {1, 8}, {1, 11}, {1, 14}, {1, 15}, {1, 16}, {1, 17}, {1, 18}, {2, 0}, {2, 4}, {2, 5}, {2, 8}, {2, 9}, {2, 11}, {2, 12}, {2, 14}, {2, 15}, {2, 19}, {3, 3}, {3, 4}, {3, 6}, {3, 8}, {3, 9}, {3, 11}, {3, 14}, {3, 15}, {3, 16}, {3, 18}, {4, 0}, {4, 6}, {4, 8}, {4, 9}, {4, 11}, {4, 12}, {4, 14}, {4, 15}, {4, 16}, {4, 17}, {4, 19}, {5, 2}, {5, 4}, {5, 6}, {5, 7}, {5, 8}, {5, 9}, {5, 12}, {5, 14}, {5, 19}, {6, 6}, {6, 10}, {6, 11}, {6, 12}, {6, 13}, {6, 15}, {6, 16}, {6, 18}, {7, 1}, {7, 2}, {7, 3}, {7, 5}, {7, 8}, {7, 11}, {7, 15}, {7, 16}, {8, 0}, {8, 2}, {8, 4}, {8, 5}, {8, 8}, {8, 9}, {8, 12}, {8, 13}, {8, 14}, {8, 15}, {8, 16}, {8, 19}, {9, 0}, {9, 1}, {9, 2}, {9, 3}, {9, 8}, {9, 9}, {9, 10}, {9, 11}, {9, 12}, {9, 14}, {9, 19}, {10, 0}, {10, 3}, {10, 5}, {10, 7}, {10, 8}, {10, 9}, {10, 11}, {10, 14}, {10, 15}, {10, 16}, {10, 17}, {11, 1}, {11, 4}, {11, 11}, {11, 13}, {11, 15}, {11, 16}, {12, 0}, {12, 3}, {12, 4}, {12, 12}, {12, 13}, {12, 16}, {12, 17}, {13, 1}, {13, 2}, {13, 3}, {13, 5}, {13, 7}, {13, 8}, {13, 9}, {13, 11}, {13, 15}, {13, 16}, {13, 17}, {13, 19}, {14, 0}, {14, 1}, {14, 6}, {14, 7}, {14, 9}, {14, 10}, {14, 13}, {14, 14}, {14, 19}, {15, 1}, {15, 5}, {15, 7}, {15, 9}, {15, 13}, {15, 14}, {15, 15}, {15, 16}, {15, 18}, {15, 19}, {16, 0}, {16, 1}, {16, 3}, {16, 4}, {16, 8}, {16, 12}, {16, 13}, {16, 14}, {16, 15}, {16, 16}, {16, 17}, {17, 0}, {17, 1}, {17, 2}, {17, 3}, {17, 4}, {17, 5}, {17, 7}, {17, 9}, {17, 10}, {17, 12}, {17, 13}, {17, 14}, {17, 15}, {17, 17}, {17, 18}, {18, 0}, {18, 3}, {18, 4}, {18, 5}, {18, 6}, {18, 8}, {18, 9}, {18, 11}, {18, 13}, {18, 14}, {18, 16}, {18, 17}, {19, 0}, {19, 1}, {19, 3}, {19, 4}, {19, 5}, {19, 7}, {19, 9}, {19, 10}, {19, 14}, {19, 15} };
	//std::cout << solution.orderOfLargestPlusSign(20, temp);

	std::vector<std::vector<int>> temp = { {3,0},{3,3} };
	std::cout << solution.orderOfLargestPlusSign(5, temp);


#endif // LEETCODE_764
	return 0;
}

int leetcodetest768()
{
#ifdef LEETCODE_768
#endif // LEETCODE_768
	return 0;
}

int leetcodetest769()
{
#ifdef LEETCODE_769
	std::vector<int> temp = { 1,0,2,3,4 };
	Solution solution;
	solution.maxChunksToSorted(temp);
#endif // LEETCODE_769
	return 0;
}

int leetcodetest775()
{
#ifdef LEETCODE_775
#endif // LEETCODE_775
	return 0;
}

int leetcodetest777()
{
#ifdef LEETCODE_777
	std::string start = "RXXLRXRXL";
	std::string end = "XRLXXRRLX";

	Solution solution;
	solution.canTransform(start, end);

#endif // LEETCODE_777
	return 0;
}

int leetcodetest779()
{
#ifdef LEETCODE_779
#endif // LEETCODE_779
	return 0;
}

int leetcodetest782()
{
#ifdef LEETCODE_782
#endif // LEETCODE_782
	return 0;
}

int leetcodetest784()
{
#ifdef LEETCODE_784
#endif // LEETCODE_784
	return 0;
}

int leetcodetest788()
{
#ifdef LEETCODE_788
	std::vector<std::string> names = { "Mary","John","Emma" };
	std::vector<int> heights = { 180, 165, 170 };


	Solution solution;
	solution.sortPeople(names, heights);
	//solution.rotatedDigits(2);
#endif // LEETCODE_788
	return 0;
}

int leetcodetest790()
{
#ifdef LEETCODE_790
#endif // LEETCODE_790
	return 0;
}

int leetcodetest791()
{
#ifdef LEETCODE_791
#endif // LEETCODE_791
	return 0;
}

int leetcodetest792()
{
#ifdef LEETCODE_792
	std::string s = "abcde";
	std::vector<std::string> words = { "a", "bb", "acd", "ace" };

	Solution solution;
	std::cout << solution.numMatchingSubseq(s, words);

#endif // LEETCODE_792
	return 0;
}

int leetcodetest795()
{
#ifdef LEETCODE_795
#endif // LEETCODE_795
	return 0;
}

int leetcodetest799()
{
#ifdef LEETCODE_799
#endif // LEETCODE_799
	return 0;
}

int leetcodetest801()
{
#ifdef LEETCODE_801
#endif // LEETCODE_801
	return 0;
}

int leetcodetest805()
{
#ifdef LEETCODE_805

	std::vector<int> temp = { 33, 86, 88, 78, 21, 76, 19, 20, 88, 76, 10, 25, 37, 97, 58, 89, 65, 59, 98, 57, 50, 30, 58, 5, 61, 72, 23, 6 };
	//std::vector<int> temp = { 1, 3 };
	//std::vector<int> temp = {1, 2, 3, 4, 5, 6, 7, 8};

	Solution solution;
	std::cout << solution.splitArraySameAverage(temp) << std::endl;

#endif // LEETCODE_805
	return 0;
}

int leetcodetest808()
{
#ifdef LEETCODE_808

	Solution solution;
	std::cout << solution.soupServings(79) << std::endl;

#endif // LEETCODE_808
	return 0;
}

int leetcodetest809()
{
#ifdef LEETCODE_809

	std::string s = "heeellooo";
	std::vector<std::string> words = { "hello", "hi", "helo" };

	Solution solution;
	std::cout << solution.expressiveWords(s, words) << std::endl;

#endif // LEETCODE_809
	return 0;
}

int leetcodetest811()
{
#ifdef LEETCODE_811
#endif // LEETCODE_811
	return 0;
}

int leetcodetest813()
{
#ifdef LEETCODE_813

	std::vector<int> temp = { 9,1,2,3,9 };
	Solution solution;
	std::cout << solution.largestSumOfAverages(temp, 3) << std::endl;

#endif // LEETCODE_813
	return 0;
}

int leetcodetest814()
{
#ifdef LEETCODE_814
#endif // LEETCODE_814
	return 0;
}

int leetcodetest816()
{
#ifdef LEETCODE_816
#endif // LEETCODE_816
	return 0;
}

int leetcodetest817()
{
#ifdef LEETCODE_817
#endif // LEETCODE_817
	return 0;
}

int leetcodetest827()
{
#ifdef LEETCODE_827
	std::vector<std::vector<int>> temp = { {1,0, 1},{0,1, 1},{1,0,0} };
	Solution solution;
	std::cout << solution.largestIsland(temp);
#endif // LEETCODE_827
	return 0;
}

int leetcodetest828()
{
#ifdef LEETCODE_828
	Solution solution;
	solution.uniqueLetterString("ABC");
#endif // LEETCODE_828
	return 0;
}

int leetcodetest829()
{
#ifdef LEETCODE_829
	Solution solution;

	std::cout << solution.consecutiveNumbersSum(6) << std::endl;

#endif // LEETCODE_829
	return 0;
}

int leetcodetest850()
{
#ifdef LEETCODE_850

	//std::vector<std::vector<int>> temp = { {0, 0, 2, 2},{1, 0, 2, 3},{1, 0, 3, 1 } };
	std::vector<std::vector<int>> temp = { {0, 0, 1000000000, 1000000000} };
	Solution solution;
	std::cout << solution.rectangleArea(temp);

#endif // LEETCODE_850
	return 0;
}

int leetcodetest854()
{
#ifdef LEETCODE_854
#endif // LEETCODE_854
	return 0;
}

int leetcodetest855()
{
#ifdef LEETCODE_855
	std::cout << "test 01" << std::endl;
	//ExamRoom examRoom(10);
	//std::cout << "    " << examRoom.seat() << std::endl;
	//std::cout << "    " << examRoom.seat() << std::endl;
	//std::cout << "    " << examRoom.seat() << std::endl;
	//std::cout << "    " << examRoom.seat() << std::endl;
	//examRoom.leave(4);
	//std::cout << "    " << examRoom.seat() << std::endl;

	//ExamRoom examRoom2(10);
	//std::cout << "    " << examRoom2.seat() << std::endl;
	//std::cout << "    " << examRoom2.seat() << std::endl;
	//std::cout << "    " << examRoom2.seat() << std::endl;
	//examRoom2.leave(0);
	//examRoom2.leave(9);
	//std::cout << "    " << examRoom2.seat() << std::endl;
	//std::cout << "    " << examRoom2.seat() << std::endl;
	//std::cout << "    " << examRoom2.seat() << std::endl;
	//std::cout << "    " << examRoom2.seat() << std::endl;

	ExamRoom examRoom2(10);
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	examRoom2.leave(0);
	examRoom2.leave(4);
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	std::cout << "    " << examRoom2.seat() << std::endl;
	examRoom2.leave(0);
	std::cout << "    " << examRoom2.seat() << std::endl;

#endif // LEETCODE_855
	return 0;
}

int leetcodetest857()
{
#ifdef LEETCODE_857

	std::vector<int> quality = { 3,1,10,10,1 };
	std::vector<int> wage = { 4,8,2,2,7 };

	Solution solution;
	std::cout << solution.mincostToHireWorkers(quality, wage, 3) << std::endl;

#endif // LEETCODE_857
	return 0;
}

int leetcodetest862()
{
#ifdef LEETCODE_862

	//std::vector<int> temp = { 2, -1, 2, 2, 3, 2, 6, 1, 5, 2, 2, 3, 2, 6, -1, -1, 3, 2, 6, 1, 5, 1, 5, 2, 2, -1, -1, -1, 3, 2, 6, 1, 5, 2, 2, -1, 2, 3, 2, 6, 1, 5, 2, 2, -1 };
	std::vector<int> temp = { 2, -1, 2, 2, 3, 2, 6, 1, 5, 2, 2, 3, 6, -1, -1, 3, 2, 6, 1, 5, 1, 5, 2, 2, -1, -1 };
	Solution solution;
	solution.shortestSubarray(temp, 5);

#endif // LEETCODE_862
	return 0;
}

int leetcodetest870()
{
#ifdef LEETCODE_870

	std::vector<int> nums1 = { 2,7,11,15 };
	std::vector<int> nums2 = { 1,10,4,11 };

	Solution solution;
	solution.advantageCount(nums1, nums2);
#endif // LEETCODE_870
	return 0;
}

int leetcodetest871()
{
#ifdef LEETCODE_871

	//std::vector<std::vector<int>> temp = { {10, 60},{20, 30},{30, 30},{60, 40} };
	std::vector<std::vector<int>> temp = {{13, 21}, {26, 115}, {100, 47}, {225, 99}, {299, 141}, {444, 198}, {608, 190}, {636, 157}, {647, 255}, {841, 123}};
	Solution solution;
	std::cout << solution.minRefuelStops(1000, 299, temp);

#endif // LEETCODE_871
	return 0;
}

int leetcodetest875()
{
#ifdef LEETCODE_875
	std::vector<int> temp = { 3 };
	Solution solution;

	std::cout << solution.minEatingSpeed(temp, 3) << std::endl;

#endif // LEETCODE_875
	return 0;
}

int leetcodetest878()
{
#ifdef LEETCODE_878

	Solution solution;
	std::cout << solution.nthMagicalNumber(5, 7, 5) << std::endl;

#endif // LEETCODE_878
	return 0;
}

int leetcodetest882()
{
#ifdef LEETCODE_882

	std::vector<std::vector<int>> temp = { {0, 2, 0},{1, 3, 1},{0, 1, 0},{1, 4, 0},{0, 4, 0},{2, 4, 4},{2, 3, 6},{0, 3, 8},{3, 4, 1},{1, 2, 4} };
	Solution solution;
	solution.reachableNodes(temp, 4, 5);

#endif // LEETCODE_882
	return 0;
}

int leetcodetest886()
{
#ifdef LEETCODE_886
	std::vector<std::vector<int>> temp = { {1,2},{2,3},{3,4},{4,5},{1,5} };
	Solution solution;
	solution.possibleBipartition(5, temp);

#endif // LEETCODE_886
	return 0;
}

int leetcodetest890()
{
#ifdef LEETCODE_890

	std::vector<std::string> temp = { "yzmyr", "fhufq", "lghlq", "oahot", "ueiuq" };
	Solution solution;

	std::vector<std::string> result = solution.findAndReplacePattern(temp, "iusiq");
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i].c_str() << std::endl;
	}

#endif // LEETCODE_890
	return 0;
}

int leetcodetest891()
{
#ifdef LEETCODE_891
#endif // LEETCODE_891
	return 0;
}

int leetcodetest895()
{
#ifdef LEETCODE_895

	FreqStack freqStack;
	freqStack.push(5);
	freqStack.push(7);
	freqStack.push(5);
	freqStack.push(7);
	freqStack.push(4);
	freqStack.push(5);
	std::cout << freqStack.pop() << std::endl;
	std::cout << freqStack.pop() << std::endl;
	std::cout << freqStack.pop() << std::endl;
	std::cout << freqStack.pop() << std::endl;


#endif // LEETCODE_895
	return 0;
}

int leetcodetest899()
{
#ifdef LEETCODE_899
#endif // LEETCODE_899
	return 0;
}

int leetcodetest901()
{
#ifdef LEETCODE_901
#endif // LEETCODE_901
	return 0;
}

int leetcodetest902()
{
#ifdef LEETCODE_902
#endif // LEETCODE_902
	return 0;
}

int leetcodetest904()
{
#ifdef LEETCODE_904

	std::vector<int> temp = { 3, 3, 1, 5, 1, 2, 1, 1, 2, 3, 4, 3, 4, 0, 2, 2, 0, 2, 0, 1, 1, 3, 1, 2, 3, 6, 6, 7, 4, 2, 6, 3, 8, 7, 1, 7, 1, 13, 3, 1, 2, 1, 5, 1, 2, 3, 3, 4 };
	Solution solution;
	solution.totalFruit(temp);

#endif // LEETCODE_904
	return 0;
}

int leetcodetest907()
{
#ifdef LEETCODE_907

	std::vector<int> temp = { 72,40,83 };
	Solution solution;
	std::cout << solution.sumSubarrayMins(temp) << std::endl;

#endif // LEETCODE_907
	return 0;
}

int leetcodetest915()
{
#ifdef LEETCODE_915
#endif // LEETCODE_915
	return 0;
}

int leetcodetest919()
{
#ifdef LEETCODE_919
	TreeNode *root = new TreeNode(1);
	//TreeNode *node1 = new TreeNode(2);
	//root->left = node1;

	CBTInserter *solution = new CBTInserter(root);
	std::cout << solution->insert(3);
	std::cout << solution->insert(3);
	std::cout << solution->insert(4);

#endif // LEETCODE_919
	return 0;
}

int leetcodetest926()
{
#ifdef LEETCODE_926
	Solution solution;
	std::string s = "1";

	std::cout << solution.minFlipsMonoIncr(s) << std::endl;
	
#endif // LEETCODE_926
	return 0;
}

int leetcodetest927()
{
#ifdef LEETCODE_927

	std::vector<int> temp = { 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 };
	Solution solution;
	
	std::vector<int> result = solution.threeEqualParts(temp);
	std::cout << result[0] << " " << result[1] << std::endl;

#endif // LEETCODE_927
	return 0;
}

int leetcodetest934()
{
#ifdef LEETCODE_934

	std::vector<std::vector<int>>temp = { {0,1},{1,0} };
	Solution solution;
	solution.shortestBridge(temp);

#endif // LEETCODE_934
	return 0;
}

int leetcodetest940()
{
#ifdef LEETCODE_940

	Solution solution;
	std::cout << solution.distinctSubseqII("abaacahaiushfqoiwrekjbnzxvjbjkasdfjkahfkjhwqkjgfbasdbgmbdsagbjkfhkjzxjbjkdsahggwiehjoipqorjewhjkadsfnmbnzvmnxbmnbvhzbjhzbhjgjahjqhewjhdfsagjhjkj") << std::endl;

#endif // LEETCODE_940
	return 0;
}

int leetcodetest942()
{
#ifdef LEETCODE_942
	string str = "IDID";
	Solution solution;

	vector<int> result = solution.diStringMatch(str);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " " << std::endl;
	}
#endif

	return 0;
}

int leetcodetest946()
{
#ifdef LEETCODE_946
#endif // LEETCODE_946
	return 0;
}

int leetcodetest951()
{
#ifdef LEETCODE_951
#endif // LEETCODE_951
	return 0;
}

int leetcodetest953()
{
#ifdef LEETCODE_953
	std::vector<std::string> words;
	std::string str = "word";
	words.push_back(str);
	str = "world";
	words.push_back(str);
	str = "row";
	words.push_back(str);
	str = "worldabcefghijkmnpqstuvxyz";

	Solution solution;

	std::cout << solution.isAlienSorted(words, str) << std::endl;

#endif
	return 0;
}

int leetcodetest961()
{
#ifdef LEETCODE_961
#endif
	return 0;
}

int leetcodetest965()
{
#ifdef LEETCODE_965
#endif // LEETCODE_965
	return 0;
}

int leetcodetest998()
{
#ifdef LEETCODE_998
#endif // LEETCODE_998
	return 0;
}

int leetcodetest1021()
{
#ifdef LEETCODE_1021
#endif // LEETCODE_1021
	return 0;
}

int leetcodetest1108()
{
#ifdef LEETCODE_1108
#endif // LEETCODE_1108
	return 0;
}

int leetcodetest1124()
{
#ifdef LEETCODE_1124
	std::vector<int> hours = { 9,9,6,0,6,6,9 };
	Solution solution;
	std::cout << solution.longestWPI(hours) << std::endl;
#endif // LEETCODE_1124
	return 0;
}

int leetcodetest1129()
{
#ifdef LEETCODE_1129
#endif // LEETCODE_1129
	return 0;
}

int leetcodetest1138()
{
#ifdef LEETCODE_1138
#endif // LEETCODE_1138
	return 0;
}

int leetcodetest1145()
{
#ifdef LEETCODE_1045
#endif // LEETCODE_1045
	return 0;
}

int leetcodetest1022()
{
#ifdef LEETCODE_1022
#endif // LEETCODE_1022
	return 0;
}

int leetcodetest1037()
{
#ifdef LEETCODE_1037
#endif // LEETCODE_1037
	return 0;
}

int leetcodetest1051()
{
#ifdef LEETCODE_1051
#endif // LEETCODE_1051
	return 0;
}

int leetcodetest1052()
{
#ifdef LEETCODE_1052
#endif // LEETCODE_1052
	return 0;
}

int leetcodetest1089()
{
#ifdef LEETCODE_1089
	std::vector<int> temp = { 1,0,0,0,0,0 };

	Solution solution;
	solution.duplicateZeros(temp);

	for (int i = 0; i < temp.size(); i++) {
		std::cout << temp[i] << std::endl;
	}
#endif // LEETCODE_1089

	return 0;
}

int leetcodetest1106()
{
#ifdef LEETCODE_1106

	std::string temp = "|(&(t,f,t),!(t))";
	Solution solution;
	solution.parseBoolExpr(temp);

#endif // LEETCODE_1106
	return 0;
}

int leetcodetest1162()
{
#ifdef LEETCODE_1162
	std::vector<std::vector<int>> temp = { {1, 0, 0, 0, 0, 1, 0, 0, 0, 1}, {1, 1, 0, 1, 1, 1, 0, 1, 1, 0}, {0, 1, 1, 0, 1, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 1, 0, 1, 0, 1}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 1}, {0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 1, 1, 1, 1, 1, 0, 0}};
	Solution solution;

	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp[i].size(); j++) {
			std::cout << temp[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << solution.maxDistance(temp) << std::endl;
#endif // LEETCODE_1162

	return 0;
}

int leetcodetest1172()
{
#ifdef LEETCODE_1172
	DinnerPlates* dinnerPlates = new DinnerPlates(2);
	int success;
	dinnerPlates->push(1);
	dinnerPlates->push(2);
	dinnerPlates->push(3);
	dinnerPlates->push(4);
	dinnerPlates->push(5);
	success = dinnerPlates->popAtStack(0);
	std::cout << success << std::endl;
	dinnerPlates->push(20);
	dinnerPlates->push(21);
	success = dinnerPlates->popAtStack(0);
	std::cout << success << std::endl;
	success = dinnerPlates->popAtStack(2);
	std::cout << success << std::endl;
	success = dinnerPlates->pop();
	std::cout << success << std::endl;
	success = dinnerPlates->pop();
	std::cout << success << std::endl;
	success = dinnerPlates->pop();
	std::cout << success << std::endl;
	success = dinnerPlates->pop();
	std::cout << success << std::endl;
	success = dinnerPlates->pop();
	std::cout << success << std::endl;

#endif // LEETCODE_1172
	return 0;
}

int leetcodetest1175()
{
#ifdef LEETCODE_1175
	Solution solution;
	std::cout << solution.numPrimeArrangements(5) << std::endl;
#endif // LEETCODE_1175
	return 0;
}

int leetcodetest1184()
{
#ifdef LEETCODE_1184
#endif // LEETCODE_1184
	return 0;
}

int leetcodetest1185()
{
#ifdef LEETCODE_1185
#endif // LEETCODE_1185
	return 0;
}

int leetcodetest1200()
{
#ifdef LEETCODE_1200
#endif // LEETCODE_1200
	return 0;
}

int leetcodetest1206()
{
#ifdef LEETCODE_1206
#endif // LEETCODE_1206
	return 0;
}

int leetcodetest1210()
{
#ifdef LEETCODE_1210
	std::vector<std::vector<int>> grid = { {0, 0, 0, 0, 0, 1},{1, 1, 0, 0, 1, 0},{0, 0, 0, 0, 1, 1},{0, 0, 1, 0, 1, 0},{0, 1, 1, 0, 0, 0},{0, 1, 1, 0, 0, 0} };
	//std::vector<std::vector<int>> grid = { {0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
	
	Solution solution;
	std::cout << solution.minimumMoves(grid) << std::endl;

#endif // LEETCODE_1210
	return 0;
}

int leetcodetest1217()
{
#ifdef LEETCODE_1217
#endif // LEETCODE_1217
	return 0;
}

int leetcodetest1223()
{
#ifdef LEETCODE_1223

	int n = 2;
	std::vector<int> rollMax = { 1,1,2,2,2,3 };

	Solution solution;
	std::cout << solution.dieSimulator(n, rollMax) << std::endl;

#endif // LEETCODE_1223
	return 0;
}

int leetcodetest1224()
{
#ifdef LEETCODE_1224
	std::vector<int> temp = { 2,2,1,1,5,3,3,5 };
	Solution solution;
	solution.maxEqualFreq(temp);
#endif // LEETCODE_1224
	return 0;
}

int leetcodetest1233()
{
#ifdef LEETCODE_1233
	//std::vector<std::string> folder = { "/a", "/a/b", "/c/d", "/c/d/e", "/c/f" };
	std::vector<std::string> folder = { "/ah/al/am","/ah/al"};

	Solution solution;
	solution.removeSubfolders(folder);
	//std::cout << solution.jobScheduling(startTime, endTime, profit) << std::endl;

#endif // LEETCODE_1233
	return 0;
}

int leetcodetest1234()
{
#ifdef LEETCODE_1234

	std::string s = "QWER";

	Solution solution;
	std::cout << solution.balancedString(s) << std::endl;

#endif // LEETCODE_1234
	return 0;
}

int leetcodetest1235()
{
#ifdef LEETCODE_1235

	std::vector<int> startTime = { 43,13,36,31,40,5,47,13,28,16,2,11 };
	std::vector<int> endTime = { 44,22,41,41,47,13,48,35,48,26,21,39 };
	std::vector<int> profit = { 8,20,3,19,16,8,11,13,2,15,1,1 };

	Solution solution;
	std::cout << solution.jobScheduling(startTime, endTime, profit) << std::endl;

#endif // LEETCODE_1235
	return 0;
}

int leetcodetest1250()
{
#ifdef LEETCODE_1250
#endif // LEETCODE_1250
	return 0;
}

int leetcodetest1252()
{
#ifdef LEETCODE_1252
#endif // LEETCODE_1252
	return 0;
}

int leetcodetest1260()
{
#ifdef LEETCODE_1260
#endif // LEETCODE_1260
	return 0;
}

int leetcodetest1282()
{
#ifdef LEETCODE_1282
#endif // LEETCODE_1282
	return 0;
}

int leetcodetest1302()
{
#ifdef LEETCODE_1302
#endif // LEETCODE_1302
	return 0;
}

int leetcodetest1331()
{
#ifdef LEETCODE_1331
#endif // LEETCODE_1331
	return 0;
}

int leetcodetest1374()
{
#ifdef LEETCODE_1374
#endif // LEETCODE_1374
	return 0;
}

int leetcodetest1399()
{
#ifdef LEETCODE_1399
#endif // LEETCODE_1399
	return 0;
}

int leetcodetest1403()
{
#ifdef LEETCODE_1403
#endif // LEETCODE_1403
	return 0;
}

int leetcodetest1408()
{
#ifdef LEETCODE_1408
	Solution *solution = new Solution();
	
	std::vector<std::string> temp = { "mass", "as", "hero", "superhero" };

	solution->stringMatching(temp);

#endif // LEETCODE_1408
	return 0;
}

int leetcodetest1413()
{
#ifdef LEETCODE_1413
#endif // LEETCODE_1413
	return 0;
}

int leetcodetest1417()
{
#ifdef LEETCODE_1417
	Solution *solution = new Solution();

	std::cout << solution->reformat("a") << std::endl;
#endif // LEETCODE_1417

	return 0;
}

int leetcodetest1422()
{
#ifdef LEETCODE_1422
	Solution solution;

	std::cout << solution.maxScore("110000") << std::endl;
#endif // LEETCODE_1422

	return 0;
}

int leetcodetest1441()
{
#ifdef LEETCODE_1441
#endif // LEETCODE_1441
	return 0;
}

int leetcodetest1450()
{
#ifdef LEETCODE_1450
#endif // LEETCODE_1450
	return 0;
}

int leetcodetest1455()
{
#ifdef LEETCODE_1455
	Solution solution;

	std::cout << solution.isPrefixOfWord("i love eating burger", "burg") << std::endl;

#endif // LEETCODE_1455
	return 0;
}

int leetcodetest1460()
{
#ifdef LEETCODE_1460
#endif // LEETCODE_1460
	return 0;
}

int leetcodetest1470()
{
#ifdef LEETCODE_1470
#endif // LEETCODE_1470
	return 0;
}

int leetcodetest1475()
{
#ifdef LEETCODE_1475
#endif // LEETCODE_1475
	return 0;
}

int leetcodetest1582()
{
#ifdef LEETCODE_1582
#endif // LEETCODE_1582
	return 0;
}

int leetcodetest1592()
{
#ifdef LEETCODE_1592
#endif // LEETCODE_1592
	return 0;
}

int leetcodetest1604()
{
#ifdef LEETCODE_1604

	std::vector<std::string> keyName = { "leslie", "leslie", "leslie", "clare", "clare", "clare", "clare", "john", "aimly"};
	std::vector<std::string> keyTime = {"13:00", "03:20", "19:00", "08:00", "18:51", "09:30", "19:49", "00:00", "13:53"};

	Solution solution;
	solution.alertNames(keyName, keyTime);

#endif // LEETCODE_1604
	return 0;
}

int leetcodetest1608()
{
#ifdef LEETCODE_1608
#endif // LEETCODE_1608
	return 0;
}

int leetcodetest1620()
{
#ifdef LEETCODE_1620

	std::vector<std::vector<int>> temp = { {0, 1, 2},{2, 1, 2},{1, 0, 2},{1, 2, 2} };
	Solution solution;
	solution.bestCoordinate(temp, 1);

#endif // LEETCODE_1620
	return 0;
}

int leetcodetest1624()
{
#ifdef LEETCODE_1624
#endif // LEETCODE_1624
	return 0;
}

int leetcodetest1632()
{
#ifdef LEETCODE_1632
	std::vector<std::vector<int>> temp = { {1,2} ,{3,4} };
	//std::vector<std::vector<int>> temp = { {7,7} ,{7,7} };
	//std::vector<std::vector<int>> temp = { {20, -21, 14},{-19, 4, 19},{22, -47, 24},{-19, 4, 19} };
	//std::vector<std::vector<int>> temp = { {7, -3, 6},{1, 4, 5},{9, 8, 2}};

	Solution solution;
	solution.matrixRankTransform(temp);

#endif // LEETCODE_1632
	return 0;
}

int leetcodetest1636()
{
#ifdef LEETCODE_1636
#endif // LEETCODE_1636
	return 0;
}

int leetcodetest1640()
{
#ifdef LEETCODE_1640
#endif // LEETCODE_1640
	return 0;
}

int leetcodetest1652()
{
#ifdef LEETCODE_1652
	std::vector<int> temp = { 2,4,9,3 };
	Solution solution;
	solution.decrypt(temp, -2);
#endif // LEETCODE_1652
	return 0;
}

int leetcodetest1656()
{
#ifdef LEETCODE_1656
#endif // LEETCODE_1656
	return 0;
}

int leetcodetest1658()
{
#ifdef LEETCODE_1658
	//std::vector<int> temp = { 1,1,4,2,3 };
	std::vector<int> temp = { 3,2,20,1,1,3 };

	Solution solution;
	std::cout << solution.minOperations(temp, 10) << std::endl;
#endif // LEETCODE_1658
	return 0;
}

int leetcodetest1662()
{
#ifdef LEETCODE_1662
#endif // LEETCODE_1662
	return 0;
}

int leetcodetest1663()
{
#ifdef LEETCODE_1663

	Solution solution;

	std::cout << solution.getSmallestString(5, 130) << std::endl;

#endif // LEETCODE_1663
	return 0;
}

int leetcodetest1664()
{
#ifdef LEETCODE_1664
#endif // LEETCODE_1664
	return 0;
}

int leetcodetest1668()
{
#ifdef LEETCODE_1668

	std::string sequence = "aaa";
	std::string word = "a";

	Solution solution;
	solution.maxRepeating(sequence, word);

#endif // LEETCODE_1668
	return 0;
}

int leetcodetest1669()
{
#ifdef LEETCODE_1669
#endif // LEETCODE_1669
	return 0;
}

int leetcodetest1678()
{
#ifdef LEETCODE_1678
#endif // LEETCODE_1678
	return 0;
}

int leetcodetest1684()
{
#ifdef LEETCODE_1684
#endif // LEETCODE_1684
	return 0;
}

int leetcodetest1687()
{
#ifdef LEETCODE_1687
#endif // LEETCODE_1687
	return 0;
}

int leetcodetest1691()
{
#ifdef LEETCODE_1691

	std::vector<std::vector<int>> temp1 = { {50, 45, 20},{95, 37, 53},{45, 23, 12 } };

	Solution solution;
	std::cout << solution.maxHeight(temp1) << std::endl;

#endif // LEETCODE_1691
	return 0;
}

int leetcodetest1697()
{
#ifdef LEETCODE_1697

	int n = 5;
	std::vector<std::vector<int>> edgeList = { {0, 1, 10},{1, 2, 5},{2, 3, 9},{3, 4, 13} };
	std::vector<std::vector<int>> queries = { {0, 4, 14},{1, 4, 13} };

	Solution solution;
	solution.distanceLimitedPathsExist(n, edgeList, queries);

#endif // LEETCODE_1697
	return 0;
}

int leetcodetest1700()
{
#ifdef LEETCODE_1700
#endif // LEETCODE_1700
	return 0;
}

int leetcodetest1703()
{
#ifdef LEETCODE_1703
	//std::vector<int> temp = { 1,0,0,1,0,1 };
	//int k = 2;
	//std::vector<int> temp = { 1,0,0,0,0,0,1,1 };
	//int k = 3;
	//std::vector<int> temp = { 1,1,0,1 };
	//int k = 2;
	std::vector<int> temp = { 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0,1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 };
	int k = 45;
	Solution solution;
	std::cout << solution.minMoves(temp, k) << std::endl;

#endif // LEETCODE_1703
	return 0;
}

int leetcodetest1704()
{
#ifdef LEETCODE_1704
#endif // LEETCODE_1704
	return 0;
}

int leetcodetest1710()
{
#ifdef LEETCODE_1710
#endif // LEETCODE_1710
	return 0;
}

int leetcodetest1728()
{
#ifdef LEETCODE_1728
#endif
	return 0;
}

int leetcodetest1732()
{
#ifdef LEETCODE_1732
#endif // LEETCODE_1732
	return 0;
}

int leetcodetest1739()
{
#ifdef LEETCODE_1739
#endif // LEETCODE_1739
	return 0;
}

int leetcodetest1742()
{
#ifdef LEETCODE_1742

	Solution solution;
	std::cout << solution.countBalls(9, 103) << std::endl;

#endif // LEETCODE_1742
	return 0;
}

int leetcodetest1750()
{
#ifdef LEETCODE_1750
	std::string temp = "cabaabac";
	Solution solution;
	solution.minimumLength(temp);

#endif // LEETCODE_1750
	return 0;
}

int leetcodetest1752()
{
#ifdef LEETCODE_1752
#endif // LEETCODE_1752
	return 0;
}

int leetcodetest1753()
{
#ifdef LEETCODE_1753
#endif // LEETCODE_1753
	return 0;
}

int leetcodetest1754()
{
#ifdef LEETCODE_1754
	std::string str1 = "cabaa";
	std::string str2 = "bcaaa";

	Solution solution;
	solution.largestMerge(str1, str2);

#endif // LEETCODE_1754
	return 0;
}

int leetcodetest1758()
{
#ifdef LEETCODE_1758
#endif // LEETCODE_1758
	return 0;
}

int leetcodetest1759()
{
#ifdef LEETCODE_1759
#endif // LEETCODE_1759
	return 0;
}

int leetcodetest1760()
{
#ifdef LEETCODE_1760

	//std::vector<int> temp = {431, 922, 158, 60, 192, 14, 788, 146, 788, 775, 772, 792, 68, 143, 376, 375, 877, 516, 595, 82, 56, 704, 160, 403, 713, 504, 67, 332, 26};
	//int k = 80;
	std::vector<int> temp = { 9 };
	int k = 2;

	Solution solution;
	solution.minimumSize(temp, k);
#endif // LEETCODE_1760
	return 0;
}

int leetcodetest1764()
{
#ifdef LEETCODE_1764
#endif // LEETCODE_1764
	return 0;
}

int leetcodetest1769()
{
#ifdef LEETCODE_1769
#endif // LEETCODE_1769
	return 0;
}

int leetcodetest1773()
{
#ifdef LEETCODE_1773
#endif // LEETCODE_1773
	return 0;
}

int leetcodetest1774()
{
#ifdef LEETCODE_1774
	Solution solution;
#endif // LEETCODE_1774
	return 0;
}

int leetcodetest1775()
{
#ifdef LEETCODE_1775

	//std::vector<int> num1 = { 1, 5, 5, 2, 1, 1, 1, 1, 4, 4, 4, 1, 5, 2, 2, 4, 6, 5, 1, 5, 3, 5, 6, 2, 3, 1, 5, 4, 4, 1, 2, 4, 1, 1, 6, 3, 6, 4, 4, 4, 3, 5, 5, 5, 2, 6, 4, 2, 5, 4, 2, 6, 3, 4, 6, 1, 5, 3, 2, 3, 5, 2, 1, 3, 2, 4, 4, 4, 5, 3, 5, 5, 4, 1, 1, 6, 5, 6, 3, 5, 3, 6, 5, 6, 5, 4, 4, 4, 5, 6, 6, 6, 4, 2, 4, 6, 1, 2, 1, 5, 3, 4, 5, 5, 6, 6, 1, 4, 3, 1, 5, 3, 4, 1, 2, 1, 4, 4, 5, 6, 5, 3, 1, 5, 1, 3, 3, 6, 5, 3, 5, 6, 2, 6, 3, 1, 2, 3, 3, 1, 1, 4, 3, 2, 6, 6, 2, 1, 2, 4, 3, 5, 5, 4, 3, 1, 1, 5, 2, 5, 1, 4, 5, 6, 4, 5, 2, 1, 2, 5, 3, 2, 6, 3, 4, 3, 4, 5, 4, 6, 3, 4, 4, 3, 3, 4, 2, 2, 6, 2, 6, 3, 1, 1, 5, 3, 1, 1, 4, 2, 5, 5, 5, 4, 3, 6, 5, 5, 5, 1, 1, 3, 6, 2, 3, 6, 3, 4, 2, 5, 4, 4, 3, 5, 6, 4, 3, 5, 1, 1, 3, 3, 1, 1, 6, 4, 6, 2, 1, 4, 3, 5, 5 };
	//std::vector<int> num2 = {1, 2, 5, 4, 3, 3, 5, 1, 1, 6, 2, 5, 4, 4, 5, 6, 6, 4, 2, 5, 6, 2, 3, 4, 5, 2, 4, 4, 3, 6, 6, 5, 4, 1, 2, 1, 2, 3, 3, 2, 6, 1, 1, 1, 1, 3, 5, 6, 2, 1, 1, 1, 4, 6, 5};

	std::vector<int> num1 = { 5, 6, 4, 3, 1, 2 };
	std::vector<int> num2 = { 6, 3, 3, 1, 4, 5, 3, 4, 1, 3, 4 };

	Solution solution;
	std::cout << solution.minOperations(num1, num2) << std::endl;

#endif // LEETCODE_1775
	return 0;
}

int leetcodetest1779()
{
#ifdef LEETCODE_1779
	Solution solution;
#endif // LEETCODE_1779
	return 0;
}

int leetcodetest1780()
{
#ifdef LEETCODE_1780
#endif // LEETCODE_1780
	return 0;
}

int leetcodetest1781()
{
#ifdef LEETCODE_1781
	Solution solution;
	std::cout << solution.beautySum("aabcb") << std::endl;
#endif // LEETCODE_1781

	return 0;
}

int leetcodetest1785()
{
#ifdef LEETCODE_1785
#endif // LEETCODE_1785
	return 0;
}

int leetcodetest1786()
{
#ifdef LEETCODE_1786
	int n = 6;
	Solution solution;

	std::vector<std::vector<int>> temp = { {6, 2, 9},{2, 1, 7},{6, 5, 10},{4, 3, 1},{3, 1, 8},{4, 6, 4},{5, 1, 7},{1, 4, 7},{4, 5, 3},{3, 6, 6},{5, 3, 9},{1, 6, 6},{3, 2, 2},{5, 2, 8} };

	std::cout << solution.countRestrictedPaths(n, temp) << std::endl;

#endif // LEETCODE_1786
	return 0;
}

int leetcodetest1790()
{
#ifdef LEETCODE_1790
#endif // LEETCODE_1790
	return 0;
}

int leetcodetest1796()
{
#ifdef LEETCODE_1796
	Solution solution;
	std::cout << solution.secondHighest("ck077");
#endif // LEETCODE_1796
	return 0;
}

int leetcodetest1797()
{
#ifdef LEETCODE_1797

	AuthenticationManager authenticationManager(13);
	authenticationManager.renew("ajvy", 1);
	std::cout << authenticationManager.countUnexpiredTokens(3) << std::endl;
	std::cout << authenticationManager.countUnexpiredTokens(4) << std::endl;
	authenticationManager.generate("fuzxq", 5);
	authenticationManager.generate("izmry", 7);
	authenticationManager.renew("puv", 12);
	authenticationManager.generate("ybiqb", 13);
	authenticationManager.generate("gm", 14);
	std::cout << authenticationManager.countUnexpiredTokens(15) << std::endl;
	std::cout << authenticationManager.countUnexpiredTokens(18) << std::endl;
	std::cout << authenticationManager.countUnexpiredTokens(19) << std::endl;
	authenticationManager.renew("ybiqb", 21);
	std::cout << authenticationManager.countUnexpiredTokens(23) << std::endl;
	std::cout << authenticationManager.countUnexpiredTokens(25) << std::endl;
	std::cout << authenticationManager.countUnexpiredTokens(26) << std::endl;
	authenticationManager.generate("aqdm", 28);
	std::cout << authenticationManager.countUnexpiredTokens(29) << std::endl;
	authenticationManager.renew("puv", 30);

	//AuthenticationManager authenticationManager(5);
	//authenticationManager.renew("aaa", 1);
	//authenticationManager.generate("aaa", 2);
	//std::cout << authenticationManager.countUnexpiredTokens(6) << std::endl;
	//authenticationManager.generate("bbb", 7);
	//authenticationManager.renew("aaa", 8);
	//authenticationManager.renew("bbb", 10);
	//std::cout << authenticationManager.countUnexpiredTokens(15) << std::endl;

#endif // LEETCODE_1797
	return 0;
}

int leetcodetest1798()
{
#ifdef LEETCODE_1798
#endif // LEETCODE_1798
	return 0;
}

int leetcodetest1799()
{
#ifdef LEETCODE_1799
#endif // LEETCODE_1799
	return 0;
}

int leetcodetest1800()
{
#ifdef LEETCODE_1800
#endif
	return 0;
}

int leetcodetest1801()
{
#ifdef LEETCODE_1801
#endif // LEETCODE_1801
	return 0;
}

int leetcodetest1802()
{
#ifdef LEETCODE_1802
	Solution solution;
	std::cout << solution.maxValue(6, 1, 10) << std::endl;
	std::cout << solution.maxValue(8, 3, 1000) << std::endl;
#endif // LEETCODE_1802
	return 0;
}

int leetcodetest1803()
{
#ifdef LEETCODE_1803
	//std::vector<int>temp = { 9,8,4,2,1 };
	//int low = 5;
	//int high = 14;
	//std::vector<int>temp = { 7881, 760, 709, 2937, 1245, 720, 5187, 6361, 3793, 141, 7238 };
	//int low = 1492;
	//int high = 3832;
	std::vector<int>temp = { 1,4,2,7 };
	int low = 2;
	int high = 6;

	Solution solution;
	std::cout << solution.countPairs(temp, low, high) << std::endl;


#endif // LEETCODE_1803
	return 0;
}

int leetcodetest1805()
{
#ifdef LEETCODE_1805

	Solution solution;
	std::cout << solution.numDifferentIntegers("0i00e") << std::endl;

#endif // LEETCODE_1805
	return 0;
}

int leetcodetest1806()
{
#ifdef LEETCODE_1806
#endif // LEETCODE_1806
	return 0;
}

int leetcodetest1807()
{
#ifdef LEETCODE_1807
#endif // LEETCODE_1807
	return 0;
}

int leetcodetest1812()
{
#ifdef LEETCODE_1812
#endif // LEETCODE_1812
	return 0;
}

int leetcodetest1813()
{
#ifdef LEETCODE_1813
	//std::string s1 = "My name is Haley";
	//std::string s2 = "My Haley";
	//std::string s1 = "A";
	//std::string s2 = "a A b A";
	std::string s1 = "Eating right now";
	std::string s2 = "Eating";

	Solution solution;
	std::cout << solution.areSentencesSimilar(s1, s2) << std::endl;

#endif // LEETCODE_1813
	return 0;
}

int leetcodetest1814()
{
#ifdef LEETCODE_1814

	Solution solution;

#endif // LEETCODE_1814
	return 0;
}

int leetcodetest1815()
{
#ifdef LEETCODE_1815

	//int batch_size = 3;
	//std::vector<int> groups = { 1,2,3,4,5,6 };
	int batch_size = 9;
	std::vector<int> groups = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };


	Solution solution;
	std::cout << solution.maxHappyGroups(batch_size, groups) << std::endl;

#endif // LEETCODE_1815
	return 0;
}

int leetcodetest1817()
{
#ifdef LEETCODE_1817
	std::vector<std::vector<int>> temp = { {0, 5},{1, 2},{0, 2},{0, 5},{1, 3} };
	int k = 5;

	Solution solution;
	solution.findingUsersActiveMinutes(temp, k);

#endif // LEETCODE_1817
	return 0;
}

int leetcodetest1819()
{
#ifdef LEETCODE_1819
	std::vector<int> temp = { 108001, 62541, 99795, 57305, 26265, 84619, 44070, 105873, 177569, 62657, 83171, 142303, 97327, 8360, 54342, 42575, 84197, 79462, 162465, 119538, 26120, 3712, 49027, 198178, 187202, 143126, 96355, 53240, 41506, 72889, 42218, 29106, 50005, 98781, 146766, 113158, 81006, 54123, 17195, 74150, 131061, 131633, 121320, 59544, 162194, 189776, 13027, 68043, 85223, 102739, 150749, 192687, 40615, 171013, 88564, 86307, 118320, 44124, 136806, 25886, 119328, 33028, 40409, 62, 100376, 44384, 34529, 28662, 145729, 167101, 54219, 165836, 28784, 14540, 151146, 199137, 128613, 58584, 141801, 104287, 188077, 91339, 76901, 23787, 58718, 96529, 195365, 6355, 24931, 69068, 73136, 75830, 144515, 81260, 47798, 113105, 180363, 128289, 84475, 98652, 73691, 143696, 105581, 54710, 109514, 91903, 18549, 183527, 139886, 116945, 79775, 80577, 103931, 92077, 185380, 173698, 7562, 74747, 34006, 29561, 196063, 84611, 62020, 176078, 63855, 135209, 155151, 180200, 90069, 36815, 157454, 12038, 91615, 43883, 152828, 65872, 138892, 168247, 104813, 186792, 15473, 190013, 162674, 59336, 78692, 88387, 90090, 134742, 195450, 157934, 194046, 11255, 618, 108155, 74261, 1849, 26020, 35971, 153328, 73996, 28655, 11022, 71673, 13647, 159298, 125097, 130891, 13634, 54181, 50447, 193494, 12439, 91443, 73581, 97738, 134652, 59345, 84031, 84617, 129027, 8978, 155065, 165096, 34986, 33679, 149083, 49566, 171650, 61558, 187137, 14259, 23494, 9101, 13327, 50125, 197771, 94048, 108212, 189143, 41314, 50906, 54619, 97878, 172812, 63666, 60116, 6684, 110424, 83774, 143832, 170007, 101198, 33995, 89602, 173502, 170714, 34944, 24784, 118627, 197904, 75322, 191683, 105343, 105312, 156279, 26279, 54313, 185768, 166815, 83833, 188293, 154561, 92031, 180326, 103095, 102209, 122116, 79960, 18327, 126160, 14799, 127463, 189137, 30026, 85505, 47777, 45396, 83409, 107467, 38467, 150135, 45148, 181310, 47909, 190220, 159575, 94900, 105851, 22986, 161457, 56633, 158215, 190310, 158214, 194309, 192011, 162435, 40804, 194826, 194937, 127769, 98138, 71230, 188070, 45867, 80004, 126895, 9142, 100760, 34966, 161852, 120281, 80156, 89793, 159977, 149445, 31826, 90206, 111989, 63376, 28583, 1421, 121105, 31511, 85203, 160203, 130052, 157967, 55229, 26545, 131860, 6026, 196964, 139856, 77973, 108513, 53968, 82447, 111402, 165754, 155793, 50950, 43746, 193984, 45637, 12741, 129410, 113708, 30153, 45310, 2872, 172120, 155363, 10505, 21725, 119647, 149155, 112775, 91208, 49763, 138332, 14414, 93525, 124652, 198277, 24236, 96022, 47550, 100298, 63419, 184841, 21055, 136639, 67624, 145274, 154877, 8361, 147583, 107496, 38115, 134163, 69920, 114152, 57681, 85890, 113156, 57210, 146443, 26737, 56608, 94510, 142945, 130576, 143412, 42084, 198921, 82055, 100085, 29270, 60902, 195057, 104896, 112314, 121471, 103588, 161912, 75203, 182565, 32819, 55416, 85260, 6355, 142118, 18878, 165605, 20741, 83419, 110963, 14407, 127064, 160202, 184692, 136825, 30478, 4055, 169447, 121126, 176226, 63703, 123054, 175975, 162873, 75997, 99338, 92051, 67980, 142928, 54468, 185428, 181946, 180438, 140028, 16169, 183476, 139308, 169301, 32429, 173896, 27067, 146478, 140643, 31954, 12049, 21179, 46175, 193624, 76082, 106732, 16264, 21999, 30041, 50373, 157850, 38223, 118610, 2185, 48592, 51424, 56504, 56124, 42745, 191480, 764, 95156, 131918, 198791, 168386, 6268, 61115, 11813, 163354, 36989, 43560, 29902, 62294, 107379, 37916, 54544, 170017, 90757, 13529, 18441, 177593, 98136, 74703, 79957, 12708, 56432, 123561, 7437, 21384, 136333, 12055, 23026, 130645, 56159, 30075, 164837, 29851, 4821, 8337, 167753, 106653, 116286, 30021, 11887, 4268, 143492, 236, 156437, 67282, 26513, 177043, 65930, 80007, 42430, 198460, 97489, 14168, 26232, 140834, 89293, 88129, 39751, 133166, 145080, 108102, 23992, 142838, 73161, 140750, 159749, 23013, 114759, 25766, 30814, 13809, 181690, 13062, 18818, 167806, 10068, 37116, 52507, 108927, 178238, 79789, 164400, 139361, 146487, 195612, 57368, 74456, 169095, 21037, 137765, 18615, 162037, 69621, 134351, 80586, 118091, 129669, 160928, 71277, 112706, 110871, 64911, 7783, 96057, 28053, 195308, 44644, 178040, 175418, 161910, 185920, 39816, 131616, 181890, 39619, 118905, 43568, 163312, 1875, 158701, 3285, 108746, 99136, 85705, 134784, 124594, 158164, 151538, 74446, 4358, 190560, 3390, 467, 22170, 191273, 34690, 183590, 64689, 183373, 127479, 52264, 27514, 22021, 71840, 26364, 50244, 194555, 33844, 79030, 35583, 88379, 38012, 140726, 33469, 194555, 27604, 153634, 187019, 103919, 125242, 58964, 13679, 119294, 57380, 144078, 144303, 181075, 132410, 124427, 151022, 57135, 190354, 78700, 54616, 96399, 75874, 189839, 7387, 166390, 162359, 126542, 138639, 194853, 45020, 165059, 103008, 149279, 177795, 174918, 73545, 181890, 37248, 177709, 71168, 115889, 98398, 44694, 154769, 163452, 7650, 117147, 77998, 112138, 106610, 149039, 109605, 112762, 101982, 45241, 192951, 140650, 160324, 99113, 50357, 50131, 19582, 168501, 121966, 175618, 177999, 137227, 150067, 84728, 61385, 192080, 186564, 101737, 198507, 19970, 74542, 27118, 32454, 101844, 5785, 54971, 160576, 106396, 145778, 118882, 103094, 65903, 20987, 62395, 103560, 25800, 133906, 74885, 117948, 172959, 75576, 66461, 114526, 139187, 121201, 62635, 91083, 84757, 61224, 90951, 173669, 5347, 65963, 166364, 132401, 31315, 197749, 126360, 199275, 175547, 84192, 78810, 14225, 10097, 69878, 141955, 102834, 106388, 46915, 150354, 21034, 87698, 69283, 469, 83357, 78127, 197282, 59624, 134510, 28587, 100858, 117945, 176084, 131596, 96373, 86706, 70353, 125915, 56667, 131876, 168474, 92643, 13510, 105835, 107131, 141786, 174035, 83812, 124927, 7189, 31262, 86883, 158374, 118735, 120618, 185046, 195843, 164164, 138614, 27823, 67752, 36151, 56806, 116, 178852, 175456, 178359, 196210, 116460, 141963, 1026, 18588, 33260, 6927, 189949, 146185, 176420, 12708, 1517, 160983, 18074, 166343, 120140, 128105, 191683, 101580, 92749, 109855, 4439, 51286, 43954, 8167, 35807, 153838, 20615, 53979, 52312, 62438, 2104, 124505, 83521, 62604, 154195, 33515, 106546, 101846, 137558, 174953, 130180, 51922, 105106, 67630, 135899, 170424, 73910, 198909, 58050, 43434, 94400, 7286, 112607, 71239, 95573, 24786, 183736, 90831, 90682, 46113, 194004, 107297, 20899, 19117, 59247, 61335, 171250, 169742, 196568, 9855, 56331, 71929, 36780, 83173, 196778, 163154, 49181, 173197, 177996, 9130, 125809, 50880, 158791, 187826, 27849, 63275, 5294, 134716, 139631, 182418, 70740, 3135, 20687, 125318, 9834, 134157, 104700 };

	Solution solution;
	std::cout << solution.countDifferentSubsequenceGCDs(temp) << std::endl;
#endif // LEETCODE_1819
	return 0;
}

int leetcodetest1822()
{
#ifdef LEETCODE_1822
#endif
	return 0;
}

int leetcodetest1824()
{
#ifdef LEETCODE_1824
	std::vector<int> temp = { 0, 1, 2, 3, 0 };

	Solution solution;
	std::cout << solution.minSideJumps(temp) << std::endl;

#endif // LEETCODE_1824
	return 0;
}

int leetcodetest1825()
{
#ifdef LEETCODE_1825
	MKAverage obj(3, 1);
	std::cout << "null" << std::endl;

	obj.addElement(3);
	obj.addElement(1);
	std::cout << obj.calculateMKAverage() << std::endl;
	obj.addElement(10);
	std::cout << obj.calculateMKAverage() << std::endl;
	obj.addElement(5);
	obj.addElement(5);
	obj.addElement(5);
	std::cout << obj.calculateMKAverage() << std::endl;

	//MKAverage obj(3, 1);
	//std::cout << "null" << std::endl;

	//obj.addElement(17612);
	//obj.addElement(74607);
	//std::cout << obj.calculateMKAverage() << std::endl;
	//obj.addElement(8272);
	//obj.addElement(33433);
	//std::cout << obj.calculateMKAverage() << std::endl;
	//obj.addElement(15456);
	//obj.addElement(64938);
	//std::cout << obj.calculateMKAverage() << std::endl;
	//obj.addElement(99741);

#endif // LEETCODE_1825
	return 0;
}

int leetcodetest1827()
{
#ifdef LEETCODE_1827
#endif // LEETCODE_1827
	return 0;
}

int leetcodetest1828()
{
#ifdef LEETCODE_1828
	std::vector<std::vector<int>> points = { {1, 3},{3, 3},{5, 3},{2, 2} };
	std::vector<std::vector<int>> queries = { {2, 3, 1},{4, 3, 1},{1, 1, 2} };

	Solution solution;
	solution.countPoints(points, queries);


#endif // LEETCODE_1828
	return 0;
}

int leetcodetest1832()
{
#ifdef LEETCODE_1832
#endif // LEETCODE_1832
	return 0;
}

int leetcodetest1909()
{
#ifdef LEETCODE_1909
	vector<int> num = { 1,1,1 };
	Solution solution;

	std::cout << solution.canBeIncreasing(num) << std::endl;

#endif
	return 0;
}

int leetcodetest1945()
{
#ifdef LEETCODE_1945
	std::string temp = "dbvmfhnttvr";
	Solution solution;
	solution.getLucky(temp, 5);

#endif // LEETCODE_1945
	return 0;
}

int leetcodetest1971()
{
#ifdef LEETCODE_1971
#endif // LEETCODE_1971
	return 0;
}

int leetcodetest2011()
{
#ifdef LEETCODE_2011
#endif // LEETCODE_2011
	return 0;
}

int leetcodetest2027()
{
#ifdef LEETCODE_2027
#endif // LEETCODE_2027
	return 0;
}

int leetcodetest2032()
{
#ifdef LEETCODE_2032
#endif // LEETCODE_2032
	return 0;
}

int leetcodetest2037()
{
#ifdef LEETCODE_2037
#endif // LEETCODE_2037
	return 0;
}

int leetcodetest2042()
{
#ifdef LEETCODE_2042
	std::string temp = "hello word 5 * 5";
	Solution solution;
	solution.areNumbersAscending(temp);
#endif // LEETCODE_2042
	return 0;
}

int leetcodetest2104()
{
#ifdef LEETCODE_2104
	vector<int> num = { 4,-2,-3,4,1 };
	Solution solution;

	std::cout << solution.subArrayRanges(num) << std::endl;

#endif
	return 0;
}

int leetcodetest2119()
{
#ifdef LEETCODE_2119
	int num = 12300;
	Solution solution;

	std::cout << solution.isSameAfterReversals(num) << std::endl;
#endif // LEETCODE_2119
	return 0;
}

int leetcodetest2180()
{
#ifdef LEETCODE_2180
#endif // LEETCODE_2180
	return 0;
}

int leetcodetest2185()
{
#ifdef LEETCODE_2185
#endif // LEETCODE_2185
	return 0;
}

int leetcodetest2283()
{
#ifdef LEETCODE_2283
#endif // LEETCODE_2283
	return 0;
}

int leetcodetest2287()
{
#ifdef LEETCODE_2287
#endif // LEETCODE_2287
	return 0;
}

int leetcodetest2293()
{
#ifdef LEETCODE_2293
	std::vector<int> temp = { 70,38,21,22 };
	Solution solution;
	solution.minMaxGame(temp);
#endif // LEETCODE_2293
	return 0;
}

int leetcodetest2299()
{
#ifdef LEETCODE_2299
#endif // LEETCODE_2299
	return 0;
}

int leetcodetest2303()
{
#ifdef LEETCODE_2303
#endif // LEETCODE_2303
	return 0;
}

int leetcodetest2309()
{
#ifdef LEETCODE_2309
#endif // LEETCODE_2309
	return 0;
}

int leetcodetest2315()
{
#ifdef LEETCODE_2315
#endif // LEETCODE_2315
	return 0;
}

int leetcodetest2319()
{
#ifdef LEETCODE_2319
#endif // LEETCODE_2319
	return 0;
}

int leetcodetest2325()
{
#ifdef LEETCODE_2325
#endif // LEETCODE_2325
	return 0;
}

int leetcodetest2331()
{
#ifdef LEETCODE_2331
#endif // LEETCODE_2331
	return 0;
}

int leetcodetest2335()
{
#ifdef LEETCODE_2335
#endif // LEETCODE_2335
	return 0;
}

int leetcodetest2341()
{
#ifdef LEETCODE_2341
#endif // LEETCODE_2341
	return 0;
}

int leetcodetest2351()
{
#ifdef LEETCODE_2351
#endif // LEETCODE_2351
	return 0;
}

int leetcodetest6306()
{
#ifdef LEETCODE_6306
	//std::vector<std::vector<int>> temp = { {1,9,1,8},{10,10,10,10 } };
	//int n = 3;
	//int k = 2;

	std::vector<std::vector<int>> temp = { {1,1,2,1},{1,1,3,1},{1,1,4,1} };
	int n = 1;
	int k = 3;

	Solution solution;
	std::cout << solution.findCrossingTime(n, k, temp) << std::endl;

#endif // LEETCODE_6306
	return 0;
}

int leetcodetestaudition0102()
{
#ifdef LEETCODE_2104_AUDITION_01_02__
#endif // LEETCODE_2104_AUDITION_01_02__
	return 0;
}

int leetcodetestaudition0109()
{
#ifdef LEETCODE_2104_AUDITION_01_09__

	std::string s1 = "waterbottle";
	std::string s2 = "erbottlewat";
	Solution solution;
	solution.isFlipedString(s1, s2);
#endif // LEETCODE_2104_AUDITION_01_09__
	return 0;
}

int leetcodetestaudition0406()
{
#ifdef LEETCODE_2104_AUDITION_04_06__
#endif
	return 0;
}

int leetcodetestaudition1709()
{
#ifdef LEETCODE_2104_AUDITION_17_09__

	Solution solution;
	solution.getKthMagicNumber(18);
#endif // LEETCODE_2104_AUDITION_17_09__
	return 0;
}

int leetcodetestaudition1711()
{
#ifdef DELEETCODE_2104_AUDITION_17_11__BUG
#endif // DELEETCODE_2104_AUDITION_17_11__BUG
	return 0;
}

int leetcodetestaudition1719()
{
#ifdef AUDITION_17_19
	std::vector<int> temp = { 1, 2, 3, 4, 6, 7, 9, 10 };
	Solution solution;
	solution.missingTwo(temp);
#endif // AUDITION_17_19
	return 0;
}

int swordOfferII041()
{
#ifdef SWORD_OFFER_II_041
#endif // SWORD_OFFER_II_041
	return 0;
}

int swordOfferII114()
{
#ifdef SWORD_OFFER_II_114
	std::vector<std::string> temp = { "wdaaajlzzz", "asfas", "afawef" };

	Solution solution;
	std::cout << solution.alienOrder(temp).c_str() << std::endl;

#endif // SWORD_OFFER_II_114
	return 0;
}

int swordOfferII115()
{
#ifdef SWORD_OFFER_II_115
#endif // SWORD_OFFER_II_115	return 0;
	return 0;
}

int leetcodeTest() {
	leetcodetest2();
	leetcodetest4();
	leetcodetest5();
	leetcodetest10();
	leetcodetest11();
	leetcodetest13();
	leetcodetest14();
	leetcodetest15();
	leetcodetest20();
	leetcodetest21();
	leetcodetest30();
	leetcodetest49();
	leetcodetest94();
	leetcodetest171();
	leetcodetest174();
	leetcodetest215();
	leetcodetest287();
	leetcodetest324();
	leetcodetest326();
	leetcodetest427();
	leetcodetest434();
	leetcodetest436();
	leetcodetest450();
	leetcodetest462();
	leetcodetest464();
	leetcodetest467();
	leetcodetest468();
	leetcodetest473();
	leetcodetest481();
	leetcodetest497();
	leetcodetest498();
	leetcodetest513();
	leetcodetest522();
	leetcodetest532();
	leetcodetest535();
	leetcodetest556();
	leetcodetest558();
	leetcodetest565();
	leetcodetest592();
	leetcodetest622();
	leetcodetest623();
	leetcodetest636();
	leetcodetest640();
	leetcodetest641();
	leetcodetest646();
	leetcodetest652();
	leetcodetest654();
	leetcodetest655();
	leetcodetest658();
	leetcodetest662();
	leetcodetest667();
	leetcodetest668();
	leetcodetest669();
	leetcodetest672();
	leetcodetest675();
	leetcodetest676();
	leetcodetest687();
	leetcodetest698();
	leetcodetest699();
	leetcodetest707();
	leetcodetest715();
	leetcodetest719();
	leetcodetest729();
	leetcodetest730();
	leetcodetest731();
	leetcodetest732();
	leetcodetest735();
	leetcodetest741();
	leetcodetest745();
	leetcodetest747();
	leetcodetest749();
	leetcodetest753();
	leetcodetest754();
	leetcodetest761();
	leetcodetest762();
	leetcodetest764();
	leetcodetest769();
	leetcodetest775();
	leetcodetest777();
	leetcodetest782();
	leetcodetest784();
	leetcodetest788();
	leetcodetest790();
	leetcodetest791();
	leetcodetest792();
	leetcodetest795();
	leetcodetest799();
	leetcodetest801();
	leetcodetest805();
	leetcodetest808();
	leetcodetest809();
	leetcodetest811();
	leetcodetest813();
	leetcodetest814();
	leetcodetest816();
	leetcodetest817();
	leetcodetest827();
	leetcodetest828();
	leetcodetest829();
	leetcodetest850();
	leetcodetest854();
	leetcodetest855();
	leetcodetest857();
	leetcodetest862();
	leetcodetest870();
	leetcodetest871();
	leetcodetest875();
	leetcodetest878();
	leetcodetest882();
	leetcodetest886();
	leetcodetest890();
	leetcodetest891();
	leetcodetest895();
	leetcodetest899();
	leetcodetest901();
	leetcodetest902();
	leetcodetest904();
	leetcodetest907();
	leetcodetest915();
	leetcodetest919();
	leetcodetest926();
	leetcodetest927();
	leetcodetest934();
	leetcodetest940();
	leetcodetest942();
	leetcodetest946();
	leetcodetest951();
	leetcodetest953();
	leetcodetest961();
	leetcodetest965();
	leetcodetest998();
	leetcodetest1021();
	leetcodetest1022();
	leetcodetest1037();
	leetcodetest1051();
	leetcodetest1052();
	leetcodetest1089();
	leetcodetest1106();
	leetcodetest1108();
	leetcodetest1124();
	leetcodetest1129();
	leetcodetest1138();
	leetcodetest1145();
	leetcodetest1162();
	leetcodetest1172();
	leetcodetest1175();
	leetcodetest1184();
	leetcodetest1185();
	leetcodetest1200();
	leetcodetest1206();
	leetcodetest1210();
	leetcodetest1217();
	leetcodetest1223();
	leetcodetest1224();
	leetcodetest1233();
	leetcodetest1234();
	leetcodetest1235();
	leetcodetest1250();
	leetcodetest1252();
	leetcodetest1260();
	leetcodetest1282();
	leetcodetest1302();
	leetcodetest1331();
	leetcodetest1374();
	leetcodetest1399();
	leetcodetest1403();
	leetcodetest1408();
	leetcodetest1413();
	leetcodetest1417();
	leetcodetest1422();
	leetcodetest1441();
	leetcodetest1450();
	leetcodetest1455();
	leetcodetest1460();
	leetcodetest1470();
	leetcodetest1475();
	leetcodetest1582();
	leetcodetest1592();
	leetcodetest1604();
	leetcodetest1608();
	leetcodetest1620();
	leetcodetest1624();
	leetcodetest1632();
	leetcodetest1636();
	leetcodetest1640();
	leetcodetest1652();
	leetcodetest1656();
	leetcodetest1658();
	leetcodetest1662();
	leetcodetest1663();
	leetcodetest1664();
	leetcodetest1668();
	leetcodetest1669();
	leetcodetest1678();
	leetcodetest1684();
	leetcodetest1687();
	leetcodetest1691();
	leetcodetest1697();
	leetcodetest1700();
	leetcodetest1703();
	leetcodetest1704();
	leetcodetest1710();
	leetcodetest1728();
	leetcodetest1732();
	leetcodetest1739();
	leetcodetest1742();
	leetcodetest1750();
	leetcodetest1752();
	leetcodetest1753();
	leetcodetest1754();
	leetcodetest1758();
	leetcodetest1760();
	leetcodetest1764();
	leetcodetest1769();
	leetcodetest1773();
	leetcodetest1774();
	leetcodetest1775();
	leetcodetest1780();
	leetcodetest1781();
	leetcodetest1785();
	leetcodetest1786();
	leetcodetest1790();
	leetcodetest1796();
	leetcodetest1797();
	leetcodetest1798();
	leetcodetest1800();
	leetcodetest1801();
	leetcodetest1802();
	leetcodetest1803();
	leetcodetest1805();
	leetcodetest1806();
	leetcodetest1807();
	leetcodetest1813();
	leetcodetest1814();
	leetcodetest1815();
	leetcodetest1817();
	leetcodetest1819();
	leetcodetest1822();
	leetcodetest1824();
	leetcodetest1825();
	leetcodetest1827();
	leetcodetest1828();
	leetcodetest1832();
	leetcodetest1909();
	leetcodetest1945();
	leetcodetest1971();
	leetcodetest2011();
	leetcodetest2027();
	leetcodetest2032();
	leetcodetest2037();
	leetcodetest2042();
	leetcodetest2104();
	leetcodetest2119();
	leetcodetest2180();
	leetcodetest2185();
	leetcodetest2283();
	leetcodetest2287();
	leetcodetest2293();
	leetcodetest2299();
	leetcodetest2303();
	leetcodetest2309();
	leetcodetest2315();
	leetcodetest2319();
	leetcodetest2325();
	leetcodetest2331();
	leetcodetest2335();
	leetcodetest2341();
	leetcodetest2351();
	leetcodetest6306();
	leetcodetestaudition0102();
	leetcodetestaudition0109();
	leetcodetestaudition0406();
	leetcodetestaudition1709();
	leetcodetestaudition1711();
	leetcodetestaudition1719();
	swordOfferII041();
	swordOfferII114();
	swordOfferII115();

	return 0;
}