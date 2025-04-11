#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

TEST(test_list_default_ctor) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_forward_traversal) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    int j = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++j) {
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(j, list.size());
}

TEST(test_backward_traversal) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    int j = list.size();
    List<int>::Iterator it = list.end();
    do {
        --it;
        --j;
        ASSERT_EQUAL(*it, j);
    }
    while(it != list.begin());
    ASSERT_EQUAL(j, 0);
}

TEST(test_erase1){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    List<int>::Iterator it = list.begin();
    list.erase(it);
    List<int>::Iterator newIterator = list.begin();
    ASSERT_EQUAL(*newIterator, 83);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 47);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 187);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1084);
}

TEST(test_erase2){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    List<int>::Iterator it = list.begin();
    it++;
    list.erase(it);
    List<int>::Iterator newIterator = list.begin();
    ASSERT_EQUAL(*newIterator, 16);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 47);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 187);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1084);
}

TEST(test_erase3){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    List<int>::Iterator it = list.begin();
    it++;
    it++;
    list.erase(it);
    List<int>::Iterator newIterator = list.begin();
    ASSERT_EQUAL(*newIterator, 16);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 83);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 187);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1084);
}

TEST(test_erase4){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    List<int>::Iterator it = list.begin();
    it++;
    it++;
    it++;
    list.erase(it);
    List<int>::Iterator newIterator = list.begin();
    ASSERT_EQUAL(*newIterator, 16);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 83);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 47);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 187);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1084);
}

TEST(test_erase5){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    List<int>::Iterator it = list.begin();
    it++;
    it++;
    it++;
    it++;
    list.erase(it);
    List<int>::Iterator newIterator = list.begin();
    ASSERT_EQUAL(*newIterator, 16);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 83);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 47);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1084);
}

TEST(test_erase6){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    List<int>::Iterator it = list.begin();
    it++;
    it++;
    it++;
    it++;
    it++;
    list.erase(it);
    List<int>::Iterator newIterator = list.begin();
    ASSERT_EQUAL(*newIterator, 16);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 83);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 47);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 1);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 187);
    newIterator++;
}

TEST(test_erase7){
    List <int> list;
    List<int>::Iterator it = list.begin();
    list.erase(it);
    ASSERT_EQUAL(list.empty(), true);
}

TEST(test_insert1){
    List<int> list;
    list.push_back(2);
    list.push_back(12);
    list.push_back(23);
    list.push_back(13);
    list.push_back(14);

    List<int>::Iterator it = list.begin();
    list.insert(it, 13);

    List<int>::Iterator newIterator = list.begin();
    ASSERT_EQUAL(*newIterator, 13);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 2);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 12);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 23);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 13);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 14);
}

TEST(test_insert2){
    List<int> list;
    list.push_back(2);
    list.push_back(12);
    list.push_back(23);

    List<int>::Iterator it = list.begin();
    it++;
    list.insert(it, 107);

    List<int>::Iterator newIterator = list.begin();
    ASSERT_EQUAL(*newIterator, 2);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 107);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 23);
}

TEST(test_insert3){
    List<int> list;
    list.push_back(2);
    list.push_back(12);
    list.push_back(23);

    List<int>::Iterator it = list.begin();
    it++;
    it++;
    list.insert(it, -367);

    List<int>::Iterator newIterator = list.begin();
    ASSERT_EQUAL(*newIterator, 2);
    newIterator++;
    ASSERT_EQUAL(*newIterator, 12);
    newIterator++;
    ASSERT_EQUAL(*newIterator, -367);
}

TEST(test_insert4){
    List<int> list;

    List<int>::Iterator it = list.begin();
    list.insert(it, 14);

    ASSERT_EQUAL(list.begin(), 14);
}

TEST(test_size1){
    List<int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    ASSERT_EQUAL(list.size(), 5);
}

TEST(test_size2){
    List<int> list;
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_size3){
    List<int> list;
    list.push_back(13);
    list.push_back(15);
    List<int>::Iterator it = list.end();
    list.insert(it, 74);
    ASSERT_EQUAL(list.size(), 3);
}

TEST(test_size4){
    List<int> list;
    list.push_back(13);
    list.push_back(15);
    List<int>::Iterator it = list.begin();
    list.erase(it);
    ASSERT_EQUAL(list.size(), 1);
    List<int>::Iterator it2 = list.end();
    it2--;
    list.erase(it2);
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_front){
    List<int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    ASSERT_EQUAL(list.front(), -17);
}

TEST(test_back){
    List<int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    ASSERT_EQUAL(list.back(), 1208);
}

