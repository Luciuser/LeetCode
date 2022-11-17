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

int leetcodetest5()
{
#ifdef LEETCODE_5
	Solution solution;
	std::cout << solution.longestPalindrome("cbbd").c_str() << std::endl;
#endif // LEETCODE_5

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
		std::cout << result[i] << std::endl;
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

int leetcodetest811()
{
#ifdef LEETCODE_811
#endif // LEETCODE_811
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

int leetcodetest875()
{
#ifdef LEETCODE_875
	std::vector<int> temp = { 3 };
	Solution solution;

	std::cout << solution.minEatingSpeed(temp, 3) << std::endl;

#endif // LEETCODE_875
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

int leetcodetest1217()
{
#ifdef LEETCODE_1217
#endif // LEETCODE_1217
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

int leetcodetest1662()
{
#ifdef LEETCODE_1662
#endif // LEETCODE_1662
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

int leetcodetest1700()
{
#ifdef LEETCODE_1700
#endif // LEETCODE_1700
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

int leetcodetest1773()
{
#ifdef LEETCODE_1773
#endif // LEETCODE_1773
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

int leetcodetest1800()
{
#ifdef LEETCODE_1800
#endif
	return 0;
}

int leetcodetest1822()
{
#ifdef LEETCODE_1822
#endif
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
	leetcodetest5();
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
	leetcodetest592();
	leetcodetest622();
	leetcodetest623();
	leetcodetest636();
	leetcodetest640();
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
	leetcodetest730();
	leetcodetest731();
	leetcodetest732();
	leetcodetest735();
	leetcodetest745();
	leetcodetest747();
	leetcodetest749();
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
	leetcodetest801();
	leetcodetest805();
	leetcodetest811();
	leetcodetest814();
	leetcodetest816();
	leetcodetest817();
	leetcodetest827();
	leetcodetest828();
	leetcodetest829();
	leetcodetest850();
	leetcodetest854();
	leetcodetest857();
	leetcodetest862();
	leetcodetest870();
	leetcodetest875();
	leetcodetest886();
	leetcodetest890();
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
	leetcodetest1162();
	leetcodetest1172();
	leetcodetest1175();
	leetcodetest1184();
	leetcodetest1185();
	leetcodetest1200();
	leetcodetest1206();
	leetcodetest1217();
	leetcodetest1224();
	leetcodetest1235();
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
	leetcodetest1608();
	leetcodetest1620();
	leetcodetest1624();
	leetcodetest1636();
	leetcodetest1640();
	leetcodetest1652();
	leetcodetest1656();
	leetcodetest1662();
	leetcodetest1668();
	leetcodetest1678();
	leetcodetest1684();
	leetcodetest1700();
	leetcodetest1710();
	leetcodetest1728();
	leetcodetest1773();
	leetcodetest1781();
	leetcodetest1786();
	leetcodetest1790();
	leetcodetest1800();
	leetcodetest1822();
	leetcodetest1909();
	leetcodetest2104();
	leetcodetest2119();
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