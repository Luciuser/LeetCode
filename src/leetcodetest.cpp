#include  "leetcodetest.h"

#ifdef LEETCODE_2
int leetcodetest2()
{
	ListNode *l13 = new ListNode(3);
	ListNode *l12 = new ListNode(4, l13);
	ListNode *l11 = new ListNode(2, l12);
	ListNode *l23 = new ListNode(4);
	ListNode *l22 = new ListNode(6, l23);
	ListNode *l21 = new ListNode(5, l22);

	Solution solution;
	std::cout << solution.addTwoNumbers(l11, l21) << std::endl;
	return 0;
}
#endif // LEETCODE_2

#ifdef LEETCODE_5
int leetcodetest5()
{
	Solution solution;
	std::cout << solution.longestPalindrome("cbbd").c_str() << std::endl;

	return 0;
}
#endif // LEETCODE_5

#ifdef LEETCODE_30
int leetcodetest30()
{
	return 0;
}
#endif // LEETCODE_30

#ifdef LEETCODE_49
int leetcodetest49()
{
	return 0;
}
#endif // LEETCODE_49

#ifdef LEETCODE_94
int leetcodetest94()
{
	return 0;
}
#endif

#ifdef LEETCODE_171
int leetcodetest171()
{
	return 0;
}
#endif // LEETCODE_171

#ifdef LEETCODE_174
int leetcodetest174()
{
	std::vector<std::vector<int>> temp = { {-2, -3, 3},{-5, -10, 1},{10,30,-5} };

	Solution solution;
	std::cout << solution.calculateMinimumHP(temp) << std::endl;

	return 0;
}
#endif // LEETCODE_174

#ifdef LEETCODE_215
int leetcodetest215()
{
	std::vector<int> temp = { 2,1};

	Solution solution;
	std::cout << solution.findKthLargest(temp, 1) << std::endl;
	return 0;
}
#endif // LEETCODE_215

#ifdef LEETCODE_287
int leetcodetest287()
{
	return 0;
}
#endif // LEETCODE_287

#ifdef LEETCODE_324
int leetcodetest324()
{
	std::vector<int> temp = {1,1,2,1,2,2};
	Solution solution;
	solution.wiggleSort(temp);

	for (int i = 0; i < temp.size(); i++) {
		std::cout << temp[i] << std::endl;
	}

	return 0;
}
#endif // LEETCODE_324

#ifdef LEETCODE_326
int leetcodetest326()
{
	Solution solution;
	solution.isPowerOfThree(243);
	return 0;
}
#endif // LEETCODE_326

#ifdef LEETCODE_427
int leetcodetest427()
{
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

	return 0;
}
#endif

#ifdef LEETCODE_434
int leetcodetest434()
{
	return 0;
}
#endif // LEETCODE_434

#ifdef LEETCODE_436
int leetcodetest436()
{
	std::vector<std::vector<int>> temp = { {1,1},{3,4} };

	Solution solution;
	std::vector<int> result = solution.findRightInterval(temp);

	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}

	return 0;
}
#endif // LEETCODE_436

#ifdef LEETCODE_450
int leetcodetest450()
{
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node3 = new TreeNode(3, node2, node4);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node6 = new TreeNode(6, nullptr, node7);

	TreeNode *root = new TreeNode(5, node3, node6);

	Solution solution;

	solution.deleteNode(root, 3);

	return 0;
}
#endif // LEETCODE_450

#ifdef LEETCODE_462
int leetcodetest462()
{
	return 0;
}
#endif // LEETCODE_462

#ifdef LEETCODE_464
int leetcodetest464()
{
	return 0;
}
#endif // LEETCODE_464

#ifdef LEETCODE_467
int leetcodetest467()
{
	Solution solution;
	std::cout << solution.findSubstringInWraproundString("zaba") << std::endl;
	return 0;
}
#endif // LEETCODE_467

#ifdef LEETCODE_468
int leetcodetest468()
{
	Solution solution;
	std::cout << solution.validIPAddress("1.00.1.1").c_str();

	return 0;
}
#endif // LEETCODE_468

