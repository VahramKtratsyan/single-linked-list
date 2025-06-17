#include <gtest/gtest.h>
#include "../../template/linked_list.tpp"

TEST(LinedList, CreateEmptyList) 
{
    LinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedList, TheListIsNotEmpty_HavingASingleData) 
{                  
    LinkedList<int> list(1);
    EXPECT_FALSE(list.isEmpty());
}

TEST(LinedList, GetData_AfterInserting1Element_WhichIs0) 
{
    LinkedList<int> list(0);
    EXPECT_EQ(list.get(0), 0);
}

TEST(LinedList, GetData_AfterInserting1Element_WhichIs1) 
{
    LinkedList<int> list(1);
    EXPECT_EQ(list.get(0), 1);
}

TEST(LinkedList, InsertSecondElementInListFromEnd_GetTheData)
{
    LinkedList<int> list(1);
    list.insertTail(2);
    EXPECT_EQ(list.get(1), 2);
}

TEST(LinkedList, GetInsertedFirstAndOnlyElmentViaInsertTail) 
{                   
    LinkedList<int> list;
    list.insertTail(2);
    EXPECT_EQ(list.get(0), 2);
}

TEST(LinkedList, GetInsertedSecondElmentFromEndViaInsertTail) 
{                   
    LinkedList<int> list;
    for (int i = 2; i <= 3; ++i)
        list.insertTail(i);
    EXPECT_EQ(list.get(1), 3);
}

TEST(LinkedList, GetInsertedThirdElmentFromEnd) 
{                   
    LinkedList<int> list;
    for (int i = 2; i <= 4; ++i)
        list.insertTail(i);
    EXPECT_EQ(list.get(2), 4);
}

TEST(LinkedList, GetInsertedSixthElmentFromEnd)
{
    LinkedList<int> list;
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    EXPECT_EQ(list.get(5), 7);
}

TEST(LinkedList, GetInsertedFifthElmentFromEnd) 
{                   
    LinkedList<int> list;
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    EXPECT_EQ(list.get(4), 6);
}

TEST(LinkedList, GetFirstElementFromEmptyList) 
{                   
    LinkedList<int> list;
    try 
    {
        list.get(0);
        FAIL() << "Expected std::out_of_range";
    } 
    catch (const std::out_of_range& e) 
    {
        ASSERT_STREQ("There is not element at the specified position.", e.what()); 
    }
}

TEST(LinkedList, GetNonValidPositionElementFromNonEmptyList) 
{                   
    LinkedList<int> list(7);
    try 
    {
        list.get(2);
        FAIL() << "Expected std::out_of_range";
    } 
    catch (const std::out_of_range& e) 
    {
        ASSERT_STREQ("There is not element at the specified position.", e.what()); 
    }
}

TEST(LinkedList, TheLengthOfListAfterInserting_1ElementFromEnd) 
{                   
    LinkedList<int> list;
    list.insertTail(2);
    EXPECT_EQ(list.length(), 1);
}

TEST(LinkedList, TheLengthOfListWhenItIsEmpty) 
{                   
    LinkedList<int> list;
    EXPECT_EQ(list.length(), 0);
}

TEST(LinkedList, InsertElementSecondPositionOfList_GetTheInsertedData) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    list.insert(1, 11);
    EXPECT_EQ(list.get(1), 11);
}

TEST(LinkedList, TheLengthOfListAfterInsertInSpecifiedPositionNonEmptyList) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    list.insert(4, 13);
    EXPECT_EQ(list.length(), 8);
}

TEST(LinkedList, InsertElementForthPositionOfList_GetTheInsertedData) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    list.insert(3, 11);
    EXPECT_EQ(list.get(3), 11);
}

TEST(LinkedList, InsertElementFromEndViaInsert_GetTheInsertedData_CheckIfInsertTailHappenedCorrectlyAfterIt) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    list.insert(7, 11);
    EXPECT_EQ(list.get(7), 11);
    list.insertTail(19);
    EXPECT_EQ(list.get(8), 19);
}

TEST(LinkedList, InsertFromHeadWhenTheListIsEpty_GetTheInsertedData) 
{                   
    LinkedList<int> list;
    list.insertHead(-1);
    EXPECT_EQ(list.get(0), -1);
}

