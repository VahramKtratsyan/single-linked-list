#include <gtest/gtest.h>
#include <utility>
#include "../../template/LinkedList.tpp"

TEST(LinedList, CreatingList) 
{
    LinkedList<int> list;
}

TEST(LinedList, IsEmpty) 
{
    LinkedList<int> list;
    ASSERT_EQ(list.isEmpty(), true);
}

TEST(LinedList, InsertDataWhileCreating) 
{
    LinkedList<int> list(2);
}

TEST(LinedList, GetData_AfterInserting1Element_WhichIs0) 
{
    LinkedList<int> list(0);
    ASSERT_EQ(list.get(0), 0);
}

TEST(LinedList, GetData_AfterInserting1Element_WhichIs1) 
{
    LinkedList<int> list(1);
    ASSERT_EQ(list.get(0), 1);
}

TEST(LinkedList, TheListIsNotEmpty_HavingASingleData) 
{                  
    LinkedList<int> list(1);
    ASSERT_EQ(list.isEmpty(), false);
}

TEST(LinkedList, InsertSecondElementInListFromEnd)
{
    LinkedList<int> list(1);
    list.insertTail(2);
}

TEST(LinkedList, Get_InsertedSecondElmentFromEnd) 
       
{                   
    LinkedList<int> list(1);
    list.insertTail(2);
    ASSERT_EQ(list.get(1), 2);
}

TEST(LinkedList, Get_InsertedFirstAndOnlyElmentViaInsertTail) 
{                   
    LinkedList<int> list;
    list.insertTail(2);
    ASSERT_EQ(list.get(0), 2);
}

TEST(LinkedList, Get_InsertedSecondElmentFromEndViaInsertTail) 
{                   
    LinkedList<int> list;
    for (int i = 2; i <= 3; ++i)
        list.insertTail(i);
    ASSERT_EQ(list.get(1), 3);
}

TEST(LinkedList, Get_InsertedThirdElmentFromEnd) 
{                   
    LinkedList<int> list;
    for (int i = 2; i <= 4; ++i)
        list.insertTail(i);
    ASSERT_EQ(list.get(2), 4);
}

TEST(LinkedList, Get_InsertedSixthElmentFromEnd)
{
    LinkedList<int> list;
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    ASSERT_EQ(list.get(5), 7);
}

TEST(LinkedList, Get_InsertedFifthElmentFromEnd) 
{                   
    LinkedList<int> list;
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    ASSERT_EQ(list.get(4), 6);
}

TEST(LinkedList, TheLengthOfListAfterInserting_1ElementFromEnd) 
{                   
    LinkedList<int> list;
    list.insertTail(2);
    ASSERT_EQ(list.length(), 1);
}

TEST(LinkedList, TheLengthOfListWhenItIsEmpty) 
{                   
    LinkedList<int> list;
    ASSERT_EQ(list.length(), 0);
}

TEST(LinkedList, InsertElementSecondPositionOfList_AndGet) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    list.insert(1, 11);
    ASSERT_EQ(list.get(1), 11);
}

TEST(LinkedList, TheLengthOfListAfterInsertInSpecifiedPositionNonEmptyList) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    list.insert(4, 13);
    ASSERT_EQ(list.length(), 8);
}

TEST(LinkedList, InsertElementForthPositionOfList_AndGet) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    list.insert(3, 11);
    ASSERT_EQ(list.get(3), 11);
}

TEST(LinkedList, InsertElementFromEndViaInsert_AndGet_AlsoCheckIfInsertTailHappenedCorrectlyAfterIt) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 7; ++i)
        list.insertTail(i);
    list.insert(7, 11);
    ASSERT_EQ(list.get(7), 11);
    list.insertTail(19);
    ASSERT_EQ(list.get(8), 19);
}

TEST(LinkedList, InsertFromHeadWhenTheListIsEpty_AndGetTheInsertedData) 
{                   
    LinkedList<int> list;
    list.insertHead(-1);
    ASSERT_EQ(list.get(0), -1);
}

TEST(LinkedList, InsertFromHeadWhenTheListHasASingleElement_AndGetAllDatasInsideList) 
{                   
    LinkedList<int> list(-1);
    list.insertHead(-2);
    ASSERT_EQ(list.get(0), -2);
    ASSERT_EQ(list.get(1), -1);
}

TEST(LinkedList, InsertFromHeadWhenTheListHasASingleElement_AlsoInsertFromTail_AndGetAllDatasInsideList_AlsoCheckLength) 
{                   
    LinkedList<int> list;
    list.insert(0, -1);
    list.insertHead(-2);
    ASSERT_EQ(list.get(0), -2);
    ASSERT_EQ(list.get(1), -1);
    list.insertTail(99);
    ASSERT_EQ(list.get(2), 99);
    ASSERT_EQ(list.length(), 3);
}

TEST(LinkedList, PrintListVisualisationChecking) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 6; ++i)
        list.insertTail(i);
    list.insert(3,7);
    list.insert(4,8);
    list.insertHead(0);
    list.insertTail(9);
    list.insertHead(10);
    list.printList();
}

TEST(LinkedList, RemoveElementFromASingleElementContainedList) 
{                   
    LinkedList<int> list(1);
    list.remove(0);
    ASSERT_EQ(list.length(), 0);
}

TEST(LinkedList, RemoveFirstElementFromtwoElementContainedList_CheckLength) 
{                   
    LinkedList<int> list(1);
    list.insertTail(2);
    list.remove(0);
    ASSERT_EQ(list.length(), 1);
}

TEST(LinkedList, RemoveFirstElementFromtwoElementContainedList_CheckFirstElement_AlsoPrintList) 
{                   
    LinkedList<int> list(1);
    list.insertTail(2);
    list.remove(0);
    ASSERT_EQ(list.get(0), 2);
    list.printList();
}