#ifdef LEETCODE_473
int leetcodetest473()
{
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

	return 0;
}
#endif // LEETCODE_473

#ifdef LEETCODE_497
int leetcodetest497()
{
	return 0;
}
#endif // LEETCODE_497

#ifdef LEETCODE_498
int leetcodetest498()
{
	return 0;
}
#endif // LEETCODE_498

#ifdef LEETCODE_513
int leetcodetest513()
{
	return 0;
}
#endif // LEETCODE_513

#ifdef LEETCODE_522
int leetcodetest522()
{
	std::vector<std::string> temp = { "aaa","aaa","aa" };
	Solution solution;
	std::cout << solution.findLUSlength(temp) << std::endl;

	return 0;
}
#endif // LEETCODE_522

#ifdef LEETCODE_532
int leetcodetest532()
{
	std::vector<int> temp = { 1,3,1,5,4 };
	Solution solution;
	std::cout << solution.findPairs(temp, 0) << std::endl;

	return 0;
}
#endif // LEETCODE_532

#ifdef LEETCODE_535
int leetcodetest535()
{
	return 0;
}
#endif // LEETCODE_535

#ifdef LEETCODE_592
int leetcodetest592()
{
	Solution solution;
	std::cout << solution.fractionAddition("-1/2+1/2") << std::endl;

	return 0;
}
#endif // LEETCODE_592

#ifdef LEETCODE_622
int leetcodetest622()
{
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




	return 0;
}
#endif // LEETCODE_622

#ifdef LEETCODE_623
int leetcodetest623()
{
	return 0;
}
#endif // LEETCODE_623

#ifdef LEETCODE_636
int leetcodetest636()
{
	Solution *solution = new Solution();
	std::vector<std::string> temp = { "0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7" };

	solution->exclusiveTime(1, temp);

	return 0;
}
#endif // LEETCODE_636

#ifdef LEETCODE_640
int leetcodetest640()
{
	Solution *solution = new Solution();

	solution->solveEquation("x+5-3+x=6+x-2");

	return 0;
}
#endif // LEETCODE_640

#ifdef LEETCODE_654
int leetcodetest654()
{
	Solution solution;
	std::vector<int> temp = { 3, 6, 7, 5, 1, 2, 8, 9 };
	solution.constructMaximumBinaryTree(temp);

	return 0;
}
#endif // LEETCODE_654

#ifdef LEETCODE_655
int leetcodetest655()
{
	Solution solution;
	return 0;
}
#endif // LEETCODE_655

#ifdef LEETCODE_668
int leetcodetest668()
{
	Solution solution;
	std::cout << solution.findKthNumber(3, 3, 5) << std::endl;
	return 0;
}
#endif // LEETCODE_668

#ifdef LEETCODE_675
int leetcodetest675()
{
	std::vector<std::vector<int>> temp = { {4,2,3},{0,0,1},{7,6,5} };

	Solution solution;
	std::cout << solution.cutOffTree(temp) << std::endl;
	return 0;

	return 0;
}
#endif // LEETCODE_675

#ifdef LEETCODE_676
int leetcodetest676()
{
	std::vector<std::string>temp = { "hello","leetcode" };

	MagicDictionary *md = new MagicDictionary();
	md->buildDict(temp);
	std::cout << md->search("hello") << std::endl;
	std::cout << md->search("hhllo") << std::endl;
	std::cout << md->search("hell") << std::endl;
	std::cout << md->search("leetcoded") << std::endl;

	return 0;
}
#endif // LEETCODE_676

#ifdef LEETCODE_699
int leetcodetest699() {
	std::vector<std::vector<int>> temp = { {1,2},{2,3},{6,1} };

	Solution solution;
	std::vector<int> result = solution.fallingSquares(temp);

	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}
	return 0;
}
#endif // LEETCODE_699

#ifdef LEETCODE_715
int leetcodetest715()
{
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

	return 0;
}
#endif // LEETCODE_715