TEST(LinkedList, InsertFromHeadWhenTheListHasASingleElement_GetAllDatasInsideList) 
{                   
    LinkedList<int> list(-1);
    list.insertHead(-2);
    EXPECT_EQ(list.get(0), -2);
    EXPECT_EQ(list.get(1), -1);
}

TEST(LinkedList, InsertFromHeadWhenTheListHasASingleElement_InsertFromTail_GetAllDatasInsideList) 
{                   
    LinkedList<int> list;
    list.insert(0, -1);
    list.insertHead(-2);
    EXPECT_EQ(list.get(0), -2);
    EXPECT_EQ(list.get(1), -1);
    list.insertTail(99);
    EXPECT_EQ(list.get(2), 99);
    EXPECT_EQ(list.length(), 3);
}

TEST(LinkedList, InsertSecondPositionOfEmptyList) 
{                   
    LinkedList<int> list;
    try 
    {
        list.insert(1,0);
        FAIL() << "Expected std::out_of_range";
    } 
    catch (const std::out_of_range& e) 
    {
        ASSERT_STREQ("Can't insert element at the specified position!", e.what()); 
    }
}

TEST(LinkedList, InsertAnyPositionOfEmptyList) 
{                   
    LinkedList<int> list;
    try 
    {
        list.insert(852,12);
        FAIL() << "Expected std::out_of_range";
    } 
    catch (const std::out_of_range& e) 
    {
        ASSERT_STREQ("Can't insert element at the specified position!", e.what()); 
    }
}

TEST(LinkedList, InsertNonValidPositionOfNonEmptyList) 
{                   
    LinkedList<int> list(1);
    list.insertHead(6);
    list.insertTail(12);
    try 
    {
        list.insert(1, 3);
        list.insert(0, 45);
        list.insert(2, 78);
        list.insert(7,0);
        FAIL() << "Expected std::out_of_range";
    } 
    catch (const std::out_of_range& e) 
    {
        ASSERT_STREQ("Can't insert element at the specified position!", e.what()); 
    }
}

TEST(LinkedList, Create_N_SizedLinkedListInWhichAllElementsAreEqual) 
{
    const std::size_t n = 4;                               
    LinkedList<int> list(n, 8);
    ASSERT_EQ(list.length(), n);
    for (std::size_t i{}; i < n; ++i)
        EXPECT_EQ(list.get(i), 8);
}

TEST(LinkedList, RemoveElementFromASingleElementContainedList) 
{                   
    LinkedList<int> list(1);
    list.remove(0);
    EXPECT_EQ(list.length(), 0);
    try 
    {
        list.get(0);
        FAIL() << "Expected std::out_of_range";
    }
    catch (const std::out_of_range& e) 
    {
        ASSERT_STREQ("There is not element at the specified position.", e.what()); 
    } 
}

TEST(LinkedList, RemoveFirstElementFromtwoElementContainedList) 
{                   
    LinkedList<int> list(1);
    list.insertTail(2);
    list.remove(0);
    ASSERT_EQ(list.length(), 1);
    EXPECT_EQ(list.get(0), 2);
}

TEST(LinkedList, RemoveFirstElementFromFiveElementContainedList) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 5; ++i)
        list.insertTail(i);
    list.remove(0);
    ASSERT_EQ(list.length(), 4);
    EXPECT_EQ(list.get(0), 2);
}

TEST(LinkedList, RemoveSecondElementFromtwoElementContainedList) 
{                   
    LinkedList<int> list(1);
    list.insertTail(2);
    list.remove(1);
    ASSERT_EQ(list.length(), 1);
    EXPECT_EQ(list.get(0), 1);
}

TEST(LinkedList, RemoveSpecifiedElementFromNonEmptyList) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 6; ++i)
        list.insertTail(i);
    list.insert(3,7);
    list.insert(4,8);
    list.insertHead(0);
    list.insertTail(9);
    list.insertHead(10);
    list.remove(5);
    ASSERT_EQ(list.length(), 10);
    EXPECT_EQ(list.get(5), 8);
}

TEST(LinkedList, RemoveLastElementFromNonEmptyList_InsertFromTheEnd) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 6; ++i)
        list.insertTail(i);
    list.insert(3,7);
    list.remove(6);
    list.insertTail(-1);
    ASSERT_EQ(list.length(), 7);
    EXPECT_EQ(list.get(6), -1);
}