TEST(LinkedList, RemoveFirstElementFromFiveElementContainedList_CheckFirstElement_AlsoPrintList) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 5; ++i)
        list.insertTail(i);
    list.remove(0);
    ASSERT_EQ(list.get(0), 2);
    list.printList();
}

TEST(LinkedList, RemoveSecondElementFromtwoElementContainedList_CheckFirstElement_AlsoPrintList) 
{                   
    LinkedList<int> list(1);
    list.insertTail(2);
    list.remove(1);
    ASSERT_EQ(list.get(0), 1);
    list.printList();
}

TEST(LinkedList, RemoveSpecifiedElementFromNonEmptyList_PrintList) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 6; ++i)
        list.insertTail(i);
    list.insert(3,7);
    list.insert(4,8);
    list.insertHead(0);
    list.insertTail(9);
    list.insertHead(10);
    list.printList();
    list.remove(5);
    list.printList();
}

TEST(LinkedList, RemoveLastElementFromNonEmptyList_PrintList_InsertFromTheEnd_Check) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 6; ++i)
        list.insertTail(i);
    list.insert(3,7);
    list.printList();
    list.remove(6);
    list.printList();
    list.insertTail(-1);
    list.printList();
    ASSERT_EQ(list.get(6), -1);
}

TEST(LinkedList, RemoveFirstElementFromNonEmptyList_PrintList_InsertFromTheHead_Check) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 6; ++i)
        list.insertTail(i);
    list.printList();
    list.remove(0);
    list.printList();
    list.insertHead(-1);
    list.printList();
    ASSERT_EQ(list.get(0), -1);
}

TEST(LinkedList, RemoveFirstElementFromASingleElementContainedList_PrintList_InsertFromTheHeadAndEnd_Check) 
{                   
    LinkedList<int> list(1);
    list.remove(0);
    list.printList();
    list.insertHead(-1);
    list.insertTail(-2);
    list.printList();
    ASSERT_EQ(list.get(0), -1);
    ASSERT_EQ(list.get(1), -2);
}


TEST(LinkedList, RemoveFirstPositionElementFromEmptyList_ExceptionChecking) 
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

TEST(LinkedList, RemoveAnytPositionElementFromEmptyList_ExceptionChecking) 
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

TEST(LinkedList, RemoveNonValidPositionElementFromNonEmptyList_ExceptionChecking) 
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

TEST(LinkedList, InsertSecondPositionOfEmptyList_ExceptionChecking) 
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

TEST(LinkedList, InsertAnyPositionOfEmptyList_ExceptionChecking) 
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

TEST(LinkedList, InsertNonValidPositionOfNonEmptyList_ExceptionChecking) 
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

TEST(LinkedList, GetFirstElementFromEmptyList_ExceptionChecking) 
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

TEST(LinkedList, GetNonValidPositionElementFromNonEmptyList_ExceptionChecking) 
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

TEST(LinkedList, CopyEmptyObjectByCopyConstructor_CheckingLengths_PrintList1) 
{                   
    LinkedList<int> list;
    LinkedList<int> list1(list);
    ASSERT_EQ(list1.length(), 0);
    list1.printList();
}

TEST(LinkedList, CopyObjectByCopyConstructor_CheckingLengths_PrintToWatchTheyAreNotPointedOnTheSmaeMemory) 
{                   
    LinkedList<int> list(1);
    for (int i = 2; i <= 6; ++i)
        list.insertTail(i);
    list.printList();
    LinkedList<int> list1(list);
    list1.insertTail(7);
    ASSERT_EQ(list1.length(), 7);
    ASSERT_EQ(list.length(), 6);
    list1.printList();
}

TEST(LinkedList, EmptyObjectCopyAssignment_CheckingLengths_PrintLists) 
{                   
    LinkedList<int> list;
    LinkedList<int> list1;
    list = list1;
    ASSERT_EQ(list1.length(), 0);
    ASSERT_EQ(list.length(), 0);
    list.printList();
    list1.printList();
}

TEST(LinkedList, CopyAssignOneObjectToAnother_CheckingLengths_PrintListsToWatchTheyAreNotPointedOnTheSmaeMemory) 
{                   
    LinkedList<int> list;
    for (int i = 1; i <= 4; ++i)
        list.insertTail(i);
    list.printList();
    LinkedList<int> list1;
    for (int i = 1; i <= 3; ++i)
        list1.insertTail(i);
    list1.printList();
    list1 = list;
    ASSERT_EQ(list1.length(), 4);
    list.insertTail(5);
    ASSERT_EQ(list.length(), 5);
    list.printList();
    list1.printList();
}

TEST(LinkedList, MoveAssignmentWithTemporaryObject_CheckLength_PrintList) 
{                              
    LinkedList<int> list;
    for (int i = 1; i <= 4; ++i)
        list.insertTail(i);
    list.printList();
    list = LinkedList<int>(3);
    EXPECT_EQ(list.length(), 1);
    list.printList();
}

TEST(LinkedList, MoveAssignmentWithNonTemporaryObject_CheckLengths_PrintList) 
{                              
    LinkedList<int> list;
    list.insertTail(10);
    list.insertTail(20);

    LinkedList<int> list1;
    list1 = std::move(list);
    list1.printList();
    EXPECT_EQ(list1.length(), 2);
    EXPECT_EQ(list.length(), 0);
}

TEST(LinkedList, MoveObjectByMoveConstructor_CheckLength_PrintList) 
{ 
    LinkedList<int> list;
    for (int i = 1; i <= 4; ++i)
        list.insertTail(i);                             
    LinkedList<int> list1(std::move(list));
    EXPECT_EQ(list1.length(), 4);
    list1.printList();
}