#ifdef LEETCODE_719
int leetcodetest719()
{
	Solution solution;

	std::vector<int> temp = { 1,6,1 };

	std::cout << solution.smallestDistancePair(temp, 5000) << std::endl;

	return 0;
}
#endif // LEETCODE_719

#ifdef LEETCODE_730
int leetcodetest730()
{
	return 0;
}
#endif // LEETCODE_730

#ifdef DEBUG
int leetcodetest731()
{
	return 0;
}
#endif // DEBUG

#ifdef LEETCODE_732
int leetcodetest732()
{
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

	return 0;
}
#endif // LEETCODE_732

#ifdef LEETCODE_735
int leetcodetest735()
{
	std::vector<int> temp = { -2,-2,1,-2 };

	Solution *solution = new Solution();
	std::vector<int> result = solution->asteroidCollision(temp);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}

	return 0;
}
#endif // LEETCODE_735

#ifdef LEETCODE_745
int leetcodetest745()
{

	std::vector<std::string> temp = { "apple", "bsize", "hello", "abcd", "ab", "hellp", "hellp", "a", "basize" };
	WordFilter *wordFilter = new WordFilter(temp);
	wordFilter->f("a", "e");

	return 0;
}
#endif // LEETCODE_745

#ifdef LEETCODE_747
int leetcodetest747()
{
	Solution solution;
	std::vector<int> test = { 1,0 };
	std::cout << solution.dominantIndex(test) << std::endl;
	return 0;
}
#endif // LEETCODE_747

#ifdef LEETCODE_749
int leetcodetest749()
{
	//std::vector<std::vector<int>> temp = { {0,1,0,0,0,0,0,1},{0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0} };
	std::vector<std::vector<int>> temp = { {1, 1, 1, 0, 0, 0, 0, 0, 0},{1, 0, 1, 0, 1, 1, 1, 1, 1},{1, 1, 1, 0, 0, 0, 0, 0, 0} };


	Solution solution;
	std::cout << solution.containVirus(temp);

	return 0;
}
#endif // LEETCODE_749

#ifdef LEETCODE_761
int leetcodetest761()
{
	Solution *solution = new Solution();

	std::cout << solution->makeLargestSpecial("11011000");


	return 0;
}
#endif // LEETCODE_761

#ifdef LEETCODE_762
int leetcodetest762()
{
	return 0;
}
#endif // LEETCODE_762

#ifdef LEETCODE_782
int leetcodetest782()
{
	return 0;
}
#endif // LEETCODE_782

#ifdef LEETCODE_814
int leetcodetest814()
{
	return 0;
}
#endif // LEETCODE_814

#ifdef LEETCODE_829
int leetcodetest829()
{
	Solution solution;

	std::cout << solution.consecutiveNumbersSum(6) << std::endl;

	return 0;
}
#endif // LEETCODE_829

#ifdef LEETCODE_875
int leetcodetest875()
{
	std::vector<int> temp = { 3 };
	Solution solution;

	std::cout << solution.minEatingSpeed(temp, 3) << std::endl;

	return 0;
}
#endif // LEETCODE_875

#ifdef LEETCODE_890
int leetcodetest890()
{
	
	std::vector<std::string> temp = { "yzmyr", "fhufq", "lghlq", "oahot", "ueiuq" };
	Solution solution;

	std::vector<std::string> result = solution.findAndReplacePattern(temp, "iusiq");
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i].c_str() << std::endl;
	}

	return 0;
}
#endif // LEETCODE_890

#ifdef LEETCODE_899
int leetcodetest899()
{
	return 0;
}
#endif // LEETCODE_899

#ifdef LEETCODE_919
int leetcodetest919()
{
	TreeNode *root = new TreeNode(1);
	//TreeNode *node1 = new TreeNode(2);
	//root->left = node1;

	CBTInserter *solution = new CBTInserter(root);
	std::cout << solution->insert(3);
	std::cout << solution->insert(3);
	std::cout << solution->insert(4);

	return 0;
}
#endif // LEETCODE_919