TEST(LinkedList, RemoveFirstElementFromNonEmptyList_InsertFromTheHead) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 6; ++i)
        list.insertTail(i);
    list.remove(0);
    list.insertHead(-1);
    ASSERT_EQ(list.length(), 6);
    EXPECT_EQ(list.get(0), -1);
}

TEST(LinkedList, RemoveFirstElementFromASingleElementContainedList_InsertFromTheHeadAndEnd) 
{                   
    LinkedList<int> list(1);
    list.remove(0);
    list.insertHead(-1);
    list.insertTail(-2);
    ASSERT_EQ(list.length(), 2);
    EXPECT_EQ(list.get(0), -1);
    EXPECT_EQ(list.get(1), -2);
}


TEST(LinkedList, RemoveFirstPositionElementFromEmptyList) 
{                   
    LinkedList<int> list;
    try 
    {
        list.remove(0);
        FAIL() << "Expected std::out_of_range";
    } 
    catch (const std::out_of_range& e) 
    {
        ASSERT_STREQ("There is no element to remove at the specified position.", e.what()); 
    }
}

TEST(LinkedList, RemoveAnytPositionElementFromEmptyList) 
{                   
    LinkedList<int> list;
    try 
    {
        list.remove(9);
        FAIL() << "Expected std::out_of_range";
    } 
    catch (const std::out_of_range& e) 
    {
        ASSERT_STREQ("There is no element to remove at the specified position.", e.what()); 
    }
}

TEST(LinkedList, RemoveNonValidPositionElementFromNonEmptyList) 
{                   
    LinkedList<int> list(7);
    list.insertTail(-8);
    try 
    {
        list.remove(2);
        FAIL() << "Expected std::out_of_range";
    } 
    catch (const std::out_of_range& e) 
    {
        ASSERT_STREQ("There is no element to remove at the specified position.", e.what()); 
    }
}

TEST(LinkedList, CopyEmptyObjectByCopyConstructor) 
{                   
    LinkedList<int> list;
    LinkedList<int> list1(list);
    EXPECT_TRUE(list1.isEmpty());
}

TEST(LinkedList, CopyObjectByCopyConstructor_TheyMustNotPointOnTheSmaeMemory) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 6; ++i)
        list.insertTail(i);

    LinkedList<int> list1(list);
    ASSERT_EQ(list1.length(), 6);
    for (std::size_t i{}; i < 6; ++i)
        EXPECT_EQ(list1.get(i), list.get(i));

    list1.insertTail(7);
    EXPECT_EQ(list1.length(), list.length() + 1);
}

TEST(LinkedList, EmptyObjectCopyAssignment) 
{                   
    LinkedList<int> list;
    LinkedList<int> list1;
    list = list1;
    EXPECT_TRUE(list.isEmpty());
}

TEST(LinkedList, CopyAssignOneObjectToAnother_TheyMustNotPointOnTheSmaeMemory) 
{                   
    LinkedList<int> list;
    for (int i = 1; i <= 4; ++i)
        list.insertTail(i);

    LinkedList<int> list1;
    for (int i = 1; i <= 3; ++i)
        list1.insertTail(i);

    list1 = list;
    ASSERT_EQ(list1.length(), 4);
    for (std::size_t i{}; i < 4; ++i)
        EXPECT_EQ(list1.get(i), list.get(i));

    list1.insertTail(5);
    EXPECT_EQ(list1.length(), list.length() + 1);
}

TEST(LinkedList, MoveObjectByMoveConstructor) 
{ 
    LinkedList<int> list;
    for (int i = 1; i <= 4; ++i)
        list.insertTail(i);
        
    LinkedList<int> copyOfList(list);
    LinkedList<int> list1(std::move(list));
    ASSERT_TRUE(list.isEmpty());
    ASSERT_EQ(list1.length(), 4);
    for (std::size_t i{}; i < 4; ++i)
        EXPECT_EQ(list1.get(i), copyOfList.get(i));
}

TEST(LinkedList, MoveAssignment) 
{                              
    LinkedList<int> list;
    for (int i = 1; i <= 4; ++i)
        list.insertTail(i);

    list = LinkedList<int>(10, -5);
    ASSERT_EQ(list.length(), 10);
    for (std::size_t i{}; i < 10; ++i)
        EXPECT_EQ(list.get(i), -5);
}