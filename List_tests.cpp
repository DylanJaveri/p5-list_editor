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

    auto it = list.begin();
    list.erase(it);
    auto newValue = list.begin();
    ASSERT_EQUAL(*newValue, 83);
    newValue++;
    ASSERT_EQUAL(*newValue, 47);
    newValue++;
    ASSERT_EQUAL(*newValue, 1);
    newValue++;
    ASSERT_EQUAL(*newValue, 187);
    newValue++;
    ASSERT_EQUAL(*newValue, 1084);
}

TEST(test_erase2){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    auto it = list.begin();
    it++;
    list.erase(it);
    auto newValue = list.begin();
    ASSERT_EQUAL(*newValue, 16);
    newValue++;
    ASSERT_EQUAL(*newValue, 47);
    newValue++;
    ASSERT_EQUAL(*newValue, 1);
    newValue++;
    ASSERT_EQUAL(*newValue, 187);
    newValue++;
    ASSERT_EQUAL(*newValue, 1084);
}

TEST(test_erase3){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    auto it = list.begin();
    it++;
    it++;
    list.erase(it);
    auto newValue = list.begin();
    ASSERT_EQUAL(*newValue, 16);
    newValue++;
    ASSERT_EQUAL(*newValue, 83);
    newValue++;
    ASSERT_EQUAL(*newValue, 1);
    newValue++;
    ASSERT_EQUAL(*newValue, 187);
    newValue++;
    ASSERT_EQUAL(*newValue, 1084);
}

TEST(test_erase4){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    auto it = list.begin();
    it++;
    it++;
    it++;
    list.erase(it);
    auto newValue = list.begin();
    ASSERT_EQUAL(*newValue, 16);
    newValue++;
    ASSERT_EQUAL(*newValue, 83);
    newValue++;
    ASSERT_EQUAL(*newValue, 47);
    newValue++;
    ASSERT_EQUAL(*newValue, 187);
    newValue++;
    ASSERT_EQUAL(*newValue, 1084);
}

TEST(test_erase5){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    auto it = list.begin();
    it++;
    it++;
    it++;
    it++;
    list.erase(it);
    auto newValue = list.begin();
    ASSERT_EQUAL(*newValue, 16);
    newValue++;
    ASSERT_EQUAL(*newValue, 83);
    newValue++;
    ASSERT_EQUAL(*newValue, 47);
    newValue++;
    ASSERT_EQUAL(*newValue, 1);
    newValue++;
    ASSERT_EQUAL(*newValue, 1084);
}

TEST(test_erase6){
    List<int> list;
    list.push_back(16);
    list.push_back(83);
    list.push_back(47);
    list.push_back(1);
    list.push_back(187);
    list.push_back(1084);

    auto it = list.begin();
    it++;
    it++;
    it++;
    it++;
    it++;
    list.erase(it);
    auto newValue = list.begin();
    ASSERT_EQUAL(*newValue, 16);
    newValue++;
    ASSERT_EQUAL(*newValue, 83);
    newValue++;
    ASSERT_EQUAL(*newValue, 47);
    newValue++;
    ASSERT_EQUAL(*newValue, 1);
    newValue++;
    ASSERT_EQUAL(*newValue, 187);
    newValue++;
}

TEST(test_insert){
    List<int> list;
    list.push_back(2);
    list.push_back(12);
    list.push_back(23);
    list.push_back(13);
    list.push_back(14);

    auto it = list.begin();
    list.insert(it, 13);

    auto newValue = list.begin();
    ASSERT_EQUAL(*newValue, 13);
    newValue++;
    ASSERT_EQUAL(*newValue, 2);
    newValue++;
    ASSERT_EQUAL(*newValue, 12);
    newValue++;
    ASSERT_EQUAL(*newValue, 23);
    newValue++;
    ASSERT_EQUAL(*newValue, 13);
    newValue++;
    ASSERT_EQUAL(*newValue, 14);
}

TEST(test_size){

    List<int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    ASSERT_EQUAL(list.size(), 5);
}

TEST(test_front_and_back){
    List<int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    ASSERT_EQUAL(list.front(), -17);
    ASSERT_EQUAL(list.back(), 1208);
}

TEST(test_pop_front){
    List<int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    list.pop_front();
    auto it = list.begin();
    ASSERT_EQUAL(*it, 8);
    ASSERT_EQUAL(list.size(), 4);
}

TEST(test_pop_back){
    List<int> list;
    list.push_back(-17);
    list.push_back(8);
    list.push_back(43);
    list.push_back(108);
    list.push_back(1208);
    list.pop_back();
    auto it = list.end();
    it--;
    ASSERT_EQUAL(*it, 108);
    ASSERT_EQUAL(list.size(), 4);
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
    
    auto it = listTwo.begin();
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