#ifdef LEETCODE_926
int leetcodetest926()
{
	Solution solution;
	std::string s = "1";

	std::cout << solution.minFlipsMonoIncr(s) << std::endl;
	
	return 0;
}
#endif // LEETCODE_926

#ifdef LEETCODE_942
int leetcodetest942()
{
	string str = "IDID";
	Solution solution;

	vector<int> result = solution.diStringMatch(str);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " " << std::endl;
	}

	return 0;
}
#endif

#ifdef LEETCODE_951
int leetcodetest951()
{
	return 0;
}
#endif // LEETCODE_951

#ifdef LEETCODE_953
int leetcodetest953()
{
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

	return 0;
}
#endif

#ifdef LEETCODE_961
int leetcodetest961()
{
	return 0;
}
#endif

#ifdef LEETCODE_965
int leetcodetest965()
{
	return 0;
}
#endif // LEETCODE_965

#ifdef LEETCODE_1021
int leetcodetest1021()
{
	return 0;
}
#endif // LEETCODE_1021

#ifdef LEETCODE_1108
int leetcodetest1108()
{
	return 0;
}
#endif // LEETCODE_1108

#ifdef LEETCODE_1022
int leetcodetest1022()
{
	return 0;
}
#endif // LEETCODE_1022

#ifdef LEETCODE_1037
int leetcodetest1037()
{
	return 0;
}
#endif // LEETCODE_1037

#ifdef LEETCODE_1051
int leetcodetest1051()
{
	return 0;
}
#endif // LEETCODE_1051

#ifdef LEETCODE_1052
int leetcodetest1052()
{
	return 0;
}
#endif // LEETCODE_1052

#ifdef LEETCODE_1089
int leetcodetest1089()
{
	std::vector<int> temp = { 1,0,0,0,0,0 };

	Solution solution;
	solution.duplicateZeros(temp);

	for (int i = 0; i < temp.size(); i++) {
		std::cout << temp[i] << std::endl;
	}

	return 0;
}
#endif // LEETCODE_1089