TEST(test_single_value){
    List<int> list;
    list.push_back(4);
    ASSERT_EQUAL(list.front(), 4);
    ASSERT_EQUAL(list.back(), 4);
}

TEST(test_pop_front){
    List<int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    
    list.pop_front();
    ASSERT_EQUAL(list.front(), 8);
    ASSERT_EQUAL(list.size(), 4);
    
    list.pop_front();
    ASSERT_EQUAL(list.front(), 43);
    ASSERT_EQUAL(list.size(), 3);
    
    list.pop_front();
    ASSERT_EQUAL(list.front(), 108);
    ASSERT_EQUAL(list.size(), 2);

    list.pop_front();
    ASSERT_EQUAL(list.front(), 1208);
    ASSERT_EQUAL(list.size(), 1);

    list.pop_front();
    ASSERT_EQUAL(list.empty(), true);
}

TEST(test_pop_front2){
    List<int> list;    
    list.push_back(2);
    list.push_back(2);
    list.push_back(2);
    list.push_back(2);
    list.push_back(2);

    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.size(), 4);
    
    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.size(), 3);
    
    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.size(), 2);

    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.size(), 1);

    list.pop_front();
    ASSERT_EQUAL(list.empty(), true);

}

TEST(test_pop_back){
    List<int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    
    list.pop_back();
    List<int>::Iterator itOne = list.end();
    itOne--;
    ASSERT_EQUAL(*itOne, 108);
    ASSERT_EQUAL(list.size(), 4);

    list.pop_back();
    List<int>::Iterator itTwo = list.end();
    itTwo--;
    ASSERT_EQUAL(*itTwo, 43);
    ASSERT_EQUAL(list.size(), 3);

    list.pop_back();
    List<int>::Iterator itThree = list.end();
    itThree--;
    ASSERT_EQUAL(*itThree, 8);
    ASSERT_EQUAL(list.size(), 2);

    list.pop_back();
    List<int>::Iterator itFour = list.end();
    itFour--;
    ASSERT_EQUAL(*itFour, -17);
    ASSERT_EQUAL(list.size(), 1);

    list.pop_back();
    ASSERT_EQUAL(list.empty(), true);
}

TEST(test_pop_back2){
    List<int> list;    
    list.push_back(2);
    list.push_back(2);
    list.push_back(2);
    list.push_back(2);
    list.push_back(2);

    list.pop_back();
    List<int>::Iterator itOne = list.end();
    itOne--;
    ASSERT_EQUAL(*itOne, 2);
    ASSERT_EQUAL(list.size(), 4);

    list.pop_back();
    List<int>::Iterator itTwo = list.end();
    itTwo--;
    ASSERT_EQUAL(*itTwo, 2);
    ASSERT_EQUAL(list.size(), 3);

    list.pop_back();
    List<int>::Iterator itThree = list.end();
    itThree--;
    ASSERT_EQUAL(*itThree, 2);
    ASSERT_EQUAL(list.size(), 2);

    list.pop_back();
    List<int>::Iterator itFour = list.end();
    itFour--;
    ASSERT_EQUAL(*itFour, 2);
    ASSERT_EQUAL(list.size(), 1);

    list.pop_back();
    ASSERT_EQUAL(list.empty(), true);

}

TEST(test_clear){
    List <int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    list.clear();
    ASSERT_EQUAL(list.empty(), true);
}

TEST(test_clear2){
    List<int> list;
    list.clear();
    ASSERT_EQUAL(list.empty(), true);
}

TEST(test_clear3){
    List<int> list;
    list.push_back(123);
    list.push_back(123);
    list.clear();
    ASSERT_EQUAL(list.empty(), true);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ASSERT_EQUAL(list.empty(), false);

    list.clear();
    ASSERT_EQUAL(list.empty(), true);
}

TEST(test_operator){
    List <int> listOne;
    List <int> listTwo;
    
    ASSERT_EQUAL(listOne, listTwo);

    listOne.push_back(20);
    listOne.push_back(30);
    listOne.push_back(40);
    listOne.push_back(50);
    
    listTwo.push_back(1);
    listTwo.push_back(2);

    listTwo = listOne;
    ASSERT_EQUAL(listTwo.size(), 4);
    
    List<int>::Iterator it = listTwo.begin();
    ASSERT_EQUAL(*it, 20);
    it++;
    ASSERT_EQUAL(*it, 30);
    it++;
    ASSERT_EQUAL(*it, 40);
    it++;
    ASSERT_EQUAL(*it, 50);
    it++;

    listOne.pop_back();
    ASSERT_EQUAL(listTwo.size() - 1, listOne.size());
}

TEST_MAIN()