#ifdef LEETCODE_1162
int leetcodetest1162()
{
	std::vector<std::vector<int>> temp = { {1, 0, 0, 0, 0, 1, 0, 0, 0, 1}, {1, 1, 0, 1, 1, 1, 0, 1, 1, 0}, {0, 1, 1, 0, 1, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 1, 0, 1, 0, 1}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 1}, {0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 1, 1, 1, 1, 1, 0, 0}};
	Solution solution;

	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp[i].size(); j++) {
			std::cout << temp[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << solution.maxDistance(temp) << std::endl;

	return 0;
}
#endif // LEETCODE_1162

#ifdef LEETCODE_1172
int leetcodetest1172()
{
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

	return 0;
}
#endif // LEETCODE_1172

#ifdef LEETCODE_1175
int leetcodetest1175()
{
	Solution solution;
	std::cout << solution.numPrimeArrangements(5) << std::endl;
	return 0;
}
#endif // LEETCODE_1175

#ifdef LEETCODE_1184
int leetcodetest1184()
{
	return 0;
}
#endif // LEETCODE_1184

#ifdef LEETCODE_1185
int leetcodetest1185()
{
	return 0;
}
#endif // LEETCODE_1185

#ifdef LEETCODE_1200
int leetcodetest1200()
{
	return 0;
}
#endif // LEETCODE_1200

#ifdef LEETCODE_1206
int leetcodetest1206()
{
	return 0;
}
#endif // LEETCODE_1206

#ifdef LEETCODE_1252
int leetcodetest1252()
{
	return 0;
}
#endif // LEETCODE_1252

#ifdef LEETCODE_1260
int leetcodetest1260()
{
	return 0;
}
#endif // LEETCODE_1260

#ifdef LEETCODE_1282
int leetcodetest1282()
{
	return 0;
}
#endif // LEETCODE_1282

#ifdef LEETCODE_1331
int leetcodetest1331()
{
	return 0;
}
#endif // LEETCODE_1331

#ifdef LEETCODE_1374
int leetcodetest1374()
{
	return 0;
}
#endif // LEETCODE_1374

#ifdef LEETCODE_1399
int leetcodetest1399()
{
	return 0;
}
#endif // LEETCODE_1399

#ifdef LEETCODE_1403
int leetcodetest1403()
{
	return 0;
}
#endif // LEETCODE_1403

#ifdef LEETCODE_1408
int leetcodetest1408()
{
	Solution *solution = new Solution();
	
	std::vector<std::string> temp = { "mass", "as", "hero", "superhero" };

	solution->stringMatching(temp);

	return 0;
}
#endif // LEETCODE_1408

#ifdef LEETCODE_1413
int leetcodetest1413()
{
	return 0;
}
#endif // LEETCODE_1413

#ifdef LEETCODE_1417
int leetcodetest1417()
{
	Solution *solution = new Solution();

	std::cout << solution->reformat("a") << std::endl;

	return 0;
}
#endif // LEETCODE_1417

#ifdef LEETCODE_1422
int leetcodetest1422()
{
	Solution solution;

	std::cout << solution.maxScore("110000") << std::endl;

	return 0;
}
#endif // LEETCODE_1422

#ifdef LEETCODE_1455
int leetcodetest1455()
{
	Solution solution;

	std::cout << solution.isPrefixOfWord("i love eating burger", "burg") << std::endl;

	return 0;
}
#endif // LEETCODE_1455

#ifdef LEETCODE_1728
int leetcodetest1728()
{
	return 0;
}
#endif

#ifdef LEETCODE_1781
int leetcodetest1781()
{
	Solution solution;
	std::cout << solution.beautySum("aabcb") << std::endl;

	return 0;
}
#endif // LEETCODE_1781

#ifdef LEETCODE_1786
int leetcodetest1786()
{
	int n = 6;
	Solution solution;

	std::vector<std::vector<int>> temp = { {6, 2, 9},{2, 1, 7},{6, 5, 10},{4, 3, 1},{3, 1, 8},{4, 6, 4},{5, 1, 7},{1, 4, 7},{4, 5, 3},{3, 6, 6},{5, 3, 9},{1, 6, 6},{3, 2, 2},{5, 2, 8} };

	std::cout << solution.countRestrictedPaths(n, temp) << std::endl;

	return 0;
}
#endif // LEETCODE_1786

#ifdef LEETCODE_1909
int leetcodetest1909()
{
	vector<int> num = { 1,1,1 };
	Solution solution;

	std::cout << solution.canBeIncreasing(num) << std::endl;

	return 0;
}
#endif

#ifdef LEETCODE_2104
int leetcodetest2104()
{
	vector<int> num = { 4,-2,-3,4,1 };
	Solution solution;

	std::cout << solution.subArrayRanges(num) << std::endl;

	return 0;
}
#endif

#ifdef LEETCODE_2119
int leetcodetest2119()
{
	int num = 12300;
	Solution solution;

	std::cout << solution.isSameAfterReversals(num) << std::endl;
	return 0;
}
#endif // LEETCODE_2119

#ifdef LEETCODE_2104_AUDITION_04_06__
int leetcodetestaudition0406()
{
	return 0;
}
#endif

#ifdef DELEETCODE_2104_AUDITION_17_11__BUG
int leetcodetestaudition1711()
{
	return 0;
}
#endif // DELEETCODE_2104_AUDITION_17_11__BUG

#ifdef SWORD_OFFER_II_041
int swordOfferII041()
{
	return 0;
}
#endif // SWORD_OFFER_II_041

#ifdef SWORD_OFFER_II_114
int swordOfferII114()
{
	std::vector<std::string> temp = { "wdaaajlzzz", "asfas", "afawef" };

	Solution solution;
	std::cout << solution.alienOrder(temp).c_str() << std::endl;

	return 0;
}
#endif // SWORD_OFFER_II_114

#ifdef SWORD_OFFER_II_115
int swordOfferII115()
{
	return 0;
}
#endif // SWORD_OFFER_II_115